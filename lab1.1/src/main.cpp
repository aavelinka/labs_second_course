#include "class_Massive.h"

void multiply_Matrix()
{
    int number;
    cout << "Пожалуйста, введите кол-во матриц: " << endl;
    cin >> number;

    Massive* Matrix = new Massive[number];
    for(int i = 0; i < number; ++i)
    {
        cin >> Matrix[i];
        if(i != 0 && Matrix[i - 1].get_cols() != Matrix[i].get_rows())
        {
            cout << "Матрицы не согласованы. Попробуйте снова\n";
            i--;
        }
    }

    Massive Result_Matrix = Matrix[0];
    for(int i = 1; i < number; ++i)
    {
        Result_Matrix = Result_Matrix.multiply(Matrix[i]);
    }

    cout << "--------- Умножение матриц --------" << endl;
    for(int i = 0; i < number; ++i)
    {
        cout << Matrix[i];
        if(i < number - 1)
        {
            cout << "*";
        }
    }
    cout << "=" << endl;
    cout << Result_Matrix;
}

int main() 
{
    char reapet;
    do
    {
        multiply_Matrix();

        cout << "Вы хотите продолжить работу с программой? ДА - 1, НЕТ - 0\nВаш выбор: ";
        cin >> reapet;
        cout << endl;

    } while(reapet != '0');
    
    cout << "Спасибо за работу, хорошего дня!<3" << endl;
    return 0;
}