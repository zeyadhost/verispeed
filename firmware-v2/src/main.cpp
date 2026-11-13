#include <Arduino.h>

// tuff pins go here from my tuff pcb
const uint8_t NUM_ROWS = 3;
const uint8_t NUM_COLS = 4;
const uint8_t ROW_PINS[NUM_ROWS] = {4, 5, 6};
const uint8_t COL_PINS[NUM_COLS] = {7, 15, 16, 17};

const char* KEY_NAMES[NUM_ROWS][NUM_COLS] = {
    {"K1", "K2", "K3", "K4"}, // r1
    {"K5", "K6", "K7", "K8"}, // r2
    {"K9", "K10", "K11", "K12"} // r3
};

const uint32_t DEBOUNCE_US = 5000;

bool rawPressed[NUM_ROWS][NUM_COLS];
bool stablePressed[NUM_ROWS][NUM_COLS];
uint32_t changedAt[NUM_ROWS][NUM_COLS];

void onKeyEvent(uint8_t row, uint8_t col, bool pressed) {
    Serial.print(KEY_NAMES[row][col]);
    Serial.println(pressed ? " pressed" : " released");
}

void updateKey(uint8_t row, uint8_t col, bool pressedNow) {
    uint32_t now = micros();

    if (pressedNow != rawPressed[row][col]) {
        rawPressed[row][col] = pressedNow;
        changedAt[row][col] = now;
        return;
    }

    bool steadyLongEnough = (now - changedAt[row][col]) >= DEBOUNCE_US;
    if (steadyLongEnough && rawPressed[row][col] != stablePressed[row][col]) {
        stablePressed[row][col] = rawPressed[row][col];
        onKeyEvent(row, col, stablePressed[row][col]);
    }
}

void scanKeys() {
    for (uint8_t row = 0; row < NUM_ROWS; row++) {
        pinMode(ROW_PINS[row], OUTPUT);
        digitalWrite(ROW_PINS[row], LOW);
        delayMicroseconds(30);

        for (uint8_t col = 0; col< NUM_COLS; col++) {
            bool pressed = (digitalRead(COL_PINS[col]) == LOW); 
            updateKey(row, col, pressed);
        }

        pinMode(ROW_PINS[row], INPUT);
    }
}

void setup() {
    Serial.begin(115200);
    Serial.setTxTimeoutMs(0);

    for (uint8_t col = 0; col < NUM_COLS; col++) {
        pinMode(COL_PINS[col], INPUT_PULLUP);
    }
    for (uint8_t row = 0; row < NUM_ROWS; row++) {
        pinMode(ROW_PINS[row], INPUT);  
    }
}

void loop() {
    scanKeys();
    delay(1);
}