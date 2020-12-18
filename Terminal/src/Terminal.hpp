#pragma once
#include <iostream>
#include <vector>

#include "Core.hpp"

#include <string>
#include "Color.hpp"

namespace GN {

    class Terminal {
       public:
        inline const static char *Escape = "\u001b";

        Terminal(u32 width, u32 height);
        ~Terminal();

        static void Clear();

        static void Newline();

        static void SetColor(Colors color);

        static void ResetColor();

       private:
        inline static u32 MAX_CLEAR = 100;
        u32 width, height;
    };

}  // namespace GN