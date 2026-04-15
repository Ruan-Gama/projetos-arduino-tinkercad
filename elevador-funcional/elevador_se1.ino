const int MotorSubir = 1;
const int MotorDescer = 2;
const int MotorEnable = 3;

const int Botao[] = {9, 10, 11, 12, 13};
const int Led[] = {4, 5, 6, 7, 8};

int AndarAtual = 1;

void setup() {
  pinMode(MotorSubir, OUTPUT);
  pinMode(MotorDescer, OUTPUT);
  pinMode(MotorEnable, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(Botao[i], INPUT);
    pinMode(Led[i], OUTPUT);
  }

  AcenderLed(0);
}

void AcenderLed(int andar) {
  for (int i = 0; i < 5; i++) {
    if (i == andar) {
      digitalWrite(Led[i], HIGH);
    } else {
      digitalWrite(Led[i], LOW);
    }
  }
}

void MoverElevador(bool subir) {
  if (subir) {
    digitalWrite(MotorSubir, HIGH);
    digitalWrite(MotorDescer, LOW);
  } else {
    digitalWrite(MotorSubir, LOW);
    digitalWrite(MotorDescer, HIGH);
  }

  digitalWrite(MotorEnable, HIGH);
  delay(1000);
  digitalWrite(MotorEnable, LOW);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    if (digitalRead(Botao[i]) == HIGH) {
      while (AndarAtual != (i + 1)) {
        if (AndarAtual < (i + 1)) {
          MoverElevador(true);
          AndarAtual++;
        } else {
          MoverElevador(false);
          AndarAtual--;
        }
        AcenderLed(AndarAtual - 1);
      }
    }
  }
  delay(10);
}
