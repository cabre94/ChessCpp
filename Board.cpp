/*
date: 28-11-2020
File: Board.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>

#include "Piece.cpp"
#include "Position.cpp"


class Board{
public:
    Board() {};	//Default constructor
    ~Board() {};
    Board(const Board &) = default;	//Copy constructor
    Board &operator=(const Board &) = default;	//Copy assignment
    Board(Board &&) = default;	//Move constructor
    Board &operator=(Board &&) = default;	// Move assignment

    virtual void printBoard() = 0;
    virtual void printPositions() = 0;
    // virtual int* string2pos(std::string str) = 0;

    virtual bool makeMove(std::string from, std::string to) = 0;

    virtual std::set<std::string> getValidMoves(std::string from, PieceType T) = 0;

protected:
    std::map<std::string, Piece*> whitePieces;
    std::map<std::string, Piece*> blackPieces;

    bool whiteTurn;


};

class ChessBoard : public Board{
public:
    ChessBoard();
    ~ChessBoard();

    void initializePieces();    //! privado
    void clearBoard();          //! privado

    // Funciones virtuales
    void printBoard();
    void printPositions();
    // int* string2pos(std::string str);

    bool makeMove(std::string from, std::string to);



private:

    bool posInBoard(int i, int j);

    std::string pos2string(int x, int y);
    int string2row(std::string str);
    int string2column(std::string str);
    // int SIZE = 8;
    void updatePiecesPositions();

    std::set<std::string> getValidMoves(std::string from, PieceType T);

    std::set<std::string> getPawnMoves(std::string from);
    std::set<std::string> getRookMoves(std::string from);
    std::set<std::string> getKnightMoves(std::string from);
    std::set<std::string> getBishopMoves(std::string from);
    std::set<std::string> getQueenMoves(std::string from);
    std::set<std::string> getKingMoves(std::string from);

    Piece* pieces[8][8];    //! No enteindo porque no puedo poner SIZE

};

ChessBoard::ChessBoard(){
    initializePieces();
}

ChessBoard::~ChessBoard(){
    clearBoard();
}

void ChessBoard::clearBoard(){
    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr){    // ? Seria mejor un metodo que me diga si hay pieza?
                delete pieces[i][j];
                pieces[i][j] = nullptr;
            }
        }
    }
}

void ChessBoard::initializePieces(){
    for(int i=0; i < 8; ++i)
        for(int j=0; j < 8; ++j)
            pieces[i][j] = nullptr;
    // Agrego los peones
    for(int j=0; j < 8; ++j){
        pieces[1][j] = new Pawn(WHITE);
        pieces[6][j] = new Pawn(BLACK);
    }

    // Agrego el resto de piezas blancas
    pieces[0][0] = new Rook(WHITE);
    pieces[0][1] = new Knight(WHITE);
    pieces[0][2] = new Bishop(WHITE);
    pieces[0][3] = new Queen(WHITE);
    pieces[0][4] = new King(WHITE);
    pieces[0][5] = new Bishop(WHITE);
    pieces[0][6] = new Knight(WHITE);
    pieces[0][7] = new Rook(WHITE);

    // Agrego las piezas negras
    pieces[7][0] = new Rook(BLACK);
    pieces[7][1] = new Knight(BLACK);
    pieces[7][2] = new Bishop(BLACK);
    pieces[7][3] = new Queen(BLACK);
    pieces[7][4] = new King(BLACK);
    pieces[7][5] = new Bishop(BLACK);
    pieces[7][6] = new Knight(BLACK);
    pieces[7][7] = new Rook(BLACK);

    whiteTurn = true;

    updatePiecesPositions();
    updatePiecesPositions();
}


void ChessBoard::printBoard(){
    std::cout << "  ";
    for(char c = 'A'; c <= 'H'; ++c)
        std::cout << " " << c << "  ";
    std::cout << std::endl;

    // ! Primera linea
    std::cout << " \u250C";
    for(int i = 7; i >=1; i--){
        std::cout << "\u2500\u2500\u2500\u252C";
    }
    std::cout << "\u2500\u2500\u2500\u2510" << std::endl;

    // ! Ahora las piezas
    for(int row = 8; row >= 1; --row){
        std::cout << row << "\u2502";
        for(int i = 0; i < 8; ++i){
            if(pieces[row-1][i] == nullptr)
                std::cout << "   \u2502";
            else{
                std::cout << " ";
                pieces[row-1][i]->printPiece();
                std::cout << " ";
                std::cout << "\u2502";
            }
            
        }
        std::cout << std::endl;

        //print the grid lines
        if(row>1) {
            std::cout << " \u251C";
            for (int i=7;i>=1;i--) {
	            std::cout << "\u2500\u2500\u2500\u253C";
            }
            std::cout << "\u2500\u2500\u2500\u2524" << std::endl;
        }
        // square = square -16;
    }

    // ! Uktima linea
    // print bottom
    std::cout << " \u2514";
    for (int i = 7; i>=1;i--) {
        std::cout << "\u2500\u2500\u2500\u2534";
    }
    std::cout << "\u2500\u2500\u2500\u2518" << std::endl;
}

std::string ChessBoard::pos2string(int x, int y){
    std::string str;
    str.resize(2);
    str[0] = char(y +'A');
    str[1] = char(x +'1');

    return str;
}

int ChessBoard::string2row(std::string str){
    return int(str[1] - '1');
}

int ChessBoard::string2column(std::string str){
    return int(str[0] - 'A');
}

void ChessBoard::updatePiecesPositions(){
    whitePieces.clear();
    blackPieces.clear();

    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr){
                PieceColour c = pieces[i][j]->getColour();
                std::string str = pos2string(i,j);
                if(c == WHITE)
                    whitePieces[str] = pieces[i][j];
                else
                    blackPieces[str] = pieces[i][j];
            }
        }
    }
}

void ChessBoard::printPositions(){

    std::cout << "White pieces:" << std::endl;

    for(auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
        std::cout << it->first << " " << it->second->getName() << " ";
    
    std::cout << std::endl << "Black pieces:" << std::endl;

    for(auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
        std::cout << it->first << " " << it->second->getName() << " ";
    
    std::cout << std::endl << std::endl;

}

bool posInBoard(int i, int j){
    if( i<0 || i>7 || j<0 || j>7 )
        return false;
    return true;
}


bool ChessBoard::makeMove(std::string from, std::string to){
    // TODO - Deberia chequear que la pieza es correcta (color y que haya pieza)
    // TODO - Dada la pieza, que el "to" este dentro de los lugares posibles
    // TODO - hacer el movimiento
    
    int pieceExist;
    // whitePieces.
    if(whiteTurn)
        pieceExist = whitePieces.count(from);
    else
        pieceExist = blackPieces.count(from);
    
    //! Esto deberia ser una excepcion
    if(!pieceExist){
        std::cout << "No piece in " << from << std::endl;
        return false;
    }
    
    int i = string2row(from);
    int j = string2column(from);
    int ni = string2row(to);
    int nj = string2column(to);

    // Piece* pieceFrom = pieces[i][j];
    // Piece* pieceTo = pieces[ni][nj];

    std::cout << from << std::endl;
    std::cout << to << std::endl;

    std::cout << i << std::endl;
    std::cout << j << std::endl;
    std::cout << ni << std::endl;
    std::cout << nj << std::endl;

    // ! Get valid move
    // std::map<std::string, Piece*> whitePieces;
    // std::set<std::string> possibleMoves = pieces[i][j];

    // if(pieceTo != nullptr)
    //     delete pieceTo;
    
    // pieceTo = pieceFrom;
    // pieceFrom = nullptr;

    if(pieces[ni][nj] != nullptr)
        delete pieces[ni][nj];
    
    pieces[ni][nj] = pieces[i][j];
    pieces[i][j] = nullptr;

    updatePiecesPositions();

    whiteTurn = !whiteTurn;

    return true;
}

std::set<std::string> getValidMoves(std::string from, PieceType T){
    switch (T){
        case PAWN:
            return getPawnMoves(from);
        case ROOK:
            return getRookMoves(from);
        case KNIGHT:
            return getKnightMoves(from);
        case BISHOP:
            return getBishopMoves(from);
        case QUEEN:
            return getQueenMoves(from);
        case KING:
            return getKingMoves(from);    
        default:
            break;
    }
}

std::set<std::string> ChessBoard::getPawnMoves(std::string from){
    std::set<std::string> pawnMoves;
    return pawnMoves;
}

std::set<std::string> ChessBoard::getRookMoves(std::string from){
    std::set<std::string> rookMoves;
    return rookMoves;
}

// ! Estoy asumiendo que en from hay una pieza
std::set<std::string> ChessBoard::getKnightMoves(std::string from){
    std::set<std::string> knightMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    for(int i=row-1; i<=row+1; i+=2){
        for(int j=col-2; j<=col+2; j+=4){
            //!Esto seguro explota
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColour() != c) )
                knightMoves.insert(pos2string(i,j));
        }
    }
    for(int i=row-2; i<=row+2; i+=4){
        for(int j=col-1; j<=col+1; j+=2){
            //!Esto seguro explota
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColour() != c) )
                knightMoves.insert(pos2string(i,j));
        }
    }

    return knightMoves;
}

std::set<std::string> ChessBoard::getBishopMoves(std::string from){
    std::set<std::string> bishopMoves;
    return bishopMoves;
}

std::set<std::string> ChessBoard::getQueenMoves(std::string from){
    std::set<std::string> queenMoves = getBishopMoves(from);
    std::set<std::string> rookMoves = getRookMoves(from);

    queenMoves.insert(rookMoves.begin(), rookMoves.end());

    return queenMoves;
}

std::set<std::string> ChessBoard::getKingMoves(std::string from){
    std::set<std::string> kingMoves;
    return kingMoves;
}








// class T1: public Board{
//     void print(){
//         for(int i=0; i < 5; ++i)
//             std::cout << matrix[i];
//         std::cout << std::endl;
//     }
// };

// class T2: public Board{
//     void print(){
//         for(int i=4; i >=0; --i)
//             std::cout << matrix[i];
//         std::cout << std::endl;
//     }
// };

/*
int main(int argc, const char** argv){
    
    Board* ptr;

    ptr = new T1;
    ptr->print();

    delete ptr;

    ptr = new T2;
    ptr->print();

    return 0;
}
*/