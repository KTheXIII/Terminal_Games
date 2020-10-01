#pragma once
#include <iostream>
#include <string>

namespace GN {

    enum ColorMode { _8, _16, _256 };

    enum Colors { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

    class Color {
       private:
       public:
        static void SetColor(Colors color);
        static void ResetColor();

        inline const static std::string Escape = "\u001b";
        inline const static std::string Reset = "\u001b[0m";

        inline static std::string Color8bit(int num) {
            return Escape + "[" + std::to_string(num) + "m";
        }

        // inline static std::string Black() { return Color8bit(30); }
        // inline static std::string Red() { return Color8bit(31); }
        // inline static std::string Green() { return Color8bit(32); }
        // inline static std::string Yellow() { return Color8bit(33); }
        // inline static std::string Blue() { return Color8bit(34); }
        // inline static std::string Magenta() { return Color8bit(35); }
        // inline static std::string Cyan() { return Color8bit(36); }
        // inline static std::string White() { return Color8bit(37); }
    };

}  // namespace GN
