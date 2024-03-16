#pragma once
#include "Requirement.h"
//Object: input a path to .csv file, create that file if not exist, inputing into that file, or return a stack of information in that file.  
class csv_file {
private:
    fsys::path filePath;
public:
    csv_file(fsys::path input) 
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
    void write()    //write content on that file.
    {
        
    }
    Stack<> out()   //get output as a stack from the file. 
    {

    }
   
};
//TODO: chinh class file cho muc tieu tot hon. 