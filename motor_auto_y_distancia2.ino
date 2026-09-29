int motorAizq = 9; //avanza para delante
int motorAder = 10;//avanza para atras
int motorBizq = 5; //avanza para delante
int motorBder = 6; //avanza para Atras

int Trig = 11;
int Echo = 12;

int giro = 0;

void setup() {
  pinMode(motorAizq, OUTPUT);
  pinMode(motorAder, OUTPUT);

  pinMode(motorBizq, OUTPUT);
  pinMode(motorBder, OUTPUT);

  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.begin (9600);
}

void loop() {

  digitalWrite(motorAizq, HIGH);//avanza 
  digitalWrite(motorAder, LOW);

  digitalWrite(motorBizq, HIGH);//avanza 
  digitalWrite(motorBder, LOW);
  
  delay(200);

  long duracion;
  long distancia;
  
  digitalWrite(Trig,LOW);
  delayMicroseconds(2);
  digitalWrite(Trig,HIGH);
  delayMicroseconds(5);
  /*digitalWrite(Trig,LOW);*/
  
  duracion = pulseIn(Echo,HIGH);
  distancia = (duracion/2)/29;

  Serial.println(distancia);

  delay(100);

  if (distancia < 40) {
     digitalWrite(motorAizq, LOW);//detiene 
     digitalWrite(motorAder, LOW);

     digitalWrite(motorBizq, LOW);//detiene
     digitalWrite(motorBder, LOW);
     delay(1000);
    
     digitalWrite(motorAizq, LOW);// 
     digitalWrite(motorAder, HIGH);//retrocede

     digitalWrite(motorBizq, LOW);
     digitalWrite(motorBder, HIGH);//retrocede
     delay(500);

     if (giro == 1) {
      digitalWrite(motorAizq, HIGH);// 
      digitalWrite(motorAder, LOW);//detiene para girar
      digitalWrite(motorBizq, LOW);//gira a la IZQUIERDA
      digitalWrite(motorBder, LOW);
      delay(1300);
      giro = giro - 1;
     }

     else if (giro == 0) {
      digitalWrite(motorBizq, HIGH);// 
      digitalWrite(motorBder, LOW);//detiene para girar
      digitalWrite(motorAizq, LOW);//gira a la DERECHA
      digitalWrite(motorAder, LOW);
      delay(1300);
      giro = giro + 1;
     }
  }
  digitalWrite(motorAizq, HIGH);//avanza
  digitalWrite(motorAder, LOW);

  digitalWrite(motorBizq, HIGH);//avanza
  digitalWrite(motorBder, LOW);
  
}
