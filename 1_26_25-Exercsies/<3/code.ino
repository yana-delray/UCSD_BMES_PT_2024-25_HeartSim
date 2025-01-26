
int sensorPin = A1; //define pin A1 (analog pin)
int ledPin2 = 2; //define pin 2 (digital pin)
int ledPin4 = 4; // define pin 4 (digital pin)
int buttonPin = 3; // define pin 3 (digital pin)
int sensorValue; //create variable for storing readings
int val = 0;
int lastval = 0;

//void setup is for configurations on start up
void setup() { 
    Serial.begin(9600); //initialize serial communication
    pinMode(ledPin2, OUTPUT); //define ledPin2 as an output
    pinMode(ledPin4, OUTPUT); // define ledPin4 as output
    pinMode(buttonPin, INPUT); // define buttonPin as input
}

void button() {
  if (val == 1 && lastval == 0) { // if button is pressed
      digitalWrite(ledPin2, HIGH); // turn on LEDpin2
      digitalWrite(ledPin4, LOW); // turn off LEDpin4
    }
  else { // if button is not pressed
      digitalWrite(ledPin2, LOW); // turn off LEDpin2
      digitalWrite(ledPin4, HIGH); // turn on LEDpin4
  }

void loop() {
    sensorValue = analogRead(sensorPin); // do a sensor reading
    Serial.print("Sensor value is: "); //print a message to the serial monitor
    Serial.println(sensorValue); //print the value to the serial monitor
    
    //check if sensorValue is below 50
    if(sensorValue < 50) { 
        digitalWrite(ledPin, HIGH); //if it is, turn on the LED on pin 2.
    }
    //if sensorValue is above 50, turn off the LED
    else{ 
        digitalWrite(ledPin, LOW);
    }

    val = digitalRead(buttonPin); //reads button state and stores it in val
    button();
    lastval = val; // store the current value
}
