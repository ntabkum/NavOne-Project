// Created by Nava Tabkum  4/21/2018
// NavOne-VSM Control using GPIO relay
// V.2
//
// #define APP_DEBUG
#include <WiFiManager.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial


char auth[] = "your auth code here"; //
WidgetLED led1(V1); 
WidgetLED led2(V2); 
WidgetLED led3(V3); 
WidgetLED led4(V4); 
WidgetLED led5(V5); 
WidgetLED led6(V6);
WidgetLED led7(V7); 
WidgetLED led8(V8);

int A = 0;
BlynkTimer T0;


void setup()
{
  Serial.begin(115200);
  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT); //led
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(16, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(0, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  // digitalWrite(15, HIGH); 
  digitalWrite(2, HIGH); //led

//WiFiManager
 
  WiFiManager wifiManager;
  
  wifiManager.autoConnect("NavOne-VSM");
  Serial.print(F("WiFi connected! IP address: "));
  Serial.println(WiFi.localIP());
  //
  // Start Blynk
  //
  Blynk.config(auth,IPAddress(ip,your,blynk,server), port);
  
  Blynk.syncVirtual(V1, V2, V3, V4, V5, V6, V7, V8, V11, V12, V13, V14, V15, V16, V17, V18);
  
  T0.setInterval(1000L, LED16);

}
void LED16() { 
  digitalWrite(2, !digitalRead(2));  
}

void SUB1() {
                  led1.off();
                  Blynk.virtualWrite(V11, 0);
                  digitalWrite(16, HIGH);
   
}
void SUB2() {
                  led2.off();
                  Blynk.virtualWrite(V12, 0);
                  digitalWrite(5, HIGH);
  
}
void SUB3() {
                  led3.off();
                  Blynk.virtualWrite(V13, 0);
                  digitalWrite(4, HIGH);
  
}
void SUB4() {
                  led4.off(); 
                  Blynk.virtualWrite(V14, 0);
                  digitalWrite(0, HIGH);
  
}
void SUB5() {
                  led5.off();
                  Blynk.virtualWrite(V15, 0);
                  digitalWrite(14, HIGH);
  
}
void SUB6() {
                  led6.off();
                  Blynk.virtualWrite(V16, 0);
                  digitalWrite(12, HIGH);
  
}
void SUB7() {
                  led7.off();
                  Blynk.virtualWrite(V17, 0);
                  digitalWrite(13, HIGH);
  
}
void SUB8() {
                  led8.off();
                  Blynk.virtualWrite(V18, 0);
                  digitalWrite(15, HIGH);
  
}
void SUB01() {
                 SUB2();SUB3();SUB4();SUB5();SUB6();SUB7();SUB8();
                 
}
void SUB02() {
                 SUB1();SUB3();SUB4();SUB5();SUB6();SUB7();SUB8();
                 
}
void SUB03() {
                 SUB2();SUB1();SUB4();SUB5();SUB6();SUB7();SUB8();
                 
}
void SUB04() {
                 SUB2();SUB3();SUB1();SUB5();SUB6();SUB7();SUB8();
                 
}
void SUB05() {
                 SUB2();SUB3();SUB4();SUB1();SUB6();SUB7();SUB8();
                 
}
void SUB06() {
                 SUB2();SUB3();SUB4();SUB5();SUB1();SUB7();SUB8();
                 
}
void SUB07() {
                 SUB2();SUB3();SUB4();SUB5();SUB6();SUB1();SUB8();
                 
}
void SUB08() {
                 SUB2();SUB3();SUB4();SUB5();SUB6();SUB7();SUB1();
                 
}
void NAVONE(int I)
{
  Serial.println("I = ");
  Serial.print(I);
  Serial.println("A = ");
  Serial.print(A);
  switch (I) {
    case 1:  //16
        
        switch (A) {
          case 0:
             SUB01();break;
          case 1: break;
          case 2:
            SUB2();break;
          case 3:
            SUB3();break;
          case 4:
            SUB4();break;
          case 5:
            SUB5();break;
          case 6:
            SUB6();break;
          case 7:
            SUB7();break;
          case 8:
            SUB8();break;          
                   }
         A = 1;       
         break;
        
     case 2:  //5 
     
        switch (A) {
          case 0: SUB02();break;
          
          case 1:
            SUB1();break;
          case 2:break;
          case 3:
            SUB3();break;
          case 4:
            SUB4();break;
          case 5:
            SUB5();break;
          case 6:
            SUB6();break;
          case 7:
            SUB7();break;
          case 8:
            SUB8();break;                         
                    }
          A = 2; 
          break;
          
     case 3:  //4    
        
        
        switch (A) {
          case 0: SUB03();break;
          case 1:
            SUB1();break;
          case 2:
            SUB2();break;
          case 3:break;
          case 4:
            SUB4();break;
          case 5:
            SUB5();break;
          case 6:
            SUB6();break;
          case 7:
            SUB7();break;
          case 8:
            SUB8();break;                         
                    }   
        A = 3; 
        break;
         
     case 4:  //0
        
        switch (A) {
          case 0: SUB04();break;
          case 1:
            SUB1();break;
          case 2:
            SUB2();break;
          case 3:
            SUB3();break;
          case 4: break;  
          case 5:
            SUB5();break;
          case 6:
            SUB6();break;
          case 7:
            SUB7();break;
          case 8:
            SUB8();break;                         
                    }
        A = 4; 
        break;         
     case 5:   //14
        
        switch (A) {
          case 0: SUB05();break;
          case 1:
            SUB1();break;
          case 2:
            SUB2();break;
          case 3:
            SUB3();break;
          case 4:
            SUB4();break;
           case 5: break; 
          case 6:
            SUB6();break;
          case 7:
            SUB7();break;
          case 8:
            SUB8();break;                         
                    }
        A = 5; 
        break;
      case 6:   //12
        
        switch (A) {
          case 0: 
              
             SUB06();break;
          case 1:
            SUB1();break;
          case 2:
            SUB2();break;
          case 3:
            SUB3();break;
          case 4:
            SUB4();break;
          case 5:
            SUB5();break;
          case 6: break;  
          case 7:
            SUB7();break;
          case 8:
            SUB8();break;                         
                    } 
        A = 6; 
        break;
      case 7:   //13
        
        switch (A) {
          case 0: SUB07();break;
          case 1:
            SUB1();break;
          case 2:
            SUB2();break;
          case 3:
            SUB3();break;
          case 4:
            SUB4();break;
          case 5:
            SUB5();break;
          case 6:
            SUB6();break;
          case 7: break;  
          case 8:
            SUB8();break;                         
                    }
        A = 7; 
        break;  
      case 8:   //15
        
        
        switch (A) {
          case 0: SUB08();break;
          case 1:
            SUB1();break;
          case 2:
            SUB2();break;
          case 3:
            SUB3();break;
          case 4:
            SUB4();break;
          case 5:
            SUB5();break;
          case 6:
            SUB6();break;
          case 7:
            SUB7();break;
           case 8:break;
                                      
                    }
        A = 8; 
        break;
      default:
      break;        
  }     
}

BLYNK_WRITE(V11) {
   digitalWrite(16, LOW); Blynk.virtualWrite(V11, 1);led1.on();
   // delay(15);digitalWrite(5, HIGH);
   NAVONE(1);
}
BLYNK_WRITE(V12) {
  digitalWrite(5, LOW); Blynk.virtualWrite(V12, 1);led2.on();
  // delay(15);digitalWrite(4, HIGH);
  NAVONE(2);
}
BLYNK_WRITE(V13) {
  digitalWrite(4, LOW); Blynk.virtualWrite(V13, 1);led3.on();
  // delay(15);digitalWrite(0, HIGH);
  NAVONE(3);
}
BLYNK_WRITE(V14) {
  digitalWrite(0, LOW); Blynk.virtualWrite(V14, 1);led4.on();
  // delay(15);digitalWrite(16, HIGH);
  NAVONE(4);
}
BLYNK_WRITE(V15) {
  digitalWrite(14, LOW); Blynk.virtualWrite(V15, 1);led5.on();
  // delay(15);digitalWrite(14, HIGH);
  NAVONE(5);
}
BLYNK_WRITE(V16) {
  digitalWrite(12, LOW); Blynk.virtualWrite(V16, 1);led6.on();
  // delay(15);digitalWrite(12, HIGH);
  NAVONE(6);
}
BLYNK_WRITE(V17) {
  digitalWrite(13, LOW); Blynk.virtualWrite(V17, 1);led7.on();
  // delay(15);digitalWrite(13, HIGH);
  NAVONE(7);
}
BLYNK_WRITE(V18) {
  digitalWrite(15, LOW); Blynk.virtualWrite(V18, 1);led8.on();
  // delay(15);digitalWrite(15, HIGH);
  NAVONE(8);
}

void loop()
{
  Blynk.run();
  T0.run();
}

  
