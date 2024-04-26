#pragma once

#include "vector.h"
namespace fsys = std::filesystem;


static void fileExistError(fsys::path fileName) {
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

// void createMultipleDirectories(fsys::path path, Stack <std::string> list_name);

class csvFile {
private:
    fsys::path filePath;        

public:
    vector<vector<std::string>> cnt;
    csvFile() {}
    csvFile(fsys::path path) {
        std::string sPath = path.generic_string();
        for (char c : sPath) {
            if (c == 92) c = '/';
        }
        fsys::path fPath(sPath);
        this->filePath = fPath;
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

    csvFile& operator=(const csvFile& b) {
        if (this == &b) return *this;
        this->filePath = b.filePath;
        this->cnt = b.cnt;
        return *this;
    }
};

