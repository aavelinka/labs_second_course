#include "class_Massive.h"

ostream& operator<<(ostream& out, const Massive& matrix)
{
    for(int i = 0; i < matrix.rows; ++i)
    {
        out << "|" ;
        for(int j = 0; j < matrix.cols; ++j)
        {
            out << matrix.mas[i][j];
            if(j < matrix.cols - 1)
            {
                out << " ";
            } 
        }
        out << "|" << endl;
    }
    return out;
}

istream& operator>>(istream& in, Massive& matrix)
{
    cout << "Пожалуйста, введите кол-во строк и столбцов для матрицы: " << endl;
    in >> matrix.rows >> matrix.cols;

    matrix.mas = new int*[matrix.rows];
    for(int i = 0; i < matrix.rows; i++)
    {
        matrix.mas[i] = new int[matrix.cols];
    }

    for(int i = 0; i < matrix.rows; ++i)
    {
        for(int j = 0; j < matrix.cols; ++j)
        {
            cout << "Элемент " << "[" << (i + 1) << "]" << "[" << (j + 1) << "] :" ;
            in >> matrix.mas[i][j];
        }
        cout << endl;
    }
    return in;
}

const Massive& Massive::operator=(const Massive& matrix)
{
    rows = matrix.rows;
    cols = matrix.cols;
    mas = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        mas[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            mas[i][j] = matrix.mas[i][j];
        }
    }
    return *this;
}

int Massive::get_rows() const
{ return this->rows; }

int Massive::get_cols() const
{ return this->cols; }

int* Massive::get_collumn(int** mas, int rows, int collumn_index) const
{
    int* collumn = new int[rows];

    for(int i = 0; i < rows; i++){
        collumn[i]= mas[i][collumn_index];
    }
    return collumn;
}
    
int element(int* row, int* col, int m_cols) 
{
    int result = 0;
    for(int i = 0; i < m_cols; ++i)
    {
        result += row[i] * col[i];
    }
    return result;
}

const Massive Massive::multiply(const Massive& matrix) 
{
//  if(this->mas == nullptr || matrix.mas == nullptr) //проверка что матрицы заполнены
//  {
//      if(this->mas == nullptr && matrix.mas != nullptr)
//      {
//          return matrix;
//      }
//      else if (matrix.mas == nullptr && this->mas != nullptr)
//      {
//          return *this;
//      }
//      else
//      {
//          cout << "Ой, пусто :(" << endl;
//          return Massive(0, 0);
//      }
//  }

    Massive Matrix_result(this->rows, matrix.cols);

    for(int i = 0; i < this->rows; ++i)
    {
        for(int j = 0; j < matrix.cols; ++j)
        {
            int* current_collumn = matrix.get_collumn(matrix.mas, matrix.rows, j);
            Matrix_result.mas[i][j] = element(this->mas[i], current_collumn, this->cols);
            delete[] current_collumn;
        }
    }
    return Matrix_result;
}

const Massive Massive::operator*(const Massive& matrix)
{
    Massive Matrix_result(this->rows, matrix.cols);

    for(int i = 0; i < this->rows; ++i)
    {
        for(int j = 0; j < matrix.cols; ++j)
        {
            int* current_collumn = matrix.get_collumn(matrix.mas, matrix.rows, j);
            Matrix_result.mas[i][j] = element(this->mas[i], current_collumn, this->cols);
            delete[] current_collumn;
        }
    }
    return Matrix_result;
}





 /*
const Massive operator*(const Massive& object1, const Massive& object2) 
{
    Massive Matrix_result(object1.get_rows(), object2.get_cols()); //создание объекта результата умножения двух матриц

    for(int i = 0; i < object1.get_rows(); ++i)
    {
        for(int j = 0; j < object2.get_cols(); ++j)
        {
            Matrix_result.get_mas()[i][j] = element(object1.get_mas()[i], collumn(object2.get_mas(), object2.get_rows(), j), object1.get_cols());
        }
    }

    return Matrix_result;
}
*/