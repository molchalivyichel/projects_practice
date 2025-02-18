#ifndef WORKFILES_H
#define WORKFILES_H
#pragma once

class Directory
{
private:
	std::string pathDirectory;
	unsigned int countRegularFile;
	unsigned int countDirectorys;
public:
	Directory(std::string _pathDirectory);

	bool checkPathDirectory();
	void editPathDirectory(std::string newPathDirectory);
	std::string getPathDirectory() const;

	void editCountRegularFile(unsigned int newCountRegularFile);
	unsigned int getCountRegularFile() const;

	void editCountDirectorys(unsigned int newCountDirectorys);
	unsigned int getCountDirectorys() const;

	void iterateDirectory(auto directoryIterator, unsigned int& countRegularFile, unsigned int& countDirectory);
	void prewiewFilesDirectory(bool recursive = false);
	void countingFiles();
};


#endif