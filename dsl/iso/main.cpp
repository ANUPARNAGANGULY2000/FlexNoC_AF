#include <iostream>
#include <memory>
#include <dot_compiler.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path-to-dot-file>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];

    std::cout << "Hello, from iso" << std::endl;

    auto obj = new dot_lang::DOT(file_path);

    std:: cout << "got" << obj->test() << " from obj " << std::endl;

    delete obj;
    return 0;
}