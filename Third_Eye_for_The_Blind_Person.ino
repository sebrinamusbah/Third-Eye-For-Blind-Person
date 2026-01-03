#define button1 2   // Alarm only
#define button2 3   // Alarm + Vibrator
#define button3 4   // Vibrator only

#define buzzer 5    // Speaker / Buzzer
#define motor  6    // Vibrator motor

#define echopin 7
#define trigpin 8

int Alarm = 1, Vibrator = 1;
int cm;
int lastDistance = -1;  // Track previous distance
int lastMode = 0;       // Track previous mode: 1=Alarm, 2=Alarm+Vibrator, 3=Vibrator

void setup() {
  Serial.begin(9600);  // Virtual Terminal baud rate

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  Serial.println("Third Eye for the Blind - System Started");
  delay(100);
}

void loop() {

  // -------- MODE SELECTION --------
  int currentMode = lastMode;

  if (digitalRead(button1) == 0) { 
    Alarm = 1; Vibrator = 0; 
    currentMode = 1;
  }
  else if (digitalRead(button2) == 0) { 
    Alarm = 1; Vibrator = 1; 
    currentMode = 2;
  }
  else if (digitalRead(button3) == 0) { 
    Alarm = 0; Vibrator = 1; 
    currentMode = 3;
  }

  // Only print mode if it changed
  if (currentMode != lastMode) {
    if (currentMode == 1) Serial.println("Mode: Alarm only");
    else if (currentMode == 2) Serial.println("Mode: Alarm + Vibrator");
    else if (currentMode == 3) Serial.println("Mode: Vibrator only");
    lastMode = currentMode;
    delay(200); // debounce
  }

  // -------- ULTRASONIC TRIGGER --------
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  long ultra_time = pulseIn(echopin, HIGH);
  cm = ultra_time / 29 / 2;

  // -------- PRINT DISTANCE AND STATUS ONLY WHEN CHANGED --------
  if (cm != lastDistance) {
    Serial.print("Distance (cm): ");
    Serial.println(cm);

    if (cm < 20) {
      Serial.println("DANGER ZONE! Alarm ON");
    } 
    else if (cm >= 20 && cm <= 100) {
      int freq = map(cm, 20, 100, 3500, 1200); 
      Serial.print("WARNING ZONE - Beep frequency: ");
      Serial.println(freq);
    } 
    else {
      Serial.println("Safe Zone - No alarm");
    }

    lastDistance = cm; // update
  }

  // -------- DISTANCE LOGIC FOR ALARM AND VIBRATOR --------
  if (cm >= 20 && cm <= 100) {
    int delayTime = map(cm, 20, 100, 50, 600);      
    int freq      = map(cm, 20, 100, 3500, 1200);   

    if (Alarm == 1) tone(buzzer, freq);
    if (Vibrator == 1) digitalWrite(motor, HIGH);

    delay(100);

    noTone(buzzer);
    digitalWrite(motor, LOW);

    delay(delayTime);
  }
  else if (cm < 20) {
    if (Alarm == 1) tone(buzzer, 4000);  // continuous sharp sound
    if (Vibrator == 1) digitalWrite(motor, HIGH);
  }
  else { // Safe Zone
    noTone(buzzer);
    digitalWrite(motor, LOW);
  }

  delay(10);
}
