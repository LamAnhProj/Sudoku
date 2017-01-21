CCC = g++
CCFLAGS = -ansi

sudoku: nsudoku.o ssudoku.o driver.o tsudoku.o 
	$(CCC) -o sudoku nsudoku.o ssudoku.o driver.o tsudoku.o 

nsudoku.o: nsudoku.h

tsudoku.o: tsudoku.h

ssudoku.o: ssudoku.h

clean:
	rm -f *.o

real_clean: clean
	rm -f sudoku