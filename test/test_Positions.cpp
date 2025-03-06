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

static std::string toLower(const std::string &str) {
    std::string lowerStr = str; // Copiar el string original
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

TEST(chessCpp, test_Positions) {

    char c[] = "A1";
    std::string str = "A1";
    std::string str_lower;

    for (char row = '1'; row <= '8'; row++) {
        for (char col = 'A'; col <= 'H'; col++) {

            // Update expected values
            c[0] = col;
            c[1] = row;
            str[0] = col;
            str[1] = row;
            str_lower = toLower(str);

            // Create Position with std::string
            const chess::Position pos_str(str);

            // Check indexes
            ASSERT_EQ(pos_str[0], col - 'A');
            ASSERT_EQ(pos_str[1], row - '1');
            ASSERT_EQ(pos_str.str(), str_lower);

            // Create Position with const char*
            const chess::Position pos_c(c);

            // Check indexes
            ASSERT_EQ(pos_c[0], col - 'A');
            ASSERT_EQ(pos_c[1], row - '1');
            ASSERT_EQ(pos_c.str(), str_lower);

            ASSERT_TRUE(pos_str == pos_c);
            ASSERT_FALSE(pos_str != pos_c);
            ASSERT_FALSE(pos_str < pos_c);
            ASSERT_FALSE(pos_c < pos_str);
        }
    }
}