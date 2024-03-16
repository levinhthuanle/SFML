#pragma once
#include "Requirement.h"
namespace fsys = std::filesystem;
class File {//This class has only worked with CSV files
private:
    std::fstream file;
    std::vector<std::string> rowContent; //Path of the "mother" folder
    std::string fileName;
    fsys::path folderPath;

public:
    File() {}

    File(fsys::path folderPath, std::string fileName) {
        this->fileName = fileName;
        this->folderPath = folderPath;
        folderPath /= fileName;
        std::fstream file(folderPath);
    }

    void open() {
        this->file.open(this->folderPath / this->fileName);
    }

    void close() {
        this->file.close();
    }

    std::vector<std::string> readRow() {//Only store one row per call
        this->rowContent.clear();
        std::string row;
        if (!(this->file >> row)) return this->rowContent;
        std::getline(this->file, row, '\n');
        std::stringstream sRow(row);
        std::string element;
        while (std::getline(sRow, element, ',')) {
            this->rowContent.push_back(element);
        }
        return this->rowContent;
    }

    void write(std::string content) {
        this->file << content << std::endl;
    }

    void update() {

    }

    ~File() {
        if (file.is_open())
            this->file.close();
    }
};