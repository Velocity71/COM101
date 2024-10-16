int numbers[10] = { // on/off instructions to the segments, in form of DP-A (idk bitRead is wierd. I don't do C++)
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01100111, // 9
};
int nothing = B00000000; // literally nothing

int segPins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // pins used in order of segments A-DP

void setup() {
  for (int i = 2; i <= 13; i++) { // segment pin initialization
    pinMode(i, 1); // output
  }

  for (int i = 0; i <= 9; i++) { // display the numbers 1-9 with a half second delay
    sendNumber(i);
    delay(500);
  }
}

void loop() {}

void sendNumber(int numb) { // display a number (in the form of a byte, see the numbers[] variable). For use with 1 digit 7 segment displays only
  int byte = numbers[numb];
  for (int i = 0; i <= 7; i++) {
    digitalWrite(segPins[i], bitRead(byte, i));
  }
}
