#include "Board.hpp"

int main () {

    // Declaration of board
    std::array<int,81> boardContents = {0, 3, 0, 7, 0, 8, 4, 0, 0,  
                                        0, 0, 0, 4, 0, 1, 0, 5, 8, 
                                        0, 0, 1, 5, 0, 0, 0, 0, 0, 
                                        0, 0, 8, 0, 0, 0, 0, 0, 9,
                                        0, 1, 0, 0, 0, 2, 0, 0, 0,
                                        0, 6, 9, 3, 0, 7, 1, 0, 0,
                                        0, 0, 0, 0, 7, 0, 0, 1, 4,
                                        1, 8, 0, 2, 0, 0, 0, 9, 0,
                                        0, 2, 0, 1, 6, 5, 0, 0, 3};
    
    //prints initial board
    printBoard(boardContents); 
    std::cout << "\n";

    // Creates new board object
    Board board(boardContents); 

    // Prints solved board
    printBoard(board.solvedBoard); 

    return 0;
}