#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>
#include "Sir_MCP4725.h"


Sir_MCP4725::Sir_MCP4725() {
}

void Sir_MCP4725::init(uint8_t addr) {
}