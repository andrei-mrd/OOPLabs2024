#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex operator + (const Complex& l, const Complex& r) {
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}
Complex operator+(const Complex& l, double r) {
    return Complex(l.real() + r, l.imag());
}
Complex operator+(double l, const Complex& r) {
    return Complex(l + r.real(), r.imag());
}

Complex operator-(const Complex& obj) {
    return Complex(-obj.real(), -obj.imag());
}
Complex operator-(double l, const Complex& r) {
    return Complex(l - r.real(), r.imag());
}
Complex operator-(const Complex & l, double r) {
    return Complex(l.real() - r, l.imag());
}
Complex operator-(const Complex& l, const Complex& r) {
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

bool operator==(const Complex& l, const Complex& r) {
    if (l.real() == r.real() && l.imag() == r.imag()) {
        return true;
    }
    else return false;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.real() << " + " << complex.imag() << "i";
    return out;
}

Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

Complex operator*(const Complex& l, const Complex& r) {
    return Complex((l.real() * r.real() - l.imag() * r.imag()), (l.real() * r.imag() + l.imag() * r.real()));
}
Complex operator*(const Complex& l, double r) {
    return Complex(l.real() * r, l.imag() * r);
}
Complex operator*(double l, const Complex& r) {
    return Complex(l * r.imag(), l * r.imag());
}

bool operator!=(const Complex& l, const Complex& r) {
    return((l.real() != r.real()) || (l.imag() != r.imag()));
}

Complex& Complex::operator++() {
    this->real_data++;
    return *this;
}

Complex Complex::operator++(int arg) {
    Complex temp = *this;  
    this->real_data++;     
    return temp;
}

Complex& Complex::operator--() {
    this->real_data--;
    return *this;
}

Complex Complex::operator--(int arg) {
    Complex temp = *this;
    this->real_data--;
    return temp;
}