#include "tsudoku.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constructor
 TSudoku::TSudoku() 
{
    for (int column=0; column<25; column++) 
    {
	    for (int row=0; row<25; row++) 
	    {
		    board[row][column] = 0;
    	}
	}
} 
    
 //Utility Function
void  TSudoku::load(const char* file)
{
    FILE *f;
    
    // Open File and Read data
    f = fopen(file,"r"); 
    
    //for every cell
    for(int column = 0; column < 25; column++)
    {
        for(int row = 0; row < 25; row++)
        {
            /* scan in the values from the opened data */
            fscanf(f, "%d", &board[row][column]);
        }
    }
}    
 
  //clear values from all memory locations  
void  TSudoku::clear()
{
   for (int column=0; column<25; column++) 
    {
	    for (int row=0; row<25; row++) 
	    {
		    board[row][column] = 0;
	    }
	} 
}
    
//Accessor Function
int  TSudoku::get_num(int row, int column)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 25 || column > 25)
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
void  TSudoku::set_num(int row, int column, int value)
{
    //Bounds check
    if(row < 1 || column < 1 || row > 25 || column > 25)
    {
         cout << "Error: Cannot set invalid grid space at ";
         cout << "(" << row << "," << column << ")\n";
        return;
    }
    
    //Number bounds check
    if (value < 0 || value > 25)
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
void  TSudoku::print()
{
    // For each row draw horizontal lines between blocks
	for (int column=0; column<25; column++) 
	{
	    if (column % 5== 0) 
	    {
			 cout << "---------------------------------------------------------------------------------" <<  endl;
		}
		
		// For each column draw verical lines between blocks
		for (int row=0; row<25; row++) 
		{
			if (row % 5 == 0) 
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
				 
				 // Switch double digit numbers to letters for cleaner look
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
                		case 17:
                			cout << " H ";
                			break;
                		case 18:
                			cout << " I ";
                			break;
                		case 19:
                			cout << " J ";
                			break;
                		case 20:
                			cout << " K ";
                			break;
                		case 21:
                			cout << " L ";
                			break;
                		case 22:
                			cout << " M ";
                			break;
                		case 23:
                			cout << " N ";
                			break;
                		case 24:
                			cout << " O ";
                			break;
                		case 25:
                			cout << " P ";
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
	 cout << "---------------------------------------------------------------------------------" <<  endl;
    }
	
// Solve Function

bool  TSudoku::solve(int row, int column)
{
	//if board is solved, finish
    if (row == 25)
	{
		return 1;
	}
	
	//if cell has value solve next cell
	if (board[row][column] != 0) 
	{
		if (column == 24)
		{	
			return solve(row + 1, 0);
		}
		
		return solve(row, column + 1);
	}
	
	//for integers 1 to 25
	for (int value = 1; value <= 25; value++) 
	{
		//if looks valid
		if (check(row, column, value)) 
		{
			//make tentative assignment
			board[row][column] = value;
			
			//start again from beginning with next step
			if (column == 24) 
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
	//if all numbers conflict start backtracking
	board[row][column] = 0;
	
	return 0;
} 
	
// Check to see if number is valid
bool  TSudoku::check(int row, int column, int value)
{
	//check rows and columns
    for (int check = 0; check < 25; check++) 
    {
		if (board[check][column] == value || board[row][check] == value)
		{
			return 0;
		}
			
	}
	
	//check boxes
	int sRow = (row / 5) * 5;
	int sCol = (column / 5) * 5;
	
	for (int r = sRow; r < sRow + 5; r++) 
	{
		for (int c = sCol; c < sCol + 5; c++) 
		{
			if (board[r][c] == value)
			{
				return 0;
			}
		}
	}
	
	return 1;
} 