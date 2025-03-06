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

TEST(chessCpp, test_Positions) {
    static const uint32_t PLAYER_ID = 0xB0CA;
    static const chess::Position expected_pos = "A1";

    const chess::Bishop bishop(PLAYER_ID, expected_pos);

    ASSERT_EQ(bishop.getPlayerID(), PLAYER_ID);
    ASSERT_EQ(bishop.getName(), "BISHOP");
    ASSERT_EQ(bishop.getPosition(), expected_pos);
}