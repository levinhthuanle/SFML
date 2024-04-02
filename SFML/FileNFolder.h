#pragma once
#include "Requirement.h"

namespace fsys = std::filesystem;

// void createMultipleDirectories(fsys::path path, Stack <std::string> list_name);

class csvFile {
private:
    fsys::path filePath;        

public:

    vector<vector<std::string>> content;

    csvFile() {}

    csvFile(fsys::path path) 
    {
        this->filePath = path;
        create();
    }

    bool create()   //return false if the file is existed, true is a file is not existed and create that file. 
    {
        if (fsys::exists(filePath)) {
            std::cerr << filePath << " already exists.\n";
            return false;
        }
        std::ofstream fout; 
        fout.open(filePath); 
        fout.close(); 
        return true;
    }

    void clearSavedContent() {
        content.clear();
    }

    void readFile() {
        content.clear();
        std::ifstream fin;
        fin.open(filePath);
        if (!fin.is_open()) {
            std::cerr << "Error opening input file " << filePath << ".\n";
            return;
        }

        std::string rowS;
        std::string cell;

        while (std::getline(fin, rowS, '\n')) {
            vector<std::string> rowContent;
            std::stringstream rowSS(rowS);
            while (std::getline(rowSS, cell, ',')) {
                rowContent.push_back(cell);
            }
            this->content.push_back(rowContent);
        }
        fin.close();
    }
    
    bool writeFile() {                  //Any change to the file's content, please call the suitable function, then call the write function to chage the file
        std::ofstream fout;
        fout.open(filePath);
        if (!fout.is_open()) {
            std::cerr << "Cannot open " << filePath << " to write.\n";
        }
        ll rowNum = this->content.size();
        for (ll i = 0; i < rowNum; i++) {
            ll colNum = content[i].size();
            for (ll j = 0; j < colNum - 1; j++)
                fout << content[i][j] << ",";
            fout << content[i][colNum - 1];
            fout << std::endl;
        }
        return true;
    }

    bool addCellOnFirstRow() {       //Used to create the first row of a page
        if (this->content.size() == 0) {        //If the content is blank, add new row
            vector<std::string> row(1, " ");
            this->content.push_back(row);
        }
        else {
            this->content[0].push_back(" ");
        }
        return true;
    }

    bool addRow() {    //AddNewRow, with the size equal to the size of above rows
        if (this->content.size() == 0)
            addCellOnFirstRow();
        vector<std::string> row(this->content[0].size(), " ");
        this->content.push_back(row);
        return true; 
    }

    bool addCol() {
        ll contentSize = this->content.size();
        if (contentSize == 0)
            addCellOnFirstRow();
        else {
            for (ll i = 0; i < contentSize; i++)
                this->content[i].push_back(" ");
        }
        return true;
    }

    bool deleteRow(ll index) {
        ll contentSize = this->content.size();
        if (index >= contentSize) return false;
        if (content[index].size() > 0) content[index].clear();
        for (ll i = index; i < contentSize - 1; i++)
            content[index] = content[index + 1];
        content.pop_back();
        return true;
    }

    bool deleteCol(ll index) {
        ll contentSize = this->content.size();
        for (ll i = 0; i < contentSize; i++) {
            if (index >= content[i].size()) return false;
            for (ll j = index; j < content[i].size() - 1; j++)
                content[i][j] = content[i][j + 1];
            content[i].pop_back();
        }
        return true;
    }
};

