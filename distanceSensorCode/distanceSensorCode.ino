const int trigPin = 11;
const int echoPin = 12;
const int redPin = 2;
const int greenPin = 3;
double duration;
double distanceCm, distanceInch;
double R1 = 0.01724;
double R2 = 0.006329;
double distanceLimit = 10;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * R1;
  distanceInch = duration * R2;
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.print(" cm/");
  Serial.print(distanceInch);
  Serial.println(" in");
  if (distanceCm < distanceLimit){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }
  if (distanceCm > distanceLimit){
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
  }
  delay(100);

}
