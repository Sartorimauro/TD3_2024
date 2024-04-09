#include <Arduino.h>

// put function declarations here:
//int myFunction(int, int);
unsigned long timestamp;
int btn_st;
void btn();


void setup() {
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  Serial.begin(115200);
  Serial.printIn("Testing serial...");


  pinMode(8,INPUT);
  pinMode(9,OUTPUT);
  btn_st=1;
}

void loop() {
  // put your main code here, to run repeatedly:
  btn();
}

// put function definitions here:
void btn()
{
    if(btn_st==0)
      return;
    if(btn_st==1)
    {
      if(digitalRead(8)==HIGH)
      {
          timestamp = millis();
          btn_st=2;
          return;
          
      }
      return;
    }
    if(btn_st==2)
    {
      if((millis()-timestamp)>20)
          {
            if(digitalRead(8)==HIGH)
              {
                digitalWrite(9,HIGH);
                return;
              }
            else{
              btn_st=1;
              return;
            }
          }
          return;
    }
}

/*int myFunction(int x, int y) {
  return x + y;
}*/
