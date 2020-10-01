#include "Terminal.hpp"

namespace GN {

    Terminal::Terminal(unsigned int width, unsigned int height)
        : width(width), height(height) {}

    Terminal::~Terminal() {}

    void Terminal::Clear() {
        std::cout << std::string(MAX_CLEAR, '\n');
        std::cout << Escape + "[" << MAX_CLEAR << "A" << Escape + "["
                  << MAX_CLEAR << "D";
    }

    void Terminal::Newline() { std::cout << '\n'; }

    void Terminal::Hello() { std::cout << "Hello, World!" << std::endl; }

}  // namespace GN
