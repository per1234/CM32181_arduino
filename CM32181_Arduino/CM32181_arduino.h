/*
  CM32181_arduino.h - Library for cm32181 driver code.
  Created by Shine Hua 2017.01.11 
  Released into the public domain.
  https://github.com/ShineHua2017/CM32181_arduino
*/

#ifndef CM32181_arduino_h
#define CM32181_arduino_h

#include <Arduino.h>
 
#define CM32181_REG_ADDR_CMD            0x00
#define CM32181_REG_ADDR_ALS            0x04
#define CM32181_REG_ADDR_STATUS         0x06
#define CM32181_REG_ADDR_ID             0x07

class CM32181
{
  public:
    CM32181(uint8_t address);
    boolean init_chip(void);
    uint16_t read_sensor_raw(void);
	uint16_t get_chip_ID(void);
	uint16_t get_chip_status(void);
	boolean powerdown_chip(void);
	boolean powerup_chip(void);
  private:
    uint8_t _address;
	void sensorWait(int time);
};
 
#endif
