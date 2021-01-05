int etatBouton;
void setup(){
    Serial.begin(9600);

  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
      etatBouton = HIGH; // on initialise l'état du bouton comme "relaché"

}

void loop(){
  etatBouton=digitalRead(2);
  int b;
 
  b = 1;
  int x=0;
 
    if(etatBouton == HIGH) // test si le bouton a un niveau logique HAUT
  {
      digitalWrite(13,HIGH);
      x=1;
      Serial.println(x);
  }
  else {
      digitalWrite(13,LOW);
    
     x=0;
   }

   
}
