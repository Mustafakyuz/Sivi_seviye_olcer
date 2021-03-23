  #define led 2
  void setup() {
  pinMode(led,OUTPUT);
    Serial.begin (9600);
  }
void loop() {
int isik = analogRead(A0);
Serial.println(isik);
delay(100);
if( isik>400){
  digitalWrite(led,HIGH);
  }
  if( isik<300){
  digitalWrite(led,LOW);
  }
}
