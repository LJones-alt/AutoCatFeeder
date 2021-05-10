#include <LiquidCrystal.h> //LCD Display

#include <Servo.h> //servo library


Servo servo; //create servo object

int angle = 90;  //create angle
int feed_time = 0; //21600000; //6 hours
const int buttonPin = 12; //where button is
int buttonState = 0;
const int confirmButtonPin = 13; //confirm selection
int confirm = 0; //not confirmed yet

//LCD pins
const int rs = 10, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //create LCD Screen object


void setup() {
  Serial.begin(9600); //int serial 
  servo.attach(9); //attach servo to pin 9
  servo.write(angle); //turn 90 degrees
  lcd.begin(16,2);
  //lcd.clear(); //clear LCD readout
  //Serial.begin(9600); //int serial 
  pinMode(buttonPin, INPUT);
  setTime();
  
}

void loop() {
  //servoTurn();
  Serial.println(feed_time);
  
}

void setTime(){
  while (confirm == 0) {
     buttonState = digitalRead(buttonPin);
     confirm = digitalRead(confirmButtonPin);
    if (buttonState == HIGH) {
      Serial.println("Button pressed, increment time");
      feed_time = feed_time +1; //add 1 hour to time delay
      Serial.println("Food delay: ");Serial.print(feed_time);
      lcd.write(Serial.read());
      delay(500);
      
    } else {
      //Serial.println("Button not pressed");
    }

  }
}

void servoTurn(){
    for (angle = 0; angle <= 180; angle += 1) { 
    // in steps of 1 degree
   servo.write(angle);
   pinMode(12, INPUT);             
    delay(10);                       
  }
  delay(1000);
  for (angle = 180; angle >= 0; angle -= 1) { 
    servo.write(angle);              
    delay(10);
  }
}
