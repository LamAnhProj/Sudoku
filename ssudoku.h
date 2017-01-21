#ifndef SSUDOKU_H
#define SSUDOKU_H

#include "ssudoku.h"
#include <iostream>
#include <fstream>
#include <string>


class SSudoku
{
public:
    
    // Constructor
    SSudoku();
    
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
	
	//check if value is valid
	bool check(int row, int column, int value);
    

private:
    //Clear board
    void clear();
    int board[16][16];
    
};

#endif