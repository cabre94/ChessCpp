#include <gtest/gtest.h>

#include <algorithm>
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

TEST(Positions, CreationAndParams) {

    char c[] = "A1";
    std::string str = "A1";
    std::string str_lower;
    std::array<uint32_t, 2> idx = {0, 0};

    for (char row = '1'; row <= '8'; row++) {
        for (char col = 'A'; col <= 'H'; col++) {

            // Update expected values
            c[0] = col;
            c[1] = row;
            str[0] = col;
            str[1] = row;
            idx[0] = (uint32_t) col - 'A';
            idx[1] = (uint32_t) row - '1';
            str_lower = toLower(str);

            // ------- std::string constructor -------
            const chess::Position pos_str(str);

            // Check indexes
            ASSERT_EQ(pos_str[0], idx[0]);
            ASSERT_EQ(pos_str[1], idx[1]);
            ASSERT_EQ(pos_str.str(), str_lower);

            // ------- const char* constructor -------
            const chess::Position pos_c(c);

            // Check indexes
            ASSERT_EQ(pos_c[0], idx[0]);
            ASSERT_EQ(pos_c[1], idx[1]);
            ASSERT_EQ(pos_c.str(), str_lower);

            // ------- Indexes constructor -------
            const chess::Position pos_idx(idx[1], idx[0]);

            // Check indexes
            ASSERT_EQ(pos_idx[0], idx[0]);
            ASSERT_EQ(pos_idx[1], idx[1]);
            ASSERT_EQ(pos_idx.str(), str_lower);

            // ------- Check comparison operator -------
            ASSERT_TRUE(pos_str == pos_c);   // operator ==
            ASSERT_TRUE(pos_c == pos_idx);   // operator ==
            ASSERT_TRUE(pos_idx == pos_str); // operator ==

            ASSERT_FALSE(pos_str != pos_c);   // operator !=
            ASSERT_FALSE(pos_c != pos_idx);   // operator !=
            ASSERT_FALSE(pos_idx != pos_str); // operator !=

            ASSERT_FALSE(pos_str < pos_c);   // operator <
            ASSERT_FALSE(pos_c < pos_idx);   // operator <
            ASSERT_FALSE(pos_idx < pos_str); // operator <

            ASSERT_FALSE(pos_str > pos_c);   // operator >
            ASSERT_FALSE(pos_c > pos_idx);   // operator >
            ASSERT_FALSE(pos_idx > pos_str); // operator >
        }
    }
}