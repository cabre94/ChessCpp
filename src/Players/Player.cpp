#include "Player.h"

Player::~Player(){
	Piece* piece;

	while(!pieces.empty()){
		piece = pieces.back();
		pieces.pop_back();
		delete piece;
	}
}