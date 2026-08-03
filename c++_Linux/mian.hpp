#ifndef MAIN_HPP_
#define MAIN_HPP_
#include <memory>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>
namespace Game {
    class Player {
    public:
        int x = 10, y = 15;
        // setter
        void set_x() {
            std::cin >> x;
        } void set_y() {
            std::cin >> y;
        }

        // getter
        int get_x() {
            return x;
        } int get_y() {
            return y;
        }
    };
    struct Config{
        std::string config = "Never Loaded";
        bool isLaoding = false;
    };
    void LoadingGame(Config &game) {
        if (game.config == "Never Loaded") {
            game.config = "Loaded";
        }
        game.isLaoding = true;
    }
    
    void EnableRawMode(termios &old) {
        tcgetattr(STDIN_FILENO, &old);
        termios raw = old;
        raw.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    void DisableRawMode(termios &old) {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &old);
    }

    void ClearScreen() {
        std::cout << "\033[2J\033[H";
    }

    void Draw(Player player) {
        ClearScreen();
        for (int row = 0; row < 15; ++row) {
            for (int col = 0; col < 30; ++col) {
                if (row == player.get_y() && col == player.get_x()) {
                    std::cout << "■ ";
                } else {
                    std::cout << "  ";
                }
            }
            std::cout << '\n';
        }
    }

    void Input(Player &player) {
        char c;
        read(STDIN_FILENO, &c, 1);

        if (c == 'w') { player.y--; }
        if (c == 's') { player.y++; }
        if (c == 'a') { player.x--; }
        if (c == 'd') { player.x++; }
    }
}
#endif