#define BAUD_RATE 9600
#define INPUT_SIZE 40

// M1 and E1 are associated to back motor for throttle.
const int M1 = 4;
const int E1 = 3;

// M2 and E2 are associated to front motor for steer.
const int M2 = 6;
const int E2 = 5;

float steer = 0;
float throttle = 0;


void update_move(float steer, float throttle) {
    return;
}









void setup() {

    Serial.begin(BAUD_RATE);
    analogReference(DEFAULT);

    pinMode(M1, OUTPUT);
    pinMode(E1, OUTPUT);

    //pinMode(M2, OUTPUT);
    //pinMode(E2, OUTPUT);
}




void loop() {

    if (Serial.available() > 0) {
        char input_data[INPUT_SIZE + 1];
        size_t nb_bytes = Serial.readBytesUntil('\n', input_data, INPUT_SIZE);
        input_data[nb_bytes] = '\0';

        char *command = strtok(input_data, ',');
        if (!command) {
            Serial.println("Error: impossible to parse steer command.");
        } else {
            steer = atof(command);

            command = strtok(NULL, ',');
            if (!command) {
                Serial.println("Error: impossible to parse steer command.");
            } else {
                throttle = atof(command);
            }
        }

        update_move();
    }



    digitalWrite(M1, LOW);
    analogWrite(E1, 250);
}
