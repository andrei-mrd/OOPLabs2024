#ifndef _ERRNO_T_DEFINED
#define _ERRNO_T_DEFINED
typedef int errno_t; // Define errno_t as an integer type
#endif


#include "Number.h"
#include <cstring>
#include <cmath>
#include <iostream>

Number::Number(const char* value, int base) {
    //std::cout << "ctor was called";
    if (base >= 2 && base <= 16) {
        this->value = new char[strlen(value) + 1];
        this->base = base;
        //errno_t err = strcpy_s(this->value, sizeof(value), value);
        //strncpy_s(this->value, strlen(value) + 1, value, strlen(value) + 1);
        strcpy_s(this->value, strlen(value) + 1, value);
        //strcpy(this->value, value);
    }
}

Number::~Number() {
    delete[] this->value;
}

Number::Number(const Number& d) {
    this->value = d.value;
    this->base = d.base;
}

Number::Number(Number&& d) {
    char* temp = d.value;
    d.value = nullptr;
    this->value = temp;
    this->base = d.base;
}

Number::Number(int v) {
    this->base = 10;
    int cpy = v, nrcif = 0;
    while (cpy) {
        nrcif++;
        cpy /= 10;
    }
    delete[] this->value;
    this->value = new char[nrcif + 1];
    this->value[nrcif] = '\0';

    while (v)
    {
        this->value[--nrcif] = v % 10 + '0';
        v /= 10;
    }
}

Number& operator + (Number& n1, Number& n2) {
    int base1, base2;
    base1 = n1.GetBase();
    base2 = n2.GetBase();

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    int number1 = 0 , number2 = 0, cnt1 = 0, cnt2 = 0;

    while (n1.value[cnt1])
    {
        number1 = number1 * 10 + (n1.value[cnt1++] - '0');
    }

    while (n2.value[cnt2]) {
        number2 = number2 * 10 + (n2.value[cnt2++] - '0');
    }

    number1 += number2;

    

    int cpyNumber = number1, nrcif = 0;;
    while (cpyNumber)
    {
        nrcif++;
        cpyNumber /= 10;
    }


    delete[] n1.value;
    n1.value = new char[nrcif + 1];
    n1.value[nrcif] = '\0';
    while (number1)
    {
        n1.value[--nrcif] = number1 % 10 + '0';
        number1 /= 10;
    }

    if (base1 > base2) {
        n1.SwitchBase(base1);
        
    }
    else {
        n1.SwitchBase(base2);
        
    }
    
    return n1;
}
Number& operator - (Number& n1, Number& n2) {
    int base1 = n1.GetBase(), base2 = n2.GetBase();

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    //std::cout << base1 << " " << base2 << "\n";

    int number1 = 0, number2 = 0;
    int cnt1 = 0, cnt2 = 0;
    while (cnt1 != strlen(n1.value)) {
        number1 = number1 * 10 + (n1.value[cnt1++] - '0');
    }
    while (cnt2 != strlen(n2.value))
    {
        number2 = number2 * 10 + (n2.value[cnt2++] - '0');
    }
    //std::cout << number1 << " " << number2;
    number1 -= number2;
    delete[] n1.value;
    n1.value = new char[cnt1 + 1];
    n1.value[cnt1] = '\0';

    while (number1)
    {
        n1.value[--cnt1] = number1 % 10 + '0';
        number1 /= 10;
    }


    if (base1 > base2) {
        n1.SwitchBase(base1);
        
    }
    else {
        n1.SwitchBase(base2);
        
    }
    return n1;
}
Number& operator += (Number& n1, Number& n2) {
    int base1, base2;
    base1 = n1.GetBase();
    base2 = n2.GetBase();

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    int number1 = 0, number2 = 0, cnt1 = 0, cnt2 = 0;

    while (n1.value[cnt1])
    {
        number1 = number1 * 10 + (n1.value[cnt1++] - '0');
    }

    while (n2.value[cnt2]) {
        number2 = number2 * 10 + (n2.value[cnt2++] - '0');
    }

    number1 += number2;



    int cpyNumber = number1, nrcif = 0;;
    while (cpyNumber)
    {
        nrcif++;
        cpyNumber /= 10;
    }


    delete[] n1.value;
    n1.value = new char[nrcif + 1];
    n1.value[nrcif] = '\0';
    while (number1)
    {
        n1.value[--nrcif] = number1 % 10 + '0';
        number1 /= 10;
    }

    if (base1 > base2) {
        n1.SwitchBase(base1);

    }
    else {
        n1.SwitchBase(base2);

    }
    return n1;
}
Number& operator -= (Number& n1, Number& n2) {
    int base1 = n1.GetBase(), base2 = n2.GetBase();

    n1.SwitchBase(10);
    n2.SwitchBase(10);

    //std::cout << base1 << " " << base2 << "\n";

    int number1 = 0, number2 = 0;
    int cnt1 = 0, cnt2 = 0;
    while (cnt1 != strlen(n1.value)) {
        number1 = number1 * 10 + (n1.value[cnt1++] - '0');
    }
    while (cnt2 != strlen(n2.value))
    {
        number2 = number2 * 10 + (n2.value[cnt2++] - '0');
    }
    //std::cout << number1 << " " << number2;
    number1 -= number2;
    delete[] n1.value;
    n1.value = new char[cnt1 + 1];
    n1.value[cnt1] = '\0';

    while (number1)
    {
        n1.value[--cnt1] = number1 % 10 + '0';
        number1 /= 10;
    }


    if (base1 > base2) {
        n1.SwitchBase(base1);

    }
    else {
        n1.SwitchBase(base2);

    }
    return n1;
}

