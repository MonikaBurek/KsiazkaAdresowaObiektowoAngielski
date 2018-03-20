#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;

/*
Klasa  zawiera funkcje czy plik jest pusty.
*/

class File
{
    fstream file;

public:
    bool isFileEmpty(string fileName);
};

#endif
