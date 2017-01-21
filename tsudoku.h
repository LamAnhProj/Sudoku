#ifndef TSUDOKU_H
#define TSUDOKU_H

#include "tsudoku.h"
#include <iostream>
#include <fstream>
#include <string>


class TSudoku
{
public:
    
    // Constructor
    TSudoku();
    
    //Utility Functions
    void load(const char* file);
    
    //Accessor Function
    int get_num(int row, int column);
    
    //Mutator Function
    void set_num(int row, int column, int value);
    
    //Display Function
    void print();

    // Solve Functions
	bool solve(int row, int column);
	
	//Check if value is valid
	bool check(int row, int column, int value);
    

private:
    //Clear board
    void clear();
    int board[25][25];
};

#endif