#pragma once

#include <cctype>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <tuple>


// todo: Other dimentions?

namespace chess {

class Position {
public:
    // Constructor explícito para evitar conversiones implícitas
    explicit Position(std::string pos) {
        // Normalizar a minúsculas
        if (pos.size() != 2) {
            throw std::invalid_argument("Invalid chess position: " + pos);
        }

        pos[0] = std::tolower(pos[0]); // Normalizar columna a minúscula
        pos[1] = std::tolower(pos[1]); // Aunque los números no cambian, es seguro hacerlo

        if (!formatAndCheckValid(pos)) {
            throw std::invalid_argument("Invalid chess position: " + pos);
        }

        row_idx = pos[0] - 'a'; // 'a' -> 0, ..., 'h' -> 7
        col_idx = pos[1] - '1'; // '1' -> 0, ..., '8' -> 7
        pos = pos;
    }

    Position(const char pos[3]) : Position(std::string(pos)) {}

    // Position(int row, int col) {
    //     if (row < 0 || row > 7 || col < 0 || col > 7) {
    //         throw std::out_of_range("Indices must be in range [0, 7]");
    //     }

    //     row_idx = row;
    //     col_idx = col;
    //     pos = std::string(1, 'a' + row) + std::string(1, '1' + col); // Convertir a notación
    //     estándar
    // }

    // Get position as string
    const std::string &str() const { return pos; }

    // Get position as index
    int getRowIdx() const { return row_idx; }
    int getColumnIdx() const { return col_idx; }

    //
    bool operator==(const Position &other) const {
        return row_idx == other.row_idx && col_idx == other.col_idx;
    }
    bool operator!=(const Position &other) const { return !(*this == other); }

	bool operator<(const Position& other) const {
		return std::tie(row_idx, col_idx) < std::tie(other.row_idx, other.col_idx);
	}

private:
    std::string pos;
    int row_idx, col_idx;

    // method to check if a position is valid
    static bool formatAndCheckValid(const std::string &pos) {
        if (pos.size() != 2)
            return false;

        char file = pos[0]; // Letra de la columna ('a' - 'h')
        char rank = pos[1]; // Número de la fila ('1' - '8')

        return (file >= 'a' && file <= 'h') && (rank >= '1' && rank <= '8');
    }
};

// Enum class para restringir PlayerID
// enum class PlayerID : uint8_t { WHITE = 0, BLACK = 1 };

using PlayerID = uint32_t;

constexpr PlayerID WHITE = 0;
constexpr PlayerID BLACK = 1;

} // namespace chess
