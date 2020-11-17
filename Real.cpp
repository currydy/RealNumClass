#include "Real.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

/* Default Constructor */
Real::Real(){
    neg = false;
    strFrac = "";
    strWhole = "";
    tempFull = "";
    whole = 0.0;
    frac_component = 0.0;
    dubResult = 0.0;
    l_longWhole = 0;
    l_longFrac = 0;

}



/* Copy Constructor */
Real::Real(const Real & R){
   neg = R.neg;
   strFrac = R.strFrac;
   strWhole = R.strWhole;
   tempFull = R.tempFull;
   l_longWhole = R.l_longWhole;
   l_longFrac = R.l_longFrac;
   dubResult = R.dubResult;
   whole = R.whole;
   frac_component = R.frac_component;
}



/* Additional Constructor (string) */
Real::Real(const string & S){
    string str = S;
    bool pastDot = false;
    strFrac = "";
    strWhole = "";

    if(S[0] == '-') {
        neg = true;
        str = S.substr(1, S.length() - 1);
    }
    else
        neg = false;

    for(char i : str){
        if(i == '.')
            pastDot = true;
        if(pastDot)
            strFrac += i;
        else
            strWhole += i;
    }
    tempFull = "";
    whole = 0.0;
    frac_component = 0.0;
    dubResult = 0.0;
    l_longWhole = 0;
    l_longFrac = 0;

}



/* Additional Constructor  (long long Whole and Fraction) */
Real::Real (long long W, long long D){
    if(to_string(W)[0] == '-')
        neg = true;
    else
        neg = false;
    strFrac = to_string(D);
    strWhole = to_string(W);
    tempFull = "";
    whole = 0.0;
    frac_component = 0.0;
    dubResult = 0.0;
    l_longWhole = 0;
    l_longFrac = 0;
}



/* Additional Constructor (double) */
Real::Real (double D){

    string S = to_string(D);
    bool pastDot = false;
    strFrac = "";
    strWhole = "";

    if(S[0] == '-') {
        neg = true;
        S = S.substr(1, S.length()-1);
    }
    else
        neg = false;

    for(char i : S){
        if(i == '.')
            pastDot = true;
        if(pastDot)
            strFrac += i;
        else
            strWhole += i;
    }
    tempFull = "";
    whole = 0.0;
    frac_component = 0.0;
    dubResult = 0.0;
    l_longWhole = 0;
    l_longFrac = 0;
}



/* Overloaded = operator */
Real & Real::operator = (const Real & R){
    if(this == &R)
        return *this;
    neg = R.neg;
    whole = R.whole;
    strFrac = R.strFrac;
    strWhole = R.strWhole;
    tempFull = R.tempFull;
    frac_component = R.frac_component;
    dubResult = R.dubResult;
    l_longFrac = R.l_longFrac;
    l_longFrac = R.l_longWhole;

    return *this;
}



/* Overloaded << operator */
ostream & operator << (ostream & outs, const Real & R) {
    if(R.neg){
        cout << '-' << R.strWhole << R.strFrac << endl;
        outs << '-' << R.strWhole << R.strFrac << endl;
    }
    else{
        cout << R.strWhole << R.strFrac << endl;
        outs << R.strWhole << R.strFrac << endl;
    }

    return outs;
}



/* Overloaded >> operator */
istream & operator >> (istream & ins, Real & R){
    ins >> R.tempFull;
    if(R.tempFull.find('.') == string::npos)
        R.strWhole = R.tempFull;
    else{
        R.strWhole = R.tempFull.substr(0, R.tempFull.find('.'));
        R.strFrac = R.tempFull.substr(R.tempFull.find('.'));
    }
    return ins;
}



/* Overloaded == operator */
bool Real::operator == (const Real & R) const{
    //Compare all members
    if((neg == R.neg) && (strFrac == R.strFrac) && (strWhole == R.strWhole) && (whole == R.whole) && (dubResult == R.dubResult) && (frac_component == R.frac_component))
        return true;
    return false;
}



