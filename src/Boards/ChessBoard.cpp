#include "Boards/ChessBoard.h"
#include "Pieces/Bishop.h"
#include "Pieces/Champion.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Magician.h"
#include "Pieces/Pawn.h"
#include "Pieces/Queen.h"
#include "Pieces/Rook.h"
#include "Positions/Position.h"

namespace chess {

// ChessBoard::ChessBoard(uint16_t nRow_, uint16_t nCol_) : nRow(nRow_), nCol(nCol_) {
ChessBoard::ChessBoard() {

    // positions = new Piece*[nRow * nCol];

#if 0
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
#endif

    for (size_t r = 0; r < N_ROW; r++) {
        for (size_t c = 0; c < N_COL; c++) {
            pieces[r][c] = nullptr;
        }
    }
}

ChessBoard::~ChessBoard() {

    // clearBoard();
    // delete [] positions;
}

void ChessBoard::printBoard() const {
    Piece *piece;

    // TODO fix to use nRow and Ncol
    // TODO En toda la funcion los indices quedaron mezclados
    std::cout << "  ";
    for (char c = 'A'; c <= 'H'; ++c)
        std::cout << " " << c << "  ";
    std::cout << std::endl;

    // ! Primera linea
    std::cout << " \u250C";
    for (int i = N_COL; i > 1; i--) {
        std::cout << "\u2500\u2500\u2500\u252C";
    }
    std::cout << "\u2500\u2500\u2500\u2510" << std::endl;

    // ! Ahora las piezas
    for (uint32_t row = N_ROW; row >= 1; --row) {
        std::cout << row << "\u2502";

        for (uint32_t j = 0; j < N_COL; ++j) {
            piece = getPieceFromIdx(row - 1, j);

            if (piece == nullptr)
                std::cout << "   \u2502";
            else {
                std::cout << " ";
                piece->printPiece();
                std::cout << " ";
                std::cout << "\u2502";
            }
        }
        std::cout << std::endl;

        // print the grid lines
        if (row > 1) {
            std::cout << " \u251C";
            for (int i = N_COL; i > 1; i--) {
                std::cout << "\u2500\u2500\u2500\u253C";
            }
            std::cout << "\u2500\u2500\u2500\u2524" << std::endl;
        }
    }

    // ! Uktima linea
    // print bottom
    std::cout << " \u2514";
    for (int i = 7; i >= 1; i--) {
        std::cout << "\u2500\u2500\u2500\u2534";
    }
    std::cout << "\u2500\u2500\u2500\u2518" << std::endl;
}

std::set<Position> ChessBoard::getParallelMoves(const Position &pos,
                                                const PlayerID player_id) const {

    std::set<Position> moves;

    constexpr int32_t directions[4][2] = {
        {1, 0},  // Up
        {-1, 0}, // Down
        {0, 1},  // Right
        {0, -1}  // Left
    };

    // Get row and column of position (order of indexes are inverted on Position representation)
    uint32_t rr = pos[1];
    uint32_t cc = pos[0];

    for (const auto &dir : directions) {
        int32_t dc = dir[0], dr = dir[1];

        uint32_t c = cc + dc;
        uint32_t r = rr + dr;

        while (validIdxs(r, c)) {
            // Check if there is a piece on position of idxs (r,c)
            if (pieces[r][c] != nullptr) {
                // check if the piece belongs to an opponent
                if (pieces[r][c]->getPlayerID() != player_id) {
                    moves.insert(Position(r, c));
                }
                break; // Stop searching at this direction, as a piece is found
            }

            // There is no piece on current position, so we keep moving on this direction
            moves.insert(Position(r, c));

            c += dc;
            r += dr;
        }
    }

    return moves;
}

std::set<Position> ChessBoard::getDiagonalMoves(const Position &pos,
                                                const PlayerID player_id) const {
    std::set<Position> moves;

    constexpr int32_t directions[4][2] = {
        {1, 1},  // Up - Right
        {1, -1}, // Up - Left
        {-1, 1}, // Down - Right
        {-1, -1} // Down - Left
    };

    // Get row and column of position (order of indexes are inverted on Position representation)
    uint32_t rr = pos[1];
    uint32_t cc = pos[0];

    for (const auto &dir : directions) {
        int32_t dc = dir[0], dr = dir[1];

        uint32_t c = cc + dc;
        uint32_t r = rr + dr;

        while (validIdxs(r, c)) {
            // Check if there is a piece on position of idxs (r,c)
            if (pieces[r][c] != nullptr) {
                // check if the piece belongs to an opponent
                if (pieces[r][c]->getPlayerID() != player_id) {
                    moves.insert(Position(r, c));
                }
                break; // Stop searching at this direction, as a piece is found
            }

            // There is no piece on current position, so we keep moving on this direction
            moves.insert(Position(r, c));

            c += dc;
            r += dr;
        }
    }

    return moves;
}

// std::set<chess::Position> ChessBoard::getLShapeMoves(const Position &pos, const PlayerID
// player_id,
//                                                      const std::vector<uint16_t> &deltas) const {
std::set<chess::Position> ChessBoard::getLShapeMoves(const Position &pos, const PlayerID player_id,
                                                     const std::vector<uint16_t> &deltas) const {
    if (deltas.size() != 2) {
        throw std::invalid_argument("getLShapeMoves requiere exactamente dos valores en deltas.");
    }

    std::set<chess::Position> moves;

    int32_t rr = pos[1];
    int32_t cc = pos[0];

    int32_t drr = static_cast<int32_t>(deltas[1]);
    int32_t dcc = static_cast<int32_t>(deltas[0]);

    // Generamos las 8 posibles orientaciones del movimiento
    std::vector<std::array<int32_t, 2>> directions = {{drr, dcc},   {dcc, drr},  {-drr, dcc},
                                                      {-dcc, drr},  {drr, -dcc}, {dcc, -drr},
                                                      {-drr, -dcc}, {-dcc, -drr}};

    for (const auto &dir : directions) {
        int32_t dc = dir[0], dr = dir[1];

        uint32_t c = cc + dc;
        uint32_t r = rr + dr;

        if (validIdxs(r, c)) {
            if (pieces[r][c] == nullptr || pieces[r][c]->getPlayerID() != player_id)
                moves.insert(chess::Position(r, c));
        }
    }

    return moves;
}

std::set<Position> ChessBoard::getFordwardMoves(const Position &pos, const PlayerID player_id,
                                                std::vector<int16_t> forward_dir,
                                                bool first) const {

    std::set<chess::Position> moves;

    if (forward_dir.size() != 2)
        throw std::invalid_argument("getForwardMoves forward_dir size != 2");

    int32_t dr = static_cast<int32_t>(forward_dir[0]);
    int32_t dc = static_cast<int32_t>(forward_dir[1]);

    // Get row and column of current position
    uint32_t rr = pos[1];
    uint32_t cc = pos[0];

    // Forward movement (no capture)
    uint32_t max_steps = first ? 2 : 1;
    for (uint32_t step = 1; step <= max_steps; ++step) {
        uint32_t r = rr + step * dr;
        uint32_t c = cc + step * dc;

        if (!validIdxs(r, c) || pieces[r][c] != nullptr) {
            break; // Cant move forward
        }

        moves.insert(Position(r, c));
    }

    // Diagonal Captures
    constexpr int32_t diagonal_offsets[2] = {-1, 1}; // Relative diagonal movements

    for (const int32_t &offset : diagonal_offsets) {
        int32_t r = rr + dr;
        int32_t c = cc + offset; // Move to the left or right

        if (validIdxs(r, c) && pieces[r][c] != nullptr) {
            if (pieces[r][c]->getPlayerID() != player_id)
                moves.insert(Position(r, c)); // Only if there is an enemy piece
        }
    }

    // TODO: Might have to complex logic if forward direction is on diagonal

    return moves;
}

std::set<Position> ChessBoard::getAllDirectionMoves(const Position &pos,
                                                    const PlayerID player_id) const {
    std::set<Position> moves = getParallelMoves(pos, player_id);
    std::set<Position> diagonal_moves = getDiagonalMoves(pos, player_id);

    moves.insert(diagonal_moves.begin(), diagonal_moves.end());

    return moves;
}

bool ChessBoard::validIdxs(uint32_t r, uint32_t c) const { return r < N_ROW && c < N_COL; }

bool ChessBoard::validPos(const Position &pos) const { return validIdxs(pos[1], pos[0]); }

// Position ChessBoard::pos2string(int x, int y){
Position ChessBoard::idx2Pos(const uint32_t r, const uint32_t c) const {
    if (validIdxs(r, c))
        throw std::out_of_range("ChessBoard::idx2Pos: Invalid indexes");

    return Position(r, c);
}

////////////////////////////////////////////////////////////////

#if 0
void ChessBoard::createPices(const char c) {
    switch (c) {
        case 'n':
            initializePieces();
            break;
        // case 'b':
        //     initializePiecesButterfly();
        //     break;
        // case 'p':
        //     initializePiecesPawnGame();
        //     break;
        // case 'c':
        //     initializePiecesChampionMagician();
        //     break;
        default:
            std::cout << "invalid input" << std::endl; //! Deberia tirar una excepcion
            exit(1);
    }
}
#endif

#if 0
void ChessBoard::initializePieces() {

    // Aca asumo que el vector para esta inicializado y tiene los punteros a vector

    // Piezas blancas
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "A2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "B2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "C2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "D2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "E2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "F2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "G2"));
    all_pieces.at(WHITE)->push_back(new Pawn(WHITE, "H2"));

    all_pieces.at(WHITE)->push_back(new Rook(WHITE, "A1"));
    all_pieces.at(WHITE)->push_back(new Knight(WHITE, "B1"));
    all_pieces.at(WHITE)->push_back(new Bishop(WHITE, "C1"));
    all_pieces.at(WHITE)->push_back(new Queen(WHITE, "D1"));
    all_pieces.at(WHITE)->push_back(new King(WHITE, "E1"));
    all_pieces.at(WHITE)->push_back(new Bishop(WHITE, "F1"));
    all_pieces.at(WHITE)->push_back(new Knight(WHITE, "G1"));
    all_pieces.at(WHITE)->push_back(new Rook(WHITE, "H1"));

    // Piezas negras
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "A7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "B7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "C7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "D7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "E7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "F7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "G7"));
    all_pieces.at(BLACK)->push_back(new Pawn(BLACK, "H7"));

    all_pieces.at(BLACK)->push_back(new Rook(BLACK, "A8"));
    all_pieces.at(BLACK)->push_back(new Knight(BLACK, "B8"));
    all_pieces.at(BLACK)->push_back(new Bishop(BLACK, "C8"));
    all_pieces.at(BLACK)->push_back(new Queen(BLACK, "D8"));
    all_pieces.at(BLACK)->push_back(new King(BLACK, "E8"));
    all_pieces.at(BLACK)->push_back(new Bishop(BLACK, "F8"));
    all_pieces.at(BLACK)->push_back(new Knight(BLACK, "G8"));
    all_pieces.at(BLACK)->push_back(new Rook(BLACK, "H8"));

    // whiteTurn = true;
    // gameEnded = false;

    // whiteKingPos = "E1";
    // blackKingPos = "E8";

    // updatePiecesPositions();

    // updateAllValidMoves();

    // updateGameState();

}
#endif

