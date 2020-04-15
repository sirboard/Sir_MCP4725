#include "Arduino.h"
#include <Wire.h>
#include "Sir_MCP4725.h"

Sir_MCP4725::Sir_MCP4725(uint8_t addr) {
}

void Sir_MCP4725::init(uint8_t addr) {
  i2caddr = addr;
  Wire.begin();
}

void Sir_MCP4725::setVoltage(uint16_t x, bool writeEEPROM ) {
  Wire.beginTransmission(i2caddr);
  if (writeEEPROM) Wire.write(WRITEDACEEPROM_CMD);
  else Wire.write(WRITEDAC_CMD);
  Wire.write(x & 0xff);   // xlow                
  Wire.write(x >> 8);     // xhigh      
  Wire.endTransmission();
}
