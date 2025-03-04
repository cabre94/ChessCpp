#include <gtest/gtest.h>

#include <cstdint>
#include <string>

#include "Pieces/Bishop.h"
// #include "Champion.h"
// #include "King.h"
// #include "Knight.h"
// #include "Magician.h"
// #include "Pawn.h"
// #include "Queen.h"
// #include "Rook.h"

TEST(chessCpp, test_Pieces) {
    static const uint32_t PLAYER_ID = 0xB0CA;
    static const chess::Position expected_pos = "A1";

    const chess::Bishop bishop(PLAYER_ID, expected_pos);

    ASSERT_EQ(bishop.getPlayerID(), PLAYER_ID);
    ASSERT_EQ(bishop.getName(), "BISHOP");
    ASSERT_EQ(bishop.getPosition(), expected_pos);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();	// TODO: check if neccesary
}