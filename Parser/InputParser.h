#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>
#include <memory>
#include "Core/Board.h"

class Pieces;

class InputParser
{
public:
    static void readPieces(Board& board);

private:
    static Position parsePosition(const std::string& square);

    static std::unique_ptr<Pieces> createPiece(const std::string& colorStr,const std::string& typeStr);
};
//ինչի static որ classiny լինի այլ ոչ objecty
#endif