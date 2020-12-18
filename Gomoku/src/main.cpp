#include <iostream>
#include <algorithm>
#include "Terminal.hpp"

constexpr unsigned int BOARD_SIZE = 12;
constexpr int BLACK_PIECE = 1;
constexpr int WHITE_PIECE = 2;

int row_index(int x, int y, int col_size) { return y * col_size + x; }

void hline(const int& width) {
    for (int i = 0; i < width; i++) std::cout << "-";
}

bool insert_at(int board[], const int& piece, const int i, const int j) {
    bool is_valid = true;
    int value = board[i * BOARD_SIZE + j];
    if (value == 0)
        board[i * BOARD_SIZE + j] = piece;
    else
        is_valid = false;

    return is_valid;
}

bool check_wins(const int board[]) {
    bool has_won = false;
    return has_won;
}

void show_board(const int board[]) {
    for (int i = 0; i < BOARD_SIZE * 2 + 1; i++) {
        for (int j = 0; j < BOARD_SIZE * 2 + 1; j++) {
            if (j == 0 && i == 0) {
                std::cout << " ";
            } else if (j % 2 == 0 && j > 0 && i == 0) {
                std::cout << "  ";
                std::cout << (char)(65 + j / 2 - 1) << " ";
            } else if (j == 0 && i > 0 && i % 2 == 0) {
                std::cout << i / 2 << " ";
            } else if (i % 2 != 0 && j > 2 && j < BOARD_SIZE * 2) {
                std::cout << "---";
            } else if (j % 2 == 0 && i % 2 == 0) {
                std::cout << " ";
                int num = board[row_index(j / 2 - 1, i / 2 - 1, BOARD_SIZE)];

                if (num == BLACK_PIECE)
                    GN::Terminal::SetColor(GN::Colors::BLUE);
                else if (num == WHITE_PIECE)
                    GN::Terminal::SetColor(GN::Colors::RED);
                else
                    GN::Terminal::SetColor(GN::Colors::WHITE);

                std::cout << num;

                GN::Terminal::ResetColor();

                std::cout << " |";
            } else if (j < 3) {
                std::cout << " ";
            }
        }

        GN::Terminal::Newline();
    }
}

void push_buffer(std::string& buffer, const std::string& message) {
    buffer += "\n" + message;
}

void switch_turn(int& current_piece, int& last_piece) {
    int tmp = current_piece;
    current_piece = last_piece;
    last_piece = tmp;
}

int main(int argc, char const* argv[]) {
    int board[BOARD_SIZE * BOARD_SIZE] = {};
    bool is_running = true;
    std::string error_message = "";
    std::string message = "";

    int current_piece = WHITE_PIECE;
    int last_piece = BLACK_PIECE;

    while (is_running) {
        GN::Terminal::Clear();

        if (error_message.length() > 0) {
            std::cout << error_message << "\n\n";
            error_message = "";
        }

        if (message.length() > 0) {
            std::cout << message << "\n\n";
            message = "";
        }

        hline(BOARD_SIZE * 5 + 2);
        std::cout << "\n";

        std::cout << "current piece: " << current_piece << "\n";
        hline(BOARD_SIZE * 5 + 2);
        std::cout << "\n";

        show_board(board);

        hline(BOARD_SIZE * 5 + 2);
        std::cout << "\n";

        std::cout << "Input: ";
        std::string s;
        std::cin >> s;

        std::transform(s.begin(), s.end(), s.begin(), ::toupper);

        if (s.length() > 2) {
            push_buffer(error_message, "input too long");
        } else if (s.length() < 2) {
            push_buffer(error_message, "input too short");
        } else {
            if (!((int)s.at(0) > 64 && (int)s.at(0) < 65 + BOARD_SIZE)) {
                push_buffer(error_message, "input pattern not correct");
            }
            if (!((int)s.at(1) > 48 - 1 &&
                  (int)s.at(1) < 48 + BOARD_SIZE + 1)) {
                push_buffer(error_message, "input out of range");
            }
        }

        if (error_message.length() > 0) continue;

        int x = (int)s.at(0) - 65;
        int y = std::stoi(s.substr(1, 2)) - 1;

        bool is_valid = insert_at(board, current_piece, y, x);

        if (!is_valid) {
            push_buffer(message, "not a valid place, try again");
            continue;
        }

        switch_turn(current_piece, last_piece);
    }

    return 0;
}
