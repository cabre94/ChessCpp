/*
date: 28-11-2020
File: Board.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

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


class Board{
public:
    int matrix[5] = {1,2,3,4,5};
    
// public:
    Board() {} ;	//Default constructor
    ~Board() {};
    Board(const Board &) = default;	//Copy constructor
    Board &operator=(const Board &) = default;	//Copy assignment
    Board(Board &&) = default;	//Move constructor
    Board &operator=(Board &&) = default;	// Move assignment

    virtual void print() = 0;
private:

};

class ChessBoard : public Board{
public:
    ChessBoard();
    ~ChessBoard();

    void initializePieces();

    void print();


    // void print(){
    //     for(int i=0; i < 5; ++i)
    //         std::cout << matrix[i];
    //     std::cout << std::endl;
    // }

private:
    // int SIZE = 8;

    Piece* pieces[8][8];    //! No enteindo porque no puedo poner SIZE

};

ChessBoard::ChessBoard(){
    initializePieces();
}

ChessBoard::~ChessBoard(){
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


}

/*
void ChessBoard::print(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(pieces[i][j] == nullptr)
                std::cout << '-';
            else
                // std::cout << 'P';
                pieces[i][j]->printPiece();
        }
        std::cout << std::endl;
    }
}
*/

void ChessBoard::print(){
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