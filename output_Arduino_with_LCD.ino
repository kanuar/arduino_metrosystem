#include <LiquidCrystal.h>

#include<Wire.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int counter=0;
void setup() {
  lcd.begin(16,2);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin(8);             
  Wire.onReceive(receiveEvent); 
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("Current Count : ");
}

void loop() {
  delay(10);
}
void receiveEvent(int howMany) 
{
  while (1 < Wire.available()) 
  { 
    char c = Wire.read();    
  }
  int x=Wire.read(); 
  if (x==102)
  {
    counter+=1;
    
    lcd.setCursor(0,1);
    lcd.print(counter);
    delay(5000);
  }
  if (x==101)
  {
    counter-=1;
    lcd.setCursor(0,1);
    lcd.print(counter);
    delay(5000);
  }
  if (counter<0)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Current Count : ");
    
  }
}
