const int MotorDireita = 1;
const int MotorEsquerda = 2;
const int MotorEnable = 3;

const int Botao = 9;
const int LedV = 4;
const int LedA = 5;

int portao = 1;

void setup() {
  pinMode(MotorDireita, OUTPUT);
  pinMode(MotorEsquerda, OUTPUT);
  pinMode(MotorEnable, OUTPUT);
  pinMode(Botao, INPUT);
  pinMode(LedV, OUTPUT);
  pinMode(LedA, OUTPUT);

  digitalWrite(MotorEnable, LOW);
}

void loop() {
  if (digitalRead(Botao) == HIGH) {
    if (portao == 1) {
      portao = 2;
      digitalWrite(MotorEnable, HIGH);
      digitalWrite(MotorDireita, LOW);
      digitalWrite(MotorEsquerda, HIGH);
      movimentar(3000);
      digitalWrite(MotorEsquerda, LOW);
      digitalWrite(MotorEnable, LOW);
      portao = 3;
    } else if (portao == 3) {
      portao = 2;
      digitalWrite(MotorEnable, HIGH);
      digitalWrite(MotorDireita, HIGH);
      digitalWrite(MotorEsquerda, LOW);
      movimentar(3000);
      digitalWrite(MotorDireita, LOW);
      digitalWrite(MotorEnable, LOW);
      portao = 1;
    }
  }
}

void movimentar(int tempo) {
  unsigned long startTime = millis();
  while (millis() - startTime < tempo) {
    digitalWrite(LedV, HIGH);
    digitalWrite(LedA, LOW);
    delay(250);
    digitalWrite(LedV, LOW);
    digitalWrite(LedA, HIGH);
    delay(250);
  }
  digitalWrite(LedV, LOW);
  digitalWrite(LedA, LOW);
}
