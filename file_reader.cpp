#include <fstream>
#include <string>
#include "file_reader.h"

bool FileReader::getdata(const int roll_num, std::string& name, float& weight, float& height) {
    std::ifstream inputFile("students.txt"); // Open the file in read mode
    int roll;

    if (inputFile.is_open()) {
        while (inputFile >> name >> roll >> weight >> height ) {
            if (roll == roll_num) {
                inputFile.close();
                return true;
            }
        }

        inputFile.close();
    }

    return false; // Return false if the student roll number is not found
}
