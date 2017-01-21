This Sudoku Solver solves 9x9, 16x16, 25x25 sudoku puzzles. 


Features include the following:
    -Takes in file name and determines size of grid
    -Stores file information
    -Solves Puzzle using backtracking solving algorithm
    -Displays progress of solving and final solution


Project Algorithm is as follows:
    -If there are no unassigned cells return true
    -If the current cell is solved, solve next cell
    -For digits from 1 to 9
        -If there is no conflict for digit at row, column, or box
            assign digit to cell and recursively try to fill in rest of grid
        -If recursion successful, return true
        -Otherwise remove digit and try another
    -If all digits have been tried and nothing worked, return false