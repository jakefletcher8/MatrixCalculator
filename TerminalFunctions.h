#pragma once

#include <iostream>
#include <conio.h>

/*

TO DO:

    -Write helper functions to do stuff in the terminal
    -Implement keyboard input to allow user to better control stuff
    -Highlight selected options

*/

inline void clearTerminal() {
    // \033[2J clears the screen, \033[1;1H moves the cursor to the top-left corner
    std::cout << "\033[2J\033[1;1H";

}

 