#if 0
void ChessBoard::clearBoard() {

    // for(int i=0; i < 8; ++i){
    //     for(int j=0; j < 8; ++j){
    //         if(pieces[i][j] != nullptr){    // ? Seria mejor un metodo que me diga si hay pieza?
    //             delete pieces[i][j];
    //             pieces[i][j] = nullptr;
    //         }
    //     }
    // }
}
#endif

#if 0
void ChessBoard::printSet(std::set<Position> moveSet) {
    (void) moveSet;

    for (auto it = moveSet.begin(); it != moveSet.end(); ++it)
        std::cout << it->str() << " ";
    std::cout << std::endl;
}
#endif

// TODO: Borrar
#if 0
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
#endif

#if 0
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
#endif

#if 0
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
#endif

#if 0
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
#endif

Piece *ChessBoard::getPieceFromIdx(const uint32_t i, const uint32_t j) const {
    (void) i;
    (void) j;

#if 0
	Position pos = idx2Position(i, j);

    for (size_t i = 0; i < all_pieces.size(); ++i) {
        for (size_t j = 0; j < all_pieces[i]->size(); ++j) {
            Position piece_pos = all_pieces.at(i)->at(j)->getPosition();

            if (pos == piece_pos)
                return all_pieces.at(i)->at(j);
        }
    }

#endif
    return nullptr;
}

