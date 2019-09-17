int i = 9;

void setup()
{
      pinMode(3,  INPUT);
      pinMode(9, OUTPUT);
      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);
      pinMode(12, OUTPUT);
      pinMode(13, OUTPUT);
    
    digitalWrite(i, HIGH);
}

int estadoBoton = 0;
int estadoAnterior = 0;

void loop()
{
  
  estadoBoton = digitalRead(3);
  
  if(estadoBoton == 1 && estadoAnterior == 0)
  {
  if(digitalRead(3)==HIGH)
    {
    
    i++;
    
    digitalWrite(i, HIGH);
    digitalWrite(i-1,LOW);
    
     if(i==14)
     {
       i=9;
       
       digitalWrite(13,LOW);
       digitalWrite(9,HIGH);
       
     }
    
  }
  }
  estadoAnterior = estadoBoton;
  delay (10);
}
