#include <cstdio>
#include <cstring>
#include <iostream>

int main(const int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; j < std::strlen(argv[i]); ++j) {
            std::putchar(std::toupper(argv[i][j]));
        }
    }
    std::cout << std::endl;
}
