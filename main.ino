#define ENA 10
#define ENB 11
#define IN1 8
#define IN2 9
#define IN3 12
#define IN4 13

// IR sensor pins
#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 5
#define IR5 6

// // Switch pin


void setup() {
  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // IR sensors
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);

  // Start with motors stopped
  // stopMotors();
  Serial.begin(9600);
  
}

void loop() {
  

  // Read IR sensor values
  int s1 = digitalRead(IR1) == HIGH?1:0;
  Serial.println(s1);
  int s2 = digitalRead(IR2) == HIGH?1:0;
  Serial.println(s2);
  int s3 = digitalRead(IR3) == HIGH?1:0;
  Serial.println(s3);
  int s4 = digitalRead(IR4) == HIGH?1:0;
  Serial.println(s4);
  int s5 = digitalRead(IR5) == HIGH?1:0;
  Serial.println(s5);
  delay(0);

  if (s3 == 1) {
    analogWrite(ENA,30);
    analogWrite(ENB,30);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);

  }
  else if (s2 == 1 && s3 == 1 && s4 == 1) {
    analogWrite(ENA,30);
    analogWrite(ENB,30);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
  }
  else if (s2 == 1 && s3 == 1) {
    analogWrite(ENA,30);
    analogWrite(ENB,30);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
  }
  else if (s3 == 1 && s4 == 1) {
    analogWrite(ENA,30);
    analogWrite(ENB,30);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);
  }
  else if ((s1 == 1 && s2 == 1) || (s1 == 1) || (s2 == 1) ||  (s1 == 1 && s2 == 1 && s3 == 1)){
   
    analogWrite(ENB,45);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,LOW);

  }    // Extreme left
  else if ((s5 == 1 && s4 == 1) || (s5 == 1) || (s4 == 1) ||  (s5 == 1 && s4 == 1 && s3 == 1)){
    analogWrite(ENA,45);
   
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4,LOW);

  } 
  else{
    analogWrite(ENA,0);
    analogWrite(ENB,0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4,LOW);
  }
} 
  