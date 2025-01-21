//used A0,GND,5V

int sensorValue;

void setup(){

    Serial.begin(9600); // sets the serial port to 9600
}

void loop(){
    
    sensorValue = analogRead(0);
    Serial.println(sensorValue, DEC);
    delay(100);
}
