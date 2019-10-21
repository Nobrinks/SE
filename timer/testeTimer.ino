int ligado=1;
void setup() {
  // put your setup code here, to run once:
  //TCCR0A = 0;
  TCCR1B = 0;
  TCNT1 = 0;//zera o contador
  TCCR1A |= (1 << WGM12); //aciona o CTC(clear timer on compare) 
  OCR1A = 16524;//16*10^16/(1*64) -1

  TCCR1B |= (1 << CS12) | (1 << CS10); //aciona o prescaler de 64
  TIMSK1 |= (1<<OCIE1A);
  Serial.begin(9600);
}
ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  if (ligado){
    digitalWrite(13,HIGH);
    Serial.println("high");
    ligado = 0;
  }
  else{
    digitalWrite(13,LOW);
    Serial.println("low");
    ligado = 1;
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}

//https://www.instructables.com/id/Arduino-Timer-Interrupts/
