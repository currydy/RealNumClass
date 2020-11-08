//
// Created by Dylan on 11/1/2020.
//

#include "Real.h"
#include <fstream>

int main(){

    ofstream myOutStream;
    myOutStream.open("myfile.txt");

    long long myLong = 12345;
    double myDub = 7.75;
    double myDub2 = 6.25;

    double myDub3 = 3.5;
    double myDub4 = -4.25;
    string myStr  = "50.425";
    Real myReal(myDub);
    Real myReal2(myDub2);
    Real myReal3(myDub3);
    Real myReal4(myDub4);
    Real myReal5(myStr);

    if(myReal3 == myReal4)
        cout << "TRUE" << endl;

    //myReal2 = myReal + myReal2;
    myReal3 = myReal - myReal2;
    myOutStream << myReal3 << endl;
    myReal5 = myReal3 + myReal4;
    myOutStream << myReal5 << endl;
    myReal5 = myReal4 + myReal3;
    myOutStream << myReal5 << endl;
    myReal2++;
    ++myReal2;
    //myOutStream << myReal4 << endl;
    myOutStream << myReal2;

    cout << "test" << endl;

    return 0;
}
