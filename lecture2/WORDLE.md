# Lecture 2: Simple Wordle (Arrays Focus)

## Game Rules (Simplified Wordle)

- The secret word is exactly 5 letters.
- The player has 6 attempts to guess the secret word.
- After each guess, provide per-letter feedback:
  - G = correct letter in the correct position
  - Y = correct letter in the wrong position
  - . = letter not in the word
- Case-insensitive input; output should normalize to all uppercase or to all lowercase.
- At the end, display whether the player won and reveal the secret word if not.

---

## Program Requirements

- Use arrays to store:
  - The secret word 
  - The player’s guess 
  - The feedback for each guess 
  - Letter frequency counts for duplicate handling (int array size 26)
  - A small built-in array of valid secret words (array of strings)
- Fixed constants:
  - WORD_LEN = 5
  - MAX_TRIES = 6
- Input:
  - Read a full line using `get_string`
  - Strip newline
  - Validate guess length and alphabetic characters
  - Convert to uppercase
- Scoring must correctly handle duplicate letters via a two-pass approach:
  1) Mark exact matches (G), track remaining non-matched letters in the secret with counts[26]
  2) For non-G positions, mark Y if the letter exists in counts with a remaining count; otherwise .
- Output:
  - After each valid guess, print:
    - Guess (uppercase)
    - Feedback string of length 5 using G/Y/.
- Randomly choose a secret word from the list each run.

---

## Provided Constants and Word List

```c
#define WORD_LEN 5
#define MAX_TRIES 6

static const string WORDS[] = {
    "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
    "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA", 
    "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY",
};
static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));


// To shuffle the words you need to seed the random number generator
srand((unsigned)time(NULL));
const char *secret = words[rand() % WORD_COUNT];
```

---


## Example Interactions

Example 1: Win in 3 tries
- Secret: APPLE

Input/output:
- Attempt 1: guess = CRANE
  - Feedback might be: . . . Y Y
- Attempt 2: guess = APRON
  - Feedback: G G . . .
- Attempt 3: guess = APPLE
  - Feedback: G G G G G
- Program: "You win in 3 attempt(s)! The word was APPLE."

Example 2: Duplicate letters
- Secret: MANGO
- Guess: MAMMA
  - First pass (exact): M ? ? ? .
  - Counts from secret (non-matched): A, N, G, O -> counts[A]=1, counts[N]=1, counts[G]=1, counts[O]=1
  - Second pass:
    - A at pos1: Y (counts[A] becomes 0)
    - M at pos2: . (no remaining M)
    - M at pos3: . (no remaining M)
    - A at pos4: . (counts[A] is 0)
  - Feedback: G Y . . .
- This demonstrates correct handling of duplicates.

Example 3: Lose after 6 attempts
- After 6 valid guesses without all G’s, program prints:
  - "Out of tries. The word was LEMON."

---
