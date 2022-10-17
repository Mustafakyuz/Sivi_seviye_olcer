#define led 9
#define buzzer 8
int lm35Pin = A0;

 float sicalik_gerilim = 0;
 int okunan_deger = 0;
 float sicalik = 0;
void setup() {

pinMode(led,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);
}

void loop() {
 
 okunan_deger = analogRead(lm35Pin);
 sicalik_gerilim = (5000.0 / 1023.0) * okunan_deger;
 sicalik = sicalik_gerilim / 10.0 ;
 Serial.println(sicalik);
 if(sicalik >= 28){
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(75);
  digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
  delay(75);  
 }
else{
   digitalWrite(led,LOW);
  digitalWrite(buzzer,LOW);
}

}
