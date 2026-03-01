#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include "Position.h"
#include "Move.h"
#include "Color.h"
#include "Pieces/Pieces.h"

class Board
{
    private:
        std::unique_ptr<Pieces> m_board[8][8];
    public:
        Board();
        ~Board() = default;
        Pieces* getPiece(const Position& position) const;
        void setPiece(const Position& position, std::unique_ptr<Pieces> piece);
        void movePiece(const Position& from, const Position& to);
        bool isInside(const Position& position) const;
        Position findKing(Color color) const;
        void print() const;
        bool isCheck(Color color) const;
        bool areKingsAdjacent() const;
        friend class CheckmateDetector;
        friend class MoveGenerator;
        friend class CheckDetector;
};

#endif