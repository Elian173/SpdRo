#include<LiquidCrystal.h>

#define NO_BUTTON 0
#define LEFT_BUTTON 1
#define RIGHT_BUTTON 2

LiquidCrystal lcd(2,3,4,5,6,7);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

int posicionCursor = 0;
int maxDerecha = 15;
int maxIzquierda = 0;

int estadoBoton=0;
int estadoAnterior=0;

int botonApretado;

void loop()
{
  
  estadoBoton = analogRead(A0);

  botonApretado = readButton();
 
  if(botonApretado == RIGHT_BUTTON)
  {
    crearCero();
  }
  if(botonApretado == LEFT_BUTTON)
  {
    borrarCero();
  }
  if(botonApretado == NO_BUTTON)
  {
    Serial.println('n');
  }

  estadoBoton = estadoAnterior;

  delay(50);
}


int readButton(){
  int value = analogRead(A0);
  //Serial.println(value);
  if (value>=0 && value<=170) return RIGHT_BUTTON;
  if (value>170 && value<=682) return LEFT_BUTTON;
  if (value>682 && value<=1023) return NO_BUTTON;
}

void borrarCero()
{
  if (posicionCursor>0)
  {
  posicionCursor--;
  }
  lcd.print(' ');
  lcd.setCursor(posicionCursor,0);
}

void crearCero()
{
  lcd.print(0);
  if(posicionCursor<16)
  {
  posicionCursor ++;
  }
}

