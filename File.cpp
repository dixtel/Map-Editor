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

std::vector <std::string>  File::GetFile( const std::string pathToFile ) {
	std::fstream file( pathToFile.c_str() );
	std::string line;
	std::vector <std::string> fileData;

	while( getline(file, line) ) {
		fileData.push_back( line );
	}

	return fileData;
}


