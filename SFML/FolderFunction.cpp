#include "FileNFolder.h"

void create_multiple_directories(fsys::path path, Stack <std::string> list_name) // Create multiple directories based on the stack which a teacher input for classes in school year.
{
	Stack<std::string>::ListNode* curr = list_name.head; 
	while (curr)
	{
		fsys::create_directories(path/curr->val); 
		curr = curr -> next; 
	}
}
// the function create only one directory exists in <filesystem>, so i don't rewrite again. 