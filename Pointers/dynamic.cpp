#include<iostream>
using namespace std;

int main(){
    int a=10;   //stored in stack
    int *p = new int(); //allocate memory n heap

    *p = 20;
    delete(p);  //deallocate memory

    p=new int[4];
    delete[] p;

    p=NULL; //imp for removing dangling pointers
}
