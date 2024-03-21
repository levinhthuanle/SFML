#pragma once
#include "Requirement.h"

namespace fsys = std::filesystem;

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
        std::stringstream content = readFile(filePath); 
    }
   
};

void createMultipleDirectories(fsys::path path, Stack <std::string> list_name);
std::stringstream readFile(fsys::path filepath);


//TODO: study csv.
//TODO: finished class.