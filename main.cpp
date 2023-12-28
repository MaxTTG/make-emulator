#include <iostream>
#include <string>
#include "makefile.h"

int main() {
    std::string make, file, target;
    while (true) {
        try {
            std::cin >> make;
            if (make != "make") {
                std::cout << "Unknown command: " << make << std::endl << 
                "Try \"make -h\"?" << std::endl;
                continue;
            }
            std::cin >> file;
            if (file == "-h") {
                std::cout << "Input format: \"make /path/to/file/ target\"" << std::endl;
                continue;
            }
            MakeFile mfile(file);
            std::cin >> target;
            mfile.build(target);
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
            break;
        }
    }
}