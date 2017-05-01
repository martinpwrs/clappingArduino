/*
 * Clapping by Steve Reich for Arduino
 * 
 * circuit: 8-ohm speaker on digital pins 7 and 8. LEDs can also be substituted for a visual element.
 * 
 * created 1 May 2017
 * by Martin Powers
 * 
 * Plays one loop of Steve Reich's Clapping Music
 * 
 */
 
#include <Tone.h>

Tone tone1;
Tone tone2;

int pattern[] = {
  true, true, true, false, true, true, false, true, false, true, true, false
};

// all notes are eigth notes
int noteDuration = 1000 / 8;

void setup() {

  // Initialize the tones
  tone1.begin(7);
  tone2.begin(8);

  // The song is 13 bars long. 
  for (int thisBar = 0; thisBar < 13; thisBar++) {
    // The pattern is a 12 note bar
    for (int thisNote = 0; thisNote < 12; thisNote++) {

      // Play the first pattern 
      if (pattern[thisNote]) {
        tone1.play(NOTE_C4);
      }
      // Play the second pattern
      if (pattern[(thisNote + thisBar)%12]) {
        tone2.play(NOTE_A4);
      }
  
      // to make the notes staccato we play the tone and then play silence, each for half the noteDuration
      delay(noteDuration);
      tone1.stop();
      tone2.stop();
      delay(noteDuration);
    }
  } 
}

void loop() {
 
}

