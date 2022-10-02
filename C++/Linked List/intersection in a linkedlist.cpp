#include<iostream>
using namespace std; 

class node
{
public: 
int data;
node* next;
node(int val)
{
data=val;
next=NULL;
}
};

void insert(node* &head,int val)
{
node* n=new node(val);
if(head==NULL)
{
head=n;
return;
}
node* temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=n;
}
void display (node* head)
{
node* temp=head;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

node* intersection(node* head,node* head1)
{
node* ptr1=head;
node* ptr2=head1;
node* head3=NULL;
node* curr=NULL;
while(ptr1 and ptr2)
{
if(ptr1->data==ptr2->data)
{
if(head3==NULL)
{
node* t=new node(ptr1->data);
head3=t;
curr=t;
}
else
{
node* t=new node(ptr1->data);
curr->next=t;
curr=curr->next;
}
ptr1=ptr1->next;
ptr2=ptr2->next;
}
else{
if(ptr1->data<ptr2->data)
ptr1=ptr1->next;
else
ptr2=ptr2->next;
}}
return head3;
}


int main()
{
node* head=NULL; 
node* head1=NULL; 
node* head2=NULL;
insert(head2,5);
insert(head2,3);
insert(head2,4);
insert(head2,3);
insert(head2,5);
insert(head,2);
insert(head,3);
insert(head,4);
insert(head,5);
insert(head,7);
insert(head1,1);
insert(head1,3);
insert(head1,4);
insert (head1,5);
display(head);
cout<<endl;
display(head1);
cout<<endl;
display(intersection(head,head1));
cout<<endl; 

}
