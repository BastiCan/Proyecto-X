#define PINBUZZER 10
#define PINBOTON 2
#define PINLED 13
#define PIN_Sensor_ON 11

// --- VARIABLES DE VELOCIDAD DE CARRERA (de Detect_Hits.ino) ---
int velocidad_1 = 50;
int velocidad_2 = 80;
int velocidad_3 = 100;
int velocidad_4 = 120;
int velocidad_5 = 150;

// --- VARIABLES DE CONTROL PD (de Tutorial_6 y Detect_Hits.ino) ---
int posicion_ideal = 0;
float Kprop = 1.0; 
float Kderiv = 6.0;
int base = 50; // Velocidad base, se inicializa con velocidad_1 en setup
int error_pasado = 0;

// --- VARIABLES DE DETECCIÓN DE HITS (de Hits.ino) ---
int fin = 0; 
int l_geo, ll_geo, lll_geo;
int umbral = 700;
int geo = 0;
int HL, HR = 0; 


void setup() {
  Serial.begin(115200);
  Peripherals_init();  
  TB6612FNG_init();    
  Sensors_init();

  digitalWrite(PINLED, LOW);
  delay(500);
  Motores(0, 0);

  Serial.println("--- Open Lamborghino | Modo Carrera ---");
  Serial.println("Presiona el botón para CALIBRAR los sensores de línea.");
  delay(500);
  WaitBoton();

  calibracion();

  base = velocidad_1; 
  delay(1000);
}

void loop() {
  int p = GetPos();
  detectGeo(); 

  int error = p - posicion_ideal;       
  int d_error = error - error_pasado;

  int correction_power = int(Kprop * error) + int(Kderiv * (d_error));

  if (correction_power > 255) {
    correction_power = 255;
  }
  else if (correction_power < -255) {
    correction_power = -255;
  }

  

  error_pasado = error;

  delay(1);
}
