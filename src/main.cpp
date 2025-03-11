/* including the required Libraries*/
#include <Arduino.h> // incldues the core Ardunio functions 
#include <Wire.h> // includes the I2C library to ensure the ESP 32 can communicate with MPU6050
#include <Adafruit_MPU6050.h> // includes the Adafruit library we downloaded  to handle direct communication with MPU6050 sensor
#include <Adafruit_Sensor.h> // needed to doemat sensor readings into a standard structure.

/*Creating the MPU6050 Object from the Adafruit class */

Adafruit_MPU6050 mpu;

/* The Set-Up function/method */
// The setup function runs only once the ESP 32 is powered up
void setup() {
  // setups communication with computer screen/monitor. That value is the baud rate and it is a standardized value.
Serial.begin(115200); 
  Wire.begin(); // Method from the Arduino Wire library ; It initializes  I2C communication
  mpu.begin() ; // initializes MPU sensor communication (returns boolean)

  // if statement to check if the sensor's communication is properly initialized. 
  /* if it is not properly initialized, we print it didn't work and exit the setup method */
  if(mpu.begin() == false){ 
    Serial.println("Connection Failed! Bad Wiring");
    return; //Exits the setup method but loop still runs 
  }
  /* If it w initalized; we print to show it was */
  else{
    Serial.println(" The Sensor is Connected") ;
  }
}

void loop() {

/* Creating variables to store the sensor data. The reason it is inside the loop is because everytime the loop runs, we want fresh
data*/

// if statement because i was getting data even when the sensor was disconnected.
if(mpu.begin() == false){ 
  Serial.println("Connection Failed! Bad Wiring");
  return; //Exits the setup method but loop still runs 
}

sensors_event_t accelData;
sensors_event_t gyroData;
sensors_event_t tempData;

// Using the getEvent() method to read the latest sensor data and store it in a structured format

mpu.getEvent(&accelData, &gyroData, &tempData);

//Printing th sensor Data. 

// Data of  Acceleration in x direction
Serial.print("Acceleration X: ");
Serial.print(accelData.acceleration.x);
Serial.println(" ms^2, ");

// Data of  Acceleration in y direction
Serial.print("Acceleration Y: ");
Serial.print(accelData.acceleration.y);
Serial.println(" ms^2, ");

// Data of  Acceleration in z direction
Serial.print("Acceleration Z: ");
Serial.print(accelData.acceleration.z);
Serial.println(" ms^2, ");

// Data of  Gyroscope in x direction
Serial.print("Gyroscope X: ");
Serial.print(gyroData.gyro.x);
Serial.println(" rad/s, ");

// Data of  Gyroscope in y direction
Serial.print("Gyroscope Y: ");
Serial.print(gyroData.gyro.y);
Serial.println(" rad/s, ");

// Data of  Gyroscope in z direction
Serial.print("Gyroscope Z: ");
Serial.print(gyroData.gyro.z);
Serial.println(" rad/s, ");

// Temperature  of chip
Serial.print("Temperature  of Chip: ");
Serial.print(tempData.temperature);
Serial.println(" degrees Celsius , ");
delay(1000);
}

 