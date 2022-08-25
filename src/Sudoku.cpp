// File name: Sudoku.cpp
// Author: Ashmita Rajkumar
// VUnetid: rajkua1
// Email: ashmita.rajkumar@vanderbilt.edu
// Class: CS3270
// Date: March 4, 2021
// Honor statement: All work completed below is my own original work.
// Assignment Number: Project 1
// Description: These methods define the Sudoku class

#include "Sudoku.h"
#include <fstream>
#include <iostream>

/**
 * Returns constructed sudoku object that is empty.
 *
 * @param  no parameters.
 * @return Sudoku object that is constructed.
 */
Sudoku::Sudoku()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = 0;
            placement[i][j] = false;
        }
    }
}

/**
 * Returns nothing is returned here.
 *
 * @param  string containing file name to read in.
 * @return no return, sudoku board is loaded in. .
 */
void Sudoku::loadFromFile(std::string filename)
{

    std::ifstream fileReader;
    fileReader.open(filename.c_str(), std::ifstream::in); // Open file for input.
    if (fileReader.fail()) {
        std::cout << "Could not read input.";
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fileReader >> grid[i][j];
            if (grid[i][j] != 0) {
                placement[i][j] = true;
            } else {
                placement[i][j] = false;
            }
        }
    }
    fileReader.close();
}

/**
 * Returns the ostream object.
 *
 * @param  ostream object .
 * @param  Sudoku board
 * @return ostream object returned while printing out contents of board.
 */
std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku)
{
    std::string printOut;
    for (int i = 0; i < sudoku.SIZE; i++) {
        for (int j = 0; j < sudoku.SIZE; j++) {
            if (j % 3 == 2 && j != 8) {
                printOut = " | ";
            } else {
                printOut = " ";
            }
            if (sudoku.grid[i][j] == 0) {
                out << " " << printOut;
            } else {
                out << sudoku.grid[i][j] << printOut;
            }
        }
        out << std::endl;
        if (i % 3 == 2 && i != 8) {
            out << "------+-------+------" << std::endl;
        }
    }
    return out;
}

/**
 * Returns boolean value depending on if boards are equal or not.
 *
 * @param  other sudoku board to compare with.
 * @return boolean value depending on if they are true or not.
 */
bool Sudoku::equals(const Sudoku& other) const
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] != other.grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Returns boolean object depending on if they are .
 *
 * @param  no parameters passed in.
 * @return boolean depending on if it is solvable or not.
 */
bool Sudoku::solve()
{
    return puzzleSolver(0, 0);
}

/**
 * Returns the ostream object.
 *
 * @param  row to recurse on .
 * @param  column to recurse on
 * @return boolean value depending on if solvable or not.
 */
bool Sudoku::puzzleSolver(int row1, int col1)
{
    if (row1 == SIZE) {
        return true;
    }
    if (col1 == SIZE) {
        return puzzleSolver(row1 + 1, 0);
    }
    if (!placement[row1][col1]) {
        for (int i = 1; i <= SIZE; i++) {
            if (isValid(i, row1, col1)) {
                grid[row1][col1] = i;
                if (puzzleSolver(row1, col1 + 1)) {
                    return true;
                }
            }
        }
        grid[row1][col1] = 0;
    } else {
        if (puzzleSolver(row1, col1 + 1)) {
            return true;
        }
    }
    return false;
}

/**
 * Returns boolean depending on if the position is valid for the value.
 *
 * @param  value to check validity for .
 * @param  row to recurse on .
 * @param  column to recurse on
 * @return boolean value depending on if the position is valid w relation to other numbers.
 */
bool Sudoku::isValid(int value, int row, int column) const
{
    for (int i = 0; i < SIZE; i++) {
        if (i != row) {
            if (grid[i][column] == value) {
                return false;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (i != column) {
            if (grid[row][i] == value) {
                return false;
            }
        }
    }
    int newRow = row - (row % 3);

    int newCol = column - (column % 3);

    for (int i = newRow; i < newRow + 3; i++) {

        for (int j = newCol; j < newCol + 3; j++) {

            if (!(i == row && j == column)) {

                if (grid[i][j] == value) {
                    return false;
                }
            }
        }
    }
    return true;
}