#define led_g 9
#define led_r 10
#define led_b 11
 
#define pot_g A0
#define pot_r A1
#define pot_b A2
 void setup() {
  pinMode(led_g,OUTPUT);
  pinMode(led_r,OUTPUT);
  pinMode(led_b,OUTPUT);
    
}

void loop() {
   int red_value=analogRead(pot_r);
   int green_value=analogRead(pot_g);
   int blue_value=analogRead(pot_b);
   
   red_value=map(red_value, 0,1023, 0,255);
   green_value=map(green_value, 0,1023, 0,255);
   blue_value=map(blue_value, 0,1023, 0,255);
   
   analogWrite(led_r,red_value);
   analogWrite(led_g,green_value);
   analogWrite(led_b,blue_value);
   
}
