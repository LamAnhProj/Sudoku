#include "ssudoku.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

// Constructor
SSudoku:: SSudoku() 
{
    for (int column=0; column<16; column++) 
    {
	    for (int row=0; row<16; row++) 
	    {
		    board[row][column] = 0;
    	}
	}
} 
    
 //Utility Function
void SSudoku::load(const char* file)
{
    FILE *f;
    
    // read in data to get puzzle
    f = fopen(file,"r"); 
    
    //far all cells
    for(int column = 0; column < 16; column++)
    {
        for(int row = 0; row < 16; row++)
        {
            /* scan in the values from the opened data */
            fscanf(f, "%d", &board[row][column]);
        }
    }
}    
 
//clear values from all memory locations    
void SSudoku::clear()
{
   for (int column=0; column<16; column++) 
    {
	    for (int row=0; row<16; row++) 
	    {
		    board[row][column] = 0;
	    }
	} 
}
    
//Accessor Function
int SSudoku::get_num(int row, int column)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 16 || column > 16)
    {
        cout << "Error: Cannot get invalid grid space at ";
         cout << "(" << row << "," << column << ")\n";
        return -1;
    }
    
    else
    {
    	//return value
        return board[row-1][column-1];
    }
}
    
//Mutator Function
void SSudoku::set_num(int row, int column, int value)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 16 || column > 16)
    {
         cout << "Error: Cannot set invalid grid space at ";
         cout << "(" << row << "," << column << ")\n";
        return;
    }
    
    //Number bounds check
    if (value < 0 || value > 16)
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
void SSudoku::print()
{
    // For each row draw horizontal lines between blocks
	for (int column=0; column<16; column++) 
	{
	    if (column % 4== 0) 
	    {
			 cout << "-----------------------------------------------------" <<  endl;
		}
		
		// For each column draw verical lines between blocks
		for (int row=0; row<16; row++) 
		{
			if (row % 4 == 0) 
			{
				 cout << "|";
			}
		
		    //Print value of block
		    if (board[row][column] != 0) 
		    {
				 if(board[row][column]<10)
				 {
				 	cout << " " << board[row][column] << " ";
				 }
				 
				 //Print letters if double digit for cleaner look
				 else
				 {
           			switch(board[row][column])
           			{
            			case 10:
                			cout << " A ";
                			break;
            			case 11:
                			cout << " B ";
                			break;
            			case 12:
                			cout << " C ";
                			break;
            			case 13:
                			cout << " D ";
                			break;
                		case 14:
                			cout << " E ";
                			break;
                		case 15:
                			cout << " F ";
                			break;
                		case 16:
                			cout << " G ";
                			break;
            			default:
                			break;
                	}
				 }
			} 
			
			else 
			{
				 cout << " . ";
			}
			
		}
		
		// Draw column at the end of board
		 cout << "|" <<  endl;
	}
	
	// Draw row at the end of board
	 cout << "-----------------------------------------------------" <<  endl;
    }
	
// Solve Function

bool SSudoku::solve(int row, int column)
{
	//print updated board
	cout << "\033[2J\033[1;1H";
	this->print();
	
	//delay function for printing
	usleep(100000/4);
    
    //If board is solved finish
    if (row == 16)
	{
		return 1;
	}
	
	//if cell has value solve next cell
	if (board[row][column] != 0) 
	{
		if (column == 15)
		{	
			return solve(row + 1, 0);
		}
		
		return solve(row, column + 1);
	}
	
	//for integers 1 to 16
	for (int value = 1; value <= 16; value++) 
	{
		//if looks valid
		if (check(row, column, value)) 
		{
			
			//make tentative assignment
			board[row][column] = value;
			
			//start again from beginning with the next cell
			if (column == 15) 
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
	}
	
	//If all numbers conflict start backtracking
	board[row][column] = 0;
	
	return 0;
} 
	
// Check to see if number is valid
bool SSudoku::check(int row, int column, int value)
{
    //Check rows and columns
    for (int check = 0; check < 16; check++) 
    {
		if (board[check][column] == value || board[row][check] == value)
		{
			return 0;
		}
			
	}
	
	//check boxes
	int sRow = (row / 4) * 4;
	int sCol = (column / 4) * 4;
	
	for (int r = sRow; r < sRow + 4; r++) 
	{
		for (int c = sCol; c < sCol + 4; c++) 
		{
			if (board[r][c] == value)
			{
				return 0;
			}
		}
	}
	
	return 1;
} 