/* Overloaded != operator */
bool Real::operator != (const Real & R) const{
    //Compare all members
    if((neg == R.neg) && (strFrac == R.strFrac) && (strWhole == R.strWhole) && (whole == R.whole) && (dubResult == R.dubResult) && (frac_component == R.frac_component))
        return false;
    return true;
}



/* Overloaded > operator */
bool Real::operator > (const Real & R) const{
    int lenDiffWhole = strWhole.length() - R.strWhole.length();
    int lenDiffFrac = strFrac.length() - R.strFrac.length();
    string tempWhole = strWhole;
    string tempWholeR = R.strWhole;
    string tempFrac = strFrac;
    string tempFracR = R.strFrac;
    lenDiffWhole = abs(lenDiffWhole);
    lenDiffFrac = abs(lenDiffFrac);
    string wZeros(lenDiffWhole, '0');
    string fZeros(lenDiffFrac, '0');

    if((this->neg) && !(R.neg))
        return false;
    else if(!(this->neg) && (R.neg))
        return true;

    //If they are the same then return false
    if(*this == R)
        return false;

    //Find out which whole number is larger
    if (strWhole.length() > R.strWhole.length()) {
        tempWholeR = wZeros + tempWholeR;
        return true;
    }
    else if (strWhole.length() < R.strWhole.length())
        tempWhole = wZeros + tempWhole;
    else{
        //If they are the same length, then which whole component is larger?
        for (int i = 0; i < tempWhole.length(); i++) {
            if (tempWhole[i] < tempWholeR[i]) {
                return false;
            } else if (tempWhole[i] > tempWholeR[i]) {
                return true;
            }
        }
    }
    //Find our which Fractional number is larger
    if (strFrac.length() > R.strFrac.length()) {
        tempFracR = tempFracR + fZeros;
        return true;
    } else if (strFrac.length() < R.strFrac.length())
        tempFrac = tempFrac + fZeros;
    else {

        //If they are the same length, then which fraction component is larger?
        for (int i = 0; i < tempFrac.length(); i++) {
            if (tempFrac[i] < tempFracR[i]) {
                return false;
            } else if (tempFrac[i] > tempFracR[i]) {
                return true;
            }
        }
    }
    return false;
}



/* Overloaded +>=operator */
bool Real::operator >= (const Real & R) const{
    if((*this > R) || (*this == R))
        return true;
    return false;
}



/* Overloaded < operator */
bool Real::operator < (const Real & R) const{
    if((*this > R) || (*this == R))
        return false;
    return true;
}



/* Overloaded <= operator */
bool Real::operator <= (const Real & R) const{
    if(*this > R)
        return false;
    return true;
}



