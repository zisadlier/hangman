/*
 * Constant strings for hangman visuals are defined here
 */

#ifndef HANG_UTIL_H
#define HANG_UTIL_H

#include <string>

const std::string HANGMAN_ONE = "____\n"
						        "|   |\n"  
						        "|\n"
						        "|\n"
						        "|\n"
						        "|______\n";

const std::string HANGMAN_TWO =  "____\n"
							     "|   |\n"  
							     "|   O\n"
							     "|\n"
							     "|\n"
							     "|______\n";

const std::string HANGMAN_THREE = "____\n"
							      "|   |\n"  
							      "|   O\n"
							      "|   |\n"
							      "| \n"
							      "|______\n";

const std::string HANGMAN_FOUR = "____\n"
							     "|   |\n"  
							     "|   O\n"
							     "| --|\n"
							     "| \n"
							     "|______\n";

const std::string HANGMAN_FIVE = "____\n"
							     "|   |\n"  
							     "|   O\n"
						         "| --|--\n"
							     "| \n"
							     "|______\n";

const std::string HANGMAN_SIX = "____\n"
						        "|   |\n"  
						        "|   O\n"
						        "| --|--\n"
						        "|  /\n"
						        "|______\n";

const std::string HANGMAN_FULL = "____\n"
							     "|   |\n"  
							     "|   O\n"
							     "| --|--\n"
							     "|  / \\\n"
							     "|______\n";

const std::string stages[] = {HANGMAN_ONE, HANGMAN_TWO, HANGMAN_THREE, HANGMAN_FOUR, HANGMAN_FIVE, HANGMAN_SIX, HANGMAN_FULL};

#endif //HANG_UTIL_H