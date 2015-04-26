#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include "puzzle.h"

using namespace std;

void menu()
{
	cout<<"=====Main Menu====="<<endl;
	cout<<"1. Harry Potter Puzzle"<<endl;
	cout<<"2. How I Met Your Mother Puzzle"<<endl;
	cout<<"3. Seinfield Puzzle"<<endl;
	cout<<"4. Sick of Puzzles Puzzle"<<endl;
	cout<<"5. Quit"<<endl;
}

//put all words on one board
//print out clues
//create hint function
void puzzleSetup(string filename)
{
	string line,hold,word,clue,type,x;
	int y;
	ifstream file;
	bool end = false;
	puzzle *cross = new puzzle();
	
	
	file.open(filename);
		
	while(!file.eof())
	{
		getline(file,line);
		stringstream ss(line);
		
		//cross->emptyBoard();
		
		while(getline(ss,hold,','))
		{
			word = hold;
			getline(ss,hold,',');
			x = hold;
			getline(ss,hold,',');
			y = std::stoi(hold);
			getline(ss,hold,',');
			type = hold;
			getline(ss,hold,',');
			clue = hold;
			
			cross->setAnswer(word,x,y,type,clue);
		}
	}
	file.close();
	
}

void guessing()
{
	int user,num;
	string guess, n,correct;
	//ifstream file;
	bool end = false;
	bool right = false;
	puzzle *cross = new puzzle();
		
	cout<<"Please enter the number of which question you'd like to answer: "<<endl;
	getline(cin,n);
	num = std::stoi(n);
	correct = cross->getWord(num);//index of word looking for
	
	cout<<"Please enter your guess. If you'd like a hint enter 'h' or if you'd like the answer enter 'a'"<<endl;
	getline(cin,guess);
	while(!right)
	{
		if(guess == "h")
		cross->hint(correct,num);
		
		else if(guess == "a")
		{
			cross->fillBoard(correct,num);
			right = true;
		}
		else if(guess == correct)
		{
			cross->currentBoard();
			cross->clues();
			cout<<"Great Job you got it! Enter the the number of the next question you'd like to answer: "<<endl;
			getline(cin,n);
			correct = cross->getWord(num);
			right = true;
			
		}
	}
}




int main()
{
	
	
	string filename, correct,n,guess;
	int user,num;
	//ifstream file;
	bool end = false;
	bool right = false;
	puzzle *cross = new puzzle();
	
	cout<<"From the menu below, please choose a crossword puzzle to complete."<<endl;
	cout<<endl;
	
	while(end != true)
	{
		menu();
		
		cin >> user;
		cin.clear();
		cin.ignore(10000,'\n');

		switch(user)
		{
			case 1:
			{
				filename = "Hclues.txt";
				puzzleSetup(filename);
				cross->emptyBoard();
				cross->clues();
				guessing();
			
				break;
			}
			
			case 2:
			{
				filename = "HIclues.txt";
				puzzleSetup(filename);
				cross->emptyBoard();
				cross->clues();
				guessing();
				break;
			}
			
			case 3:
			{
				filename = "Sclues.txt";
				puzzleSetup(filename);
				cross->emptyBoard();
				cross->clues();
				guessing();
				break;
			}
			
			case 4:
			{
				filename = "Xclues.txt";
				puzzleSetup(filename);
				cross->emptyBoard();
				cross->clues();
				guessing();
				break;
			}
			
			case 5:
			{
				cout<<"Goodbye!"<<endl;
				end = true;
				break;
			}
			default:
			{
				cout<<"error"<<endl;
				break;
			}
		}

	}
		
	
	
	

	
	return 0;
}



