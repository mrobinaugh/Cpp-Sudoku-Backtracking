#pragma once
#include "Solver.hpp"
#include "Square.hpp"

#include <iostream>

class Board : public Solver, public Square{
public:
    std::array<int,81> initBoard;
    std::array<int,81> solvedBoard;

    Board(std::array<int,81>);
    void printBoard(std::array<int,81>);
    
};

Board::Board(std::array<int,81> boardContents){
    // Board array is generated for object
    initBoard = boardContents; 

    // A solution the the board is found
    solvedBoard = solveBoard(initBoard); 

    Square square0(); Square square1(); Square square2();
    Square square3(); Square square4(); Square square5();
    Square square6(); Square square7(); Square square8();
    Square square9(); Square square10(); Square square11();
    Square square12(); Square square13(); Square square14();
    Square square15(); Square square16(); Square square17();   
    Square square18(); Square square19(); Square square20();
    Square square21(); Square square22(); Square square23();
    Square square24(); Square square25(); Square square26();
    Square square27(); Square square28(); Square square29();
    Square square30(); Square square31(); Square square32();
    Square square33(); Square square34(); Square square35(); 
    Square square36(); Square square37(); Square square38(); 
    Square square39(); Square square40(); Square square41(); 
    Square square42(); Square square43(); Square square44(); 
    Square square45(); Square square46(); Square square47(); 
    Square square48(); Square square49(); Square square50(); 
    Square square51(); Square square52(); Square square53(); 
    Square square54(); Square square55(); Square square56(); 
    Square square57(); Square square58(); Square square59(); 
    Square square60(); Square square61(); Square square62(); 
    Square square63(); Square square64(); Square square65(); 
    Square square66(); Square square67(); Square square68(); 
    Square square69(); Square square70(); Square square71(); 
    Square square72(); Square square73(); Square square74(); 
    Square square75(); Square square76(); Square square77(); 
    Square square78(); Square square79(); Square square80();
    

};

// Prints board in readable format
void printBoard(std::array<int,81> board){  
    // Loops through each index of the board
    for (int i=0; i<81; ++i){ 
        // Prints int at the end of a group of rows and the line seperating each cell block
        if (((i+1)%27) == 0 && (i+1) != 81) {
            std::cout << board[i] << "\n" << "- - - - - - - - - - -" << "\n"; 
        }
        // Prints int at the end of a row and returns a new line
        else if((i+1)%9 == 0) {
            std::cout << board[i] << "\n"; 
        }
        // Prints int at the end of a column block and a pipe seperating the next column
        else if (((i+1)%3) == 0){
            std::cout << board[i] << " " << "|" << " ";  
        }
        // Prints int if no other condition is met
        else{
            std::cout << board[i] << " "; 
        } 
    }
};

