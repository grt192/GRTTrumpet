#include <Servo.h>;
 
 // pushbutton pin
 const int button1Pin = 8;
 const int button2Pin = 9;
 const int button3Pin = 11;
 
 // servo pin
 const int servo1Pin = 3;
 const int servo2Pin = 4;
 const int servo3Pin = 5;

 Servo servo1;
 Servo servo2;
 Servo servo3;
 
//create a variable to store a counter and set it to 0
 int counter1 = 0;
 int counter2 = 0;
 int counter3 = 0;

void setup(){
  servo1.attach (servo1Pin);
  servo2.attach (servo2Pin);
  servo3.attach (servo3Pin);
 
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
}
void loop()
{
 // local variable to hold the pushbutton states
  int button1State;
  int button2State;
  int button3State;

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
 
  
  if (button1State == LOW) {
    servo1.write(180); //zero degrees apparently(fact check pls)
  }
  else if(button1State == HIGH){
    servo1.write(20);
  }
  
  if(button2State == LOW) {
    servo2.write(20);
  }
  else if(button2State == HIGH){
    servo2.write(180);
  }
  
  if(button3State == LOW) {
    servo3.write(180);
  }
  else if(button3State == HIGH){
    servo3.write(20);
  }
  else{
    servo1.write(20);
  }
 
 

}
