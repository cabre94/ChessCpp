/*
date: 21-12-2020
File: ChessBoard.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "ChessBoard.hpp"

ChessBoard::ChessBoard(char c) : typeDistribution(c){
    switch (c){
        case 'n':
            initializePieces();
            break;
        case 'b':
            initializePiecesButterfly();
            break;
        case 'p':
            initializePiecesPawnGame();
            break;
        case 'c':
            initializePiecesChampionMagician();
            break;
        default:
            std::cout << "invalid input" << std::endl;  //! Deberia tirar una excepcion
            exit(1);
    }
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

void ChessBoard::printSet(std::set<std::string> moveSet){
    for(auto it = moveSet.begin(); it!= moveSet.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
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
    gameEnded = false;

    whiteKingPos = "E1";
    blackKingPos = "E8";

    updatePiecesPositions();

    updateAllValidMoves();

    updateGameState();
}

void ChessBoard::initializePiecesButterfly(){
    for(int i=0; i < 8; ++i)
        for(int j=0; j < 8; ++j)
            pieces[i][j] = nullptr;
    // Agrego los peones con la distribucion mariposa
    pieces[1][0] = new Pawn(WHITE);
    pieces[2][1] = new Pawn(WHITE);
    pieces[3][2] = new Pawn(WHITE);
    pieces[4][3] = new Pawn(WHITE);
    pieces[4][4] = new Pawn(WHITE);
    pieces[3][5] = new Pawn(WHITE);
    pieces[2][6] = new Pawn(WHITE);
    pieces[1][7] = new Pawn(WHITE);

    pieces[6][0] = new Pawn(BLACK);
    pieces[5][1] = new Pawn(BLACK);
    pieces[4][2] = new Pawn(BLACK);
    pieces[3][3] = new Pawn(BLACK);
    pieces[3][4] = new Pawn(BLACK);
    pieces[4][5] = new Pawn(BLACK);
    pieces[5][6] = new Pawn(BLACK);
    pieces[6][7] = new Pawn(BLACK);
    

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
    gameEnded = false;

    whiteKingPos = "E1";
    blackKingPos = "E8";

    updatePiecesPositions();

    updateAllValidMoves();

    updateGameState();
}

void ChessBoard::initializePiecesPawnGame(){
    for(int i=0; i < 8; ++i)
        for(int j=0; j < 8; ++j)
            pieces[i][j] = nullptr;
    // Agrego los peones
    for(int j=0; j < 8; ++j){
        pieces[1][j] = new Pawn(WHITE);
        pieces[6][j] = new Pawn(BLACK);
    }

    // Agrego los peones extra para las blancas en esta distribucion
    pieces[2][1] = new Pawn(WHITE);
    pieces[2][2] = new Pawn(WHITE);
    pieces[2][5] = new Pawn(WHITE);
    pieces[2][6] = new Pawn(WHITE);

    pieces[3][2] = new Pawn(WHITE);
    pieces[3][3] = new Pawn(WHITE);
    pieces[3][4] = new Pawn(WHITE);
    pieces[3][5] = new Pawn(WHITE);

    // Agrego el resto de piezas blancas
    pieces[0][0] = new Rook(WHITE);
    pieces[0][1] = new Knight(WHITE);
    pieces[0][2] = new Bishop(WHITE);
    // pieces[0][3] = new Queen(WHITE);     // Saco la reina blanca
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
    gameEnded = false;

    whiteKingPos = "E1";
    blackKingPos = "E8";

    updatePiecesPositions();

    updateAllValidMoves();

    updateGameState();
}

void ChessBoard::initializePiecesChampionMagician(){
    for(int i=0; i < 8; ++i)
        for(int j=0; j < 8; ++j)
            pieces[i][j] = nullptr;
    // Agrego los peones
    for(int j=0; j < 8; ++j){
        pieces[1][j] = new Pawn(WHITE);
        pieces[6][j] = new Pawn(BLACK);
    }

    // Agrego el resto de piezas blancas
    pieces[0][0] = new Champion(WHITE);
    pieces[0][1] = new Magician(WHITE);
    pieces[0][2] = new Bishop(WHITE);
    pieces[0][3] = new Queen(WHITE);
    pieces[0][4] = new King(WHITE);
    pieces[0][5] = new Bishop(WHITE);
    pieces[0][6] = new Magician(WHITE);
    pieces[0][7] = new Champion(WHITE);

    // Agrego las piezas negras
    pieces[7][0] = new Champion(BLACK);
    pieces[7][1] = new Magician(BLACK);
    pieces[7][2] = new Bishop(BLACK);
    pieces[7][3] = new Queen(BLACK);
    pieces[7][4] = new King(BLACK);
    pieces[7][5] = new Bishop(BLACK);
    pieces[7][6] = new Magician(BLACK);
    pieces[7][7] = new Champion(BLACK);

    whiteTurn = true;
    gameEnded = false;

    whiteKingPos = "E1";
    blackKingPos = "E8";

    updatePiecesPositions();

    updateAllValidMoves();

    updateGameState();
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

void ChessBoard::printPosAndPieces(){

    std::cout << "White pieces:" << std::endl;

    for(auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
        std::cout << it->first << " " << it->second->getName() << " ";
    
    std::cout << std::endl << "Black pieces:" << std::endl;

    for(auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
        std::cout << it->first << " " << it->second->getName() << " ";
    
    std::cout << std::endl << std::endl;

}

bool ChessBoard::posInBoard(int i, int j){
    if( i>=0 && i<8 && j>=0 && j<8 )
        return true;
    return false;
}

bool ChessBoard::makeMove(std::string from, std::string to){

    if(whiteTurn)
        std::cout << "White turn..." << std::endl;
    else
        std::cout << "Black turn..." << std::endl;

    std::cout << "Choose piece: ";
    if(from.empty())
        std::cin >> from;
    else
        std::cout << from << std::endl;
    
    // Chequeamos que la pieza sea del color correcto
    int pieceExist;
    if(whiteTurn)
        pieceExist = whitePieces.count(from);
    else
        pieceExist = blackPieces.count(from);
    
    //! Esto deberia ser una excepcion
    // Chequeamos que la pieza sea del color correcto
    if(!pieceExist){
        std::cout << "No piece in " << from << std::endl;
        return false;
    }
    
    // Tomo las coordenas viejas
    int i = string2row(from);
    int j = string2column(from);
    

    // Tomo los lugares validos a los que se puede mover la pieza
    std::set<std::string> validMoves = pieces[i][j]->getPossibleMoves(this, from);

    if(validMoves.empty()){
        std::cout << "No available moves: ";
        return false;
    }

    std::cout << "Available moves: ";
    printSet(validMoves);

    std::cout << "Choose where to move it: ";
    if(to.empty())
        std::cin >> to;
    else
        std::cout << to << std::endl;

    //!Esto deberia arrojar una excepcion en vez de hacerlo a mano
    // Chequeamos si es una posiciones validas
    int validMove = validMoves.count(to);
    if(!validMove){
        std::cout << "Invalid Move" << std::endl;
        return false;
    }

    // Tomo las coordenadas nuevas
    int ni = string2row(to);
    int nj = string2column(to);

    if(pieces[ni][nj] != nullptr)
        delete pieces[ni][nj];
    
    pieces[ni][nj] = pieces[i][j];
    pieces[i][j] = nullptr;

    updatePiecesPositions();

    updateAllValidMoves();

    updateGameState();

    // Chequear si hay algun mate

    whiteTurn = !whiteTurn;

    return true;
}

std::set<std::string> ChessBoard::getValidMoves(std::string from, PieceType T){
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
        case CHAMPION:
            return getChampionMoves(from);
        case MAGICIAN:
            return getMagicianMoves(from);
        default:
            std::set<std::string> empty;
            return empty;
    }
}

std::set<std::string> ChessBoard::getPawnMoves(std::string from){
    std::set<std::string> pawnMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    int forward = 1;
    bool initialPos = false;

    if(c == BLACK){
        forward *= -1;
        if(row == 6)
            initialPos = true;
    }else if(row == 1)
        initialPos = true;
    
    // Si esta vacio, avanza
    if((row+forward >= 0 || row+forward < 8) && pieces[row+forward][col] == nullptr)
        pawnMoves.insert(pos2string(row+forward,col));
    
    // 
    if(initialPos && pieces[row+2*forward][col] == nullptr)
        pawnMoves.insert(pos2string(row+2*forward,col));
    
    // Por ultimo, chequeo si en la diagonal hay una pieza contraria que se pueda comer
    if(posInBoard(row+forward,col+1) && pieces[row+forward][col+1] != nullptr && pieces[row+forward][col+1]->getColour() != c)
        pawnMoves.insert(pos2string(row+forward,col+1));
    if(posInBoard(row+forward,col-1) && pieces[row+forward][col-1] != nullptr && pieces[row+forward][col-1]->getColour() != c)
        pawnMoves.insert(pos2string(row+forward,col-1));

    return pawnMoves;
}

std::set<std::string> ChessBoard::getRookMoves(std::string from){
    std::set<std::string> rookMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    // Arriba
    for(int i=row+1; i < 8; ++i){
        if(pieces[i][col] == nullptr)
            rookMoves.insert(pos2string(i,col));
        else if(pieces[i][col]->getColour() != c){
            rookMoves.insert(pos2string(i,col));
            break;
        }else
            break;
    }

    // Abajo
    for(int i=row-1; i >= 0; --i){
        if(pieces[i][col] == nullptr)
            rookMoves.insert(pos2string(i,col));
        else if(pieces[i][col]->getColour() != c){
            rookMoves.insert(pos2string(i,col));
            break;
        }else
            break;
    }

    // Derecha
    for(int i=col+1; i < 8; ++i){
        if(pieces[row][i] == nullptr)
            rookMoves.insert(pos2string(row,i));
        else if(pieces[row][i]->getColour() != c){
            rookMoves.insert(pos2string(row,i));
            break;
        }else
            break;
    }

    // Izquierda
    for(int i=col+1; i < 8; ++i){
        if(pieces[row][i] == nullptr)
            rookMoves.insert(pos2string(row,i));
        else if(pieces[row][i]->getColour() != c){
            rookMoves.insert(pos2string(row,i));
            break;
        }else
            break;
    }


    return rookMoves;
}

std::set<std::string> ChessBoard::getKnightMoves(std::string from){
    std::set<std::string> knightMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    for(int i=row-1; i<=row+1; i+=2){
        for(int j=col-2; j<=col+2; j+=4){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColour() != c) )
                knightMoves.insert(pos2string(i,j));
        }
    }
    for(int i=row-2; i<=row+2; i+=4){
        for(int j=col-1; j<=col+1; j+=2){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColour() != c) )
                knightMoves.insert(pos2string(i,j));
        }
    }

    return knightMoves;
}

std::set<std::string> ChessBoard::getBishopMoves(std::string from){
    std::set<std::string> bishopMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    // Arriba a la derecha
    for(int i=1; (row+i < 8) && (col+i < 8); ++i){
        if(pieces[row+i][col+i] == nullptr)
            bishopMoves.insert(pos2string(row+i,col+i));
        else if(pieces[row+i][col+i]->getColour() != c){
            bishopMoves.insert(pos2string(row+i,col+i));
            break;
        }else
            break;
    }

    // Abajo a la derecha
    for(int i=1; (row-i >= 0) && (col+i < 8); ++i){
        if(pieces[row-i][col+i] == nullptr)
            bishopMoves.insert(pos2string(row-i,col+i));
        else if(pieces[row-i][col+i]->getColour() != c){
            bishopMoves.insert(pos2string(row-i,col+i));
            break;
        }else
            break;
    }

    // Abajo a la izquierda
    for(int i=1; (row-i >= 0) && (col-i >= 0); ++i){
        if(pieces[row-i][col-i] == nullptr)
            bishopMoves.insert(pos2string(row-i,col-i));
        else if(pieces[row-i][col-i]->getColour() != c){
            bishopMoves.insert(pos2string(row-i,col-i));
            break;
        }else
            break;
    }

    // Arriba a la izquierda
    for(int i=1; (row+i < 8) && (col-i >= 0); ++i){
        if(pieces[row+i][col-i] == nullptr)
            bishopMoves.insert(pos2string(row+i,col-i));
        else if(pieces[row+i][col-i]->getColour() != c){
            bishopMoves.insert(pos2string(row+i,col-i));
            break;
        }else
            break;
    }

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
    std::set<std::string> oppositeMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    if(c == WHITE)
        oppositeMoves = allBlackMoves;
    else
        oppositeMoves = allBlackMoves;

    for(int i=-1; i <= 1; ++i){
        for(int j=-1; j <= 1; ++j){
            if(i == 0 && j == 0)
                continue;
            if  (posInBoard(row+i,col+j) && ((pieces[row+i][col+j] == nullptr) || (pieces[row+i][col+j]->getColour() != c) ) && !stringInSet(oppositeMoves, pos2string(row+i,col+j)) )
                kingMoves.insert(pos2string(row+i,col+j));
        }
    }

    return kingMoves;
}

std::set<std::string> ChessBoard::getChampionMoves(std::string from){
    std::set<std::string> championMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    // Movimientos de a dos
    for(int i=-2; i <= 2; i+=2){
        for(int j=-2; j <= 2; j+=2){
            if(i == 0 && j == 0)
                continue;
            if(posInBoard(row+i,col+j) && (pieces[row+i][col+j] == nullptr || pieces[row+i][col+j]->getColour() != c))
                championMoves.insert(pos2string(row+i,col+j));
        }
    }

    for(int i=-1; i <= 1; ++i){
        for(int j=-1; j <= 1; ++j){
            if(i == j || i == -j)
                continue;
            if(posInBoard(row+i,col+j) && (pieces[row+i][col+j] == nullptr || pieces[row+i][col+j]->getColour() != c))
                championMoves.insert(pos2string(row+i,col+j));
        }
    }

    return championMoves;
}

std::set<std::string> ChessBoard::getMagicianMoves(std::string from){
    std::set<std::string> magicianMoves;

    int row = string2row(from);
    int col = string2column(from);

    PieceColour c = pieces[row][col]->getColour();

    for(int i=row-1; i<=row+1; i+=2){
        for(int j=col-3; j<=col+3; j+=6){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColour() != c))
                magicianMoves.insert(pos2string(i,j));
        }
    }
    for(int i=row-3; i<=row+3; i+=6){
        for(int j=col-1; j<=col+1; j+=2){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColour() != c) )
                magicianMoves.insert(pos2string(i,j));
        }
    }

    return magicianMoves;
}

void ChessBoard::updateAllValidMoves(){
    allWhiteMoves.clear();
    allBlackMoves.clear();

    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr){    // ? Seria mejor un metodo que me diga si hay pieza?
                std::set<std::string> aux = pieces[i][j]->getPossibleMoves(this, pos2string(i,j));
                if(pieces[i][j]->getColour() == WHITE)
                    allWhiteMoves.insert(aux.begin(), aux.end());
                else
                    allBlackMoves.insert(aux.begin(), aux.end());
            }
        }
    }

}

void ChessBoard::updateGameState(){
    // bool whiteking = false, whiteking;
    whiteKingPos.clear();
    blackKingPos.clear();

    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr && pieces[i][j]->getType() == KING){
                if(pieces[i][j]->getColour() == WHITE)
                    whiteKingPos = pos2string(i,j);
                else
                    blackKingPos = pos2string(i,j);
            }
        }
    }

    if(whiteKingPos.empty() || blackKingPos.empty())
        gameEnded = true;
    else if(stringInSet(allWhiteMoves, blackKingPos))
        blackInCheck = true;
    else if(stringInSet(allBlackMoves, whiteKingPos))
        whiteInCheck = true;
    
}