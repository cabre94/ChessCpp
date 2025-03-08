#include <gtest/gtest.h>

#include <cstdint>
#include <string>

#include "Pieces/Bishop.h"
#include "Positions/Position.h"
// #include "Champion.h"
// #include "King.h"
// #include "Knight.h"
// #include "Magician.h"
// #include "Pawn.h"
// #include "Queen.h"
// #include "Rook.h"

TEST(Pieces, Getters) {
    static const chess::PlayerID player_id = chess::WHITE;
    static const chess::Position expected_pos = "A1";

    const chess::Bishop bishop(player_id, expected_pos);

    ASSERT_EQ(bishop.getPlayerID(), player_id);
    ASSERT_EQ(bishop.getName(), "BISHOP");
    ASSERT_EQ(bishop.getPosition(), expected_pos);
}