bool Number::operator>(Number& arg) {
    int initialBase1 = this->base, initialBase2 = arg.base;
    SwitchBase(10);
    arg.SwitchBase(10);
    int number1 = 0, number2 = 0;

    int nrDig1 = GetDigitsCount(), nrDig2 = arg.GetDigitsCount(), cnt = 0;
    while (cnt < nrDig1)
    {
        number1 = number1 * 10 + (this->value[cnt] - '0');
        cnt++;
    }
    cnt = 0;
    while (cnt < nrDig2)
    {
        number2 = number2 * 10 + (arg.value[cnt] - '0');
        cnt++;
    }

    bool ret = false; //daca e 0 se returneaza 0, altfel 1
    if (number1 > number2) {
        ret = true;
    }

    SwitchBase(initialBase1);
    arg.SwitchBase(initialBase2);
    return ret;
}
bool Number::operator<(Number& arg) {
    int initialBase1 = this->base, initialBase2 = arg.base;
    SwitchBase(10);
    arg.SwitchBase(10);
    int number1 = 0, number2 = 0;

    int nrDig1 = GetDigitsCount(), nrDig2 = arg.GetDigitsCount(), cnt = 0;
    while (cnt < nrDig1)
    {
        number1 = number1 * 10 + (this->value[cnt] - '0');
        cnt++;
    }
    cnt = 0;
    while (cnt < nrDig2)
    {
        number2 = number2 * 10 + (arg.value[cnt] - '0');
        cnt++;
    }

    bool ret = false; //daca e 0 se returneaza 1, altfel 0
    if (number1 > number2) {
        ret = false;
    }

    SwitchBase(initialBase1);
    arg.SwitchBase(initialBase2);
    return ret;
}
bool Number::operator>=(Number& arg) {
    int initialBase1 = this->base, initialBase2 = arg.base;
    SwitchBase(10);
    arg.SwitchBase(10);
    int number1 = 0, number2 = 0;

    int nrDig1 = GetDigitsCount(), nrDig2 = arg.GetDigitsCount(), cnt = 0;
    while (cnt < nrDig1)
    {
        number1 = number1 * 10 + (this->value[cnt] - '0');
        cnt++;
    }
    cnt = 0;
    while (cnt < nrDig2)
    {
        number2 = number2 * 10 + (arg.value[cnt] - '0');
        cnt++;
    }

    bool ret = false; //daca e 0 se returneaza 0, altfel 1
    if (number1 >= number2) {
        ret = true;
    }

    SwitchBase(initialBase1);
    arg.SwitchBase(initialBase2);
    return ret;
}
bool Number::operator==(Number& arg) {
    int initialBase1 = this->base, initialBase2 = arg.base;
    SwitchBase(10);
    arg.SwitchBase(10);
    int number1 = 0, number2 = 0;

    int nrDig1 = GetDigitsCount(), nrDig2 = arg.GetDigitsCount(), cnt = 0;
    while (cnt < nrDig1)
    {
        number1 = number1 * 10 + (this->value[cnt] - '0');
        cnt++;
    }
    cnt = 0;
    while (cnt < nrDig2)
    {
        number2 = number2 * 10 + (arg.value[cnt] - '0');
        cnt++;
    }

    bool ret = false; //daca e 0 se returneaza 0, altfel 1
    if (number1 == number2) {
        ret = true;
    }

    SwitchBase(initialBase1);
    arg.SwitchBase(initialBase2);
    return ret;
}
bool Number::operator<=(Number& arg) {
    int initialBase1 = this->base, initialBase2 = arg.base;
    SwitchBase(10);
    arg.SwitchBase(10);
    int number1 = 0, number2 = 0;

    int nrDig1 = GetDigitsCount(), nrDig2 = arg.GetDigitsCount(), cnt = 0;
    while (cnt < nrDig1)
    {
        number1 = number1 * 10 + (this->value[cnt] - '0');
        cnt++;
    }
    cnt = 0;
    while (cnt < nrDig2)
    {
        number2 = number2 * 10 + (arg.value[cnt] - '0');
        cnt++;
    }

    bool ret = false; //daca e 0 se returneaza 0, altfel 1
    if (number1 <= number2) {
        ret = true;
    }

    SwitchBase(initialBase1);
    arg.SwitchBase(initialBase2);
    return ret;
}
void Number::operator=(int number) {
    this->base = 10;
    int nrcif = 0, cpyNumber = number;
    while (cpyNumber)
    {
        nrcif++;
        cpyNumber /= 10;
    }
    delete[] this->value;
    this->value = new char[nrcif + 1];
    this->value[nrcif] = '\0';
    while (number)
    {
        this->value[--nrcif] = number % 10 + '0';
        number /= 10;
    }
}
void Number::operator=(Number& arg) {
    this->base = arg.base;
    delete[] this->value;
    this->value = new char[strlen(arg.value) + 1];
    strcpy_s(this->value, strlen(arg.value) + 1, arg.value);
    //strcpy(this->value, arg.value);
}
void Number::operator=(const char* arg) {
    delete[] this->value;
    this->value = new char[strlen(arg) + 1];
    strcpy_s(this->value, strlen(arg) + 1, arg);
}
Number& Number::operator--() {
    int i = 0;
    while (this->value[i + 1])
    {
        this->value[i] = this->value[i + 1];
        i++;
    }
    this->value[i] = '\0';

    return *this;
}
void Number::operator --(int arg) {
    this->value[strlen(this->value) - 1] = '\0';
}
char Number::operator [](int arg) {
    if (arg >= 0 && arg < strlen(this->value)) {
        return this->value[arg];
    }
    else {
        std::cout << "Eroare";
        return 'e';
    }
}

