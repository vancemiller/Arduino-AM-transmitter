#define ANTENNA 9
#define IN1 2
#define IN2 3 
#define IN3 4
#define IN4 5
void setup() 
 {
    // set up Timer 1
    TCCR1A = _BV (COM1A0);  // toggle OC1A on Compare Match
    TCCR1B = _BV(WGM12) | _BV(CS10);   // CTC, no prescaler
    OCR1A =  9;       // compare A register value to 10 (zero relative)

    pinMode(IN1, INPUT);
    pinMode(IN2, INPUT);
    pinMode(IN3, INPUT);
    pinMode(IN4, INPUT);
}
void loop() {
    int n1 = digitalRead(IN1) * 1;
    int n2 = digitalRead(IN2) * 2;
    int n3 = digitalRead(IN3) * 4;
    int n4 = digitalRead(IN4) * 8;
    int note = n1 + n2 + n3 + n4;
    play(note + 1);
}

void play(int n) {
    pinMode(ANTENNA, OUTPUT);
    delay(n);
    pinMode(ANTENNA, INPUT);
    delay(n);
}
