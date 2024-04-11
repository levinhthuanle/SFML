#include "FileNFolder.h"

bool createFolder(fsys::path folderPath)
{
    if (fsys::exists(folderPath)) {
        std::cerr << folderPath << " already exists.\n";
        return false;
    }

    fsys::create_directories(folderPath);
    return true;
}

bool csvFile::isCreate()
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

void csvFile::readFile(){
    cnt.clear();
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
        this->cnt.push_back(rowContent);
    }
    fin.close();
}

bool csvFile::writeFile()
{                  //Any change to the file's cnt, please call the suitable function, then call the write function to chage the file
    std::ofstream fout;
    fout.open(filePath);
    if (!fout.is_open()) {
        std::cerr << "Cannot open " << filePath << " to write.\n";
    }
    ll rowNum = this->cnt.size();
    for (ll i = 0; i < rowNum; i++) {
        ll colNum = cnt[i].size();
        for (ll j = 0; j < colNum - 1; j++)
            fout << cnt[i][j] << ",";
        fout << cnt[i][colNum - 1];
        fout << std::endl;
    }
    return true;
}

bool csvFile::addCellOnFirstRow()
{       //Used to create the first row of a page
    if (this->cnt.size() == 0) {        //If the cnt is blank, add new row
        vector<std::string> row(1, " ");
        this->cnt.push_back(row);
    }
    else {
        this->cnt[0].push_back(" ");
    }
    return true;
}

bool csvFile::addRow()
{    //AddNewRow, with the size equal to the size of above rows
    if (this->cnt.size() == 0)
        addCellOnFirstRow();
    vector<std::string> row(this->cnt[0].size(), " ");
    this->cnt.push_back(row);
    return true;
}

bool csvFile::addCol()
{
    ll contentSize = this->cnt.size();
    if (contentSize == 0)
        addCellOnFirstRow();
    else {
        for (ll i = 0; i < contentSize; i++)
            this->cnt[i].push_back(" ");
    }
    return true;
}

bool csvFile::deleteRow(ll index)
{
    ll contentSize = this->cnt.size();
    if (index >= contentSize) return false;
    if (cnt[index].size() > 0) cnt[index].clear();
    for (ll i = index; i < contentSize - 1; i++)
        cnt[index] = cnt[index + 1];
    cnt.pop_back();
    return true;
}

bool csvFile::deleteCol(ll index)
{
    ll contentSize = this->cnt.size();
    for (ll i = 0; i < contentSize; i++) {
        if (index >= cnt[i].size()) return false;
        for (ll j = index; j < cnt[i].size() - 1; j++)
            cnt[i][j] = cnt[i][j + 1];
        cnt[i].pop_back();
    }
    return true;
}