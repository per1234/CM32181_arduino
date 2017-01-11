/* Arduino demo code for control Light Sensor chip -- CM32181  
 * Setup chip on polling mode and read Lux value
 * 
 * The circuit:
 *    Ardunio           CM32181
 *      SDA    <--->      SDA
 *      SCL    <--->      SCL
 *      
 * library coding based on TWI library
 * 
 * Written by Shine Hua
 * Email Address: 20497409@qq.com huashine2013@gmail.com
 *  
 */

#include <CM32181_arduino.h>
//CM32181 ADDR pin pull high to select address 0x48 
//or low to select address 0x10

CM32181 cm(0x10);  //when  ADDR pin connect GND

void setup() {
  
  boolean error = false;
  uint16_t chip_id = 0; 
  //uint16_t chip_status = 0;
  
  Serial.begin(9600);
  
  error = cm.init_chip();
  if(error == false){
    Serial.println("Not found chip device or init error!");
    while(true)
    {}
  } 
  
  chip_id = cm.get_chip_ID();
  if(chip_id != 0x81){                         //chip ID must be 0x81
    Serial.println("unknown chip!");
    while(true)
    {}
  } 
  
  //chip_status = cm.get_chip_status();  
  //error = cm.powerdown_chip();
  //error = cm.powerup_chip();
     
}

void loop() {
  
  uint16_t get_data = cm.read_sensor_raw();       //This is sensor raw data, not lux value. you need trans.
  String desc = "LUX raw data:";
  desc += get_data;
  Serial.println(desc); 
  delay(5);
  
}
