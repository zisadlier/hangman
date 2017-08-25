/*
 * Hangman implementation in C++
 *
 * Zackary Sadlier, 2017
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits.h>
#include "GuessWord.h"
#include "hang_util.h"

using namespace std;

// Function to pring the state of the hangman and unguessed letters
void print_hangman(GuessWord &gw) {
	string letters = "";

	for (size_t i = 0; i < gw.get_unused().size(); ++i) {
		letters += gw.get_unused()[i];
	}

	if (!gw.dead() && !gw.win()) {
		cout << stages[gw.get_stage()] << "Unused letters: " << letters << endl << endl;
	}
	else if (gw.win()) {
		cout << endl << gw << endl << "You won!" << endl;
	}
	else {
		cout << stages[gw.get_stage()] << gw << endl << "You lost!" << endl;
	}
}

// Function to load words from a file into a vector
void load_words(string fname, vector<string> &words) {
	ifstream infile(fname.c_str());

	string word;
	while(getline(infile, word)) {
		words.push_back(word);
	}
}

int main(int argc, char *argv[]) {
	string word;
	string fname;
	vector<string> words;

	srand(time(0));

	if (argc < 2) {
		cerr << "Error: No word file given" << endl;
		return 1;
	}
	else if (argc > 2) {
		cerr << "Error: Too many command line arguments given" << endl;
		return 1;
	}
	else {
		fname = argv[1];
	}

	// Load words from the specified file then pick a random one
	load_words(fname, words);
	random_shuffle(words.begin(), words.end());
	word = words[0];

	GuessWord game_word = GuessWord(word);

	while ((word != game_word.get_hidden()) && !game_word.dead()) {

		print_hangman(game_word);
		string temp = "";
		cout << game_word << endl;
		cout << "Enter a letter: ";
		cin >> temp;

		// Make sure the input is not more than one character long
		if (temp.length() != 1) {
			cout << "That's not a letter, try again" << endl;
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		char guess = temp[0];
		GuessResult result = game_word.guess(guess);

		// Print the correct response based on the guess result
		switch(result) {
			case duplicate: cout << "You already entered that letter" << endl; break;
			case correct: cout << "Correct!" << endl; break;
			case incorrect: cout << "Not in the word, try again" << endl; break;
			case invalid: cout << "That's not a letter, try again" << endl; break;
		}
	}

	print_hangman(game_word);

	return 0;
}