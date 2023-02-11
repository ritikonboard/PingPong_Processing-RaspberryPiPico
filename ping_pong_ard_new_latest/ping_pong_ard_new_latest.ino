#include "hal.h"
#include "font.h"

int Score1,Score2;

int color1 = 1;
int color2;
String Name1,Name2;
int temp;
///////////////////////////////////////////////////////////////////////////////////////////////
void displayNum(int s1,int s2){
  int fontArrayRowNumber=s1;
  
  for(int pinNoIndex =0; pinNoIndex < NUM_LED_SEGMENTS; pinNoIndex++){
        digitalWrite( LEDfirst[pinNoIndex], fontSymbolBits[fontArrayRowNumber][pinNoIndex]);}
    
  fontArrayRowNumber=s2;
  
  for(int pinNoIndex =0; pinNoIndex < NUM_LED_SEGMENTS; pinNoIndex++){
       digitalWrite( LEDsecond[pinNoIndex], fontSymbolBits[fontArrayRowNumber][pinNoIndex]);}
}
///////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  for (int i = 0; i < NUM_LED_SEGMENTS; i++) { pinMode(LEDfirst[i],  OUTPUT); }
  for (int i = 0; i < NUM_LED_SEGMENTS; i++) { pinMode(LEDsecond[i], OUTPUT); } 
 // pinMode(switch1,INPUT_PULLUP);
  //pinMode(switch2,INPUT_PULLUP);
  
  Serial.begin(9600);
  while (!Serial) {
        ;}
  
  while(Serial.available() <= 0){
        ;} 
  temp = Serial.read();
  
  Serial.print("PLAYER 1 NAME :  ");
  while(Serial.available() <= 0){
        ;} 
  Name1 = Serial.readString();
  
  Serial.print("PLAYER 2 NAME :  ");
  while(Serial.available() <= 0){
        ;} 
  Name2 = Serial.readString();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {  
  int p1=analogRead(player1);
  int p2=analogRead(player2);
  int switch1read = digitalRead(switch1);
  int switch2read = digitalRead(switch2);
  
  Serial.print(Name1); Serial.print(","); Serial.print(Name2); Serial.print(",");
  Serial.print(p1); Serial.print(","); Serial.print(p2); Serial.print(",");

  if(Serial.available()>0){
    Score1 = Serial.read();
    Score2 = Serial.read();
    }
    
  Serial.print(switch1read); Serial.print(","); Serial.print(switch2read); Serial.print("\n");
  
  displayNum(Score1,Score2);
  delay(10);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
