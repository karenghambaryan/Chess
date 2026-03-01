#include "InputParser.h"

#include <iostream>
#include <sstream>

#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"

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

        if (!(iss >> colorStr >> typeStr >> square))
        {
            std::cout << "Ինչ-որ բան սխալ է;\n";
            continue;
        }

        Position pos = parsePosition(square);

        if (!pos.isValid())
        {
            continue;
        }

        std::unique_ptr<Pieces> piece = createPiece(colorStr, typeStr);

        if (!piece)
        {
            std::cout << "տառասխալ։ հետևեք օրինակին\n";
            continue;
        }

        Pieces* existingPiece = board.getPiece(pos);
        if (existingPiece)
        {
            std::cout << "կա այստեղ " << square << " արդեն խաղաքար\n";
            continue;
        }

        board.setPiece(pos, std::move(piece));
    }
}

Position InputParser::parsePosition(const std::string& square)
{
    if (square.size() != 2)
    {
        std::cout << "սխալ։ օգտագործեք այսպես 'a1', 'h8'.\n";
        return Position{ -1, -1 };
    }

    char file = square[0];   
    char rank = square[1];   

    if (file < 'a' || file > 'h' || rank < '1' || rank > '8')
    {
        std::cout << "սխալ։ հնարավոր տեղեր 1-8 և a-h\n";
        return Position{ -1, -1 };
    }

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
