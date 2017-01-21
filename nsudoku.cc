#include "nsudoku.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

// Constructor
NSudoku:: NSudoku() 
{
    for (int column=0; column<9; column++) 
    {
	    for (int row=0; row<9; row++) 
	    {
		    board[row][column] = 0;
    	}
	}
} 
    
 //Utility Function
void NSudoku::load(const char* file)
{
    FILE *f;
	//Open file and read data
    f = fopen(file,"r");

    //For every cell
    for(int column = 0; column < 9; column++)
    {
        for(int row = 0; row < 9; row++)
        {
            // scan in the values from the opened data
            fscanf(f, "%d", &board[row][column]);
       }
    }
}
 
//Clear Values from all memory locations
void NSudoku::clear()
{
   for (int column=0; column<9; column++) 
    {
	    for (int row=0; row<9; row++) 
	    {
		    board[row][column] = 0;
	    }
	} 
}
    
//Accessor Function
int NSudoku::get_num(int row, int column)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 9 || column > 9)
    {
        cout << "Error: Cannot get invalid grid space at ";
         cout << "(" << row << "," << column << ")\n";
        return -1;
    }
    
    else
    {
        //Return value
        return board[row-1][column-1];
    }
}
    
//Mutator Function
void NSudoku::set_num(int row, int column, int value)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 9 || column > 9)
    {
         cout << "Error: Cannot set invalid grid space at ";
         cout << "(" << row << "," << column << ")\n";
        return;
    }
    
    //Number bounds check
    if (value < 0 || value > 9)
    {
         cout << "Error: Cannot set grid space at ";
         cout << "(" << row << "," << column << ")";
         cout << " to " << value;
        return;
    }
        
    else
    {
    	//set value
        board[row-1][column-1] = value;
    }
}
    
//Display Function
void NSudoku::print()
{
    // For each row draw horizontal lines between blocks
	for (int column=0; column<9; column++) 
	{
	    if (column % 3== 0) 
	    {
			 cout << "-------------------------------" <<  endl;
		}
		
		// For each column draw verical lines between blocks
		for (int row=0; row<9; row++) 
		{
			if (row % 3 == 0) 
			{
				 cout << "|";
			}
		
		    //Print value of block
		    if (board[row][column] != 0) {
				 cout << " " << board[row][column] << " ";
			} else {
				 cout << " . ";
			}
			
		}
		
		// Draw column at the end of board
		 cout << "|" <<  endl;
	}
	
	// Draw row at the end of board
	 cout << "-------------------------------" <<  endl;
    }
	
// Solve Function

bool NSudoku::solve(int row, int column)
{
	//Print out updated board
	cout << "\033[2J\033[1;1H";
	this->print();
	
	//Delay function for printing 
	usleep(100000);
    
    // If board is solved finish
    if (row == 9)
	{
		return 1;
	}
	
	//If cell has value solve next cell 
	if (board[row][column] != 0) 
	{
		if (column == 8)
		{	
			return solve(row + 1, 0);
		}
		
		return solve(row, column + 1);
	}
	
	//For integers 1 to 9
	for (int value = 1; value <= 9; value++) 
	{
		//If looks valid
		if (check(row, column, value)) 
		{
			//Make tentative assignment
			board[row][column] = value;
			
			//Start Again from beginning with next cell
			if (column == 8) 
			{
				if (solve(row + 1, 0))
				{
					return 1;
				}
			}
			else 
			{
				if (solve(row, column + 1))
				{	
					return 1;
				}	
			}
		}
	
	//If all numbers conflict start backtracking
	board[row][column] = 0;	
	}
	
	return 0;
} 
	
// Check to see if number is valid
bool NSudoku::check(int row, int column, int value)
{
    //Check rows and columns
    for (int check = 0; check < 9; check++) 
    {
		if (board[check][column] == value || board[row][check] == value)
		{
			return 0;
		}
			
	}
	
	//Check boxes
	int sRow = (row / 3) * 3;
	int sCol = (column / 3) * 3;
	
	for (int r = sRow; r < sRow + 3; r++) 
	{
		for (int c = sCol; c < sCol + 3; c++) 
		{
			if (board[r][c] == value)
			{
				return 0;
			}
		}
	}
	
	return 1;
} 
    
    
   