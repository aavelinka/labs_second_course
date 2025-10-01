#ifndef CLASS_MASSIVE_H
#define CLASS_MASSIVE_H

#include<iostream>
using namespace std;

class Massive
{
    private:
    int rows, cols;
    int** mas;

    public:
    Massive()
    {
        rows = 0;
        cols = 0;
        mas = nullptr;
    };
    Massive(int n, int m) 
    {
        rows = n;
        cols = m;
        mas = new int*[rows];
        for(int i = 0; i < rows; ++i)
            mas[i] = new int[cols];
    };
    Massive(const Massive& object)
    {
        rows = object.rows;
        cols = object.cols;
        mas = new int*[rows];
        for(int i = 0; i < rows; ++i)
        {
            mas[i] = new int[cols];
        }

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                mas[i][j] = object.mas[i][j];
            }
        }
    };
    ~Massive()
    {
        for (int i = 0; i < rows; ++i) {
            delete[] mas[i];
        }
    
        delete[] mas;
        mas = nullptr;
    };
    friend ostream& operator<<(ostream&, const Massive&);
    friend istream& operator>>(istream&, Massive&);
    const Massive& operator=(const Massive&);
    int get_rows() const;
    int get_cols() const;
    int* get_collumn(int**, int, int) const;
    const Massive multiply(const Massive&);
    const Massive operator*(const Massive&);
};

#endif