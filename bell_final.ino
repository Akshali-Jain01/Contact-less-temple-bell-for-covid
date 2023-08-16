const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
int flag = 1;
int motor1pin1 = 5;
//int motor1pin2 = 6;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(motor1pin1, OUTPUT);
  //pinMode(motor1pin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(motor1pin1, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = microsecondsToCentimeters(duration);
  Serial.println(String(distance));
//  delay(760);
  if (distance <= 20) {
    if (flag == 1) {
      digitalWrite(motor1pin1, LOW);
     // digitalWrite(motor1pin2, LOW);
      delay(800);
      digitalWrite(motor1pin1, HIGH);
      delay(500);
      //digitalWrite(motor1pin2, HIGH);
      //delay(2000);
      //digitalWrite(motor1pin1, LOW);
      //digitalWrite(motor1pin2, LOW);
      flag = 0;
    }

  }
  else {
    flag = 1;
    digitalWrite(motor1pin1, HIGH);
    //digitalWrite(motor1pin2, LOW);
   // delay(1000);

  }
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
