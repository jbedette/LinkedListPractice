#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
//what to do:
//1. display node
//2. add node
//3. clean

//questions:
//1. when I'm making a new head with addNode end, do I have to create a pointer to start with?
//2. 
void displayThings(int,bool);
void displayText(char[],bool);
bool again();

struct node{
    node * next;
    int data;
    char * event;
};

void appendNode(node * head,int data){
    cerr << ">>in appendNode :"<< '\n'; 
    /*
        if(head==NULL){//if head doesn't exist make it
        displayText("In null head",true);
        head->next = NULL;
        head->data = data;
    }else{
    */
        node * current = head;
        node * temp = head;
        while(current){
            temp = current;
            current = current->next;
        }
        current = new node;
        current->data = data;
        current->next = NULL;
        temp->next = current;
    }
}
/*
void recursiveAppend(node * head,int & data /* need to bring in a pointer to obj, int data is tes){
    if(!head){//if head doesn't exist make it
        head = new node;
        head->next = NULL;
        head->data = data;
        data = 0;
    }else{
        addNodeEnd(head->next, data);
    }
}
*/
void displayAll(node * head){
    if(!head){
        displayText("NO DATA",true); 
    }else{
        displayText("DATA EXISTS",true);
        displayAll(head->next);
        displayThings(head->data, false); 
    }
}
void clean(node * & head){
    if(!head){
        return;
    }else{
        clean(head->next);
        delete head->event;
        head = NULL;
    }
}


int main(){
    int input = 0;

    //node * head = NULL;

    //defining head
   node * head;       
   head->next=NULL;
   head->data=NULL;
   

    displayText("pre entry check",true);
    
    displayAll(head);
    do{
        displayText("enter int",true);
        cin >> input;

        displayText("entering node add",true);
        appendNode(head,input);
        
        if(head->next)
            displayText("head->exists",true);
        else
            displayText("head->null",true);
        
        displayAll(head);


    }while(again());


    clean(head);
    displayAll(head);
    
    return 0;
}

void displayThings(int text/*char text[]*/,bool dbl){
    cout << ">>" << text << "\n";
    if(dbl) cout << '\n';
}
void displayText(char text[],bool dbl){
    cerr << ">>" << text << "\n";
    if(dbl) cout << '\n';
}
bool again(){
    char option = ' ';
    cout << ">>again?" << '\n';
    cin >> option;
    cin.ignore(100,'\n');
    if(tolower(option)=='n') return false;
    return true;
}




