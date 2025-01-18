#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
node *start=NULL;
node *rear=NULL;
node *createll(node *start){
    int num;
    cout<<"Enter data or -1 to end list: ";
    cin>>num;
    while (num != -1)
    {
        node *newnode=new node();
        newnode->data=num;
        if(start==NULL)
        {
            newnode->next=NULL;
            start=newnode;
            rear=newnode;
        }
        else
        {
            newnode->next=NULL;
            rear->next=newnode;
            rear=newnode;
            rear->next=start;
        }
        cout<<"Enter data or -1 to end list: ";
        cin>>num;
    }
    return start;
}
void displayll(node *start)
{
    node *ptr=start;
    while (ptr->next!=start)
    {
        cout<<ptr->data<<"\t";
        ptr=ptr->next;
    }
    cout<<ptr->data<<endl;
}
node *insert_beg(node *start)
{
    node *newnode=new node();
    int num;
    cout<<"Enter data to add at begining: ";
    cin>>num;
    newnode->data=num;
    newnode->next=start;
    start=newnode;
    rear->next=start;
    return start;
}
node *insert_end(node *start)
{
    node *newnode=new node();
    // node *ptr=start;
    int num;
    cout<<"Enter data to add at the end: ";
    cin>>num;
    newnode->data=num;
    rear->next=newnode;
    // while(ptr->next!=start)
    // {
    //     ptr=ptr->next;
    // }
    newnode->next=start;
    rear=newnode;
    return start;
}
node *insert_middle(node *start)
{
    node *newnode=new node();
    node *ptr=start;
    node *preptr=start;
    int val,num;
    cout<<"After which node you want to insert new node: ";
    cin>>val;
    cout<<"Enter data for newnode: ";
    cin>>num;
    newnode->data=num;
    while(preptr->data != val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}
node *delete_beg(node *start)
{
    node *ptr=start;
    if(start==NULL)
    {
        cout<<"The list is empty";
    }
    else
    {
        start=start->next;
        free(ptr);
        rear->next=start;
    }
    return start;
}
node *delete_end(node *start)
{
    node *ptr=start;
    node *preptr=start;
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    free(ptr);
    preptr->next=start;
    rear=preptr;
    return start;
}
node *delete_middle(node *start)
{
    int num;
    cout<<"Enter data which node you want to delete: ";
    cin>>num;
    node *ptr=start;
    node *preptr=start;
    while(ptr->data!=num)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
int main()
{
    int choice=0;

    while(choice != 11)
    {
        cout<<"Enter choice: ";
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
            start=delete_beg(start);
            displayll(start);
            break;

        case 6:
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
            cout<<"Enter proper choice!";
            break;
        }
        
    }
    return 0;
}