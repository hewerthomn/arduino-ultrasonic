
#define pinTrig 12
#define pinEcho 13

#define CM 1
#define INC 0

long duration, distacne_cm, distance_inc;

void setup()
{
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pinTrig, LOW);
  
  int distancia = (ultrasonic_ranging(CM));
  
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(1000);
}

long ultrasonic_timing()
{
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  duration = pulseIn(pinEcho,HIGH);
  return duration;
}

long ultrasonic_ranging(int sys)
{
  ultrasonic_timing();
  
  distacne_cm = duration /29 / 2 ;
  distance_inc = duration / 74 / 2;
  if (sys)
  return distacne_cm;
  else
  return distance_inc;
}
