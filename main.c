
class Led {
  private:
    int pin;

  public:
    Led(int p) {
      pin = p;
      pinMode(pin, OUTPUT);
    }
    void setPrenderLed() {
      digitalWrite(pin, HIGH);
    }
    void setApagarLed() {
      digitalWrite(pin, LOW);
    }

};

class Pulsador {
  private:
    int pin;
    bool flanco = HIGH;
    bool estado_anterior = !flanco;

    //metodo
  public:
    Pulsador(int p) {
      pin = p;

      pinMode(pin, INPUT);
    }

    void setFlanco(bool f) {
      flanco = f;
      estado_anterior = !flanco;
    }

    //metodos o acciones
    bool getIsPress() {
      bool estado_actual = digitalRead(pin);
      bool estado = (estado_anterior != estado_actual) && estado_actual == flanco;
      estado_anterior = estado_actual;
      return estado;
    }

    String getIsPressText() {
      if (getIsPress()) return "PRESS";
      else return "IS NOT PRESS";
    }

};

#define PIN_PULSADOR_1 3
#define PIN_PULSADOR_2 6
#define PIN_LED 13

Pulsador *p1 = new Pulsador(PIN_PULSADOR_1);
Pulsador *p2 = new Pulsador(PIN_PULSADOR_2);
Led *l1 = new Led(PIN_LED);

int contador = 0;
void setup() {
  Serial.begin(9600);
  p1->setFlanco(LOW);
  p2->setFlanco(HIGH);
}

void loop() {

  if (p1->getIsPress()) {
    Serial.println("p1 is press");
    l1->setPrenderLed();
  }

  if (p2->getIsPress()) {
    Serial.println("p2 is press");
    l1->setApagarLed();
  }


}
