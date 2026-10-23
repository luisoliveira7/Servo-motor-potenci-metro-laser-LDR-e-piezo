agora projeto2: int laser = 7;
int ldr = A2;
int buzzer = 8;

int limite = 500; // ajuste depois de ver os valores no monitor serial

void setup() {
  pinMode(laser, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(laser, HIGH); // laser sempre ligado
  Serial.begin(9600);
}

void loop() {
  int valor = analogRead(ldr);
  Serial.println(valor);

  // se o objeto passar na frente, o LDR recebe menos luz
  if (valor < limite) {
    tone(buzzer, 1000); // toca o som
  } else {
    noTone(buzzer);
  }

  delay(50);
}
