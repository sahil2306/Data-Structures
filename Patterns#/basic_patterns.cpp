#include<iostream>

using namespace std;

int main(){

    int row = 5;
    int col = 4;

    cout<<"\nPattern 1 : "<<endl;

    for(int r=0;r<row;r++){
        for (int c=0;c<col;c++)
        {
            cout<<"\t*";
        }
        cout<<"\n";
    }

    /*
    Pattern 1 :
        *       *       *       *
        *       *       *       *
        *       *       *       *
        *       *       *       *
        *       *       *       *


    */

//------------------------------------------------------

    cout<<"\n\nPattern 2 : "<<endl;

    for(int r=1;r<=row;r++){
        for (int c=1;c<=col;c++)
            {
                if(r==1 || r==row || c==1 || c==4){
                    cout<<"\t*";
                }
                else{
                    cout<<"\t";
                }
            }
        
        cout<<"\n";
    }
    /*
    
    Pattern 2 :
        *       *       *       *
        *                       *
        *                       *
        *                       *
        *       *       *       *


    
    */

    //------------------------------------------------------
    cout<<"\n\nInverted Pyramid : "<<endl;
    
    int ci = col;
    for(int r=1;r<=row;r++){
        for (int c=ci;c>=0;c--)
            {
                cout<<"\t*";
            }
        ci--;    
        cout<<"\n";
    }

    /*
    
    Inverted Pyramid :
        *       *       *       *       *
        *       *       *       *
        *       *       *
        *       *
        *

    
    */

    //------------------------------------------------------

    cout<<"\n\nHalf Pyramid After 180 rotation: "<<endl;
    ci = (col);
    for(int r=1;r<=row;r++){
        for (int c=1;c<=col;c++)
            {
                if(c>ci){cout<<"\t*";}
                else{
                    cout<<"\t";
                }
            }
        ci--;    
        cout<<"\n";
    }

    /*
    Half Pyramid After 180 rotation:

                                *
                        *       *
                *       *       *
        *       *       *       *

    */

    //------------------------------------------------------

    cout<<"\n\nHalf Pyramid Numbers: "<<endl;
    for(int r=1;r<=row;r++){
        for (int c=1;c<=r;c++)
            {
                cout<<"\t"<<r;
            }
        cout<<"\n";
    }

    /*
    Half Pyramid Numbers:
        1
        2       2
        3       3       3
        4       4       4       4
        5       5       5       5       5


    */

    //------------------------------------------------------

    int count=1;
    cout<<"\n\nFloyd's Triangle: "<<endl;
    for(int r=1;r<=row;r++){
        for (int c=1;c<=r;c++)
            {
                cout<<"\t"<<count++;
            }
        cout<<"\n";
    }

    /*
    Floyd's Triangle:
        1
        2       3
        4       5       6
        7       8       9       10
        11      12      13      14      15


    
    */

    //------------------------------------------------------

    int n=4;
    cout<<"\n\nButterfly Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=r;c++)
        {
            cout<<"\t*";
        }
        for (int c=1;c<=((2*n)-(2*r));c++)
        {
            cout<<"\t";
        }
        for (int c=1;c<=r;c++)
        {
            cout<<"\t*";
        }
        cout<<"\n";
    }
    for(int r=n;r>=1;r--){
        for (int c=1;c<=r;c++)
        {
            cout<<"\t*";
        }
        for (int c=1;c<=((2*n)-(2*r));c++)
        {
            cout<<"\t";
        }
        for (int c=1;c<=r;c++)
        {
            cout<<"\t*";
        }
        cout<<"\n";
    }

    /*
    Butterfly Pattern:
        *                                                       *
        *       *                                       *       *
        *       *       *                       *       *       *
        *       *       *       *       *       *       *       *
        *       *       *       *       *       *       *       *
        *       *       *                       *       *       *
        *       *                                       *       *
        *                                                       *


    
    */
}