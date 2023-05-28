#include <Keypad.h>
#include <Servo.h>

Servo servo_Motor;
char* password = "1,2,3";
int position = 0;
const byte rows = 4; 
const byte cols = 4; 
char keys[rows][cols] = {
  {'1','2','3','A'},                 
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {8, 7, 6, 9}; 
byte colPins[cols] = {5, 4, 3, 2}; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);


void setup()                    
{
Serial.begin(9600);
  servo_Motor.attach(11);
  setLocked(true);
}

void loop()                    
{
  char key = keypad.getKey();
  if (key == '*'  || key =='#')
  {
    // unlocked and * pressed so change code
    position = 0;
    setLocked(true);
  }
  if (key == password[position])
  {
    position ++;
  }
  if (position == 3)
  {
   setLocked(false);
  }
  delay(100);
}
void setLocked (int locked){
if  (locked) {

servo_Motor.write(170);

}
else{
  servo_Motor.write(90);
}
 }
 