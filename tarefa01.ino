#define LED_PIN 2
#define BUT_PIN 12
#define BUT2_PIN 8
byte status=0;
long int tInicial=0, tFinal, intervalo=1000, tempo, but_ac=0, but_dc=0;
boolean on_off=true;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN, INPUT);
  pinMode(BUT2_PIN, INPUT);
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

void pisca(){
  tempo=millis();
  if(on_off==true){
    if((tempo-tInicial)>=intervalo){
      digitalWrite(LED_PIN, HIGH); tInicial=tempo; on_off=false;
    }
  }
  else{
    if((tempo-tInicial)>=intervalo){
      tInicial=tempo; digitalWrite(LED_PIN, LOW); on_off=true;
     }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  pisca();
  if( (digitalRead(BUT2_PIN)==0) && (digitalRead(BUT_PIN)==0) ){
    status=3;
    frequencia();
    status=0;
    while(1);
  }
  if(but_ac){
    if(digitalRead(BUT_PIN)){
      but_ac=0;
    }
  }
  else if(digitalRead(BUT_PIN)==LOW){
    but_ac=1;
    status=1;
    frequencia(); 
  }
  
  if(but_dc){
    if(digitalRead(BUT2_PIN)){
      but_dc=0;
    }
  }
  else if(digitalRead(BUT2_PIN)==LOW){
    but_dc=1;
    status=2;
    frequencia(); 
  }
   
}
