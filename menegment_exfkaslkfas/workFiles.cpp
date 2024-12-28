#include <filesystem> 
#include <fstream>
#include <string>
#include <map>
#include "interface.h"
#include "workFiles.h"
#include <iostream>


namespace fs = std::filesystem;

Directory::Directory(std::string _pathDirectory) : pathDirectory(_pathDirectory)
{
	if (checkPathDirectory() == false) {
		printError("There is no path");
		editPathDirectory("");
	}
}

bool Directory::checkPathDirectory()
{
	return fs::is_directory(pathDirectory);
}

void Directory::editPathDirectory(std::string newPathDirectory)
{
	this->pathDirectory = newPathDirectory;
}

std::string Directory::getPathDirectory() const
{
	return pathDirectory;
}

void Directory::prewiewFilesDirectory(bool recursive) const
{

	unsigned long long int count = 0;
	
	fs::directory_options options = fs::directory_options::skip_permission_denied | fs::directory_options::follow_directory_symlink;
	try {
		if (!recursive) {
			for (const fs::directory_entry& dir_entry : fs::directory_iterator(pathDirectory, options))
			{
				std::cout << dir_entry.path().string() << "\n"; //крч wcout для безопасности и в конце L"\n"
				if (dir_entry.is_regular_file()) count++;
			}
		}
		else {
			for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(pathDirectory, options))
			{
				std::cout << count << ". " << dir_entry.path().string() << "\n"; //крч wcout для безопасности и в конце L"\n"
				if (dir_entry.is_regular_file()) count++;
			}
		}
	}
	catch (const fs::filesystem_error& e){
		std::wcerr << "Caught filesystem error: " << e.what() << L"\n";
		std::wcerr << "Error code: " << e.code() << L"\n";
		std::wcerr << "Path causing the error: " << e.path1() << L"\n";
	}

	std::cout << "\n" << count << " files\n";
}

