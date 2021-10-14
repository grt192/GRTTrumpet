#include <Servo.h>


 // pushbutton pin
 const int testPin = 7;
 
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
  pinMode(testPin, OUTPUT);
  
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);

}
void loop() //takes 200 micro seconds 
{
 digitalWrite(testPin, HIGH);
 counter1 = counter1 + 1;
 counter2 = counter2 + 1;
 counter3 = counter3 + 1;
 
 // local variable to hold the pushbutton states
  int button1State;
  int button2State;
  int button3State;


  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);

    
  Serial.print("test");
 
  
  if (button1State == LOW) {
    servo1.write(180); //zero degrees apparently(fact check pls)
    if (counter1 == 1600){
      servo1.write(0);
    }
  }
  
  else if(button1State == HIGH){
    servo1.write(20);
    counter1 = 0;
  }
  
  if(button2State == LOW) {
    servo2.write(20);
    if(counter2 == 1600){
      servo2.write(0);
    }
  }
  
  else if(button2State == HIGH){
    servo2.write(180);
    counter2 = 0;
  }
  
  if(button3State == LOW) {
    servo3.write(180);
    if(counter3 == 1600){
      servo3.write(0);
    }
  }
  
  else if(button3State == HIGH){
    servo3.write(20);
    counter3 = 0;
  }
  
  else{
    servo1.write(0); //assuming 0 is rest
    
  }

  

  digitalWrite(testPin, LOW);

}
