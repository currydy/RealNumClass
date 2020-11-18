#pragma once
#include <iostream>
using namespace std;
class Real
{
    public:
        Real();
        Real(const Real & R);
        Real(const string & S);
        Real (long long W, long long D);
        Real (double D);
        Real & operator = (const Real & R);
        friend ostream & operator << (ostream & outs, const Real & R);
        friend istream & operator >> (istream & ins, Real & R);
        bool operator == (const Real & R) const;
        bool operator != (const Real & R) const;
        bool operator > (const Real & R) const;
        bool operator >= (const Real & R) const;
        bool operator < (const Real & R) const;
        bool operator <= (const Real & R) const;
        Real operator + (const Real & R) const;
        Real operator += (const Real & R);
        Real operator ++ ();
        Real operator ++ (int);
        Real operator - (const Real & R) const;
        Real operator -= (const Real & R);
        Real operator -- ();
        Real operator -- (int);
        Real operator * (const Real & R) const;
        Real operator *= (const Real & R);
    
    private:
        string strFrac;
        string strWhole;
        string tempFull;
        bool neg;
      
};
