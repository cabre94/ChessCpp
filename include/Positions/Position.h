#pragma once

#include <array>
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
    explicit Position(std::string pos_) {
        // Normalizar a minúsculas
        if (pos_.size() != 2) {
            throw std::invalid_argument("Invalid chess position: " + pos);
        }

        pos_[0] = (char) std::tolower(pos_[0]); // Normalizar columna a minúscula
        pos_[1] = (char) std::tolower(pos_[1]); // Aunque los números no cambian, es seguro hacerlo

        if (!formatAndCheckValid(pos_)) {
            throw std::invalid_argument("Invalid chess position: " + pos);
        }

        idx = {(uint32_t) pos_[0] - 'a', (uint32_t) pos_[1] - '1'};
        pos = pos_;
    }

    // TODO: Should be explicit too?
    Position(const char pos_[3]) : Position(std::string(pos_)) {}

    // Constructor a partir de índices de fila y columna
    Position(uint32_t row, uint32_t col) {
        // Assume that indexes are already checked
        // if (row > 7 || col > 7)
        //     throw std::out_of_range("Invalid indices for chess position");

        idx = {col, row};
        pos.resize(2);
        pos[0] = (char) 'a' + idx[0];
        pos[1] = (char) '1' + idx[1];
    }

    // Get position as string
    const std::string &str() const { return pos; }

    // Get position as index
    uint32_t operator[](size_t i) const { return idx.at(i); }
    bool operator==(const Position &other) const { return idx == other.idx && pos == other.pos; }
    bool operator!=(const Position &other) const { return !(*this == other); }
    bool operator<(const Position &other) const { return idx < other.idx; }
    bool operator>(const Position &other) const { return idx > other.idx; }

    friend std::ostream &operator<<(std::ostream &os, const Position &position) {
        return os << position.pos;
    }

private:
    std::string pos;
    std::array<uint32_t, 2> idx;

    static bool formatAndCheckValid(const std::string &pos) {
        if (pos.size() != 2)
            return false;

        char row = pos[0]; // Letra de la columna ('a' - 'h')
        char col = pos[1]; // Número de la fila ('1' - '8')

        // TODO: Puede que deba estar en otro lado y que la posicion no sepa las dimensiones
        return (row >= 'a' && row <= 'h') && (col >= '1' && col <= '8');
    }
};

// Enum class para restringir PlayerID
// enum class PlayerID : uint8_t { WHITE = 0, BLACK = 1 };

using PlayerID = uint32_t;

constexpr PlayerID WHITE = 0;
constexpr PlayerID BLACK = 1;

} // namespace chess