#if 0
void ChessBoard::updatePiecesPositions(){
    whitePieces.clear();
    blackPieces.clear();

    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr){
                PieceColor c = pieces[i][j]->getColor();
                Position str = pos2string(i,j);
                if(c == WHITE)
                    whitePieces[str] = pieces[i][j];
                else
                    blackPieces[str] = pieces[i][j];
            }
        }
    }
}
#endif

#if 0
void ChessBoard::printPosAndPieces() const {
    std::cout << "White pieces:" << std::endl;

    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
        std::cout << it->first << " " << it->second->getName() << " ";

    std::cout << std::endl << "Black pieces:" << std::endl;

    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
        std::cout << it->first << " " << it->second->getName() << " ";

    std::cout << std::endl << std::endl;
}
#endif

#if 0
bool ChessBoard::makeMove(Position from, Position to) {
    (void) from;
    (void) to;
	
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
    std::set<Position> validMoves = pieces[i][j]->getPossibleMoves(this, from);

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
#endif

#if 0
std::set<Position> ChessBoard::getPawnMoves(Position from) {
	(void) from;
    std::set<Position> pawnMoves;

    #if 0

    int row = string2row(from);
    int col = string2column(from);

    PieceColor c = pieces[row][col]->getColor();

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
    if(posInBoard(row+forward,col+1) && pieces[row+forward][col+1] != nullptr && pieces[row+forward][col+1]->getColor() != c)
        pawnMoves.insert(pos2string(row+forward,col+1));
    if(posInBoard(row+forward,col-1) && pieces[row+forward][col-1] != nullptr && pieces[row+forward][col-1]->getColor() != c)
        pawnMoves.insert(pos2string(row+forward,col-1));

    #endif

    return pawnMoves;
}


std::set<Position> ChessBoard::getKnightMoves(Position from) {
	(void) from;
    std::set<Position> knightMoves;

    #if 0

    int row = string2row(from);
    int col = string2column(from);

    PieceColor c = pieces[row][col]->getColor();

    for(int i=row-1; i<=row+1; i+=2){
        for(int j=col-2; j<=col+2; j+=4){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColor() != c) )
                knightMoves.insert(pos2string(i,j));
        }
    }
    for(int i=row-2; i<=row+2; i+=4){
        for(int j=col-1; j<=col+1; j+=2){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColor() != c) )
                knightMoves.insert(pos2string(i,j));
        }
    }

    #endif

    return knightMoves;
}