/* Overloaded + operator */
Real Real::operator + (const Real & R) const{

    //Make a new Real() object to return once we have computed result
    Real *rResult = new Real();

    //Need to make a temp to avoid CONST issue when wanting to change the sign and call -operator
    Real *tempReal = new Real();

    //Declare and set locals
    int carry = 0;
    int lenDiffWhole = strWhole.length() - R.strWhole.length();
    int lenDiffFrac = strFrac.length() - R.strFrac.length();
    string tempThis;
    string tempR;
    string result;
    string tempWhole = strWhole;
    string tempWholeR = R.strWhole;
    string tempFrac = strFrac;
    string tempFracR = R.strFrac;
    lenDiffWhole = abs(lenDiffWhole);
    lenDiffFrac = abs(lenDiffFrac);
    string wZeros (lenDiffWhole, '0');
    string fZeros (lenDiffFrac, '0');

    //Pad numbers to be the same length
    if(strWhole.length() > R.strWhole.length())
        tempWholeR = wZeros + tempWholeR;
    else if(strWhole.length() < R.strWhole.length())
        tempWhole = wZeros + tempWhole;
    if(strFrac.length() > R.strFrac.length())
        tempFracR = tempFracR + fZeros;
    else if(strFrac.length() < R.strFrac.length())
        tempFrac = tempFrac + fZeros;
    tempThis = tempWhole + tempFrac;
    tempR = tempWholeR + tempFracR;

    //Reverse the two strings for proper addition technique
    reverse(tempThis.begin(), tempThis.end());
    reverse(tempR.begin(), tempR.end());

    //Perform addition
    if((!neg && !R.neg) || (neg && R.neg)) {
        for (int i = 0; i < tempThis.length(); i++) {
            if (tempThis[i] == '.') {
                result.push_back('.');
                continue;
            }
            int sum = ((tempThis[i] - '0') + (tempR[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        //Add carry digit to number if not zero
        if (carry)
            result.push_back(carry + '0');
    }
    //Using -operator in this case
    else if(neg && !R.neg) {
        *tempReal = *this;
        tempReal->neg = false;
        //We are essentially treating it like a pos - pos now
        *rResult = R - *tempReal;
        return *rResult;
    }
    //Using -operator in this case
    else{
        *tempReal = R;
        tempReal->neg = false;
        *rResult = *this - *tempReal;
        return *rResult;
    }
    //Reverse result string
    reverse(result.begin(), result.end());

    //Set rResult's Whole and Fraction portions using result
    std::size_t pos = result.find('.');
    rResult->strWhole = result.substr(0, pos);
    rResult->strFrac = result.substr(pos);

    return *rResult;
}



/* Overloaded += operator */
Real Real::operator += (const Real & R){

    //Declare and set locals
    int carry = 0;
    int lenDiffWhole = strWhole.length() - R.strWhole.length();
    int lenDiffFrac = strFrac.length() - R.strFrac.length();
    string tempThis;
    string tempR;
    string result;
    string tempWhole = strWhole;
    string tempWholeR = R.strWhole;
    string tempFrac = strFrac;
    string tempFracR = R.strFrac;
    lenDiffWhole = abs(lenDiffWhole);
    lenDiffFrac = abs(lenDiffFrac);
    string wZeros (lenDiffWhole, '0');
    string fZeros (lenDiffFrac, '0');

    //Pad numbers to be the same length
    if(strWhole.length() > R.strWhole.length())
        tempWholeR = wZeros + tempWholeR;
    else if(strWhole.length() < R.strWhole.length())
        tempWhole = wZeros + tempWhole;
    if(strFrac.length() > R.strFrac.length())
        tempFracR = tempFracR + fZeros;
    else if(strFrac.length() < R.strFrac.length())
        tempFrac = tempFrac + fZeros;
    tempThis = tempWhole + tempFrac;
    tempR = tempWholeR + tempFracR;

    //Reverse the two strings for proper addition technique
    reverse(tempThis.begin(), tempThis.end());
    reverse(tempR.begin(), tempR.end());

    //Perform addition
    if((!neg && !R.neg) || (neg && R.neg)) {
        for (int i = 0; i < tempThis.length(); i++) {
            if (tempThis[i] == '.') {
                result.push_back('.');
                continue;
            }
            int sum = ((tempThis[i] - '0') + (tempR[i] - '0') + carry);
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        //Add carry digit to number if not zero
        if (carry)
            result.push_back(carry + '0');
    }
    //Using -operator in this case
    else if(neg && !R.neg) {
        this->neg = false;
        //We are essentially treating it like a pos - pos now
        *this = R - *this;
        return *this;
    }
    //Using -operator in this case
    else{
        this->neg = false;
        *this= *this - R;
        return *this;
    }
    //Reverse result string
    reverse(result.begin(), result.end());

    //Set "this" object's Whole and Fraction portions using result
    std::size_t pos = result.find('.');
    strWhole = result.substr(0, pos);
    strFrac = result.substr(pos);
    neg = R.neg;
    frac_component = R.frac_component;
    dubResult = R.dubResult;
    l_longFrac = R.l_longFrac;
    l_longFrac = R.l_longWhole;

    return *this;
}



/* Overloaded ++ operator (pre) */
Real Real::operator ++ (){
    Real *tempReal = new Real(1.0);
    *this = *this + *tempReal;
    return *this;
}



/* Overloaded ++ operator (post) */
Real Real::operator ++ (int){
    Real tmp(*this);
    operator++();
    return tmp;
}



/* Overloaded - operator */
Real Real::operator - (const Real & R) const {
    //Make a new Real() object to return once we have computed result
    Real *rResult = new Real();

    //Need to make a temp to avoid CONST issue when wanting to change the sign and call +operator
    Real *tempReal = new Real();

    //Declare and set locals
    int carry = 0;
    bool thisWholeLarger = false;
    bool thisFracLarger = false;
    int lenDiffWhole = strWhole.length() - R.strWhole.length();
    int lenDiffFrac = strFrac.length() - R.strFrac.length();
    string biggerNumber;
    string smallerNumber;
    string tempThis;
    string tempR;
    string result;
    string tempWhole = strWhole;
    string tempWholeR = R.strWhole;
    string tempFrac = strFrac;
    string tempFracR = R.strFrac;
    lenDiffWhole = abs(lenDiffWhole);
    lenDiffFrac = abs(lenDiffFrac);
    string wZeros(lenDiffWhole, '0');
    string fZeros(lenDiffFrac, '0');

    //Pad numbers to be the same length
    //And find out which number is larger
    if (strWhole.length() > R.strWhole.length()) {
        tempWholeR = wZeros + tempWholeR;
        thisWholeLarger = true;
    } else if (strWhole.length() < R.strWhole.length())
        tempWhole = wZeros + tempWhole;
    else {

        //If they are the same length, then which whole component is larger?
        for (int i = 0; i < tempWhole.length(); i++) {
            if (tempWhole[i] < tempWholeR[i]) {
                thisWholeLarger = false;
                break;
            } else if (tempWhole[i] > tempWholeR[i]) {
                thisWholeLarger = true;
                break;
            }
        }
    }
    if (strFrac.length() > R.strFrac.length()) {
        tempFracR = tempFracR + fZeros;
        thisFracLarger = true;
    } else if (strFrac.length() < R.strFrac.length())
        tempFrac = tempFrac + fZeros;
    else {

        //If they are the same length, then which fraction component is larger?
        for (int i = 0; i < tempFrac.length(); i++) {
            if (tempFrac[i] < tempFracR[i]) {
                thisFracLarger = false;
                break;
            } else if (tempFrac[i] > tempFracR[i]) {
                thisFracLarger = true;
                break;
            }
        }
    }

    //Concatenate whole and fractional components
    tempThis = tempWhole + tempFrac;
    tempR = tempWholeR + tempFracR;

    //Need to set the bigger string and smaller string based on which number is numerically larger
    if (thisWholeLarger || (*this == R) || ((tempWhole == tempWholeR) && (thisFracLarger))) {
        biggerNumber = tempThis;
        smallerNumber = tempR;
        rResult->neg = this->neg;
    } else {
        biggerNumber = tempR;
        //If the right operand is bigger and the signs are the same for both operands, we preemtively change the result sign
        if(this->neg && R.neg)
            rResult->neg = false;
        else if(!(this->neg) && !(R.neg))
            rResult->neg = true;
        smallerNumber = tempThis;
    }

    //Reverse the two strings for proper subtraction technique
    reverse(biggerNumber.begin(), biggerNumber.end());
    reverse(smallerNumber.begin(), smallerNumber.end());

    if((!neg && !R.neg) || (neg && R.neg)){
        //Perform subtraction
        for (int i = 0; i < biggerNumber.length(); i++) {
            if (biggerNumber[i] == '.') {
                result.push_back('.');
                continue;
            }

            int sub = ((biggerNumber[i] - '0') - (smallerNumber[i] - '0') - carry);

            //If the subtraction resulted in a negative, we need to add ten and set the carry
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            result.push_back(sub + '0');
        }
    }
    //Using the +operator for this case
    else if(neg && !R.neg) {
        *tempReal = *this;
        tempReal->neg = false;
        *rResult = *tempReal + R;
        rResult->neg = true;
        return *rResult;
    }
    //Using the +operator for this case
    else{
        *tempReal = R;
        tempReal->neg = false;
        *rResult = *this + *tempReal;
        return *rResult;
    }

    //Reverse result string
    reverse(result.begin(), result.end());


    //Set rResult's Whole and Fraction portions using result
    std::size_t pos = result.find('.');
    rResult->strWhole = result.substr(0, pos);
    rResult->strFrac = result.substr(pos);

    return *rResult;
    
}



/* Overloaded -= operator */
Real Real::operator -= (const Real & R){

    //Need to make a temp to avoid CONST issue when wanting to change the sign and call +operator
    Real *tempReal = new Real();

    //Declare and set locals
    int carry = 0;
    bool thisWholeLarger = false;
    bool thisFracLarger = false;
    int lenDiffWhole = strWhole.length() - R.strWhole.length();
    int lenDiffFrac = strFrac.length() - R.strFrac.length();
    string biggerNumber;
    string smallerNumber;
    string tempThis;
    string tempR;
    string result;
    string tempWhole = strWhole;
    string tempWholeR = R.strWhole;
    string tempFrac = strFrac;
    string tempFracR = R.strFrac;
    lenDiffWhole = abs(lenDiffWhole);
    lenDiffFrac = abs(lenDiffFrac);
    string wZeros(lenDiffWhole, '0');
    string fZeros(lenDiffFrac, '0');

    //Pad numbers to be the same length
    //And find out which number is larger
    if (strWhole.length() > R.strWhole.length()) {
        tempWholeR = wZeros + tempWholeR;
        thisWholeLarger = true;
    } else if (strWhole.length() < R.strWhole.length())
        tempWhole = wZeros + tempWhole;
    else {

        //If they are the same length, then which whole component is larger?
        for (int i = 0; i < tempWhole.length(); i++) {
            if (tempWhole[i] < tempWholeR[i]) {
                thisWholeLarger = false;
                break;
            } else if (tempWhole[i] > tempWholeR[i]) {
                thisWholeLarger = true;
                break;
            }
        }
    }
    if (strFrac.length() > R.strFrac.length()) {
        tempFracR = tempFracR + fZeros;
        thisFracLarger = true;
    } else if (strFrac.length() < R.strFrac.length())
        tempFrac = tempFrac + fZeros;
    else {

        //If they are the same length, then which fraction component is larger?
        for (int i = 0; i < tempWhole.length(); i++) {
            if (tempFrac[i] < tempFracR[i]) {
                thisFracLarger = false;
                break;
            } else if (tempFrac[i] > tempFracR[i]) {
                thisFracLarger = true;
                break;
            }
        }
    }

    //Concatenate whole and fractional components
    tempThis = tempWhole + tempFrac;
    tempR = tempWholeR + tempFracR;

    //Need to set the bigger string and smaller string based on which number is numerically larger
    if (thisWholeLarger || (*this == R) || ((tempWhole == tempWholeR) && (thisFracLarger))) {
        biggerNumber = tempThis;
        smallerNumber = tempR;
        //rResult->neg = this->neg;
    } else {
        biggerNumber = tempR;
        //If the right operand is bigger and the signs are the same for both operands, we preemtively change the result sign
        if(this->neg && R.neg)
            this->neg = false;
        else if(!(this->neg) && !(R.neg))
            this->neg = true;
        smallerNumber = tempThis;
    }

    //Reverse the two strings for proper subtraction technique
    reverse(biggerNumber.begin(), biggerNumber.end());
    reverse(smallerNumber.begin(), smallerNumber.end());

    if((!neg && !R.neg) || (neg && R.neg)){
        //Perform subtraction
        for (int i = 0; i < biggerNumber.length(); i++) {
            if (biggerNumber[i] == '.') {
                result.push_back('.');
                continue;
            }

            int sub = ((biggerNumber[i] - '0') - (smallerNumber[i] - '0') - carry);

            //If the subtraction resulted in a negative, we need to add ten and set the carry
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            result.push_back(sub + '0');
        }
    }
        //Using the +operator for this case
    else if(neg && !R.neg) {
        this->neg = false;
        *this = *this + R;
        this->neg = true;
        return *this;
    }
        //Using the +operator for this case
    else{
        *tempReal = R;
        tempReal->neg = false;
        *this = *this + *tempReal;
        return *this;
    }

    //Reverse result string
    reverse(result.begin(), result.end());

    //Set rResult's Whole and Fraction portions using result
    std::size_t pos = result.find('.');
    strWhole = result.substr(0, pos);
    strFrac = result.substr(pos);
    neg = R.neg;
    frac_component = R.frac_component;
    dubResult = R.dubResult;
    l_longFrac = R.l_longFrac;
    l_longFrac = R.l_longWhole;

    return *this;
}


/* Overloaded -- operator (pre) */
Real Real::operator -- (){
    Real *tempReal = new Real(1.0);
    *this = *this - *tempReal;
    return *this;
}


/* Overloaded -- operator (post) */
Real Real::operator -- (int){
    Real tmp(*this);
    operator--();
    return tmp;
}



/* Overloaded * operator */
Real Real::operator * (const Real & R) const{

    //Need to make a temp to avoid CONST issue when wanting to change the sign and call +operator
    Real *tempReal = new Real();

    string str1 = strFrac.empty() ? strWhole : strWhole + strFrac.substr(1);
    string str2 = R.strFrac.empty() ? R.strWhole : R.strWhole + R.strFrac.substr(1);

    if (str1=="0" || str2=="0")
        tempReal->strWhole = "0";

    int len1 = str1.length();
    int len2  = str2.length();
    vector<int> result(len1+len2, 0);
    string res;

    for (int i = len1 - 1; i >= 0; --i)
    {
        for (int j = len2 - 1; j >= 0; --j)
        {
            result[i+j+1] += (str1[i] - '0')*(str2[j] - '0');
        }
    }

    for (int k = len1 + len2 - 1; k > 0; --k){
        if (result[k] >= 10)
        {
            result[k-1] += result[k]/10;
            result[k] %= 10;
        }
    }

    int count = 0;
    for (int l=0; l<result.size(); ++l){
        if (result[l]==0 && l==count)
            ++count;
        else
            res += result[l] + '0';
    }
    int test = strFrac.length();
    res.insert(res.length() - (R.strFrac.length()-1+strFrac.length()-1), ".");
    tempReal->strWhole = res.substr(0, res.find('.'));
    tempReal->strFrac = res.substr(res.find('.'));

    return *tempReal;
}



/* Overloaded *= operator */
Real Real::operator *= (const Real & R){
    //Need to make a temp to avoid CONST issue when wanting to change the sign and call +operator
    //Real *tempReal = new Real();

    string str1 = strFrac.empty() ? strWhole : strWhole + strFrac.substr(1);
    string str2 = R.strFrac.empty() ? R.strWhole : R.strWhole + R.strFrac.substr(1);

    if (str1=="0" || str2=="0")
        strWhole = "0";

    int len1 = str1.length();
    int len2  = str2.length();
    vector<int> result(len1+len2, 0);
    string res;

    for (int i = len1 - 1; i >= 0; --i)
    {
        for (int j = len2 - 1; j >= 0; --j)
        {
            result[i+j+1] += (str1[i] - '0')*(str2[j] - '0');
        }
    }

    for (int k = len1 + len2 - 1; k > 0; --k){
        if (result[k] >= 10)
        {
            result[k-1] += result[k]/10;
            result[k] %= 10;
        }
    }

    int count = 0;
    for (int l=0; l<result.size(); ++l){
        if (result[l]==0 && l==count)
            ++count;
        else
            res += result[l] + '0';
    }
    int test = strFrac.length();
    res.insert(res.length() - (R.strFrac.length()-1+strFrac.length()-1), ".");
    strWhole = res.substr(0, res.find('.'));
    strFrac = res.substr(res.find('.'));

    return *this;
}


