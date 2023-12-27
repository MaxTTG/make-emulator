#include <iostream>
#include <fstream>
#include <map>
#include "makefile.h"

int main() {
    std::string make, file, target;
    std::map<std::string, MakeFile> mfiles;
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
            mfiles[file] = MakeFile::file_read(file);
            std::cin >> target;
            mfiles[file].build(target);
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
            break;
        }
    }
}
