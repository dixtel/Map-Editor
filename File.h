/*
 * File.h
 *
 *  Created on: Nov 18, 2016
 *      Author: marcin
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>
#include <vector>
#include <fstream>

class File {
public:
	File();
	~File();
	std::vector <std::string>  GetFile( const std::string pathToFile );
};

#endif /* FILE_H_ */
