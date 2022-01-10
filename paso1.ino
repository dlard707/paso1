/*
  
  Programa que controla el giro del motor 28BYJ-48 en conjunto con el controlador
  basado en ULN2003 usando botones. La secuencia es la de
  paso completo simple (wave drive) energizando de a una bobina por vez. Alimentar Arduino
  con fuente de alimentacion externa de 6 a 12 Vdc.

  Autor: David larronda

*/

int IN1 = 8;  // pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 9;  // pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 10; // pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 11; // pin digital 11 de Arduino a IN4 de modulo controlador
int IN1b = 4; // pin digital 4 de Arduino a IN1 de modulo controlador
int IN2b = 5; // pin digital 5 de Arduino a IN2 de modulo controlador
int IN3b = 6; // pin digital 6 de Arduino a IN3 de modulo controlador
int IN4b = 7; // pin digital 7 de Arduino a IN4 de modulo controlador

int demora = 20;       // demora entre pasos, no debe ser menor a 10 ms.
const int boton1 = 2;  // pin digital 2 de Arduino a boton1
const int boton2 = 3;  // pin digital 3 de Arduino a boton2
const int boton3 = 14; // pin digital 14  (Analog 0) de Arduino a boton3
const int boton4 = 15; // pin digital 15  (Analog 1) de Arduino a boton4

void setup()
{
  pinMode(IN1, OUTPUT); // todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN1b, OUTPUT); // todos los pines como salida
  pinMode(IN2b, OUTPUT);
  pinMode(IN3b, OUTPUT);
  pinMode(IN4b, OUTPUT);
  pinMode(14, INPUT); // pin digital 14 de Arduino a entrada digital del boton3
  pinMode(15, INPUT); // pin digital 15 de Arduino a entrada digital del boton4
}

void paso1()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);
}

void paso2()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(demora);
}

void paso3()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(demora);
}

void paso4()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(demora);
}
void paso1b()
{
  digitalWrite(IN1b, HIGH);
  digitalWrite(IN2b, LOW);
  digitalWrite(IN3b, LOW);
  digitalWrite(IN4b, LOW);
  delay(demora);
}

void paso2b()
{
  digitalWrite(IN1b, LOW);
  digitalWrite(IN2b, HIGH);
  digitalWrite(IN3b, LOW);
  digitalWrite(IN4b, LOW);
  delay(demora);
}

void paso3b()
{
  digitalWrite(IN1b, LOW);
  digitalWrite(IN2b, LOW);
  digitalWrite(IN3b, HIGH);
  digitalWrite(IN4b, LOW);
  delay(demora);
}

void paso4b()
{
  digitalWrite(IN1b, LOW);
  digitalWrite(IN2b, LOW);
  digitalWrite(IN3b, LOW);
  digitalWrite(IN4b, HIGH);
  delay(demora);
}

void frenar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1b, LOW);
  digitalWrite(IN2b, LOW);
  digitalWrite(IN3b, LOW);
  digitalWrite(IN4b, LOW);
  delay(1000);
}

void reloj()
{
  paso1();
  paso2();
  paso3();
  paso4();
}
void relojb()
{
  paso1b();
  paso2b();
  paso3b();
  paso4b();
}

void contrareloj()
{
  paso4();
  paso3();
  paso2();
  paso1();
}

void contrarelojb()
{
  paso4b();
  paso3b();
  paso2b();
  paso1b();
}

void loop()
{

  if (digitalRead(boton1) == HIGH)
  {
    reloj();
  }
  else if (digitalRead(boton2) == HIGH)
  {
    contrareloj();
  }
  else if (digitalRead(boton3) == HIGH)
  {
    relojb();
  }
  else if (digitalRead(boton4) == HIGH)
  {
    contrarelojb();
  }
  else
  {
    frenar();
  }
}
