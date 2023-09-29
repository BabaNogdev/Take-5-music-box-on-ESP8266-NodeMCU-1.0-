# Take 5 music box on ESP8266 (NodeMCU 1.0)
A simple mono channel music box playing Dave Brubeck's iconic jazz piece Take Five, created for an [ESP-8266](https://en.wikipedia.org/wiki/ESP8266) microcontroller device.

# Variable description
1. `take5[]` -> `int` array of frequency values, defined in `pitches.h`, and rests, denoted by `R`. Stores the notes and the rests between each note.
2. `noteDurations[]` -> `int` array of time duration in ms. Stores the values of duration of each note and rest.
3. `DR, WR, HR, QR` -> `int` values. Allowed values of rests _(2, 4, 8, 16)_.
4. `tempo` and `rest` -> `int` values. Denotes the base speed of a note and a rest respectively.
5. `currNote` -> `int` value. Index for accessing elements of the take5[] and noteDurations[].
6. `pauseBetweenNotes` and `noteDuration` -> `int` values. Denotes the base duration of the rests and notes respectively.
7. `pitches.h` -> Has all the possible notes playable on a standard 88-keys piano, expressed as their sound frequencies.

# Code walkthrough
1. Create two arrays of notes and their corresponding durations. The notes can be taken from the music sheet notations or other means.
2. The values for the durations, tempo, and rests were obtained via a combination of hit-and-trial, and analysis of the music sheet and the MIDI audio recording of the track. A trained musician might have better luck in doing this speedily ;).
3. Iterate through the notes to play them by incrementing the value of `currNote`.
3.1. If the value of the array element is `R`, then delay the next note by `pauseBetweenNotes = rest / noteDurations[currNote]` time. The in-built `delay()` function is used to do that.
3.2. Else, output the note for `noteDuration = tempo / noteDurations[currNote]` time on the D1 pin. The in-built `tone()` function is used to do that.
4. The note sequence is infinitely looped (like a music box) by calling `setup()` in the `loop()` function.

The circuit diagram for this setup is pretty straightforward. Connect the positive end of the buzzer with the D1 pin of ESP8266 module, and the negative to the GND pin. I haven't done anything regarding power switches, but I think it should be fairly simple. I might update this repo if I ever get around to do that.

# Acknowledgement
The original code that helped me to get started was taken from this [video tutorial](https://www.youtube.com/watch?v=fxYD9ZUkGks). Kudos to Asia-DJ for making such a simple-to-follow tutorial.

# Possible future updates
1. Add a power switch to the setup.
2. Upload a complete circuit diagram.
3. Experiment with the possibility of making this a stereo setup with two buzzers; one emitting the melody, and the other the bass.
