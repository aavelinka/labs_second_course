#pragma once

#include "BinaryFile.h"
#include <cstdint>

template <typename T>
BinaryFile<T>& BinaryFile<T>::operator=(const BinaryFile<T>& other)
{
    if (this != &other)
    {
        filename = other.filename;
    }
    return *this;
}

template <typename T>
void BinaryFile<T>::openFileBin(fstream& file, ios_base::openmode mode) const
{
    file.open(filename, mode | ios::binary);
    if (!file.is_open())
    {
        throw FileException("Unable to open file: " + filename);
    }
}

template <typename T>
void BinaryFile<T>::saveRecordBin(const T& object)
{
    fstream file;
    openFileBin(file, ios::out | ios::app);
    object.saveBinaryRecord(file);
    file.close();
}

template <typename T>
T* BinaryFile<T>::readRecordBin()
{
    fstream file;
    openFileBin(file, ios::in);

    if (file.peek() == EOF)
    {
        return nullptr;
    }

    T object;
    object.loadFromBinary(file);
    file.close();
    return new T(object);
}

template <typename T>
Deque<T*> BinaryFile<T>::readAllRecordsBin()
{
    fstream file;
    openFileBin(file, ios::in);
    Deque<T*> records;

    while (file.peek() != EOF)
    {
        T object;
        object.loadFromBinary(file);
        records.pushBack(new T(object));
    }

    file.close();
    return records;
}

template <typename T>
void BinaryFile<T>::clearFileBin() const
{
    fstream file;
    openFileBin(file, ios::out | ios::trunc);
    file.close();
}
