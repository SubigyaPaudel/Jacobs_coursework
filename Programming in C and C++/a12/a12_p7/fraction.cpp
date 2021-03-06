#include <iostream>
#include "fraction.h"

using namespace std;

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	int tmp_gcd = gcd(n, d);
    num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b)
{
    int tmp_gcd = 1, lesser;
    if(a < b)
        lesser = a;
    else
        lesser = b ;   
    for(int i = 1; i <= lesser; i++){
        if(a % i == 0 && b % i == 0){
            tmp_gcd = i;
        }
    }
	return tmp_gcd;
}

int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);

}

int Fraction::getnum() const{
    return num;
}

int Fraction::getden() const{
    return den;
}

void Fraction::Fraction::print() const
{
	std::cout << num << "/" << den << std::endl;
}


ostream& operator <<(ostream& out, const Fraction & frac){
    out << frac.getnum() << "/" << frac.getden();
    return out;
}

istream& operator >>(istream& in, Fraction& frac){
    in >> frac.num;
    getchar();
    in >> frac.den;
    return in;
}

Fraction operator /(Fraction& a, Fraction& b){
    int newnum, newdem;
    newnum = a.getnum() * b.getden();
    newdem = a.getden() * b.getnum();
    return (Fraction(newnum, newdem));
}

Fraction operator *(const Fraction& a, const Fraction& b){
    int newnum, newdem;
    newnum = a.getnum() * b.getnum();
    newdem = a.getden() * b.getden();
    return (Fraction(newnum, newdem));  
}

Fraction Fraction::operator+(const Fraction& a){
    int newden, newnum;
    newden = lcm(this->den, a.getden());
    newnum = (newden / this->den) * this->num + (newden/a.getden()) * a.num;
    return Fraction(newnum,newden);
}

Fraction Fraction::operator-(const Fraction& a){
    int newden, newnum;
    newden = lcm(this->den, a.getden());
    newnum = (newden / this->den) * this->num - (newden/a.getden()) * a.num;
    return Fraction(newnum, newden);
}

void Fraction::operator=(const Fraction& a){
    this->den = a.getden();
    this->num = a.getnum();
}

bool Fraction::operator<(const Fraction& a){
    Fraction compare;
    compare = *this - a;
    return (compare.getnum() < 0);
}

bool Fraction::operator>(const Fraction& a){
    Fraction compare;
    compare = *this -a;
    return (compare.getnum() > 0);
}

Fraction::~Fraction(){  
}