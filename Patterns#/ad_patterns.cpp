#include<iostream>
using namespace std;

int main(){

    int row=5;
    int col=5;
    int n=5;
    
    //------------------------------------------------------
    
    cout<<"\n\nInverted Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=(n-r+1);c++)
        {
            cout<<"\t"<<c;
        }
        cout<<"\n";
    }
    
    /*
    Inverted Pattern:
        1       2       3       4       5
        1       2       3       4
        1       2       3
        1       2
        1
    */


    //------------------------------------------------------
    int ans=0;
    cout<<"\n\nAlternate 0-1 Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=r;c++)
        {
            cout<<"\t"<<(ans^=1);
        }
        cout<<"\n";
    }

    /*
    Alternate 0-1 Pattern:
        1
        0       1
        0       1       0
        1       0       1       0
        1       0       1       0       1
    */

    //------------------------------------------------------
    cout<<"\n\n0-1 Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=r;c++)
        {
            if((r+c)%2==0)cout<<"\t"<<1;
            else cout<<"\t"<<0;
        }
        cout<<"\n";
    }

    /*
    0-1 Pattern:
        1
        0       1
        1       0       1
        0       1       0       1
        1       0       1       0       1
    */

    //------------------------------------------------------
    cout<<"\n\nRhombus Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=(n-r);c++)
        {
            cout<<" ";
        }
        for (int c=1;c<=n;c++)
        {
            cout<<" *";
        }
        cout<<"\n";
    }
    /*
                    Rhombus Pattern:
                    * * * * *
                   * * * * *
                  * * * * *
                 * * * * *
                * * * * *
    */
    //------------------------------------------------------
    cout<<"\n\nPyramid Number Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=((n-r)+1);c++)
        {
            cout<<" ";
        }
        for (int c=1;c<=r;c++)
        {
            cout<<" "<<c;
        }
        cout<<"\n";
    }
    /*
                Pyramid Number Pattern:
                            1
                           1 2
                          1 2 3
                         1 2 3 4
                        1 2 3 4 5

    */
    //------------------------------------------------------
    cout<<"\n\nPalendromic Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=((n-r)+1);c++)
        {
            cout<<"\t";
        }
        for (int c=r;c>=1;c--)
        {
            cout<<"\t"<<c;
        }
        for (int c=2;c<=r;c++)
        {
            cout<<"\t"<<c;
        }
        cout<<"\n";
    }
    /*
                Palendromic Pattern:
                                                1
                                        2       1       2
                                3       2       1       2       3
                        4       3       2       1       2       3       4
                5       4       3       2       1       2       3       4       5
    */

    //------------------------------------------------------
    
    cout<<"\n\nStar Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=((n-r)+1);c++)
        {
            cout<<" ";
        }
        for (int c=1;c<=(2*r-1);c++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int r=n;r>=1;r--){
        for (int c=1;c<=((n-r)+1);c++)
        {
            cout<<" ";
        }
        for (int c=1;c<=(2*r-1);c++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }

    /*
    
                        Star Pattern:
     *
    ***
   *****
  *******
 *********
 *********
  *******
   *****
    ***
     *


    
    */

    
    //------------------------------------------------------
    n=13;
    cout<<"\n\nZigZag Pattern: "<<endl;
    for(int r=1;r<=3;r++){
        for (int c=1;c<=n;c++)
        {
            if((r+c)%4==0 || (r==2 && c%4==0)){
                cout<<"\t*";
            }
            else{
                cout<<"\t";
            }
        }
        cout<<"\n";
    }
    /*
    
    ZigZag Pattern:
                        *                               *                               *

                *               *               *               *               *               *

        *                               *                               *
*


    
    */
    //------------------------------------------------------
    n=5;
    cout<<"\n\nDiamond Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=(n-r+1);c++)
        {
            cout<<" ";
        }
        for (int c=1;c<=(2*r-1);c++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int r=n;r>=1;r--){
        for (int c=0;c<=(n-r);c++)
        {
            cout<<" ";
        }
        for (int c=(2*r-1);c>=1;c--)
        {
            cout<<"*";
        }
        cout<<"\n";
    }

    /*
    Diamond Pattern:
     *
    ***
   *****
  *******
 *********
 *********
  *******
   *****
    ***
     *


    
    */

    //------------------------------------------------------
    n=5;
    cout<<"\n\nHollow Diamond Pattern: "<<endl;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=(n-r+1);c++)
        {
            cout<<" ";
        }
        for (int c=1;c<=(2*r-1);c++)
        {
            if(c==1 || c==(2*r-1))cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
    for(int r=n;r>=1;r--){
        for (int c=0;c<=(n-r);c++)
        {
            cout<<" ";
        }
        for (int c=(2*r-1);c>=1;c--)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    /*
    
    Hollow Diamond Pattern:
     *
    * *
   *   *
  *     *
 *       *
 *********
  *******
   *****
    ***
     *


    
    */
    //------------------------------------------------------
    n=5;
    cout<<"\n\nHollow Diamond Inscribed in a Rectangle: "<<endl;
    
    int ci = (2*n-1)/2;
    for(int r=1;r<=n;r++){
        for (int c=1;c<=ci;c++)
        {
            cout<<"*";
        }
        for (int c=1;c<=2*r-1;c++)
        {
            if(c==1 || c==2*r-1){
                cout<<"*";
            }
            else {  cout<<" ";}
        }
        for (int c=1;c<=ci;c++)
        {
            cout<<"*";
        }
        cout<<"\n";
        ci--;
    }

    ci = 0;
    for(int r=n;r>=1;r--){
        for (int c=1;c<=ci;c++)
        {
            cout<<"*";
        }
        for (int c=1;c<=2*r-1;c++)
        {
            if(c==1 || c==2*r-1){
                cout<<"*";
            }
            else {  cout<<" ";}
        }
        for (int c=1;c<=ci;c++)
        {
            cout<<"*";
        }
        cout<<"\n";
        ci++;
    }

    /*
    Hollow Diamond Inscribed in a Rectangle:
*********
**** ****
***   ***
**     **
*       *
*       *
**     **
***   ***
**** ****
*********


    
    */
}