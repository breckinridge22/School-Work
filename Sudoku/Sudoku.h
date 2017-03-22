// CS3270 Vanderbilt University
// Prof. Roth
// Name: Breckinridge Stodghill
// VunetID: stodghbs
// email: breckinridge.s.stodghill@vanderbilt.edu
// Project 1
// Date: 02/15/2017

#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <string>

class Sudoku {

private:

    int grid [9][9];

    bool notInRow(int row, int num);

    bool notInCol(int col, int num);

    bool notInGrid(int startRow, int startCol, int num);

    //bool isNumSafe(int row, int col, int num);

    bool nextUnassigned(int &row, int &col);

public:

    Sudoku();

    void loadFromFile(std::string fileName);

    bool solve();

    void print() const;

    bool equals(const Sudoku &other) const;

};


#endif //SUDOKU_SUDOKU_H
