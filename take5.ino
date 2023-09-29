// Variable description:
// 1. take5[] -> int array of frequency values, defined in pitches.h,
//    and rests, denoted by 'R'.
//    Stores the notes and the rests between each note.
// 2. noteDurations[] -> int array of time duration in ms.
//    Stores the values of duration of each note and rest.
// 3. DR, WR, HR, QHR, QR -> int values. QHR is basically a hack,
//    to make the double-beamed notes sound just right.
//    Allowed values of rests (2, 4, 8, 16).
// 4. tempo and rest -> int values.
//    Denotes the base speed of a note and a rest respectively.
// 5. currNote -> int value.
//    Index for accessing elements of the take5[] and noteDurations[].
// 6. pauseBetweenNotes and noteDuration -> int values.
//    Denotes the base duration of the rests and notes respectively.
// 7. pitches.h -> Has all the possible notes playable on a standard
//    88-keys piano, expressed as their sound frequencies.

// Code walkthrough:
// 1. Create two arrays of notes and their corresponding durations.
//    The notes can be taken from the music sheet notations or other means.
// 2. The values for the durations, tempo, and rests were obtained via a
//    combination of hit-and-trial, and analysis of the music sheet and the
//    MIDI audio recording of the track ;).
//    A trained musician might have better luck in doing this speedily.
// 3. Iterate through the notes to play them  by incrementing the value of currNote.
// 3.1. If the value of the array element is 'R', then delay the next note
//      by pauseBetweenNotes = rest / noteDurations[currNote] time.
//      The in-built delay() function is used to do that.
// 3.2. Else, output the note for noteDuration = tempo / noteDurations[currNote]
//      time on the D1 pin.
//      The in-built tone() function is used to do that.
// 4. The note sequence is infinitely looped (like a music box) by calling setup()
//    in the loop() function.

#include "pitches.h"

int DR = 2;
int WR = 4;
int HR = 8;
int QHR = 14;
int QR = 16;

int take5[] =
{
  E2, R, E4, R, E2, R, E4, R, B2, R, D4, R,
  E2, R, E4, R, E2, R, E4, R, B2, R, D4, R,
  E2, R, E4, R, E2, R, E4, R, B2, R, D4, R,
  E2, R, E4, R, E2, R, E4, R, B2, R, D4, R,
  E2, R, E4, R, E2, R, E4, R, // Bouncy bass line
  B3, R, E4, R, G4, R, A4, R,
  AS4, R, B5, R, AS4, R, A4, R, G4, R, // Initial melody line
  B3, R, C4, R, CS4, R, D4, R, E4, R, // The spicy trill
  F4, R, G4, R, F4, R, E4, R, D4, R, E4, R,
  D4, R, E4, R, D4, R, B3, R, A3, R, B3, R, // Phrase end
  D4, R, F4, R, G4, R, F4, R, E4, R, D4, R, E4, R, // Pre-loop phrase
  0
};

int noteDurations[] = 
{
  4, HR, 8, WR, 4, HR, 8, WR, 2, WR, 4, WR,
  4, HR, 8, WR, 4, HR, 8, WR, 2, WR, 4, WR,
  4, HR, 8, WR, 4, HR, 8, WR, 2, WR, 4, WR,
  4, HR, 8, WR, 4, HR, 8, WR, 2, WR, 4, WR,
  4, HR, 8, WR, 4, HR, 8, WR, // Bouncy bass line
  4, HR, 4, HR, 4, HR, 4, HR,
  4, HR, 4, HR, 4, HR, 4, HR, 2, WR, // Initial melody line
  2, HR, 2, QR, 4, QR, 2, QHR, 2, DR, // The spicy trill
  8, HR, 4, QHR, 4, QHR, 4, QHR, 4, QHR, 4, WR,
  8, HR, 4, QHR, 4, QHR, 4, QHR, 4, QHR, 4, DR, // Phrase end
  4, WR, 8, QHR, 8, QHR, 8, QHR, 8, QHR, 8, QHR, 4, DR, // Pre-loop phrase
  1,
};

int tempo = 2000;
int rest = 1400;

void setup() {
	int currNote = 0;
	//pinMode(D2, INPUT);

	while(take5[currNote] > 0) {
    if (take5[currNote] == R) {
      int pauseBetweenNotes = rest / noteDurations[currNote];
      delay(pauseBetweenNotes);
    }

    else {
      int noteDuration = tempo / noteDurations[currNote];
      tone(D1, take5[currNote], noteDuration);
    }
    
    currNote++;
	}

	noTone(D1);
}

void loop() {
  // setup();
}
