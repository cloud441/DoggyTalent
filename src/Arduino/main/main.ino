#include <Servo.h>


#define BAUD_RATE 9600
#define INPUT_SIZE 40
#define MAX_MOTOR_VALUE 255.0
#define SERVO_PIN 10
#define MAX_ANGLE 180.0
#define ATOM_TIME 25
#define ATOM_ANGLE 10

// M1 and E1 are associated to back motor for throttle.
const int M1 = 4;
const int E1 = 3;

// Servo motor is for steer control.
Servo steer_servo;
int current_angle = 0;

// Steer and throttle global value to update:
float steer = 0;
float throttle = 0;


void update_move(float steer, float throttle) {

    // Manage Throttle:
    throttle *= MAX_MOTOR_VALUE;

    throttle < 0 ? digitalWrite(M1, LOW) : digitalWrite(M1, HIGH);
    analogWrite(E1, abs(throttle));

    // Manage steer:
    //steer = (steer + 1.0) * MAX_ANGLE / 2.0;

    //if (steer == current_angle) {
    //    return;
    //}

    //current_angle += (steer > current_angle) ? ATOM_ANGLE : -ATOM_ANGLE;
    //current_angle = max(0, current_angle);
    //current_angle = min(MAX_ANGLE, current_angle);

    //steer_servo.write(current_angle);
    //delay(ATOM_TIME);
}


void setup() {

    Serial.begin(BAUD_RATE);
    analogReference(DEFAULT);

    pinMode(M1, OUTPUT);
    pinMode(E1, OUTPUT);

    // steer_servo.attach(SERVO_PIN);
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
                Serial.println("Error: impossible to parse throttle command.");
            } else {
                throttle = atof(command);
            }
        }

        update_move(steer, throttle);
    }
}
