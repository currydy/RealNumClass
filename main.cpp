//
// Created by Dylan on 11/1/2020.
//

#include "Real.h"
#include <fstream>

int main(){

    ofstream myOutStream;
    ifstream myInStream;

    myOutStream.open("myfile.txt");
    myInStream.open("testInput.txt");

    if(!myInStream.is_open())
        cout << "PROBLEM OPENING INPUT FILE" << endl;
    long long myLong = 12345;
    double myDub = 7.75;
    double myDub2 = 6.25;

    double myDub3 = 3.5;
    double myDub4 = -4.25;
    double myDub6 = -4.25;
    string myStr  = "50.425";
    string myStr2 = "50.421";
    string myStr3 = "22.5";
    string myStr4 = "23.5";
    Real myReal(myDub);
    Real myReal2(myDub2);
    Real myReal3(myDub3);
    Real myReal4(myDub4);
    Real myReal5(myStr);
    Real myReal6(myDub6);
    Real myReal7(myStr2);
    Real myReal8(myStr);

    if(myReal3 == myReal4)
        cout << "TRUE" << endl;

    //myReal2 = myReal + myReal2;
    myReal3 = myReal - myReal2;
    myOutStream << myReal3 << endl;
    myReal5 = myReal3 + myReal4;
    myOutStream << myReal5 << endl;
    cout << "last myReal5 value" << endl;
    myReal5 = myReal4 + myReal3;
    myOutStream << myReal5 << endl;
    myReal2++;
    ++myReal2;
    myReal3 += myReal4;
    myOutStream << myReal3;
    myReal3 += myReal6;
    cout << "testing myReal3_1" << endl;
    myOutStream << myReal3;
    myReal3 = myReal3 - myReal6;
    myOutStream << myReal3;
    //myOutStream << myReal4 << endl;
    myOutStream << myReal2;
    myOutStream << myReal6;
    cout << "testing2" << endl;
    myOutStream << myReal6 - myReal2;
    myOutStream << myReal2 - myReal6;
    myReal6 -= myReal2;
    myOutStream << myReal6;
    myReal3 -= myReal6;
    myOutStream << myReal3;
    --myReal3;
    myOutStream << myReal3;

    Real realestReal(myStr3);
    Real realestReal2(myStr4);
    myReal3 = realestReal * realestReal2;
    myOutStream << myReal3;

    double newdub = .5;
    Real newReal(newdub);
    Real newerReal(1.0);
    cout << "startNewReal" << endl;
    newerReal = newReal - newerReal;
    myOutStream << newerReal;
    myOutStream << --newReal;
    myOutStream << newReal--;
    myOutStream << newReal;
    myOutStream << ++newReal;
    myOutStream << newReal++;
    myOutStream << newReal;

    if(myReal8 > myReal7)
        cout << "GREATER THAN" << endl;

    cout << "test" << endl;

    Real inputReal;
    Real inputReal2(2);
    myInStream >> inputReal;
    myOutStream << inputReal;
    Real lastReal = inputReal *= inputReal2;
    myOutStream << lastReal;

    return 0;
}
