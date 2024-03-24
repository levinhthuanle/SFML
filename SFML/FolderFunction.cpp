#include "FileNFolder.h"

void createMultipleDirectories(fsys::path path, Stack <std::string> list_name)
//Create multiple directories based on the linked list which a teacher input for classes in school year // student in a class.
{
    Stack<std::string>::ListNode* curr = list_name.head;
    while (curr)
    {
        fsys::create_directories(path / curr->val);
        curr = curr->next;
    }
}
//std::stringstream readFile(fsys::path filepath)
//{
//    std::stringstream content;
//    std::ifstream fin;
//    fin.open(filepath);
//    if (fin.is_open())
//        content << fin.rdbuf();
//    return content;
//
//}
//Stack <std::stringstream> readFile(fsys::path filepath)
//{
//    Stack<std::stringstream> contentList;
//
//    std::ifstream fin;
//    fin.open(filepath);
//    if (!fin.is_open()) return contentList; 
//    while (fin.eof())
//    {
//        std::string line; 
//        contentList.newslot(); 
//        std::getline(fin, line);
//        contentList.head->val << line; 
//    }
//    return contentList;
//}



//TODO: create student folder with file. 