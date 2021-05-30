#include<bits/stdc++.h>
using namespace std;
#define v 4

int PrimsAlgo(int graph[v][v]){
    int res=0;
    
    int key[v]; //Distance Array with infinity at beginning
    fill(key,key+v,INT_MAX);
    key[0]=0;   

    //Visited Array
    bool vis[v];
    for(int i=0;i<v;i++){
        vis[i]=0;
    }    

    for(int co=0;co<v;co++){   

        int min_ind = -1;
        for(int i=0;i<v;i++){
            if(!vis[i] and (min_ind==-1 or key[i]<key[min_ind])){
                min_ind = i;
            }
        }

        vis[min_ind] = 1;
            
        res +=key[min_ind];

        for(int i=0;i<v;i++){
            if(!vis[i] and graph[min_ind][i]!=0){
                key[i] = min(key[i], graph[min_ind][i]);
            }
        }

    }

    return res;
}

int main() 
{ 
    //Adjacency Matrix
    int graph[v][v] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<PrimsAlgo(graph); 

	return 0; 
} 



