// CS3270 Vanderbilt University
// Prof. Roth
// Name: Breckinridge Stodghill
// VunetID: stodghbs
// email: breckinridge.s.stodghill@vanderbilt.edu
// Project 1
// Date: 02/15/2017


#include <string>
#include <iostream>
#include <fstream>
#include "Sudoku.h"

using namespace std;

/**
 * Default ctor
 * Initializes the grid to 0's
 */
Sudoku::Sudoku() {

    // fill the grid with 0's
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            grid[row][col] = 0;
        }
    }

}

/**
 *  Loads the sudoku board from a file
 *  Assumes the standard 9 by 9 height and width
 *
 * @param fileName
 */
void Sudoku::loadFromFile(std::string fileName) {

    string str;
    int x;
    ifstream file(fileName);

    // Do error checking here
   if (!file) {
        cout << "Unable to open file. Press enter to exit program.";
        getline(cin, str);  // consume existing line
        cin.get();  // get the key press
        exit(1);
    }




    if (file.is_open()){

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                file >> x;
                grid[row][col] = x;
            }
        }
    }


    file.close();

}

/**
 * Given a sudoku board, will check for unassigned values
 * and recursively backtrack to fill unassigned values with
 * values that abide by sudoku rules.
 *
 * @return
 */
bool Sudoku::solve() {

    int row, col;

    // if there are no more unnasigned values then done
    if (!nextUnassigned(row, col)){
        return true;
    }

    // for each number 1-9 try in current row, col
    for (int i = 1; i <= 9; i++){

        // if not in row, col, or grid
        if (notInRow(row, i) && notInCol(col, i) && notInGrid(row - row%3, col - col%3, i)){

            // try a number
            grid[row][col] = i;

            // recursive call on solve to see if it works
            if (solve()){
                return true;
            }

            // if not, reassign to 0
            grid[row][col] = 0;

        }

    }

    // no solution
    return false;

}

/**
 * Prints the Sudoku board in the format specified in the project folder
 */
void Sudoku::print() const {

    for (int row = 0; row < 9; row++){

        for (int col = 0; col < 9; col++){

            cout << grid[row][col] << " ";

            if (col == 2 || col == 5 ){
                cout << "| ";
            }

            if ((row == 2 || row == 5) && col == 8 ){
                cout << "\n------+-------+------" << endl;
            } else if (col == 8){
                cout << endl;
            }
        }
    }

}

/**
 * Tests each element in a sudoku grid for equallity
 * with a corresponding element in another sudoku grid
 * @param other
 * @return
 */
bool Sudoku::equals(const Sudoku &other) const {

    // check each element in the grids for equality.

    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
            if (grid[row][col] != other.grid[row][col]){
                return false;
            }
        }
    }

    return true;

}

/**
 *  Checks each column in the specified row for a number
 *
 * @return true if not in row
 * @return false if in row
 *
 */
bool Sudoku::notInRow(int row, int target) {

    for (int col = 0; col < 9; col++){

        if (grid[row][col] == target){
            return false;
        }

    }

    return true;

}

/**
 * Checks each row in the specified col for a number
 *
 * @return true if not in col
 * @return false if in col
 */
bool Sudoku::notInCol(int col, int target) {

    for (int row = 0; row < 9; row++){

        if (grid[row][col] == target){
            return false;
        }

    }

    return true;

}


/**
 * Checks a 3x3 box of the sudoku grid for a number
 *
 * @return true if num not in grid
 * @return false if num in grid
 */
bool Sudoku::notInGrid(int startRow, int startCol, int target) {
    // throw exception if start row or startCol + 3 > 9

    // check each row and col extending three boxes from startRow and Col for target
    // return true if in grid
    // return false if not

    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){

            if (grid[startRow + i][startCol + j] == target)
                return false;

        }

    }
    return true;


}

/**
 * Checks for next unnasigned value in the grid and sets
 * the reference to row and col to it.
 * @return true if an unassigned value exists
 * @return false if no unassigned values.
 */
bool Sudoku::nextUnassigned(int &row, int &col) {

    // check for unassigned values and return true or false
    // set the reference to row and col as the next unnassigned value

    for (row = 0; row < 9; row++){

        for (col = 0; col < 9; col++){

            if (grid[row][col] == 0)
                return true;

        }

    }

    return false;

}

