int redLed = 2;
int whiteLed = 21;

int delayTime = 1000;

void ledSetup(){
  pinMode(redLed, OUTPUT);
  pinMode(whiteLed, OUTPUT);
}

void onRedLed(){
  digitalWrite(redLed, HIGH);
  delay(delayTime);   
}

void offRedLed(){
  digitalWrite(redLed, LOW);
  delay(delayTime);   
}

void onWhiteLed(){
  digitalWrite(whiteLed, HIGH);
  delay(delayTime);   
}


void offWhiteLed(){
  digitalWrite(whiteLed, LOW);
  delay(delayTime);   
}

