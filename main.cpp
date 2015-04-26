#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include "puzzle.h"

using namespace std;




int main()
{
	
	
	string line,hold,word,clue,type,x;
	int y;
	ifstream file;
	puzzle *cross = new puzzle();
	file.open("Hclues.txt");
	

	
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
	

	
	
	
	
	

	
	return 0;
}



