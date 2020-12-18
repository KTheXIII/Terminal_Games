#include "Terminal.hpp"

namespace GN {

    Terminal::Terminal(u_int32_t width, u_int32_t height)
        : width(width), height(height) {}

    Terminal::~Terminal() {}

    void Terminal::Clear() { std::cout << "\033[H\033[2J"; }

    void Terminal::Newline() { std::cout << '\n'; }

    void Terminal::SetColor(Colors color) {
        std::cout << Color::Color8bit(30 + color);
    }

    void Terminal::ResetColor() { std::cout << Color::Reset; }

}  // namespace GN
