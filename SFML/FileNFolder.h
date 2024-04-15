#pragma once
#include "Requirement.h"
#include "vector.h"
namespace fsys = std::filesystem;

void fileExistError(fsys::path fileName) {
    std::cerr << fileName << " already exists.\n";
}
static bool createFolder(fsys::path folderPath) {
    if (fsys::exists(folderPath)) {
        fileExistError(folderPath);
        return false;
    }
    fsys::create_directories(folderPath);
    return true;
}


 //void createMultipleDirectories(fsys::path path, Stack <std::string> list_name);

class csvFile {
private:
    fsys::path filePath;        

public:
    vector<vector<std::string>> cnt;
    csvFile() {}
    csvFile(fsys::path path) {
        this->filePath = path;
        isCreate();
    }

    bool isCreate();   //return false if the file is existed, true is a file is not existed and create that file. 


    void clearSavedContent() {
        cnt.clear();
    }

    void readFile();

    bool writeFile(); 

    bool addCellOnFirstRow();

    bool addRow();

    bool addCol();

    bool deleteRow(ll index);

    bool deleteCol(ll index);
};

