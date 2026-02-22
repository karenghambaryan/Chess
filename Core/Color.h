#ifndef COLOR_H
#define COLOR_H

enum class Color
{
    White,
    Black
};

inline Color opposite(Color c) // Inline փօքր ֆունկցի առանց cpp
{
    if(c == Color::White)
    {
        return Color::Black;
    }
    else
    {
        return Color::White;
    }
    
}

#endif