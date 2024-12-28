#ifndef WORKFILES_H
#define WORKFILES_H
#pragma once

class Directory
{
private:
	std::string pathDirectory;
	int countFile;
public:
	Directory(std::string _pathDirectory);

	bool checkPathDirectory();
	void editPathDirectory(std::string newPathDirectory);
	std::string getPathDirectory() const;
	void prewiewFilesDirectory(bool recursive = false) const;
};


#endif