#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    
    //--------Pointers----------
    int c = 100;
    int *ptr=&c;

    cout<<"Pointer : "<<ptr;
    cout<<"\nValue stored in Pointer : "<<*ptr;

    //Pointers can also be used for modification
    *ptr = 200;
    cout<<"\nvalue c after modification using pointers : "<<c;

    //-----------Array as pointers----------------
    int arr[] = {10,11,12};
    cout<<"\n\n*arr : "<<*arr<<endl;

    int *ptr1 = arr;
    
    cout<<"\nArray values : ";
    for(int i=0;i<3;i++){
        cout<<(*arr+i)<<" ";
    }

    cout<<"\nArray values using pointers : ";
    for(int i=0;i<3;i++){
        cout<<*ptr1++<<" ";
    }



    //----------Pointers to function-----------------
    int a=2,b=4;

    swap(&a, &b);
    cout<<"\n\nAfter swapping : "<<a<<" "<<b;

    cout<<"\n";

    return 0;
} 