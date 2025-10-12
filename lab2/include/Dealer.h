#pragma once

#include "Employer.h"
#include "Tourist.h"

class Dealer : public Employer, public Tourist
{
private:
    char address[10];

public:
    Dealer(char* n, Data data, char* l, Taxes t, char* p, Countries c, const char* ad) : Person(n, data), Employer(l, t), Tourist(p, c)
    {
        strcpy(this->address, ad);
    }
    ~Dealer(){};

    void setAddress(char*);
    char** getAddress() const;

    void show() override;
};