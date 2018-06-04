const int switchPin1 = 2;
const int switchPin2 = 3; 
const int ledPin =  13;      

// variables will change:
int switch1State = 0;
int switch1PreviousState = 0;
int switch2State = 0;
int switch2PreviousState = 0;

int note1 = 0x10;
int note2 = 0x20;
int note3 = 0x30;
int note4 = 0x40;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);

  Serial.begin(31250);
}

void loop() {
  switch1PreviousState = switch1State;
  switch2PreviousState = switch2State;

  switch1State = digitalRead(switchPin1);
  switch2State = digitalRead(switchPin2);

  if(switch1State == HIGH && switch1PreviousState == LOW){
    note(note1);
        flashLed();

  }else if(switch1State == LOW && switch1PreviousState == HIGH){
    note(note2);
        flashLed();

  }
  if(switch2State == HIGH && switch2PreviousState == LOW){
 
    note(note3);
       flashLed();
  }else if(switch2State == LOW && switch2PreviousState == HIGH){
    note(note4);
        flashLed();

  }
}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void note(int pitch) {
  int cmd = 0x90;
  int velocity = 0x00;
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void flashLed(){
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}
