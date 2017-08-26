## Hangman

A C++ implementation of the classic guessing game, hangman. This version allows 6 incorrect guesses then the hangman is complete and the player loses.

## Compiling and Playing
To compile into hangman.exe, run the following command:
```
g++ hangman.cpp GuessWord.cpp -o hangman
```
To run with the provided wordfile run:
```
./hangman words/long-words.txt
```
You can make your own word files too provided they are in the same format.