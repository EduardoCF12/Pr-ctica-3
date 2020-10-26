void setup() {
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

double pot1 = 0;
int Il=0;
double rl;
double luz;

void loop() {
  delay(1000);
  pot1=analogRead(A0);
  luz=pot1*5/1023;
   rl=680*((5/luz)-1);

   Il=pow(rl/126951,-1.1655);

   if(Il<3000)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }

  Serial.print("La Intensidad luminosa es: ");
  Serial.print(Il);
  Serial.println(" lux");
  Serial.print("Valor Voltaje Analogico: ");
  Serial.print(luz);
  Serial.println(" V");
  Serial.print("Valor Resistencia: ");
  Serial.print(rl);
  Serial.println(" Ohms");
  Serial.println();
  
}
