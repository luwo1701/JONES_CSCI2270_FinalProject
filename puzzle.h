#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <string>
#include <vector>

struct puzz
{
	std::string word;
	int x;
	int y;
	std::string type;
	std::string clue;
	
};

struct position
{
	char n;
	int row;
	int col;
	bool guess = false;
};


class puzzle
{
	public:
		void setAnswer(std::string, std::string, int, std::string, std::string);//puts words and properties into vector
		int setPos(std::string);//takes x coordinate converts to index
		void setCurrentBoard();//adds position of first letter of words to vector
		void emptyBoard();//prints out empty/initial board
		void fullBoard();//prints out ALL answers on board
		void fillBoard(std::string,int);//prints out currently guessing word onto board
		void currentBoard(std::string);//prints out ALL answers correctly guessed so far
		void clues();//prints out clues for across and down words
		void hint(std::string,int,int);//after 3 attempts, function gives user hints leading to answer
		void cipher();//takes clues and encodes them using a cipher for user to guess
		std::string getWord(int);//gets the correct word for clue user chose
	private:
		//std::vector<puzz>answers;
		
		
};
#endif
