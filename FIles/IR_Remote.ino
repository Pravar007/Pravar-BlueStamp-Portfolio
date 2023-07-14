#include <IRremoteTank.h>

#define ML_Ctrl 13
#define ML_PWM 11
#define MR_Ctrl 12 
#define MR_PWM 3

int RECV_PIN = A0;       
IRrecv irrecv(RECV_PIN);   
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Initialize the IR receiver 

  pinMode(ML_Ctrl,OUTPUT);
  pinMode(ML_PWM,OUTPUT);
  pinMode(MR_Ctrl,OUTPUT);
  pinMode(MR_PWM,OUTPUT);

}
void loop() {
  if (irrecv.decode(&results)) {
    if(results.value==0xFF629D) //FRONT
    {
        digitalWrite(ML_Ctrl,LOW);
        analogWrite(ML_PWM,200);
        digitalWrite(MR_Ctrl,LOW);
        analogWrite(MR_PWM,200);
    }
    else if(results.value==0xFFA857) //BACK
    {
      digitalWrite(ML_Ctrl,HIGH);
      analogWrite(ML_PWM,200);
      digitalWrite(MR_Ctrl,HIGH);
      analogWrite(MR_PWM,200);
    }

    else if(results.value==0xFF22DD) //LEFT
    {
      digitalWrite(ML_Ctrl,LOW);
      analogWrite(ML_PWM,200);
      digitalWrite(MR_Ctrl,HIGH);
      analogWrite(MR_PWM,200);
    }

    else if(results.value==0xFFC23D) //RIGHT
    {
      digitalWrite(ML_Ctrl,HIGH);
      analogWrite(ML_PWM,200);
      digitalWrite(MR_Ctrl,LOW);
      analogWrite(MR_PWM,200);
    }

    else if(results.value==0xFF02FD) //STOP
    {
      analogWrite(ML_PWM,0);
      analogWrite(MR_PWM,0);
    }
        irrecv.resume(); //receive the next value
      }
}