class LED{
private:
  int pinNumber;
  double frequency;
  double lastBlinkTime;
  
public:
  LED(int pinNumber, double frequency){
    pinMode(pinNumber, OUTPUT);
    this->pinNumber = pinNumber;
    this->frequency = frequency;
    lastBlinkTime = micros()/1000000.0;
  }

  void blinkOnce(){
    digitalWrite(pinNumber, HIGH);
    delay(1);
    digitalWrite(pinNumber, LOW);
  }

  void setFrequency(double frequency){
    this->frequency = frequency;
  }

  void use(){
    double currentTime = micros()/1000000.0;
    if((currentTime - lastBlinkTime)*frequency >= 1.0){
      blinkOnce();
      lastBlinkTime = currentTime;
    }
  }
};

LED led{3, 52.6};
int potPin = A5;

double myMap(double value, double fromLow, double fromHigh, double toLow, double toHigh){
  return (((value - fromLow)/(fromHigh - fromLow))*(toHigh - toLow)) + toLow;
}

void setup() {
  
}

void loop() {
  led.setFrequency(myMap(analogRead(potPin), 0, 1023, 49, 57));
  led.use();
}
