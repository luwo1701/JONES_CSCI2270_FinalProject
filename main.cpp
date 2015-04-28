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
	
	cross->setCurrentBoard();
}

void guessing(int times)
{
	int user,num;
	int questions = 0;
	int htry = 0;
	string guess, n,correct;
	//ifstream file;
	bool end = false;
	bool right = false;
	puzzle *cross = new puzzle();
		
	cout<<"Please enter the number of which question you'd like to answer: "<<endl;
	getline(cin,n);
	num = std::stoi(n);
	correct = cross->getWord(num);//index of word looking for
	
	//do
	//{
		/*if(questions > 0)
		{
			getline(cin,n);
			num = std::stoi(n);
			correct = cross->getWord(num);
		}*/
		cout<<"Please enter your guess. Enter 'h' for a hint or enter 'a' for the answer."<<endl;
		getline(cin,guess);
		//cout<<"c"<<correct<<endl;
		//cout<<"n"<<num<<endl;
		cross->fillBoard(correct,num);
		while(!right)
		{
			if(guess == "h")
			{
				while(htry <= 4)
				{
					htry++;
					cross->hint(correct,num,htry);
					
				}
				right = true;
			}
			else if(guess == "a")
			{
				cross->currentBoard(correct);
				
			}
			else if(guess == correct)
			{
				cross->currentBoard(correct);
				cross->clues();
				cout<<"Great Job you got it! Enter the the number of the next question you'd like to answer: "<<endl;
				times++;
				/*if(times <=5)
				guessing(times);
				else
				{
					cout<<"Amazing! You solved the puzzle!"<<endl;
				}*/
				//getline(cin,n);
				//correct = cross->getWord(num);
				right = true;
				
			}
			else if(guess != correct)
			{
				cout<<"Please try again: "<<endl;
				getline(cin,guess);	
			}
		}
		right = false;
		questions++;
	//}while(questions >= 5);
}




int main()
{
	
	
	string filename, correct,n,guess;
	int user;
	int count = 0;
	int times = 0;
	int num = 0;
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
				if(count < 1)
				{
					puzzleSetup(filename);
					count++;
				}
				cross->emptyBoard();
				cross->clues();
				while(count <=6)
				{
				guessing(times);
				count++;
				}
				//cross->setCurrentBoard(num);
				break;
			}
			
			case 2:
			{
				filename = "HIclues.txt";
				if(count < 1)
				{
					puzzleSetup(filename);
					count++;
				}
				cross->emptyBoard();
				cross->clues();
				while(count <=6)
				{
				guessing(times);
				count++;
				}
				break;
			}
			
			case 3:
			{
				filename = "Sclues.txt";
				if(count < 1)
				{
					puzzleSetup(filename);
					count++;
				}
				cross->emptyBoard();
				cross->clues();
				guessing(times);
				break;
			}
			
			case 4:
			{
				filename = "Xclues.txt";
				if(count < 1)
				{
					puzzleSetup(filename);
					count++;
				}
				cross->emptyBoard();
				cross->clues();
				guessing(times);
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
