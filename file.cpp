#include <iostream>
#include "file.h"

using namespace std;

bool File::isFileEmpty(string fileName)
{
    int length;

    file.open(fileName.c_str());
    file.seekg(0, ios::end); // Przej�cie na koniec pliku

    length = file.tellg();  // Sprawdzamy pozycj�, kt�ra odpowiada d�ugo�ci pliku!

    if (length == 0)
        return 0;//"Plik jest pusty." << endl;
    else
        return 1; //"Plik zawiera dane." << endl;
}
