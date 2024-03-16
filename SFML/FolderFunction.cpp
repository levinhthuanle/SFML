#include "FileNFolder.h"

void create_multiple_directories(fsys::path path, Stack <std::string> list_name) 
//Create multiple directories based on the linked list which a teacher input for classes in school year // student in a class.
{
	Stack<std::string>::ListNode* curr = list_name.head; 
	while (curr)
	{
		fsys::create_directories(path/curr->val); 
		curr = curr -> next; 
	}
}
//TODO: create student folder with file. 