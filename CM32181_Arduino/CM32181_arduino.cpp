/*
  CM32181_arduino.cpp - Library for cm32181 driver code.
  Created by Shine Hua 2017.01.11 
  Released into the public domain.
  https://github.com/ShineHua2017/CM32181_arduino
*/

#include <CM32181_arduino.h>
#include <Wire.h>

CM32181::CM32181(uint8_t address)
{
	Wire.begin(); 
	_address = address;
}

boolean CM32181::init_chip(void)
{
 
		uint8_t quantity = 2;
		uint32_t iaddr = 0x0008;  //set ALS_IT = 1000
		uint8_t isize = 3;
		uint8_t sendStop = 0;
		boolean detect = false;
		Wire.requestFrom(_address, quantity, iaddr, isize, sendStop);
		sensorWait(5);
		Wire.flush();
        detect = Wire.endTransmission(true); 
		sensorWait(20);
		if(detect == 0){
			return true;
		}else{
			return false;
		}

		
}

uint16_t CM32181::read_sensor_raw()
{
	
	uint16_t raw_value = 0;
	uint8_t quantity = 2;
	
	Wire.beginTransmission(_address);  
    Wire.write(uint8_t(CM32181_REG_ADDR_ALS));            
    Wire.endTransmission(false);        
    sensorWait(20); 
	Wire.requestFrom(_address, quantity);    
    sensorWait(1500); 
    while(Wire.available()) {  
      if(Wire.available() >=2){
        uint16_t Ldata = (uint16_t)Wire.read();
        uint16_t Mdata = (uint16_t)Wire.read();
        raw_value = (Mdata << 8) | Ldata;
        break;
      }
    }
    Wire.endTransmission(true);
	return raw_value;
	
}

uint16_t CM32181::get_chip_ID()
{
	
	uint16_t id_value = 0;
	uint8_t quantity = 2;
	
	Wire.beginTransmission(_address);  
    Wire.write(uint8_t(CM32181_REG_ADDR_ID));            
    Wire.endTransmission(false);        
    sensorWait(20); 
	Wire.requestFrom(_address, quantity);    
    sensorWait(1500); 
    while(Wire.available()) {  
      if(Wire.available() >=2){
        uint16_t Ldata = (uint16_t)Wire.read();
        uint16_t Mdata = (uint16_t)Wire.read();
        id_value = (Mdata << 8) | Ldata;
        break;
      }
    }
    Wire.endTransmission(true);
	return (id_value & 0xFF);
	
}

uint16_t CM32181::get_chip_status()
{
	
	uint16_t id_value = 0;
	uint8_t quantity = 2;
	
	Wire.beginTransmission(_address);  
    Wire.write(uint8_t(CM32181_REG_ADDR_STATUS));            
    Wire.endTransmission(false);        
    sensorWait(20); 
	Wire.requestFrom(_address, quantity);    
    sensorWait(1500); 
    while(Wire.available()) {  
      if(Wire.available() >=2){
        uint16_t Ldata = (uint16_t)Wire.read();
        uint16_t Mdata = (uint16_t)Wire.read();
        id_value = (Mdata << 8) | Ldata;
        break;
      }
    }
    Wire.endTransmission(true);
	return (id_value);
	
}

boolean CM32181::powerdown_chip()
{
	
		uint8_t quantity = 2;
		uint32_t iaddr = 0x0100;
		uint8_t isize = 3;
		uint8_t sendStop = 0;
		boolean detect = false;
		Wire.requestFrom(_address, quantity, iaddr, isize, sendStop);
		sensorWait(5);
		Wire.flush();
        detect = Wire.endTransmission(true); 
		sensorWait(20);
		if(detect == 0){
			return true;
		}else{
			return false;
		}

}

boolean CM32181::powerup_chip()
{
	
		uint8_t quantity = 2;
		uint32_t iaddr = 0x0000;
		uint8_t isize = 3;
		uint8_t sendStop = 0;
		boolean detect = false;
		Wire.requestFrom(_address, quantity, iaddr, isize, sendStop);
		sensorWait(5);
		Wire.flush();
        detect = Wire.endTransmission(true); 
		sensorWait(20);
		if(detect == 0){
			return true;
		}else{
			return false;
		}
		
}

void CM32181::sensorWait(int time)
{
	delay(time);
}
