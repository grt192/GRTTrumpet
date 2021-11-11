#include <Servo.h>

// a Valve has a button pin, a servo pin, a servo, a counter, a buttonstate
  Servo s1;
  Servo s2;
  Servo s3;
  
class Valve {
  public:
    int _buttonpin;
    int _servopin;
    Servo _servo;
    int _counter;
    int _buttonstate;
 
    Valve(int buttonpin, int servopin, Servo servo, int counter){
      _buttonpin = buttonpin;
      _servopin = servopin;
      _counter = counter;
      _servo = servo;
      _buttonstate = HIGH;     
    }
};

    Valve* valves[3];
    // star either means pointer or "give me the thing at the address"

    void setup() {
      Serial.begin(9600);
  // put your setup code here, to run once:
      valves[0] = new Valve(8, 3, s1, 0);
      valves[1] = new Valve(9, 4, s2, 0);
      valves[2] = new Valve(11, 5, s3, 0);
      
      //valves[3] = {v1, v2, v3};
      for (int i = 0; i < 3; i++){
        //valves[i]._servo.attach (valves[i]._servopin);
        //*(valves[i]).servo
        valves[i]->_servo.attach(valves[i]->_servopin);
        pinMode(valves[i]->_buttonpin, INPUT);
        digitalRead(valves[i]->_buttonpin);
      }
    }
    void loop() {
      // put your main code here, to run repeatedly:
      for (int i = 0; i < 3; i++){
        valves[i]->_buttonstate = digitalRead(valves[i]->_buttonpin);
      
      }
          
      if (valves[0]->_buttonstate == HIGH) {
        valves[0]->_servo.write(180); //zero degrees apparently(fact check pls)
      }
      else{
        valves[0]->_servo.write(20);
        Serial.print("s1\n");

      }
    
      if(valves[1]->_buttonstate == HIGH) {
        valves[1]->_servo.write(20);
      }
      else{
        valves[1]->_servo.write(180);
            Serial.print("s2\n");
      }
    
      if(valves[2]->_buttonstate == HIGH) {
        valves[2]->_servo.write(180);
      }
      else {
        valves[2]->_servo.write(20);
            Serial.print("s3\n");
      }
      //else{
      //  valves[0]->_servo.write(20);
      //}
   }
