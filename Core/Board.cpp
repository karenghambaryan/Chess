#include "Board.h"
#include "Pieces/Pieces.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include <iostream>
#include <cmath>

Board::Board()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            m_board[row][col] = nullptr;
        }
    }
}
Pieces* Board::getPiece(const Position& position) const
{
    if(isInside(position))
    {
        return m_board[position.row][position.col].get();
    }
    else
    {
        return nullptr;
    }
}
void Board::setPiece(const Position& position,std::unique_ptr<Pieces> piece)
{
    if(isInside(position))
    {
        m_board[position.row][position.col] = std::move(piece);
    }
}
void Board::movePiece(const Position& from, const Position& to)
{
    if(isInside(from) && isInside(to))
    {
        m_board[to.row][to.col] = std::move(m_board[from.row][from.col]);
    }
}
void Board::handlePawnPromotion(const Position& position)
{
    if(!isInside(position))
    {
        return;
    }
    Pieces* piece = m_board[position.row][position.col].get();
    if(!piece)
    {
        return;
    }
    if(piece->getSymbol() == 'P' || piece->getSymbol() == 'p')
    {
        Color color = piece->getColor();
        if((color == Color::White && position.row == 0) || 
           (color == Color::Black && position.row == 7))
        {
            m_board[position.row][position.col] = std::make_unique<Queen>(color);
        }
    }
}
bool Board::isInside(const Position& position) const
{
    if( position.row >= 0 && position.row < 8 && position.col >= 0 && position.col < 8)
    {
        return true;
    }
    return false;
}
Position Board::findKing(Color color) const
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            Pieces* piece = m_board[row][col].get();
            if(piece && piece->getColor() == color)
            {
                if(piece->getSymbol() == 'K' || piece->getSymbol() == 'k')
                {
                    return Position{row,col};
                }
            }
        }
    }
    return Position {-1,-1};
}
void Board::print() const
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (m_board[row][col])
            {
                std::cout << m_board[row][col]->getSymbol() << " ";
            }
            else
            {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

bool Board::areKingsAdjacent() const
{
    Position whiteKing = findKing(Color::White);
    Position blackKing = findKing(Color::Black);
    
    if(whiteKing.row == -1 || blackKing.row == -1)
    {
        return false;
    }
    int rowDiff = std::abs(whiteKing.row - blackKing.row);
    int colDiff = std::abs(whiteKing.col - blackKing.col);
    if (rowDiff <= 1 && colDiff <= 1)
    {
        if (rowDiff == 0 && colDiff == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}