#define BAUD_RATE 9600


const int M1 = 4;
const int E1 = 3;


void setup() {

    Serial.begin(BAUD_RATE);

    analogReference(DEFAULT);

//    pinMode(M1, OUTPUT);
    pinMode(M1, OUTPUT);
    pinMode(E1, OUTPUT);
}




void loop() {

    if (Serial.available() > 0) {
        String input_data = Serial.readStringUntil('\n');
    }

    digitalWrite(M1, LOW);
    analogWrite(E1, 250);
}
