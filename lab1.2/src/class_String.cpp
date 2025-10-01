#include"class_String.h"

ostream& operator<<(ostream& out, const String& str)
{
    out << str.info;

    return out;
}

istream& operator>>(istream& in, String& str)
{
    char init[79];
    for(int i = 0; init[i] != '\n'; ++i)
    {
        in >> init[i];
        str.lenth++;
    }
    str.info = new char[str.lenth];
    str.info = init;
    str.info[str.lenth + 1] = '\0';

    return in;
}

String String::operator+(const String& str) //объект + объект
{
    String Result(this->lenth + str.lenth);
    Result.info = strcat(this->info, str.info);

    return Result;
}

String String::operator+(const char* str) // объект + строка
{
    String Result(this->lenth + strlen(str)); 
    Result = strcat(this->info, str);
    
    return Result;
}

String operator+(char* str1, const String& str2) //строка + объект
{
    String Result(strlen(str1) + str2.lenth);
    Result.info = strcat(str1, str2.info);

    return Result;
}

String& String::operator+=(const String& str)
{
    String Result(this->lenth + str.lenth);
    Result.info = strcat(this->info, str.info);
    *this = Result.info;

    return *this;
}

String& String::operator+=(const char* str)
{
    String Result(this->lenth + strlen(str));
    Result.info = strcat(this->info, str);
    this->info = Result.info;

    return *this;
}

String& String::operator=(const String& str)
{
    this->lenth = str.lenth;
    this->info = new char[str.lenth];
    this->info = str.info;

    return *this;
}

char String::operator[](int index)
{
    return this->info[index];
}

String String::operator()(int index1, int index2)
{
    String Str(index2 - index1);
    int i = 0;
    while(i != Str.lenth)
    {
        Str.info[i] = this->info[index1];
        index1++;
    }

    return Str;
}

int String::operator>(const String& str)
{
    if(this->lenth > str.lenth)
    {
        return this->lenth;
    } 
    else 
    {
        return str.lenth;
    }
}

int String::operator>(const char* str)
{
    if(this->lenth > strlen(str))
    {
        return this->lenth;
    } 
    else 
    {
        return strlen(str);
    }
}

int String::operator<(const String& str)
{
    if(this->lenth < str.lenth)
    {
        return this->lenth;
    } 
    else 
    {
        return str.lenth;
    }
}

int String::operator<(const char* str)
{
    if(this->lenth < strlen(str))
    {
        return this->lenth;
    } 
    else 
    {
        return strlen(str);
    }
}

String& String::operator++()
{
    
}

String& String::operator--()
{

}