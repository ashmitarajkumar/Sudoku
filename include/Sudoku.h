// File name: Sudoku.h
// Author: Ashmita Rajkumar
// VUnetid: rajkua1
// Email: ashmita.rajkumar@vanderbilt.edu
// Class: CS3270
// Date: March 4, 2021
// Honor statement: All work completed below is my own original work.
// Assignment Number: Project 1
// Description: These methods declare the Sudoku class

#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>

class Sudoku {
public:
    Sudoku(); // constructor
    void loadFromFile(std::string filename);
    bool solve();
    bool equals(const Sudoku& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku);

private:
    static const int SIZE = 9;
    int grid[SIZE][SIZE];
    bool placement[SIZE][SIZE];
    bool puzzleSolver(int row1, int col1);
    bool isValid(int value, int row, int column) const;
};
#endif // PROJECT1_SUDOKU_H