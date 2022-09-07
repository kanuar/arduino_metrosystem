// C++ code
//
int entrypd = 0;

int exitpd = 0;

int entrycd = 0;

int exitcd = 0;

int counter = 0;

int temp = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A4, INPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  entrypd = 0;
  exitpd = 0;
  counter = 0;
  temp = 0;

  if (temp != (-40 + 0.488155 * (analogRead(A0) - 20))) {
    temp = (-40 + 0.488155 * (analogRead(A0) - 20));
    if ((-40 + 0.488155 * (analogRead(A4) - 20)) > 39) {
      tone(7, 440, 1000); // play tone 57 (A4 = 440 Hz)
      noTone(7);
    } else {
      if (0.01723 * readUltrasonicDistance(9, 10) < 30) {
        counter += 1;
        delay(5000); // Wait for 5000 millisecond(s)
      }
    }
  }
  if (0.01723 * readUltrasonicDistance(2, 4) < 30) {
    counter = (counter - 1);
    delay(5000); // Wait for 5000 millisecond(s)
  }
}
