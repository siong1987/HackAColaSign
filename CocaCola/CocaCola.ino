#include "Constants.h"

void setup() {
    randomSeed(analogRead(0));

    for (int i = 0; i < sizeof(Lights); i++) {
        pinMode(Lights[i], PATTERN_INITIALIZE);
    }
}

// code above the man is ignored by the emulator
// code below it is transpiled into js and run by the emulator

// )'(
// Scenes

void lettersAllOn() {
    log('lettersAllOn - START');
    for (int i = 0; i < sizeof(letters); i++) {
        log('lettersAllOn ', i);
        digitalWrite(letters[i], PATTERN_ON);
        delay(none);
    }
}

void lettersAllOff() {
    log('lettersAllOff - START');
    for (int i = 0; i < sizeof(letters); i++) {
        log('lettersAllOff i: ', i);
        digitalWrite(letters[i], PATTERN_OFF);
        delay(none);
    }
}

void backgroundAllOn() {
    log('backgroundAllOn - START');
    for (int i = 0; i < sizeof(background); i++) {
        log('backgroundAllOn ', i);
        digitalWrite(background[i], PATTERN_ON);
        delay(none);
    }
}

void backgroundAllOff() {
    log('backgroundAllOff - START');
    for (int i = 0; i < sizeof(background); i++) {
        log('backgroundAllOff i: ', i);
        digitalWrite(background[i], PATTERN_OFF);
        delay(none);
    }
}

void lettersOnLeftToRight() {
    log('lettersOnLeftToRight - START');
    for (int i = 0; i < sizeof(letters); i++) {
        log('lettersOnLeftToRight i: ', i);
        digitalWrite(letters[i], PATTERN_ON);
        delay(normal);
    }
}

void backgroundOnLeftToRight() {
    // turn the background on from left to right
    log('backgroundOnLeftToRight - START');
    for (int i = 0; i < sizeof(background); i++) {
        log('backgroundOnLeftToRight i: ', i);
        digitalWrite(background[i], PATTERN_ON);
        delay(minimal);
    }
}

void backgroundOffRightToLeft() {
    log('backgroundOffRightToLeft - START');
    for (int i = sizeof(background) - 1; i >= 0; i--) {
        digitalWrite(background[i], PATTERN_OFF);
        delay(minimal);
    }
}

void backgroundOnOutsideIn() {
    log('backgroundOnOutsideIn - START');
    for (int i = 0, j = sizeof(background) - 1; i < (sizeof(background) / 2); i++, j--) {
        log('backgroundOnOutsideIn i: ', i);
        digitalWrite(background[i], PATTERN_ON);
        delay(none);
        log('backgroundOnOutsideIn j: ', j);
        digitalWrite(background[j], PATTERN_ON);
        delay(minimal);
    }
}

void backgroundOffInsideOut() {
    log('backgroundOffInsideOut - START');
    for (int i = (sizeof(background) / 2) - 1, j = i + 1; i >= 0; i--, j++) {
        log('backgroundOffInsideOut i: ', i);
        digitalWrite(background[i], PATTERN_OFF);
        delay(none);
        log('backgroundOffInsideOut j: ', j);
        digitalWrite(background[j], PATTERN_OFF);
        delay(minimal);
    }
}

void backgroundOffOutsideIn() {
    log('backgroundOffOutsideIn - START');
    for (int i = 0, j = sizeof(background) - 1; i < (sizeof(background) / 2); i++, j--) {
        log('backgroundOffOutsideIn i: ', i);
        digitalWrite(background[i], PATTERN_OFF);
        delay(none);
        log('backgroundOffOutsideIn j: ', j);
        digitalWrite(background[j], PATTERN_OFF);
        delay(minimal);
    }
}

void backgroundOnInsideOut() {
    log('backgroundOnInsideOut - START');
    for (int i = (sizeof(background) / 2) - 1, j = i + 1; i >= 0; i--, j++) {
        log('backgroundOnInsideOut i: ', i);
        digitalWrite(background[i], PATTERN_ON);
        delay(none);
        log('backgroundOnInsideOut j: ', j);
        digitalWrite(background[j], PATTERN_ON);
        delay(minimal);
    }
}

void allOff() {
    for (int i = 0; i < sizeof(Lights); i++) {
        digitalWrite(Lights[i], PATTERN_OFF);
        delay(none);
    }
}

void allOn() {
    for (int i = 0; i < sizeof(Lights); i++) {
        digitalWrite(Lights[i], PATTERN_ON);
        delay(none);
    }
}

// Patterns

void classicBackground() {
    backgroundOnLeftToRight();
    delay(extended);
    backgroundOffRightToLeft();
}

void outsideInOnInsideOutOffBackground(int times, int endingWithLightsOn) {
	for (int count = 0; count < times; count++) {
      backgroundOnOutsideIn();
      delay(extended);
		if (count + 1 != times || !endingWithLightsOn) {
			backgroundOffInsideOut();
		}
	}
}

void insideOutOnOutsideInOffBackground(int times, int endingWithLightsOn) {
	for (int count = 0; count < times; count++) {
	    backgroundOnInsideOut();
	    delay(extended);
 		 if (count + 1 != times || !endingWithLightsOn) {
			 backgroundOffOutsideIn();
		 }
	 }
}

void racingOnLeftToRight() {
	for (int x = 0; x < sizeof(background); x++) {
		for (int y = 0; y < sizeof(background) - x - 1; y++) {
			digitalWrite(background[y], PATTERN_ON);
			delay(minimal);
			digitalWrite(background[y], PATTERN_OFF);
		}

		digitalWrite(background[sizeof(background) - x - 1], PATTERN_ON);
		delay(minimal);
	}
}

void blinkBackgroundPairLeftToRight() {
	int half = sizeof(background) / 2;

	for (int count = 0; count < random(5, 10); count++) {
		for (int x = 0; x < half; x++) {
			digitalWrite(background[x], PATTERN_ON);
			digitalWrite(background[x + half], PATTERN_ON);
			delay(minimal);

			digitalWrite(background[x], PATTERN_OFF);
			digitalWrite(background[x + half], PATTERN_OFF);
		}
	}
}

void blinkLetters(int times) {
    for (int x = 0; x < times; x++) {
        lettersAllOff();
        delay(blinky);

        lettersAllOn();
        delay(blinky);
    }
}

void blinkBackground(int times) {
   for (int x = 0; x < times; x++) {
       backgroundAllOff();
       delay(blinky);

       backgroundAllOn();
       delay(blinky);
   }
}

// Arduino loop

void loop() {
    allOff();

    lettersOnLeftToRight();
    classicBackground();
    delay(normal);

    outsideInOnInsideOutOffBackground(random(2, 5), true);
    delay(normal);

	 insideOutOnOutsideInOffBackground(random(2, 5), false)
	 delay(normal);

	 racingOnLeftToRight();
	 blinkBackground(random(5, 10));
    delay(normal);

    blinkLetters(random(5, 10));

    lettersAllOff();

    delay(ish);
}

