#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "GuessWord.h"

using namespace std;

// Constructor for a game word, takes in the word to be guessed
GuessWord::GuessWord(string word_in)
	: word(word_in), hidden_word(""), stage(0) {
		for (size_t i = 0; i < word.length(); ++i) {
			hidden_word += "-";
		}

		char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
		vector<char> letters(alphabet, alphabet + sizeof(alphabet) - 1) ;
		unused_letters = letters;
	}

GuessResult GuessWord::guess(char letter) {
	int count = 0;

	// If the character is not a letter return invalid 
	if (!isalpha(letter)) {
		return invalid;
	}

	letter = toupper(letter);

	// Check to make sure the letter is not a duplicate guess
	vector<char>::iterator position = find(unused_letters.begin(), unused_letters.end(), letter);
	if (position != unused_letters.end()) {
		unused_letters.erase(position);
	}
	else {
		return duplicate;
	}

	letter = tolower(letter);

	// Check if the letter is in the word
	for (size_t i = 0; i < word.length(); ++i) {
		if (word[i] == letter) {
			hidden_word[i] = letter;
			++count;
		}
	}
  
	if (count) {
		return correct;
	}
	else {
		++stage;
		return incorrect;
	}
}

bool GuessWord::dead() const {
	return stage == MAX_STAGES;	
}

bool GuessWord::win() const {
	return word == hidden_word;
}

int GuessWord::get_stage() const {
	return stage;
}

string GuessWord::get_hidden() const {
	return hidden_word;
}

string GuessWord::get_word() const {
	return word;
}

vector<char> GuessWord::get_unused() const {
	return unused_letters;
}

ostream & operator<<(std::ostream &os, const GuessWord &guess_word) {
	string representation = "";

	// Print the word with unguessed letters replaced with underscores
	// If the player lost, print the whole word to show them what it was
	if (!guess_word.dead()) {
		for (size_t i = 0; i < guess_word.get_hidden().length(); ++i) { 
			representation += guess_word.get_hidden()[i];
			representation += " ";
		}
	}
	else {
		for (size_t i = 0; i < guess_word.get_word().length(); ++i) { 
			representation += guess_word.get_word()[i];
			representation += " ";
		}
	}

	os << representation;
	return os;
}