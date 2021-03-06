#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;


struct node *display(struct node *start){

    struct node *ptr=start;
    cout<<"\n Printing List\t";
    while(ptr->next!=start){
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
        cout<<ptr->data;    // for last node since excluded in above 
// since in above while loop if write ptr->next above print then skip first node print so sacrifice and write extra for either first node or last node
            /*  OR could write as below

            cout<<  first node data
    while(ptr->next!=start){
        ptr=ptr->next;
        cout<<ptr->data<<" -> ";    // this cout also prints last node data //since above cout is before shifting ptr sacrifice cannot print last node data in above method
    }*/
    
    return start;   
}

struct node *create(struct node *start){

cout<<"\n Enter -1 to end";
cout<<"\n Enter data of Node ";
int data;

while(1){

cin>>data;
if(data==-1)
    break;

    if(start==NULL){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=data;
        start=new_node;
        new_node->next=new_node;
    }
    else{
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=data;

    struct node *ptr=start;

        while(ptr->next!=start){
        ptr=ptr->next;
        }

        ptr->next=new_node;
        new_node->next=start;
    }

}
display(start);
    return start;
}

// works for mulitple occ
struct node *search_list(struct node *start){

struct node *ptr=start;

    cout<<"\n enter number to search";
    int data;
    cin>>data;

int node=1;

    while(ptr->next!=start){
        if(ptr->data==data)
            cout<<"\n found at postion node "<<node;
        node++;
        ptr=ptr->next;
    }

    return start;
}


struct node *insert_beg(struct node *start){

    struct node *ptr=start;

struct node *new_node=(struct node *)malloc(sizeof(struct node));

int data;
cout<<"\n Enter data";
cin>>data;
new_node->data=data;

new_node->next=start;

    while(ptr->next!=start)
        ptr=ptr->next;

ptr->next=new_node;
start=new_node;

/************************Creates seg fault********************************************************************
    
     // why wrong why not implicitly last elemnet updated??
     LESSON >>      // because start at the time of creation the last node next was fixed to ex first node 
             as start hence not updated since create() func called in the past

  struct node *insert_beg(struct node *start){

    struct node *ptr=start;

struct node *new_node=(struct node *)malloc(sizeof(struct node));

int data;
cout<<"\n Enter data";
cin>>data;
new_node->data=data;

 new_node->next=start;

start=new_node;

display(start);

    return start;
}*/

display(start);

    return start;
}

struct node *insert_end(struct node *start){

    struct node *ptr=start;

    while(ptr->next!=start){
        ptr=ptr->next;
    }    

    struct node *new_node=(struct node *)malloc(sizeof(struct node));

    cout<<"\n enter data";
    int data;
    cin>>data;

    new_node->data=data;
    
    ptr->next=new_node;
    new_node->next=start;

   display(start);
return start;
}

//?? EDGE CASE >>   delete beg and end stable if only one elemnet in list?
        // SOLVE using 
        /*  
        struct node *ptr=start;
            if(ptr->next==start)
                cout<<"\n only one node present deleting that"
                start=NULL
        */

struct node *delete_beg(struct node *start){


struct node *ptr=start;
struct node *tmp=start;

while(tmp->next!=start){
    tmp=tmp->next;
}

ptr=ptr->next;
start=ptr;
tmp->next=ptr;

    return start;
}

struct node *delete_end(struct node *start){

    struct node *ptr=start;

    struct node *pre_ptr=start;

while(ptr->next!=start){
    pre_ptr=ptr;
    ptr=ptr->next;
}

pre_ptr->next=start;

ptr->next=NULL;
display(start);
    return start;
}

struct node *delete_node(struct node *start){
   cout<<"\n enter node to delette";
   int delValue;
   cin>>delValue;

   if(start == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct node *temp1 = start;
      struct node *temp2;

      while(temp1 -> data != delValue)
      {
         if(temp1 -> next == start)
         {
            printf("\nGiven node is not found in the list!!!");
            goto FuctionEnd;
         }
         else
         {
            temp2 = temp1;

      if(temp1 -> next == start){
         start = NULL;
         free(temp1);
      }
      else{
         if(temp1 == start)
         {
            temp2 = start;
            while(temp2 -> next != start)
               temp2 = temp2 -> next;
            start = start -> next;
            temp2 -> next = start;
            free(temp1);
         }
         else
         {
            if(temp1 -> next == start)
            {
               temp2 -> next = start;
            }
            else
            {
               temp2 -> next = temp1 -> next;
            }   
            free(temp1);
         }
      }
      printf("\nDeletion success!!!");
   }
            temp1 = temp1 -> next;
         }
      }
   FuctionEnd:
}
/*****************************************************************
                        // ??? some repetitions not deleted 
    // between 2 unique nums if 2 mulitple occ 1 left behind all else occs deleted
    // between 2 unique nums if 3 mulitple occ 2 left behind all else occs deleted
                                4 >> 2
struct node *delete_node(struct node *start){

    struct node *ptr=start;

    struct node *pre_ptr=ptr;
    int data;
    cout<<"\n enter node to delete";
    cin>>data;

    struct node *tmp=start;

while(ptr->next!=start){

    if(ptr==start && ptr->data==data){
        
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start->next;
        start=start->next;
    }
    else if(ptr->data==data){
        pre_ptr->next=ptr->next;
    }

pre_ptr=ptr;
ptr=ptr->next;
}
// for last eleement
if(ptr->data==data){
    pre_ptr->next=ptr->next;
    start=pre_ptr->next;
}

display(start);
    return start;
}

*****************************also puts delted element at last ****************************************************************
        SOLVED      // caused due to multiple start pointers fallacy

while(ptr->next!=start){

    // cout<<"\n initial value of start"<<start;

    if(ptr==start && ptr->data==data){
        struct node *tmp=start;
        start=start->next;          // here start definition changed also affects below while loop therefore puts first node deleted while priniting at last
        while(tmp->next!=start){
            tmp=tmp->next;
        }
        tmp->next=start;
    }
    else if(ptr->data==data){
        pre_ptr->next=ptr->next;
    }

pre_ptr=ptr;
ptr=ptr->next;
}

*/



int main(){
cout<<"\n\n";

int choice=0;

do{

cout<<"\n *************Cicrcular Linked List*******************";
cout<<"\n 1.create";
cout<<"\n 2.display";
cout<<"\n 3.insert beg";
cout<<"\n 4.insert end";
cout<<"\n 5.delete beg";
cout<<"\n 6.delete end";
cout<<"\n 7.search Node";
cout<<"\n 8.delete node";
cout<<"\n 9.insert after";
cout<<"\n 10.insert before";


cout<<"\n Enter choice\n";
cin>>choice;


    switch(choice){
        case 1:
            start=create(start);
            break;
        case 2:
            start=display(start);
            break;
        case 3:
            start=insert_beg(start);
            break;
        case 4:
            start=insert_end(start);
            break;
        case 5:
            start=delete_beg(start);
            break;
        case 6:
            start=delete_end(start);
            break;
        case 7:
            start=search_list(start);
            break;
        case 8:
            start=delete_node(start);
            break;
                
            
    }

}while(choice!=13);


cout<<"\n\n";
return 0;
}