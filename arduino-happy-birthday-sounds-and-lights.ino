// * Happy Birthday to You
// * Original Composition : 
// * Composed by : 
// * Coded By - http://forum.arduino.cc/index.php?topic=178460.0
// * Use BSD Clause 2 License for Distribution
// * Collection by GitHub User @abhishekghosh - https://github.com/AbhishekGhosh/Arduino-Buzzer-Tone-Codes

int speakerPin = 9;
int ledPin = 13;
int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
bool b1 = true;
bool b2 = true;
bool b3 = true;

int length = 28; // the number of notes

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };

int tempo = 150;

void playTone(int tone, int duration) {

int index = 1;
for (long i = 0; i < duration * 1000L; i += tone * 2) {

   digitalWrite(speakerPin, HIGH);
   digitalWrite(ledPin, HIGH);

   delayMicroseconds(tone);

   digitalWrite(speakerPin, LOW);
   digitalWrite(ledPin, LOW);

   index++;

   delayMicroseconds(tone);

}

}

void playNote(char note, int duration) {

char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                 'c', 'd', 'e', 'f', 'g', 'a', 'b',

                 'x', 'y' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                 956,  834,  765,  593,  468,  346,  224,

                 655 , 715 };

int SPEE = 5;

// play the tone corresponding to the note name

for (int i = 0; i < 17; i++) {

   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);

   }

}

}

void setup() {

pinMode(speakerPin, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);

}

void loop() {

for (int i = 0; i < length; i++) {

   if (notes[i] == ' ') {

     delay(beats[i] * tempo); // rest

   } else {

     playNote(notes[i], beats[i] * tempo);

   }

   if (i % 3 == 0) {
    if (b1) digitalWrite(ledPin1, HIGH); else digitalWrite(ledPin1, LOW);
    b1 = !b1;
   }
   else if (i % 3 == 1) {
    if (b2) digitalWrite(ledPin2, HIGH); else digitalWrite(ledPin2, LOW);
    b2 = !b2;
   }
   else if (i % 3 == 2) {
    if (b3) digitalWrite(ledPin3, HIGH); else digitalWrite(ledPin3, LOW);
    b3 = !b3;
   }

   // pause between notes

   delay(tempo);

}

}
