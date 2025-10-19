//ARCHIVO PARA LA FUNCIÓN DE MOTORES 

//-------PINES DEL MOTOR------- 
#define MOTOR_IZQ_ENA 5    // PWM velocidad motor izquierdo
#define MOTOR_IZQ_IN1 8    // Control dirección 1 izquierdo
#define MOTOR_IZQ_IN2 9   // Control dirección 2 izquierdo

#define MOTOR_DER_ENB 6    // PWM velocidad motor derecho  
#define MOTOR_DER_IN3 4    // Control dirección 1 derecho
#define MOTOR_DER_IN4 7   // Control dirección 2 derecho
//-----------------------------

void Motores_init(){
  pinMode(MOTOR_IZQ_ENA, OUTPUT);
  pinMode(MOTOR_IZQ_IN1, OUTPUT);
  pinMode(MOTOR_IZQ_IN2, OUTPUT);

  pinMode(MOTOR_DER_ENB, OUTPUT);
  pinMode(MOTOR_DER_IN3, OUTPUT);
  pinMode(MOTOR_DER_IN4, OUTPUT);
}

void Motores(int speed_L, int speed_R){ //solo sigue para adelante 
  speed_L = constrain(speed_L, -255, 255);
  speed_R = constrain(speed_R, -255, 255);

  //MOTOR IZQUIERDO
  if (speed_L > 0){
    digitalWrite(MOTOR_IZQ_IN1, HIGH);
    digitalWrite(MOTOR_IZQ_IN2, LOW);
    analogWrite(MOTOR_IZQ_ENA, speed_L);
  } else{
    digitalWrite(MOTOR_IZQ_IN1, LOW);
    digitalWrite(MOTOR_IZQ_IN2, LOW); 
    analogWrite(MOTOR_IZQ_ENA, 0); //se detiene 
  }

  //MOTOR DERECHO
  if (speed_L > 0){
    digitalWrite(MOTOR_DER_IN3, HIGH);
    digitalWrite(MOTOR_DER_IN4, LOW);
    analogWrite(MOTOR_DER_ENB, speed_R);
  } else{
    digitalWrite(MOTOR_DER_IN3, LOW);
    digitalWrite(MOTOR_DER_IN4, LOW); 
    analogWrite(MOTOR_DER_ENB, 0); //se detiene
  }
} 
