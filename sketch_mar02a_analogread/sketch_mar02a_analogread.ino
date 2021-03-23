#define buton A0
int x;
void setup() {

Serial.begin(9600);
pinMode(buton,INPUT);
}

void loop() {
x =  analogRead(buton);
Serial.println(x);
delay(1000);

}
