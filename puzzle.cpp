#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "puzzle.h"

using namespace std;
vector<puzz> answers;
vector<position> words;
position board[12][12];

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
	int o = 0;
	puzz answer;
	string place;
	answer.word = w;
	answer.x = setPos(x);
	answer.y = y;
	answer.type = t;
	answer.clue = c;
	answers.push_back(answer);

}

//This function loops through the vector of answers
//and adds the position and first char of each word
void puzzle::setCurrentBoard()
{
	position word;
	
	for(int i = 0; i < answers.size();i++)
	{
		word.n = answers[i].word[0];
		word.row = answers[i].x;
		word.col = answers[i].y;
		words.push_back(word);
	}

}

//This function creates an empty board that is first displayed to 
//the user before any guesses are made. Provides a visual and 
//initial setup of the crossword puzzle.
void puzzle::emptyBoard()
{
	char row[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L'};
	string column[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};

	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j <12; j++)
		{
			board[i][j].n = '*';
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
			cout<<board[r][c].n<<" ";
		}
		cout<<endl;
		cout<<"    ";
	}
	
}

//This is a getter that returns 
//the word at the given index #
string puzzle::getWord(int num)
{
	for(int t = 0; t < answers.size(); t++)
	{
		if(num == t)
		{
			words[t].guess = true;
			return answers[t].word;
		}
	}
}

//This function prints out the across and down
//clues for each word. Displays each clue by
//index of each word in vector answers
void puzzle::clues()
{
	cout<<endl;
	cout<<"Across Words:"<<endl;
	for(int h = 0; h < answers.size(); h++)
	{
		if(answers[h].type == " a")
		{
			cout<<"   "<<h<<answers[h].clue<<endl;
		}

	}
	cout<<endl;
	cout<< "Down Words:"<<endl;
	for(int i = 0; i < answers.size(); i++)
	{
		if(answers[i].type == " d")
		{
			cout<<"   "<<i<<answers[i].clue<<endl;
		}
	}
	cout<<endl;
}

//This function provides hints that help
//the user discover the answer. if the 
//user is still struggling after 3 attempts, function gives answer
void puzzle::hint(string correct,int num, int htry)
{
	int tot;
	for(int i = 0; i < correct.size(); i++)
	{
		tot += correct[i];
	}

	if(correct == answers[num].word && htry == 1)
	{
		cout << "The first letter is "<< correct[0]<<endl;
	}

	if(correct == answers[num].word && htry == 2)
	{
		cout << "There are a total of "<<tot<<" letters."<<endl;
	}

	if(correct == answers[num].word && htry == 3)
	{
		cout << "Ends with "<< correct[correct.length()-1]<<endl;
	}

	if(correct == answers[num].word && htry == 4)
	{
		cout << "The answer is: "<<correct<<endl;
	}
	
}

//This function encodes the clues to the 
//words in the puzzle
void puzzle::cipher()
{
	for(int i = 0; i < answers[i].clue.length(); i++)
	{
		if(answers[i].clue[i] == "a")
		answers[i].clue[i] = "o";
		else if (answers[i].clue[i] == "e")
		answers[i].clue[i] = "k";
	}
	
	cout<<endl;
	cout<<"Across Words:"<<endl;
	for(int h = 0; h < answers.size(); h++)
	{
		if(answers[h].type == " a")
		{
			cout<<"   "<<h<<answers[h].clue<<endl;
		}
	}
	cout<<endl;
	cout<< "Down Words:"<<endl;
	for(int i = 0; i < answers.size(); i++)
	{
		if(answers[i].type == " d")
		{
			cout<<"   "<<i<<answers[i].clue<<endl;
		}
	}
	cout<<endl;
	
}
//This function determines where the word is placed after the
//user has correctly guessed the word. By first looking at if 
//the word is across or down, the function then increases row/column index.
void puzzle::fillBoard(string correct, int num)
{
	int t = 0;
	position word;
	
	char row[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L'};
	string column[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};

	
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
						
			if(correct == answers[num].word)
			{
				int a = answers[num].x;
				int b = answers[num].y;
				//word.n = answers[num].word[0];
				//word.guess = true;

				if(answers[num].type == " a")
				{
					for(int z = 0; z < answers[num].word.length(); z++)
					{
						board[a][b].n = answers[num].word[z];
						b++;

					}
				}
				else
				{
					for(int u = 0; u < answers[num].word.length(); u++)
					{
						//board[words[num].row][words[num].col].n = answers[num].word[u];
						//words[num].row++;
						board[a][b].n = answers[num].word[u];
						a++;
					}
				}
			}

		}
	}
}

//This function prints out ALL currently
//and correctly guessed words onto the board
void puzzle::currentBoard(string correct)
{
	
	char row[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L'};
	string column[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};

	for(int i = 0; i < words.size(); i++)
	{
		if(words[i].guess == true)
		{
			board[words[i].row][words[i].col].n = words[i].n;
			//cout<<words[j].n<<endl;
			if(answers[i].type == " a")
			{
				for(int z = 0; z < answers[i].word.length(); z++)
				{
					board[words[i].row][words[i].col].n = answers[i].word[z];
					words[i].col++;

				}
			}
			else
			{
				for(int u = 0; u < answers[i].word.length(); u++)
				{
					board[words[i].row][words[i].col].n = answers[i].word[u];
					words[i].row++;
				}
			}
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
			cout<<board[r][c].n<<" ";
		}
		cout<<endl;
		cout<<"    ";
	}
	
	
}

//
//This function prints out total words on the board
//showing the end result after completing the puzzle
void puzzle::fullBoard()//int x, int y, string word, string type
{
	char row[] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L'};
	string column[] = {"0","1","2","3","4","5","6","7","8","9","10","11"};

	for(int i = 0; i < words.size(); i++)
	{

		board[words[i].row][words[i].col].n = words[i].n;
		//cout<<words[j].n<<endl;
		if(answers[i].type == " a")
		{
			for(int z = 0; z < answers[i].word.length(); z++)
			{
				board[words[i].row][words[i].col].n = answers[i].word[z];
				words[i].col++;

			}
		}
		else
		{
			for(int u = 0; u < answers[i].word.length(); u++)
			{
				board[words[i].row][words[i].col].n = answers[i].word[u];
				words[i].row++;
			}
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
			cout<<board[r][c].n<<" ";
		}
		cout<<endl;
		cout<<"    ";
	}
	
}

