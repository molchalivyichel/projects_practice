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

void Directory::editCountRegularFile(unsigned int newCountRegularFile)
{
	this->countRegularFile = newCountRegularFile;
}

unsigned int Directory::getCountRegularFile() const
{
	return countRegularFile;
}

void Directory::editCountDirectorys(unsigned int newCountDirectorys)
{
	this->countDirectorys = newCountDirectorys;
}
unsigned int Directory::getCountDirectorys() const
{
	return countDirectorys;
}

void Directory::prewiewFilesDirectory(bool recursive)
{
	unsigned int countRegularFile = 0;
	unsigned int countDirectory = 0;
	
	fs::directory_options options = fs::directory_options::skip_permission_denied | fs::directory_options::follow_directory_symlink;
	try {
		if (!recursive) {
			for (const fs::directory_entry& dir_entry : fs::directory_iterator(this->pathDirectory, options))
			{
				std::cout << countRegularFile + countDirectory << ". ";
				printPath(dir_entry.path().c_str());
				if (dir_entry.is_regular_file()) countRegularFile++;
				else countDirectory++;
			}
		}
		else {
			for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(this->pathDirectory, options))
			{
				std::cout << countRegularFile + countDirectory << ". ";
				printPath(dir_entry.path().c_str());

				if (dir_entry.is_regular_file()) countRegularFile++;
				else countDirectory++;
			}
		}
	}
	catch (const fs::filesystem_error& e){
		std::wcerr << "Caught filesystem error: " << e.what() << L"\n";
		std::wcerr << "Error code: " << e.code() << L"\n";
		std::wcerr << "Path causing the error: " << e.path1() << L"\n";
	}

	std::cout << "\nRegular file: " << countRegularFile << "\n";
	std::cout << "Directory file: " << countDirectory << "\n";
}

void Directory::countingFiles()
{
	unsigned int countRegularFile = 0;
	unsigned int countDirectory = 0;

	fs::directory_options options = fs::directory_options::skip_permission_denied | fs::directory_options::follow_directory_symlink;

	for (const fs::directory_entry& dir_entry : fs::recursive_directory_iterator(this->pathDirectory, options))
	{
		if (dir_entry.is_regular_file()) countRegularFile++;
		else countDirectory++;
	}

	editCountRegularFile(countRegularFile);
	editCountDirectorys(countDirectory);
}