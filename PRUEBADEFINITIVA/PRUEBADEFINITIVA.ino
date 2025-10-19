//ARCHIVO PRINCIPAL PARA EL FUNCIONAMIENTO DEL ROBOT SIGUE LÍNEA

//-------DEFINICIÓN DE LAS VARIABLES------- 
#define PINBUZZER 10
#define PINBOTON 2
#define PINLED 13
#define PIN_Sensor_ON 11

//VAR. GLOBALES PARA CONTROL PID Y VELOCIDAD
const float Kp = 0.4;    //Ganancia Proporcional
const float Ki = 0.001;  //Ganancia Integral
const float Kd = 0.8;    //Ganancia Derivativa

//------Variables de Estado PID Y HITS------
//------------------------------------------
int fin = 0;     //Contador de etapas
int base = 150;  //Velocidad base del robot

int errorAnterior = 0;
long sumaError = 0;
//------------------------------------------
//Velocidades por etapas
int velocidad_1 = 150;
int velocidad_2 = 180;
int velocidad_3 = 200;
int velocidad_4 = 220;
int velocidad_5 = 250;
//------------------------------------------
int umbral = 700; //DEPENDE (HAY QUE MERDIRLO)
int HL = 0;
int HR = 0;
int geo = 0;
int l_geo = 0;
int ll_geo = 0;
int lll_geo = 0;
//------------------------------------------

void setup(){
  Serial.begin(9600);
  Peripherals_init();
  Motores_init();
  Sensors_init();

  //Se espera que se presione el botón para comenzar la calibración
  WaitBoton();
  calibracion();
  WaitBoton(); //(OPCIONAL) SE ESPERA OTRA VEZ EL BOTÓN PARA COMENZAR EL BUCLE PRINCIPAL
}

void loop(){

  int posicion = GetPos(); 
  
  // Opcional: Imprime la posición para verla en el Monitor Serie
   Serial.print("Posicion: ");
   Serial.println(posicion);
   
  //int error = GetPos(); //EL ERROR ES LA POSICIÓN DE LA LÍNEA 

  //int P_term = (int)(error*Kp); //Proporcional
  
  //sumaError += error; //Integral
  //sumaError = constrain(sumaError, -5000, 5000);
  //int I_term = (int)(sumaError*Ki);

  //int D_term = (int)((error - errorAnterior)*Kd); // Derivativo

  //Corrección Total del PID
  //int correction = P_term + I_term + D_term;

  //errorAnterior = error; //Se actualiza para la próxima iteración

  //int speed_L = base - correction; //MOTOR IZQ
  //int speed_R = base + correction; //MOTOR DER

  //Limitando
  //speed_L = constrain(speed_L, 0, 255);
  //speed_R = constrain(speed_R, 0, 255);

  //Motores(speed_L, speed_R);

  //detectGeo();
}

