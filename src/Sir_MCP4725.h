#define WRITEDAC_CMD            (0x40)  
#define WRITEDACEEPROM_CMD      (0x60)  

class Sir_MCP4725{
  private:
    uint8_t i2c_address;

  public:
    Sir_MCP4725();
    void init(uint8_t);  
    void setVoltage(uint16_t, bool);
};