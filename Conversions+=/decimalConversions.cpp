//Decimal -> Binary, Hexadecimal, Octa
//Binary, Hexadecimal, Octa -> Decimal



#include<iostream>
using namespace std;


int binaryToDecimal(int n){
    int dec=1;
    int ans=0;
    while(n>0){
        int r = n%10;
        ans+=dec*r;
        dec*=2;     //2 as it is binary;1,2,4,8.....
        n=n/10;
    }
    return ans;
}

int octaToDecimal(int n){
    int dec=1;
    int ans=0;
    while(n>0){
        int r = n%10;
        ans+=dec*r;
        dec*=8;     //8 as it is octa
        n=n/10;
    }
    return ans;
}

int hexaToDecimal(string n){
    int dec=1;
    int ans=0;
    int s = n.size();

    for (int i = s-1; i>=0; i--){
        if(n[i]>='0' && n[i]<='9'){
            ans+=dec*(n[i]-'0');
        }
        if(n[i]>='A' && n[i]<='F'){
            ans+=dec*(n[i]-'A'+10);
        }
        dec*=16;
    }
    return ans;
}

//-----------------------------------------

int decimalToBinary(int n){
    int x=1;
    int ans=0;
    while(x<=n){
        x*=2;
    }
    x/=2;

    while(x>0){
        int lastDigit = n/x;
        n-=lastDigit*x;
        x/=2;
        ans=ans*10 + lastDigit;
    }

    return ans;
}

int decimalToOcta(int n){
    int x=1;
    int ans=0;
    while(x<=n){
        x*=8;
    }
    x/=8;

    while(x>0){
        int lastDigit = n/x;
        n-=lastDigit*x;
        x/=8;
        ans=ans*10 + lastDigit;
    }

    return ans;
}

string decimalToHexa(int n){
    
    int x=1;
    string ans="";
    while(x<=n){
        x*=16;
    }
    x/=16;

    while(x>0){
        int lastDigit = n/x;
        n-=lastDigit*x;
        x/=16;

        if(lastDigit<=9){
            ans=ans + to_string(lastDigit);
        }
        else{
            ans.push_back('A' + (lastDigit-10));
        }
    }

    return ans;
}

//----------------------------------

int main(){
    int n,c;
    do{
        cout<<"\n1)D-B 2)B-D 3)D-O 4)O-D 5)D-H 6)H-D 7)Exit";
        cin>>c;

        switch (c)
        {
        case 1:{
            //D-B
            cout<<"Enter Decimal Number : ";
            cin>>n;
            int bin = decimalToBinary(n);
            cout<<"\nBinary is : "<<bin;
            break;
        }
        case 2:{
            //B-D
            cout<<"Enter Binary Number : ";
            cin>>n;
            int dec = binaryToDecimal(n);
            cout<<"\nDecimal is : "<<dec;
            break;
        }
        case 3:{
            //D-O
            cout<<"Enter Decimal Number : ";
            cin>>n;
            int bin = decimalToOcta(n);
            cout<<"\nOctal is : "<<bin;
            break;
        }
        case 4:{
            //O-D
            cout<<"Enter Octal Number : ";
            cin>>n;
            int dec = octaToDecimal(n);
            cout<<"\nDecimal is : "<<dec;
            break;
        }
        case 5:{
            //D-H
            cout<<"Enter Decimal Number : ";
            cin>>n;
            string bin = decimalToHexa(n);
            cout<<"\nHexa is : "<<bin;
            break;
        }
        case 6:{
            //H-D
            string s;
            cout<<"Enter Hexa Number : ";
            cin>>s;
            int dec = hexaToDecimal(s);
            cout<<"\nDecimal is : "<<dec;
            break;
        }

        default:
            break;
        }

        
    }while(c<7);
}