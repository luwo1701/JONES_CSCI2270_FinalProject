#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "puzzle.h"

using namespace std;
//This function takes the letter of the row and changes it to 
//its index that is then used to determine which row it is
//in the crossword puzzle
int puzzle::setPos(string x)
{
	string row[] = {" A", " B", " C"," D"," E"," F"," G"," H"," I"," J"," K"," L"};
	char Board[12][12];
	
	for(int g = 0; g <12; g++)
	{
		if(row[g] == x)
		 return g;

	}
	
}

//This function takes in each word and stores it in a vector of "answers"
//which is a struct with the different properties of that word
//such as its clue, placement in the crossword,etc.
void puzzle::setAnswer(string w, string x, int y, string t, string c)
{ 
	vector<puzz>answers;
	puzz answer;
	string place;
	answer.word = w;
	answer.x = setPos(x);
	answer.y = y;
	answer.type = t;
	answer.clue = c;
	answers.push_back(answer);
	

	emptyBoard(answer.x,answer.y,answer.word,answer.type);
	
}

//This function creates an empty board that is first displayed to 
//the user before any guesses are made. Provides a visual and 
//initial setup of the crossword puzzle.
void puzzle::emptyBoard()
{
	char row[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L'};
	string column[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};
	char Board[12][12];
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j <12; j++)
		{
			Board[i][j] = '*';
		}
	}
	cout<<"    ";
	for(int m = 0; m<12;m++)
	{
		cout<<column[m]<<" ";
	}
	cout<<endl;
	cout<<"    ";
	
	for(int r = 0; r<12; r++)
	{
		cout<<row[r]<<" ";
		for(int c = 0; c<12; c++)
		{
			cout<<Board[r][c]<<" ";
		}
		cout<<endl;
		cout<<"    ";
	}
	
}

//This function determines where the word is placed after the
//user has correctly guessed the word. By first looking at if 
//the word is across or down, the function then increases row/column index.
void puzzle::emptyBoard(int x, int y, string word, string type)
{
	int t = 0;
	char row[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L'};
	string column[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};
	char Board[12][12];
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j <12; j++)
		{
			if(i == x && j == y)
			{
				if(type == " a")
				{
					Board[x][y] = word[t];
					y++;
					t++;
				}
				else
				{
					Board[x][y] = word[t];
					x++;
					t++;
				}
			}
			else
			Board[i][j] = '*';
		}
	}
	cout<<"    ";
	for(int m = 0; m<12;m++)
	{
		cout<<column[m]<<" ";
	}
	cout<<endl;
	cout<<"    ";
	
	for(int r = 0; r<12; r++)
	{
		cout<<row[r]<<" ";
		for(int c = 0; c<12; c++)
		{
			cout<<Board[r][c]<<" ";
		}
		cout<<endl;
		cout<<"    ";
	}
	
}

