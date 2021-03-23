#define echo A0
#define triq 11
#define buzzer 10
float mesafe;
int sure;
int maximumrange= 100;
int minimumrange= 0;
void setup() {
  pinMode(triq,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600); 

}

void loop() {
   digitalWrite(triq,LOW);
   delayMicroseconds(20);
   digitalWrite(triq,HIGH);
   delayMicroseconds(200);
   digitalWrite(triq,LOW);
   sure=pulseIn(echo,HIGH); 
   mesafe= (sure/2) / 29,1;
   if(mesafe<4){
    digitalWrite(buzzer,HIGH);
   }
else{
  digitalWrite(buzzer,LOW);
}
   Serial.print("cisme olan uzaklik=");
   Serial.println(mesafe);
   Serial.println("--------------");
   delay(500);
   
   

}
