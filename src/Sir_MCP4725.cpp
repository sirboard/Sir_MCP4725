#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>
#include "Sir_MCP4725.h"


Sir_MCP4725::Sir_MCP4725(uint8_t addr) {
}

void Sir_MCP4725::init(uint8_t addr) {
  i2caddr = addr;
  Wire.begin();
}

void Sir_MCP4725::setVoltage(uint16_t x, bool writeEEPROM )
{
  uint8_t xlow = x & 0xff;
  uint8_t xhigh = (x >> 8);
#ifdef TWBR
  uint8_t twbrback = TWBR;
  TWBR = ((F_CPU / 400000L) - 16) / 2; // Set I2C frequency to 400kHz
#endif
  Wire.beginTransmission(i2caddr);
  if (writeEEPROM) Wire.write(WRITEDACEEPROM_CMD);
  else Wire.write(WRITEDAC_CMD);
  Wire.write(xlow);                   
  Wire.write(xhigh);            
  Wire.endTransmission();
#ifdef TWBR
  TWBR = twbrback;
#endif
}