void Number::SwitchBase(int newBase) {
    int decimal = 0;
    int power = 0;
    char digit = ' ';
    int digitValue = 0;

    for (int i = strlen(this->value) - 1; i >= 0; i--) {
        digit = this->value[i];
        digitValue = 0;

        if (isdigit(digit))
            digitValue = digit - '0';
        else
            digitValue = toupper(digit) - 'A' + 10;

        decimal += digitValue * (int)pow(this->base, power);
        power++;
    }
    this->base = newBase;
    int cpyDecimal = decimal, nrcif = 0;
    while (cpyDecimal) {
        nrcif++;
        cpyDecimal /= 10;
    }
    
    char* result = new char[nrcif + 1];
    result[nrcif] = '\0';

    int remainder = 0;
    int cnt = 0;


    while (decimal > 0) {

        remainder = decimal % newBase;
        if (remainder < 10)
            digit = remainder + '0';
        else
            digit = remainder - 10 + 'A';

        
        result[cnt++] = digit;

        decimal /= newBase;
    }

    result[cnt] = '\0';
    
    int start = 0;
    int end = cnt - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    delete[] this->value;
    this->value = new char[strlen(result) + 1];
    strncpy_s(this->value, strlen(result) + 1, result, strlen(result) + 1);
    //strcpy(this->value, result);
    delete[] result;
}
void Number::Print() {
	std::cout << this->value<<"\n";
}
int Number::GetDigitsCount() {
    int count = 0;
    while (this->value[count])
    {
        count++;
    }
    return count;
}
int Number::GetBase() {
    int x = this->base;
	return x;
}
