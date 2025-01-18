#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
};

node *start=NULL;
node *rear=NULL;

node *createll(node *start){
    int num;
    cout<<"Enter data to enter in list or -1 to end list: ";
    cin>>num;
    while(num != -1){
        node *newnode=new node();
        newnode->data=num;
        if(start==NULL){
            newnode->prev=NULL;
            newnode->next=NULL;
            start=newnode;
            rear=newnode;
        }
        else{
            newnode->prev=rear;
            rear->next=newnode;
            rear=newnode;
        }
        cout<<"Enter data to enter in list or -1 to end list: ";
        cin>>num;
    }
    return start;
}

void displayll(node *start){
    node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        cout<<ptr->data<<"\t";
        ptr=ptr->next;
    }
    cout<<ptr->data<<"\n";
}

node *insert_beg(node *start){
    int num;
    cout<<"Enter number to add at begining: ";
    cin>>num;
    node *newnode=new node();
    newnode->data=num;
    newnode->next=start;
    start->prev=newnode;
    newnode->prev=NULL;
    start=newnode;
    return start;
}

node *insert_end(node *start)
{
    int num;
    cout<<"Enter number to insert at end: ";
    cin>>num;
    node *newnode=new node();
    newnode->data=num;
    newnode->prev=rear;
    rear->next=newnode;
    newnode->next=NULL;
    rear=newnode;
    return start;
}

node *insert_middle(node *start)
{
    node *ptr=start;
    node *preptr=start;
    node *newnode=new node();
    int num,val;
    cout<<"Enter the value of node after you want to add new node: ";
    cin>>val;
    cout<<"Enter data for new node: ";
    cin>>num;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    newnode->data=num;
    newnode->next=ptr;
    newnode->prev=preptr;
    preptr->next=newnode;
    ptr->prev=newnode;
    return start;
}

node *delete_beg(node *start)
{
    node *ptr=start;
    start=ptr->next;
    start->prev=NULL;
    free(ptr);
    return start;
}

node *delete_end(node *start)
{
    node *ptr=rear;
    rear=rear->prev;
    rear->next=NULL;
    free(ptr);
    return start;
}

node *delete_middle(node *start)
{
    int val;
    cout<<"Enter the value of node after you want to delete a node: ";
    cin>>val;
    node *ptr=start;
    node *preptr=start;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    ptr->next->prev=preptr;
    free(ptr);
    return start;
}

int main()
{
    int choice=0;

    while(choice!=11)
    {
        cout<<"Enter choice: \n";
        cout<<"1: Create Linklist: \n";
        cout<<"2: Insert at begining: \n";
        cout<<"3: Insert at end: \n";
        cout<<"4: Insert in middle: \n";
        cout<<"5: Delete at begining: \n";
        cout<<"6: Delete at end: \n";
        cout<<"7: Delete in middle: \n";
        cout<<"11: Exit!\n";

        cin>>choice;

        switch (choice)
        {
        case 1:
            start=createll(start);
            displayll(start);
            break;
        
        case 2:
            start=insert_beg(start);
            displayll(start);
            break;

        case 3:
            start=insert_end(start);
            displayll(start);
            break;

        case 4:
            start=insert_middle(start);
            displayll(start);
            break;

        case 5:
            cout<<"List after deleting at begining\n";
            start=delete_beg(start);
            displayll(start);
            break;

        case 6:
            cout<<"List after deleting at end\n";
            start=delete_end(start);
            displayll(start);
            break;

        case 7:
            start=delete_middle(start);
            displayll(start);
            break;

        case 11:
            exit;
            break;

        default:
            cout<<"Enter proper choice";
            break;
        }
    }    
}