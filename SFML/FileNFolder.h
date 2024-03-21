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
    void create()   //create a csv if not exist.
    {
        if (fsys::exists(filePath)) return; 
        std::ofstream fout; 
        fout.open(filePath); 
        fout.close(); 
        return; 
    }
    bool write(std::stringstream input)    //write content on that file.
    {
        std::ofstream fout; 
        fout.open(filePath); 
        if (!fout.is_open()) return false; 
        else
        {
            std::string t; 
            while (input >> t)
            {
                fout << t; 
                //add more format; 
            }
            fout.close(); 
            return true; 
        }
    }
    void out()   //get output as a stack from the file. 
    {
        return;
    }
   
};



//TODO: study csv.
//TODO: finished class.