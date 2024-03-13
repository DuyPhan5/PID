#include <TimerOne.h>
double T,xung;
double tocdo, Tocdodat;
double E, E1, E2;
double alpha, gamma, beta, Kp, Kd, Ki;
double Output, LastOutput;
void setup() {  
  pinMode(2, INPUT_PULLUP);//chân ngắt  
  pinMode(4, INPUT_PULLUP);//chân đọc encoder  
  pinMode(5, OUTPUT);//chân PWM  
  pinMode(7, OUTPUT);//chân DIR1  
  pinMode(8, OUTPUT);//chân DIR2  
  Tocdodat = 200; tocdo=0;  
  E = 0 ; E1 = 0; E2 = 0;  
  Output=0; LastOutput=0;  
  T=0.01;  
  Kp=1; Kd= 0 ; Ki=0.01;  
  Serial.begin(9600);  
   attachInterrupt(0,Demxung,FALLING);  
   Timer1.initialize(10000);  
   Timer1.attachInterrupt(pid);
   }
   void loop() {  
    int i;  
    for( i= 0;i<10; i++);  
    delay(1);  
    Serial.println(tocdo);
    }
    void Demxung() { 
       if(digitalRead(4) == LOW)  
       xung++; 
        else  
        xung--;
        }
        void pid() {  
          tocdo = (xung/1800)*(1/T)*60;  
          xung=0;  
          E = Tocdodat - tocdo;  
          alpha = 2*T*Kp + Ki*T*T + 2*Kd;  
          beta = T*T*Ki -4*Kd -2*T*Kp;  
          gamma = 2*Kd;  
          Output = (alpha*E + beta*E1 + gamma*E2 +2*T*LastOutput)/(2*T);  
          LastOutput = Output;  
          E2=E1;  
          E1=E;  
          if(Output > 255)  Output=255; 
          if(Output < 0)  Output=0;  
          if(Output>0){   
             analogWrite(5, Output);    
             digitalWrite(7, HIGH);    
             digitalWrite(8, LOW);  }  
             else{   analogWrite(5, 0);    
             digitalWrite(7, LOW);   
             digitalWrite(8, LOW);  
             } 
        }
        

  
