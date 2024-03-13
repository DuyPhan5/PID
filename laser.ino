#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup()
{
  pinMode(12,INPUT_PULLUP);
  digitalWrite(12,HIGH);
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop()
{
  int distance =sensor.readRangeContinuousMillimeters();

  Serial.print(distance);

  Serial.println();
  delay(100);
} 