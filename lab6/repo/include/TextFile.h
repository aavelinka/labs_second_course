#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "File.h"
#include "Deque.hpp"
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class TextFile : public File
{
public:
    TextFile(const string& fname) : File(fname) {}
    ~TextFile() = default;

    TextFile<T>& operator=(const TextFile<T>& other);
    void saveRecordTxt(const T& object);
    T* readRecordTxt();
    Deque<T*> readAllRecordsTxt();
    void clearFileTxt() const;
    void openFileTxt(fstream& file, ios_base::openmode mode) const;
    bool hasRecordsTxt() const;
};

#include "TextFile.tpp"

#endif
