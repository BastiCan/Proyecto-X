//CONEXIONES
const int ledPins[4] = {2, 3, 4, 5};
const int btnUp = 8;
const int btnDown = 9; 
const int btnBuzz = 10;
const int buzzerPin = 11; 
const int potPin = A0;

int value = 0;
bool lastUp = HIGH;
bool lastDown = HIGH;
bool lastBuzz = HIGH; 


void setup(){
  //CONFIGURACIÓN DE LOS PINES
  for (int i = 0; i < 4; i++){
  	pinMode(ledPins[i], OUTPUT);
  }
  
  //CONF. DE LOS BOTONES
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnBuzz, INPUT_PULLUP);
  
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
}


void loop(){
  //Leer botones 
  bool upState = digitalRead(btnUp);
  bool downState = digitalRead(btnDown);
  bool buzzState = digitalRead(btnBuzz);
  
  if (lastUp == HIGH && upState == LOW){
  	value = (value + 1) & 0x0F;
    delay(140);
  }
  
  if (lastDown == HIGH && downState == LOW){
  	if (value == 0) value = 15;
    else value--;
    delay(140);
  }
  
  for (int i = 0; i < 4; i++){
  	digitalWrite(ledPins[i], (value >> i) & 1);
  }
  
  if (buzzState == LOW){
  	int potValue = analogRead(potPin);
    
    if (potValue <= 5){
      digitalWrite(buzzerPin, LOW);
    } else {
    	int dutyPercent = map(potValue, 0, 1023, 5, 95);
    	int toneFreq = map(value, 0, 15, 0, 2000);
    
    	int freq = map(value, 0, 15, 0, 2000);
    	if (freq < 20) freq = 20;
    	unsigned long period_us = 1000000UL / freq;
    	unsigned long highTime = (period_us * dutyPercent) / 100;
    	if (highTime < 2) highTime = 2;
    	unsigned long lowTime = period_us - highTime;
    	if (lowTime < 2) lowTime = 2;
    
    	while (digitalRead(btnBuzz) == LOW){
    		digitalWrite(buzzerPin, HIGH);
      		delayMicroseconds(highTime);
      		digitalWrite(buzzerPin, LOW);
      		delayMicroseconds(lowTime);
        }
        digitalWrite(buzzerPin, LOW);
    }
        
   } else{
    
    digitalWrite(buzzerPin, LOW);
  }
  
  lastUp = upState;
  lastDown = downState;
  lastBuzz = buzzState;   
  
}