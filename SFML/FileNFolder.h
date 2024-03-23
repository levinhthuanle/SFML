#pragma once
#include "Requirement.h"

namespace fsys = std::filesystem;

void createMultipleDirectories(fsys::path path, Stack <std::string> list_name);
//Create multiple directories based on the linked list which a teacher input for classes in school year // student in a class.

//std::stringstream readFile(fsys::path filepath);
Stack <std::stringstream> readFile(fsys::path filepath);

class csvFile {
private:
    fsys::path filePath;
public:
    csvFile(fsys::path input) 
    {
        filePath = input; 
    }
    bool create()   //return false if the file is existed, true is a file is not existed and create that file. 
    {
        if (fsys::exists(filePath)) return false; 
        std::ofstream fout; 
        fout.open(filePath); 
        fout.close(); 
        return true;
    }
    
    bool write(Stack <std::stringstream> content)
    {
        return true;
    }
    bool addingLines(Stack <std::stringstream> input)    //adding new line on a existing file.
    {
        return true; 
    }
    Stack <std::stringstream> get()   //get output as a stack from the file. 
    {
        return (readFile(filePath)); 
    }
    bool save(/*content*/)
    {
        return true; 
    }
};



//TODO: study csv.
//TODO: finished class.