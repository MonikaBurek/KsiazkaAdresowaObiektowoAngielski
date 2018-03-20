#include <iostream>
#include "file.h"

using namespace std;

bool File::isFileEmpty(string fileName)
{
    int length;

    file.open(fileName.c_str());
    file.seekg(0, ios::end); // Go to the end of the file.

    length = file.tellg();  // We check the position that corresponds to the length of the file.


    if (length == 0)
        return 0;// The file is empty.
    else
        return 1; // The file contains data.
}
