#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
node *start=NULL;
node *rear=NULL;
node *createll(node *start){
    node *newnode;
    int num;
    cout<<"Enter data or -1 to end the list: ";
    cin>>num;
    while(num != -1){
        newnode=new node();
        newnode->data=num;
        if(start==NULL){
            newnode->next=NULL;
            start=newnode;
            rear=newnode;
        }
        else{
            rear->next=newnode;
            // newnode->next=NULL;
            rear=newnode;
        }
        cout<<"Enter data or -1 to end the list: ";
        cin>>num;
    }
    return start;
}
void displayll(node *start){
    node *ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        cout<<ptr->data<<"\t";
        ptr=ptr->next;
    }
    cout<<ptr->data<<"\n";
}
node *insert_beg(node *start){
    node *newnode=new node();
    int num;
    cout<<"Enter number to add at the begining: ";
    cin>>num;
    newnode->data=num;
    newnode->next=start;
    start=newnode;
    return start;
}
node *insert_end(node *start){
    node *newnode=new node();
    int num;
    cout<<"Enter number to insert at end: ";
    cin>>num;
    rear->next=newnode;
    newnode->data=num;
    newnode->next=NULL;
    rear=newnode;
    return start;
}
node *insert_middle(node *start){
    node *newnode=new node();
    node *ptr=start;
    node *preptr=start;
    int num,val;
    cout<<"Enter the node value after which you want to create newnode :";
    cin>>val;
    cout<<"Enter data to enter: ";
    cin>>num;
    newnode->data=num;
    while(ptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr=ptr;
    ptr=preptr->next;
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}
node *delete_beg(node *start){
    node *ptr=start;
    start=ptr->next;
    free(ptr);
    return start;
}
node *delete_end(node *start){
    node *ptr=start;
    node *preptr=start;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    preptr=rear;
    free(ptr);
    return start;
}
node *delete_middle(node *start){
    node*ptr=start;
    node *preptr=start;
    int num;
    cout<<"Enter data which node you want to delete: ";
    cin>>num;
    while(ptr->data!=num){
        preptr=ptr;
        ptr=ptr->next;
    }
    ptr=ptr->next;
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
int main()
{
    int choice;
    
    while(choice!=11){
    cout<<"Enter choice what you want to do: \n";
    cout<<"1: Create link list: \n";
    cout<<"2: Insert at beginig: \n";
    cout<<"3: Insert at end: \n";
    cout<<"4: Insert in middle: \n";
    cout<<"5: Delete at begining: \n";
    cout<<"6: Delete at end: \n";
    cout<<"7: Delete in middle: \n";
    cout<<"11: Exit\n";
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
            cout<<"List after deleting in middle\n";
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