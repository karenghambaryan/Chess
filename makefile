CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

TARGET = chess

SRC = main.cpp \
    Core/Board.cpp \
    Logic/CheckDetector.cpp \
    Logic/CheckmateDetector.cpp \
    Logic/MoveGenerator.cpp \
    Parser/InputParser.cpp \
    Pieces/Bishop.cpp \
    Pieces/King.cpp \
    Pieces/Knight.cpp \
    Pieces/Pawn.cpp \
    Pieces/Queen.cpp \
    Pieces/Rook.cpp

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)