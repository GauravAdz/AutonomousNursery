#include <Wire.h> 
#include<SoftwareSerial.h> 
#include <dht.h>
SoftwareSerial bt(8,9);
 
  #define dht_apin0 A1 
 int stateco2 = 0;
 const int AOUTpin=2;
dht DHT;
int Buzzer1 =6;
int sensor_pin1 = A0; // Soil Sensor input at Analog PIN A0
 
 
float output_value ;
float temperature;
float humidity;
float humid;
 int limit;
int value; 
 
void setup(){
 
  Serial.begin(9600);
   pinMode(2, OUTPUT);//humidity
  pinMode(3, OUTPUT);// Motor
    pinMode(4, OUTPUT);// fan 
    pinMode(5, OUTPUT);//Bulb
  pinMode(sensor_pin1, INPUT);
  pinMode(Buzzer1,OUTPUT);
bt.begin(9600);
 
  Serial.println("Reading From the Sensor ...");
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensorlcd.begin(16,2);
 
 
}//end "setup()"
 
void loop(){
 
  //Start of Program 
  output_value= analogRead(sensor_pin1);
 Serial.print("Soil Mositure : ");
 Serial.println(output_value);
 
 
    DHT.read11(dht_apin0);
 
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.println("%  ");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println(" C  ");
 
 
    bt.print("Current humidity = ");
    bt.print(DHT.humidity);
    bt.println("%  ");
    bt.print("Temperature = ");
    bt.print(DHT.temperature); 
    bt.println(" C  ");
    temperature = DHT.temperature;
   humidity = DHT.humidity;
 
 humid = ((1024 -output_value)*100)/1024;
      if(humidity < 45.00){
  digitalWrite(5, LOW);
 }
 else
 {
   digitalWrite(5, HIGH);       
 }
 
if(temperature > 24.00){
  digitalWrite(3, LOW);
 
 }
 else
 {
   digitalWrite(3, HIGH);
 
 }
 
if(temperature < 34.00){
  digitalWrite(2, LOW);
 
 }
 else
 {
   digitalWrite(2, HIGH);
 
 }
 
 
 
if(output_value < 900.00){
  digitalWrite(4, HIGH);
 
 }
 else
 {
   digitalWrite(4, LOW);
 
 }
  value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
limit= 300;
Serial.print(value);
if (value>limit && stateco2 == 0){
digitalWrite(Buzzer1, HIGH);
 //if limit has been reached, LED turns on as status indicator
}
else{
digitalWrite(Buzzer1, LOW);
//if threshold not reached, LED remains off
stateco2 =0;
 
}
 
 
  //Fastest should be once every two seconds.
 
}// end loop()
