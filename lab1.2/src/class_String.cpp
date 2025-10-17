#include"class_String.h"

ostream& operator<<(ostream& out, const String& str)
{
    out << str.info;

    return out;
}

istream& operator>>(istream& in, String& str)
{
    in.clear();
    in.ignore(INT_MAX);
    char init[79];
    in.getline(init, 79);

    delete [] str.info;
    str.lenth = strlen(init);
    str.info = new char[str.lenth + 1];
    strcpy(str.info, init);

    return in;
}

String String::operator+(const String& str)                             //объект + объект
{
    String Result(this->lenth + str.lenth);
    strcpy(Result.info, this->info);
    strcat(Result.info, str.info);

    return Result;
}

String& String::operator+=(const String& str)
{
    // String Result(this->lenth + str.lenth);
    // strcpy(Result.info, this->info);
    // strcat(Result.info, str.info);
    // *this = Result.info;
    *this = *this + str;

    return *this;
}

String String::operator+(const char* str)                             // объект + строка
{
    String Result(this->lenth + strlen(str)); 
    strcpy(Result.info, str);
    Result = Result + *this;
    
    return Result;
}

String operator+(char* str1, const String& str2)                       //строка + объект
{
    String Result(strlen(str1) + str2.lenth);
    strcpy(Result.info, str1);
    strcat(Result.info, str2.info);
    //String Result(*str1);
    //Result = Result + str2;

    return Result;
}

String String::operator-(const String& str)                           // объект - объект
{
    String Result(this->lenth);
    int realSize = 0;
    for(int i = 0; i < this->lenth; ++i)
    {
        for(int j = 0; j < str.lenth; ++j)
        {
            if(this->info[i] != str.info[j])
            {
                Result.info[i] = this->info[i];
                realSize++;
            }
        }
    }

    Result.lenth = realSize;
    // for(int i = 0; i < Result.lenth; ++i)
    // {
    // this->info[i] = Result.info[i];
    // }
    Result.info[Result.lenth + 1] = '\0';

    return Result;
}

String String::operator-(const char* str)                             // объект - строка
{
    String Result(this->lenth);
    int realSize = 0;
    for(int i = 0; i < this->lenth; ++i)
    {
        for(int j = 0; j < strlen(str); ++j)
        {
            if(this->info[i] != str[j])
            {
                Result.info[i] = this->info[i];
                realSize++;
            }
        }
    }
    Result.lenth = realSize;
    Result.info[Result.lenth + 1] = '\0';

    return Result;
}

String operator-(char* str1, const String& str2)                      // строка - объект
{
    String Result(strlen(str1));
    int realSize = 0;
    for(int i = 0; i < strlen(str1); ++i)
    {
        for(int j = 0; j < str2.lenth; ++j)
        {
            if(str1[i] != str2.info[j])
            {
                Result.info[i] = str1[i];
                realSize++;
            }
        }
    }

    Result.lenth = realSize;
    Result.info[Result.lenth + 1] = '\0';

    return Result;
}



String& String::operator+=(const char* str)
{
    String Result(this->lenth + strlen(str));
    Result.info = strcat(this->info, str);
    this->info = Result.info;

    return *this;
}

String& String::operator-=(const String& str)
{
    String Result(this->lenth);
    int realSize = 0;
    for(int i = 0; i < this->lenth; ++i)
    {
        for(int j = 0; j < str.lenth; ++j)
        {
            if(this->info[i] != str.info[j])
            {
                Result.info[i] = this->info[i];
                realSize++;
            }
        }
    }

    this->lenth = realSize;
    for(int i = 0; i < this->lenth; ++i)
    {
        this->info[i] = Result.info[i];
    }
    this->info[this->lenth + 1] = '\0';

    return *this;
}

String& String::operator-=(const char* str)
{
    String Result(this->lenth);
    int realSize = 0;
    for(int i = 0; i < this->lenth; ++i)
    {
        for(int j = 0; j < strlen(str); ++j)
        {
            if(this->info[i] != str[j])
            {
                Result.info[i] = this->info[i];
                realSize++;
            }
        }
    }

    this->lenth = realSize;
    for(int i = 0; i < this->lenth; ++i)
    {
        this->info[i] = Result.info[i];
    }
    this->info[this->lenth + 1] = '\0';

    return *this;
}

String& String::operator=(const String& str)
{
    if(this != &str)
    {
        delete[] this->info;
        this->lenth = str.lenth;
        this->info = new char[str.lenth + 1];
    }
    strcpy(this->info, str.info);

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

String& String::operator++()                               //закодировать  строку
{
    for(int i = 0; i < this->lenth; ++i)
    {
        this->info[i] = 255 - this->info[i];
    }

    return *this;
}

String& String::operator--()                               //раскодировать строку
{
    for(int i = 0; i < this->lenth; ++i)
    {
        this->info[i] = 255 - this->info[i];
    }

    return *this;
}

String String::operator*(int number)
{
    String Result(this->lenth * number);
    for(int i = 0; i < number; ++i)
    {
        Result += *this;
        Result.info[this->lenth * (i + 1)] = ' ';
    }

    return Result;
}

String String::operator&(const String& str)
{
    String Result(this->lenth);
    int realSize = 0;
    for(int i = 0; i < this->lenth; ++i)
    {
        for(int j = 0; j < str.lenth; ++j)
        {
            if(this->info[i] == str.info[j])
            {
                Result.info[i] == this->info[i];
                realSize++;
            }
        }
    }

    Result.lenth = realSize;
    Result.info[Result.lenth + 1] = '\0';

    return Result;
}