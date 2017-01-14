/*
 * File.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#include "File.h"

File::File() {


}

File::~File() {

}

std::vector <std::string> File::GetFile( const std::string pathToFile ) {
	std::fstream file( pathToFile.c_str() );
	std::vector <std::string> fileData;

	if(!file.is_open()) {
		file.close();
		return fileData;
	}

	std::string line;
	while( getline(file, line) ) {
		fileData.push_back( line );
	}

	file.close();
	return fileData;
}

bool File::SaveFileToTextFile( std::vector <std::string> text, std::string pathFile ) {
	std::fstream file( pathFile.c_str(), std::ios::out );

	if(!file.is_open()) {
		return false;
	}

	for(unsigned int i = 0; i < text.size(); ++i) {
		file << text[i] + "\n";
	}

	file.close();
	return true;
}



