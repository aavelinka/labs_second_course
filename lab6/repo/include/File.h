#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>
#include <sstream>
#include "../../exceptions/include/FileException.h"

using namespace std;

class File 
{
protected:
    string filename;
    ifstream iFile;
    ofstream oFile;
    fstream fFile;
    
public:
    File(const string& filename) : filename(filename) {}
    virtual ~File()
    {
        if (iFile.is_open())
        {
            iFile.close();
        }
        if (oFile.is_open()) 
        {
            oFile.close();
        }
        if (fFile.is_open()) 
        {
            fFile.close();
        }
    }
};

#endif
