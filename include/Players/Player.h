#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "Piece.h"
#include "Types.h"


class Player{
public:
	Player(PlayerID player_id_) : player_id(player_id_){}
	virtual ~Player();

	std::vector<Piece*>& getPieces(){return pieces;}

	virtual void dummy() const = 0;

protected:

	const PlayerID player_id;

	std::vector<Piece*> pieces;

};


#endif // PLAYER_H