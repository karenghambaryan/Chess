#include <iostream>
#include <memory>
#include "Core/Board.h"
#include "Parser/InputParser.h"
#include "Logic/CheckDetector.h"
#include "Logic/CheckmateDetector.h"

int main()
{
    Board board;
    std::cout << "Գրիր խաղաքարի տեղը (օրինակ: White King h4)\n";
    std::cout << "Գրիր END ավարտելու համար\n\n";
    InputParser::readPieces(board);
    std::cout << "\nBoard:\n";
    board.print();

    if(board.areKingsAdjacent())
    {
        std::cout << "Սխալ Դիրք: Արքաները կպած են իրար!\n";
        return 1;
    }

    std::cout << "\n";

    if (CheckDetector::isCheck(board, Color::White))
    {
        std::cout << "Սպիտակ Արքան շախի տակ է \n";
    }

    if (CheckDetector::isCheck(board, Color::Black))
    {
        std::cout << "Սև Արքան շախի տակ է \n";
    }
    if (CheckmateDetector::isCheckmate(board, Color::White))
    {
        std::cout << "Մատ։Սևերը հաղթեցին\n";
    }

    if (CheckmateDetector::isCheckmate(board, Color::Black))
    {
        std::cout << "Մատ։Սպիտակները հաղթեցին\n";
    }

    if (CheckmateDetector::isCheckmateInOneMove(board, Color::White))
    {
        std::cout << "Սպիտակները կարող են մատ անել մեկ քայլով\n";
    }

    if (CheckmateDetector::isCheckmateInOneMove(board, Color::Black))
    {
        std::cout << "Սևերը կարող են մատ անել մեկ քայլով\n";
    }

    if (CheckmateDetector::isCheckmateInTwoMoves(board, Color::White))
    {
        std::cout << "Սպիտակները կարող են մատ անել երկու քայլով\n";
    }

    if (CheckmateDetector::isCheckmateInTwoMoves(board, Color::Black))
    {
        std::cout << "Սևերը կարող են մատ անել երկու քայլով\n";
    }

    return 0;
}