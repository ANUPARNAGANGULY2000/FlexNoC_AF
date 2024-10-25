#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

// Utility function to trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

//compares the file contents and returns true if same
void compare_files(const std::string& file1, const std::string& file2, int caseNumber) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    // Check if either file failed to open
    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Error opening one of the files in case " << caseNumber << "." << std::endl;
        return;
    }

    // Compare the contents of both files line by line
    std::string line1, line2;
    int line_number = 1;
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        // Trim the lines before comparing
        line1 = trim(line1);
        line2 = trim(line2);
        
        if (line1 != line2) {
            std::cout << "Case " << caseNumber << " failed at line " << line_number << "." << std::endl;
            std::cout << "Actual: " << line1 << std::endl;
            std::cout << "Expected: " << line2 << std::endl;
            return;
        }
        line_number++;
    }

    // Check if either file has more lines
    if (f1.eof() != f2.eof()) {
        std::cout << "Case " << caseNumber << " failed at line " << line_number << "." << std::endl;
        if (!f1.eof()) {
            std::cout << "Actual has extra lines starting from line " << line_number << "." << std::endl;
        }
        if (!f2.eof()) {
            std::cout << "Expected has extra lines starting from line " << line_number << "." << std::endl;
        }
        return;
    }
    std::cout << "Case " << caseNumber << " passed." << std::endl;

    f1.close();
    f2.close();
}
