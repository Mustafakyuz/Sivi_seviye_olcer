#include <Wire.h>
#define buton A0
int x = 0;
 
void setup() {
Serial.begin(9600);
pinMode(buton, INPUT);

}

void loop() {
x = analogRead(buton);
Serial.println(x);
delay(500); 
}