std::set<Position> ChessBoard::getKingMoves(Position from) {
	(void) from;
    std::set<Position> kingMoves;
    std::set<Position> oppositeMoves;	// oponente TODO

    #if 0


    int row = string2row(from);
    int col = string2column(from);

    PieceColor c = pieces[row][col]->getColor();

    if(c == WHITE)
        oppositeMoves = allBlackMoves;
    else
        oppositeMoves = allBlackMoves;

    for(int i=-1; i <= 1; ++i){
        for(int j=-1; j <= 1; ++j){
            if(i == 0 && j == 0)
                continue;
            if  (posInBoard(row+i,col+j) && ((pieces[row+i][col+j] == nullptr) || (pieces[row+i][col+j]->getColor() != c) ) && !stringInSet(oppositeMoves, pos2string(row+i,col+j)) )
                kingMoves.insert(pos2string(row+i,col+j));
        }
    }

    #endif

    return kingMoves;
}

std::set<Position> ChessBoard::getChampionMoves(Position from) {
	(void) from;
    std::set<Position> championMoves;

    #if 0

    int row = string2row(from);
    int col = string2column(from);

    PieceColor c = pieces[row][col]->getColor();

    // Movimientos de a dos
    for(int i=-2; i <= 2; i+=2){
        for(int j=-2; j <= 2; j+=2){
            if(i == 0 && j == 0)
                continue;
            if(posInBoard(row+i,col+j) && (pieces[row+i][col+j] == nullptr || pieces[row+i][col+j]->getColor() != c))
                championMoves.insert(pos2string(row+i,col+j));
        }
    }

    for(int i=-1; i <= 1; ++i){
        for(int j=-1; j <= 1; ++j){
            if(i == j || i == -j)
                continue;
            if(posInBoard(row+i,col+j) && (pieces[row+i][col+j] == nullptr || pieces[row+i][col+j]->getColor() != c))
                championMoves.insert(pos2string(row+i,col+j));
        }
    }

    #endif

    return championMoves;
}

std::set<Position> ChessBoard::getMagicianMoves(Position from) {
	(void) from;
    std::set<Position> magicianMoves;

    #if 0

    int row = string2row(from);
    int col = string2column(from);

    PieceColor c = pieces[row][col]->getColor();

    for(int i=row-1; i<=row+1; i+=2){
        for(int j=col-3; j<=col+3; j+=6){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColor() != c))
                magicianMoves.insert(pos2string(i,j));
        }
    }
    for(int i=row-3; i<=row+3; i+=6){
        for(int j=col-1; j<=col+1; j+=2){
            if(posInBoard(i,j) && (pieces[i][j] == nullptr || pieces[i][j]->getColor() != c) )
                magicianMoves.insert(pos2string(i,j));
        }
    }

    #endif

    return magicianMoves;
}
#endif

#if 0
void ChessBoard::updateAllValidMoves(){
    allWhiteMoves.clear();
    allBlackMoves.clear();

    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr){    // ? Seria mejor un metodo que me diga si hay pieza?
                std::set<Position> aux = pieces[i][j]->getPossibleMoves(this, pos2string(i,j));
                if(pieces[i][j]->getColor() == WHITE)
                    allWhiteMoves.insert(aux.begin(), aux.end());
                else
                    allBlackMoves.insert(aux.begin(), aux.end());
            }
        }
    }

}
#endif

#if 0
void ChessBoard::updateGameState(){
    // bool whiteking = false, whiteking;
    whiteKingPos.clear();
    blackKingPos.clear();

    for(int i=0; i < 8; ++i){
        for(int j=0; j < 8; ++j){
            if(pieces[i][j] != nullptr && pieces[i][j]->getType() == KING){
                if(pieces[i][j]->getColor() == WHITE)
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
#endif

} // namespace chess