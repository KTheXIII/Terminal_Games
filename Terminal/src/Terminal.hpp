#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Color.hpp"

namespace GN {

    class Terminal {
       public:
        inline const static std::string Escape = "\u001b";

        Terminal(unsigned int width, unsigned int height);
        ~Terminal();

        static void Clear();

        static void Newline();

        static void Hello();

       private:
        inline static unsigned int MAX_CLEAR = 100;
        unsigned int width, height;
    };

}  // namespace GN