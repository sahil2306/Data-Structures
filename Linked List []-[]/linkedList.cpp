#include<iostream>
using namespace std;

//Basic Node Structure
struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};


//Inserting new node
void insertLast(node* &head, int val){
    node *n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }


    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertStart(node* &head, int val){
    node *n = new node(val);
    
    n->next = head;
    head = n;
}

void insertAfter(node* &head, int val, int aft){
    
    node *n = new node(val);
    node *temp = head;

    while(temp->next!=NULL){
        if(temp->data==aft){
            break;
        }
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

//Deletion
void deleteLast(node* &head){
    
    if(head==NULL){
        return;
    }
    
    node *temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    node* temp2 = temp->next;
    temp->next = NULL;
    delete temp2;
}

void deleteStart(node* &head){
    if(head==NULL){
        return;
    }
    node* temp = head;
    head = head->next;

    delete temp;
}

void deleteVal(node* &head, int val){
    if(head==NULL){
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    
    node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

//Search
bool isPresent(node* head, int val){
    node *temp = head;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


//Display linkedList
void display(node* head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    
    cout<<"\nCreating a null LinkedList ";
    node *head = NULL;      //NULL


    cout<<"\nInsert at last node ";
    insertLast(head,5);     // 5
    display(head);

    cout<<"\nInsert at starting i.e at head ";
    insertStart(head,1);    // 1,5
    display(head);

    cout<<"\nInserting after a value ";
    insertAfter(head,3,1);  // 1,3,5
    display(head);
    
    
    insertLast(head,7);
    insertLast(head,8);
    insertLast(head,9);
    display(head);          //1,3,5,7,8,9

    cout<<"\nLinear Search";
    cout<<" : Is the value present? "<<isPresent(head, 4)<<endl;

    cout<<"\nDelete Head ";
    deleteStart(head);
    display(head);  //3,5,7,8,9
    
    cout<<"\nDelete some value ";
    deleteVal(head, 8);   //3,5,7,9
    display(head);

    cout<<"\nDelete last ";
    deleteLast(head);   //3,5,7
    display(head);
    
}