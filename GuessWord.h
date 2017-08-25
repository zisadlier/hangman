/*
 * Implementation for a representation of a hidden word for hangman
 */

#ifndef GUESS_WORD_H
#define GUESS_WORD_H

#include <string>
#include <iostream>
#include <vector>

// Possible results for a guess attempt
enum GuessResult { correct, incorrect, duplicate, invalid };

class GuessWord {
public:

	// Constructor, takes in the word for the game
	GuessWord(std::string word);

	// Method for making a letter guess, returns the result of the guess
	GuessResult guess(char letter);

	// Methods for determining if the game is over
	// dead() returns true if the player lost, false otherwise
	// win() returns true if the player won, false otherwise
	bool dead() const;
	bool win() const;

	// Methods to get various private members of the class
	int get_stage() const;
	std::string get_hidden() const;
	std::string get_word() const;
	std::vector<char> get_unused() const;

private:
	int stage;
	std::string word;
	std::string hidden_word;
	std::vector<char> unused_letters;

	static const int MAX_STAGES = 6;
};

// Override output operator to print object nicely
std::ostream & operator<<(std::ostream &os, const GuessWord &guess_word);

#endif //GUESS_WORD_H