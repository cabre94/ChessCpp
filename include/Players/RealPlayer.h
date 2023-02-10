#ifndef REALPLAYER_H
#define REALPLAYER_H

#include "Player.h"

class RealPlayer : public Player{
public:
	RealPlayer(PlayerID player_id_) : Player(player_id_) {}
	~RealPlayer(){}

	void dummy() const override;
};

#endif // REALPLAYER_H