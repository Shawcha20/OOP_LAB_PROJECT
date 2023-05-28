#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>

class FileReader {
public:
    bool getdata(const int roll_num, std::string& name, float& weight, float& height);
};

#endif  // FILE_READER_H
