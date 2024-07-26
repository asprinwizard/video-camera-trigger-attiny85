//Set current state
int triggerPin = 4;
int statusLedPin = 0;
//int triggerLedPin = 13;
int recStatusPin = 3;
int currentRecState = LOW;
const int STARTUP_DELAY = 1000;
int recStateType;
int isRecording = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(statusLedPin, OUTPUT);
  //pinMode(triggerLedPin, OUTPUT);
  pinMode(recStatusPin, INPUT);

  // Delay start before reading state of remote pin
  delay(STARTUP_DELAY);
  recStateType = (digitalRead(recStatusPin) == HIGH) ? LOW : HIGH;
  currentRecState = digitalRead(recStatusPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the raw data coming in on analog pin 0:
  int recState = digitalRead(recStatusPin);

  // If state has changed send a pulse
  if (recState != currentRecState) {

    // Set rec state
    currentRecState = recState;
    isRecording = (currentRecState == recStateType) ? HIGH : LOW; 

    // Set rec status led
    digitalWrite(statusLedPin, isRecording);

    //Pulse trigger and led
    digitalWrite(triggerPin, HIGH);
    //digitalWrite(triggerLedPin, HIGH);
    delay(250);
    digitalWrite(triggerPin, LOW);
    //digitalWrite(triggerLedPin, LOW);
  }
}
