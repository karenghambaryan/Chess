#include "InputParser.h"

#include <iostream>
#include <sstream>

#include "Chess/Pieces/King.h"
#include "Chess/Pieces/Queen.h"
#include "Chess/Pieces/Rook.h"
#include "Chess/Pieces/Bishop.h"
#include "Chess/Pieces/Knight.h"
#include "Chess/Pieces/Pawn.h"

void InputParser::readPieces(Board& board)
{
    std::string line;

    while (true)
    {
        std::getline(std::cin, line);

        if (line == "END")
        {
            break;
        }

        if (line.empty())
        {
            continue;
        }

        std::istringstream iss(line);

        std::string colorStr;
        std::string typeStr;
        std::string square;

        iss >> colorStr >> typeStr >> square;

        if (colorStr.empty() || typeStr.empty() || square.empty())
        {
            std::cout << "Invalid input format\n";
            continue;
        }

        Position pos = parsePosition(square);

        if (!pos.isValid())
        {
            std::cout << "Invalid position\n";
            continue;
        }

        std::unique_ptr<Pieces> piece = createPiece(colorStr, typeStr);

        if (!piece)
        {
            std::cout << "Invalid piece type\n";
            continue;
        }

        board.setPiece(pos, std::move(piece));
    }
}

Position InputParser::parsePosition(const std::string& square)
{
    if (square.size() != 2)
        return Position{ -1, -1 };

    char file = square[0];   
    char rank = square[1];   

    int col = file - 'a';
    int row = 8 - (rank - '0');

    return Position{ row, col };
}

std::unique_ptr<Pieces> InputParser::createPiece(const std::string& colorStr,const std::string& typeStr)
{
    Color color;

    if (colorStr == "White")
    {
        color = Color::White;
    }
    else if (colorStr == "Black")
    {
        color = Color::Black;
    }
    else
    {
        return nullptr;
    }

    if (typeStr == "King")
    {
        return std::make_unique<King>(color);
    }
    if (typeStr == "Queen")
    {
        return std::make_unique<Queen>(color);
    }
    if (typeStr == "Rook")
    {
        return std::make_unique<Rook>(color);
    }
    if (typeStr == "Bishop")
    {
        return std::make_unique<Bishop>(color);
    }
    if (typeStr == "Knight")
    {
        return std::make_unique<Knight>(color);
    }
    if (typeStr == "Pawn")
    {
        return std::make_unique<Pawn>(color);
    }
    return nullptr;
}
