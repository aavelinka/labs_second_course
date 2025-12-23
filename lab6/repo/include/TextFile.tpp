#pragma once

#include "TextFile.h"
#include "Deque.tpp"
#include <sstream>

template <typename T>
TextFile<T>& TextFile<T>::operator=(const TextFile<T>& other)
{
    if (this != &other)
    {
        filename = other.filename;
    }
    return *this;
}

template <typename T>
void TextFile<T>::openFileTxt(fstream& file, ios_base::openmode mode) const
{
    file.open(filename, mode);
    if (!file.is_open())
    {
        throw FileException("Unable to open file: " + filename);
    }
}

template <typename T>
void TextFile<T>::saveRecordTxt(const T& object)
{
    fstream file;
    openFileTxt(file, ios::out | ios::app);
    object.saveTextRecord(file);
    file.close();
}

template <typename T>
T* TextFile<T>::readRecordTxt()
{
    fstream file;
    openFileTxt(file, ios::in);
    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }
        istringstream iss(line);
        T object;
        object.loadFromText(iss);
        file.close();
        return new T(object);
    }

    file.close();
    return nullptr;
}

template <typename T>
Deque<T*> TextFile<T>::readAllRecordsTxt()
{
    fstream file;
    openFileTxt(file, ios::in);
    Deque<T*> records;
    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }
        istringstream iss(line);
        T object;
        object.loadFromText(iss);
        records.pushBack(new T(object));
    }

    file.close();
    return records;
}

template <typename T>
void TextFile<T>::clearFileTxt() const
{
    fstream file;
    openFileTxt(file, ios::out | ios::trunc);
    file.close();
}

template <typename T>
bool TextFile<T>::hasRecordsTxt() const
{
    ifstream file(filename, ios::ate);
    if (!file.is_open())
    {
        return false;
    }

    return file.tellg() > 0;
}
