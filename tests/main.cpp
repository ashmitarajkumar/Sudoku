#include "Sudoku.h"
#include <gtest/gtest.h>
#include <string>

int main(int argc, char** argv)
{
    if (argc > 1) {
        std::string ans, filename;
        Sudoku puzzle;

        std::cout << std::endl << "Enter puzzle text file (assumes file is in \"txt\" folder).";
        std::cout << std::endl << "Pressing <Enter> will run the file \"sudoku-test1.txt\".";
        std::cout << std::endl;
        std::getline(std::cin, filename);

        if (filename.empty()) {
            filename = "sudoku-test1.txt";
        }

        puzzle.loadFromFile("../txt/" + filename);

        std::cout << "\nPuzzle:\n\n";
        std::cout << puzzle;

        std::cout << std::endl;
        std::cout << "Solution:\n\n";

        clock_t startTime = clock();

        if (puzzle.solve()) {
            std::cout << puzzle << std::endl; // Print solved puzzle.
        } else {
            std::cout << "No Solution" << std::endl; // Indicate there is no solution.
        }

        clock_t endTime = clock();

        std::cout << "Time used: " << (endTime - startTime) / (double)CLOCKS_PER_SEC << " seconds."
                  << std::endl;
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}