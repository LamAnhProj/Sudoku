#include "nsudoku.h"
#include "ssudoku.h"
#include "tsudoku.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <cstdlib>
using namespace std;

//Function to count words in string
unsigned int countWordsInString(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

int main()
{
    NSudoku board1;
    SSudoku board2;
    TSudoku board3;
    
    cout<<"Welcome to Sudoku Solver!!"<<endl;
    cout<< "What is the name of your file?" <<endl;
    
    string filename;
    
    // Get the first line from the standard input stream.
    getline(cin, filename);
    
    // Open filename as a file
    ifstream file;
    file.open(filename.c_str(), fstream::in | fstream::out);
    
    // Get the first line from the file
    string buffer;
    getline(file, buffer);
    
    // count characters in string
    unsigned int count = countWordsInString(buffer);
    
    //close file and open in class
    file.close();
    
    //print grid size
    cout<< "The grid size is " <<count<<"x"<<count<<endl;
    
   	//for a 9x9 board
   	if(count==9)	
    {
    	//Get file info
    	board1.load(filename.c_str());
		
    	// Print the board before solving.
		board1.print();
	
		cout << endl;
	
		// Solve board
		if (board1.solve(0,0)) 
		{
	
	  		//If the board is solvable 
	  		cout << "Here is the solution:" << endl;
	  		board1.print();
		} 
	
		else 
		{
			//If the board is not solvable
			cout << "Puzzle is not solvable.";
		}
	
		cout << endl;
	
		// Exit normally
    	return 0;
	}
	
	if(count==16)	
    {
    	//Get file info
    	board2.load(filename.c_str());
    	
    	// Print the board before solving.
		board2.print();
	
		cout << endl;
	
		// Solve board
		if (board2.solve(0,0)) 
		{
			//If the board is solvable 
	  		cout << "Here is the solution:" << endl;
	  		board2.print();
		} 
	
		else 
		{
			//If the board is not solvable 
			cout << "Puzzle is not solvable.";
		}
	
		cout << endl;
	
		// Exit normally
    	return 0;
	}
	
	if(count==25)	
    {
    	//Get file info
    	board3.load(filename.c_str());
    	
    	// Print the board before solving.
		board3.print();
	
		std::cout << std::endl;
	
		// Solve board
		if (board3.solve(0,0)) 
		{
			//If the board is solvable 
	  		cout << "Here is the solution:" << endl;
	  		board3.print();
		} 
	
		else 
		{
			//If the board is solvable 
			cout << "Puzzle is not solvable.";
		}
	
		cout << endl;
	
		// Exit normally
    	return 0;
	}
}
	