#include "Color.hpp"

namespace GN {
    void Color::SetColor(Colors color) { std::cout << Color8bit(30 + color); }

    void Color::ResetColor() { std::cout << Reset; }

}  // namespace GN
