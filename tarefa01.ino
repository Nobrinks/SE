#define LED_PIN 12
#define BUT_PIN 2
#define BUT2_PIN 4
byte status=0;
int intervalo=1000;
unsigned long tempo;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN, INPUT);
  pinMode(BUT2_PIN, INPUT);
  digitalWrite(BUT2_PIN,HIGH);
  digitalWrite(BUT_PIN,HIGH);
}
void pisca(){
  digitalWrite(LED_PIN, HIGH);
  delay(intervalo);
  digitalWrite(LED_PIN, LOW);
  delay(intervalo);
}
void frequencia(){
  if(status==1){
    intervalo+=250;
  }
  else if((status==2)&&(intervalo>200)){
    intervalo-=250;
  }
  else if(((status==3)&&((millis()-tempo)<500))){
    digitalWrite(LED_PIN, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  tempo=millis();
  pisca();
  if( (digitalRead(BUT2_PIN)==0) && (digitalRead(BUT_PIN)==0) ){
    status=3;
    frequencia();
    while(1);
  }
  if(digitalRead(BUT_PIN)==LOW){
    status=1;
    frequencia(); 
    while(digitalRead(BUT_PIN)==LOW){pisca();}
  }
  if(digitalRead(BUT2_PIN)==LOW){
    status=2;
    frequencia(); 
    while(digitalRead(BUT2_PIN)==LOW){pisca();}
  }
   
}
