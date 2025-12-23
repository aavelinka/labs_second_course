#ifndef BINFILE_H
#define BINFILE_H

#include "File.h"
#include "Deque.hpp"
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class BinaryFile : public File
{
public:
    BinaryFile(const string& fname) : File(fname) {}
    ~BinaryFile() = default;

    BinaryFile<T>& operator=(const BinaryFile<T>& other);
    void saveRecordBin(const T& object);
    T* readRecordBin();
    Deque<T*> readAllRecordsBin();
    void clearFileBin() const;
    void openFileBin(fstream& file, ios_base::openmode mode) const;
};

#include "BinaryFile.tpp"

#endif
