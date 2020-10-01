#include <iostream>
#include "Terminal.hpp"

constexpr unsigned int BOARD_SIZE = 5;
constexpr int BLACK_PIECE = 1;
constexpr int WHITE_PIECE = 2;

int row_index(int x, int y, int col_size) { return y * col_size + x; }

void hline(const int width) {
    for (int i = 0; i < width; i++) std::cout << "--- ";
}

void show_board(const int board[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << " ";

            if (board[row_index(j, i, BOARD_SIZE)] == BLACK_PIECE)
                GN::Color::SetColor(GN::Colors::RED);
            else if (board[row_index(j, i, BOARD_SIZE)] == WHITE_PIECE)
                GN::Color::SetColor(GN::Colors::CYAN);
            else
                GN::Color::ResetColor();

            std::cout << board[row_index(j, i, BOARD_SIZE)];

            GN::Color::ResetColor();
            if (j < BOARD_SIZE - 1) std::cout << " |";
        }
        GN::Terminal::Newline();
        if (i < BOARD_SIZE - 1) hline(BOARD_SIZE);
        GN::Terminal::Newline();
    }
}

int main(int argc, char const* argv[]) {
    int board[BOARD_SIZE * BOARD_SIZE] = {};

    GN::Terminal::Clear();

    board[3] = WHITE_PIECE;

    show_board(board);

    std::cout << (int)'A' << std::endl;

    return 0;
}
