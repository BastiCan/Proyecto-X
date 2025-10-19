void setup() {
  // Inicializa la comunicación serial para los mensajes de depuración
  Serial.begin(9600); 

  // Inicializa los pines de los periféricos (Botón, Buzzer, LED)
  Peripherals_init(); 
  
  // Inicializa los pines de los sensores
  Sensors_init();    
  
  // Espera que se presione el botón para comenzar la calibración
  WaitBoton();     
  
  // Realiza la calibración de los sensores (obtiene min y max)
  calibracion();   
  
  // Espera otra vez el botón antes de comenzar el bucle principal
  WaitBoton();     
}

void loop() {
  // Lee los sensores, calcula la posición y la almacena en 'pos'
  int posicion = GetPos(); 
  
  // Opcional: Imprime la posición para verla en el Monitor Serie
   Serial.print("Posicion: ");
   Serial.println(posicion);

  // Aquí iría el código para mover los motores basado en 'posicion'
}