#pragma once

#include <array>

class Solver{
private:
    // Indices of cell are defined
    int cells[9][9] = {{0, 1, 2, 9, 10, 11, 18, 19, 20}, {3, 4, 5, 12, 13, 14, 21, 22, 23},
                        {6, 7, 8, 15, 16, 17, 24, 25, 26}, {27, 28, 29, 36, 37, 38, 45, 46, 47}, 
                        {30, 31, 32, 39, 40, 41, 48, 49, 50}, {33, 34, 35, 42, 43, 44, 51, 52, 53}, 
                        {54, 55, 56, 63, 64, 65, 72, 73, 74}, {57, 58, 59, 66, 67, 68, 75, 76, 77}, 
                        {60, 61, 62, 69, 70, 71, 78, 79, 80}};  

public:
    std::array<int,81> solveBoard(std::array<int,81>);
    int findNextValue(std::array<int,81>, int);
   // std::array<int,81> toOneDArray(int[9][9]);

};

// Solves board and returns solved board array
std::array<int,81> Solver::solveBoard(std::array<int,81> initBoard){
    std::array<int,81> solvedBoard = initBoard;
    int i = 0;
    bool backtracking = false;
    while (i < 81){
        if (initBoard[i] == 0){
            // Stop backtracking if initial board has a blank value at index
            backtracking = false;  
            // Replace current value at index with the next valid int
            solvedBoard[i] = findNextValue(solvedBoard,i); 
        }
        if (solvedBoard[i] == 0) {
            // If no valid value is found, start backtracking
            backtracking = true; 
            --i;
        } else if (backtracking) {
            // Continue back tracking if init board of index is not 0
            --i; 
        } else{
            // Procede to next index if a valid value is found for current square
            ++i; 
        }
    }
    return solvedBoard;
};

// Find the next value from 1 to 9 that is valid for a square
int Solver::findNextValue(std::array<int,81> solvedBoard, int index){  
    // Initializes temp value as current int at index
    int tempValue = solvedBoard[index]; 
    solvedBoard[index] = 0; 

    // Finds index of the first value in the current row
    int firstRowValue = index - index % 9; 

    // Determines column current index is in
    int column = index % 9; 

    // Determines cell current index is in
    int rowBlock = index/27;
    int cellNumber = 3*rowBlock + (index % 9)/3; 
    while (tempValue < 9 && solvedBoard[index] == 0){
        // Increments temp value if previous value wasn't valid and is less than 9
        ++tempValue;  
        bool goodValue = true;
        int i = 0;
        while (i<9 && goodValue){
            // Checks if replacement value is valid at given index of row, column, and cell the checked value is conatined in
            if (solvedBoard[firstRowValue+i] != tempValue && solvedBoard[Solver::cells[cellNumber][i]] != tempValue && 
                solvedBoard[column+9*i] != tempValue){ 
                goodValue = true;
            } else{
                goodValue = false;
            }
            ++i;
        }
        if (goodValue == true){
            // Sets index of solved board to temp value if temp value is valid
            solvedBoard[index] = tempValue; 
        }
    }
    // Returns final value as 0 or temp value if a valid value was found
    return solvedBoard[index]; 
};
