#define BUT_DC 11
#define BUT_AC 10
#define LED_OUT 7
int led=0, fim, inicio=0, intervalo=1000,butPressac=0, butPressdc, tempiEst=0, tempfEst, but_ac, but_dc;
void setup() {
  // put your setup code here, to run once:
  pinMode(BUT_AC, INPUT);
  pinMode(BUT_DC, INPUT);
  pinMode(LED_OUT, OUTPUT);
  Serial.begin(9600);
}

void frequencia(int f){
  int local;
  if((f==1)&&(intervalo>=250)){
    Serial.println("Decrementa");
    local=(intervalo-250);
    intervalo=local;
  }
  else if((f==0)&&(intervalo<=3000)){
    Serial.println("Incrementa");
    local=(intervalo+250);
    intervalo=local;
  }
}
//estado 1
void estado1(){
  Serial.println("ESTADO 1");
  fim=millis();
  if((fim-inicio)>intervalo){
    digitalWrite(LED_OUT, led);
    led = !led;
    inicio=millis();
    estado2();
  }
  else{
    but_ac=digitalRead(BUT_AC);
    but_dc=digitalRead(BUT_DC);
    Serial.print("but ac 1: "); Serial.print(but_ac);Serial.print(" but dc 1: "); Serial.print(but_dc); Serial.print(" est 1 inter: "); Serial.println(intervalo);
    if(but_ac==0){
      Serial.print("press ac1: ");Serial.println(butPressac);
      if(butPressac==0){
        butPressac= !butPressac;
        //digitalWrite(LED_OUT, HIGH);
        //frequencia(1);
        estado3();
      }
    }
    else if(but_dc==0){
      Serial.print("press dc1: "); Serial.println(butPressdc);
      if(butPressdc==0){
        butPressdc= !butPressdc;
        //digitalWrite(LED_OUT, LOW);
        //frequencia(0);
        estado3();
      }
    }
  }
}

void estado2(){
  Serial.println("ESTADO 2");
  fim=millis();
  if((fim-inicio)>intervalo){
    digitalWrite(LED_OUT, led);
    led = !led;
    inicio=millis();
    estado1();
  }
  else{
    but_ac=digitalRead(BUT_AC);
    but_dc=digitalRead(BUT_DC);
    Serial.print("but ac 2: "); Serial.print(but_ac);Serial.print(" but dc 2: "); Serial.print(but_dc); Serial.print(" est 2 inter: "); Serial.println(intervalo);
    if(but_ac==0){
      Serial.print("press ac2: ");Serial.println(butPressac);
      if(butPressac==0){
        butPressac= !butPressac;
        //digitalWrite(LED_OUT, HIGH);
        //frequencia(1);
        estado4();
      }
    }
    else if(but_dc==0){
      Serial.print("press dc2: "); Serial.println(butPressdc);
      if(butPressdc==0){
        butPressdc= !butPressdc;
        //digitalWrite(LED_OUT, LOW);
        //frequencia(0);
        estado4();
      }
    }
  }
}
void estado3(){
  Serial.println("ESTADO 3");
  fim=millis();
  tempfEst=millis();
  if((fim-inicio)>intervalo){
    digitalWrite(LED_OUT, led);
    led = !led;
    inicio=millis();
    estado4();
  }
  else if((tempfEst-tempiEst)>=500){
    tempiEst=millis();
    estado1(); 
  }
  else{
    but_ac=digitalRead(BUT_AC);
    but_dc=digitalRead(BUT_DC);
    Serial.print("but ac 3: "); Serial.print(but_ac);Serial.print(" but dc 3: "); Serial.print(but_dc); Serial.print(" est 3 inter: "); Serial.println(intervalo);
    if((but_ac==0)&&(but_dc==0)){
      Serial.println("Parar");
      estado5();
    }
    else if(but_ac==1){
      Serial.print("press ac3: ");Serial.println(butPressac);
      butPressac= !butPressac;
      frequencia(1);
      estado1();
      
    }
    else if(but_dc==1){
      Serial.print("press dc3: "); Serial.println(butPressdc);
      butPressdc = !butPressdc;
      frequencia(0);
      estado1();
    }
  }
}
void estado4(){
  Serial.println("ESTADO 4");
  fim=millis();
  tempfEst=millis();
  if((fim-inicio)>intervalo){
    digitalWrite(LED_OUT, led);
    led = !led;
    inicio=millis();
    estado3();
  }
  else if((tempfEst-tempiEst)>=500){
    tempiEst=millis();
    estado2(); 
  }
  else{
    but_ac=digitalRead(BUT_AC);
    but_dc=digitalRead(BUT_DC);
    Serial.print("but ac 4: "); Serial.print(but_ac);Serial.print(" but dc 4: "); Serial.print(but_dc); Serial.print(" est 4 inter: "); Serial.println(intervalo);
    if((but_ac==0)&&(but_dc==0)){
      Serial.println("Parar");
      estado5();
    }
    else if(but_ac==1){
      Serial.print("press ac4: ");Serial.println(butPressac);
      butPressac= !butPressac;
      frequencia(1);
      estado2();
      
    }
    else if(but_dc==1){
      Serial.print("press dc4: "); Serial.println(butPressdc);
      butPressdc = !butPressdc;
      frequencia(0);
      estado2();
    }
  }
}
void estado5(){
  while(1);
}
void loop() {
  // put your main code here, to run repeatedly:
  estado1();

}
