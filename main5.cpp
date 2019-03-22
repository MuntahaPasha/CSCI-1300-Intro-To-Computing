// Muntaha Pasha: CS1300 Fall 2017
// Recitation:  – Camilla, 204
//
// Assignment 5

#include <iostream>
#include "Assignment5.cpp"

using namespace std;

int main()
{
    float test[]={2.0,3.0,4.0};
    cout<<sumArray(test,3);

    int testo[]={-5, 3. 200, 1, 0, 9};
    cout<<convert(testo, 6);

    float test2[]={9.8,2.3,5.6,10.7,34.0,89.7,94.6,8.2,6.7,0.8,6.7};
    sortArray(test2,11);

    float test5[]={200,300,800,600,89};

    float test3[]={1,2, 3, 5};
    cout << findMedian(test3, 4) << endl;

    float test4[]={5.0, 9.0};
    cout<<calculateDifference(5, 3, 2)<<endl;
}

