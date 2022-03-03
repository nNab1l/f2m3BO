int LDR_In = A0;


int lichtHoeveelheid = 867;

uint8_t Led1 = D3;
uint8_t Led2 = D5;
uint8_t Led3 = D6;


void setup() {
  Serial.begin(9600);
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
}

void loop() {
  lichtHoeveelheid = analogRead(LDR_In);



  Serial.println(lichtHoeveelheid);

  if ( lichtHoeveelheid > 650.25) {
    digitalWrite(Led1, HIGH);
  }
  else{
    digitalWrite(Led1, LOW);
  }

   if ( lichtHoeveelheid > 433.5) {
    digitalWrite(Led2, HIGH);
  }
  else{
    digitalWrite(Led2, LOW);
  }

   if ( lichtHoeveelheid > 216.75) {
  digitalWrite(Led3, HIGH);
  }
  else{
    digitalWrite(Led3, LOW);
  }



delay(1000);
}
