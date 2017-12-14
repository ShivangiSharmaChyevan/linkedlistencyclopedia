#include<bits/stdc++.h>
//#include<unordered_set>
using namespace std;

struct node
{
        int data;
        node * next;
};

class linked
{
        node * head;
        int n;
        public:
        node *end,*rand;
        int n1;
        linked()
        {
        head=NULL;
        n1=0;
        }
        void create();
        void insert(int);
        void display();
        void insertbeg();
        void insertend();
        void insertaftervalue();
        void insertatpos();
        void delet();
        node* returnhead();
        void lengthit();
        void lengthrec(node *);
        void isearch(int);
        void recsearch(int,node*);
        void swap();
        void getfromindex();
        void getmid();
        void nfromlast();
        void revit();
        void revrec(node*);
        void detectloop();
        void mergeit();
        node* mergecur(node * heada,node *headb);
        void mer1();
        void palin();
        void ipoint();
        void printrec(node*);
        void remdep();
        void uremdep();
        void pswapi();
        node* pswapr(node *);
        void mov2first();
        void intersect();
        void alternate();
        void midhead();
        void insnend();
        void sort012();
        void mergesort();
        void revgroup();
        void addone();
        void detrem();
};

void linked::addone()
{
        node *prev=NULL,*curr=head,*nex;
        
        while(curr!=NULL)
        {
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
        }
        
        head=prev;
        
        
        node *p=head;
        
        
        
        while(1)
        {
                if(p->data+1>=10)
                {
                        p->data=0;
                        p=p->next;
                }
                else
                {
                p->data=p->data+1;
                break;
                }     
        }
        
        
        
        prev=NULL,curr=head;
        
        while(curr!=NULL)
        {
                nex=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
        }
        
        head=prev;
        
       
}
void linked::revgroup()
{
        stack<node*>s;
        node*prev=NULL;
        int k;
        int count =0;
        cout<<"\n Size of group ";
        cin>>k;
        node *p=head;
        
        while(p!=NULL)
        {
                count=0;
                while(p!=NULL && count<k)
                {
                        s.push(p);
                        p=p->next;count++;
                }
                
                while(!s.empty())
                {
                        if(prev==NULL)
                        {
                                prev=s.top();
                                head=prev;
                                s.pop();
                                
                        }
                        else
                        {
                                prev->next=s.top();
                                prev=prev->next;
                                s.pop();
                        }
                }
               
        }
        prev->next=NULL;
}

void linked::sort012()
{
        node* zero=NULL,*pre1=NULL;
        node* one=NULL,*pre2=NULL;
        node* two=NULL,*pre3=NULL;
        
        node *p=head;
        node *k;
        while(p!=NULL)
        {
                if(p->data==0)
                {
                        if(pre1==NULL)
                        {
                              k=new node();
                              k->data=0;
                              k->next=NULL;
                              pre1=k;zero=pre1;  
                        }
                        else
                        {
                                 k=new node();
                              k->data=0;
                              k->next=NULL;
                                pre1->next=k;
                                pre1=pre1->next;
                        }
                }
                 if(p->data==1)
                {
                        if(pre2==NULL)
                        {
                              k=new node();
                              k->data=1;
                              k->next=NULL;
                              pre2=k;one=pre2;  
                        }
                        else
                        {
                                 k=new node();
                              k->data=1;
                              k->next=NULL;
                                pre2->next=k;
                                pre2=pre2->next;
                        }
                }
                 if(p->data==2)
                {
                        if(pre3==NULL)
                        {
                              k=new node();
                              k->data=2;
                              k->next=NULL;
                              pre3=k;two=pre3;  
                        }
                        else
                        {
                                 k=new node();
                              k->data=2;
                              k->next=NULL;
                                pre3->next=k;
                                pre3=pre3->next;
                        }
                }
                p=p->next;
        }
        
    pre1->next=one!=NULL?one:two;
    pre2->next=two;
    pre3->next=NULL;
    
    head=zero;
       
}
void linked::insnend()
{
        int x,m;
        cout<<"\n Enter the value to be inserted and place  ";
        cin>>x>>m;
        node *fast=head,*slow=head;
        for(int i=0;i<m;++i)
        {
                fast=fast->next;
        }
        while(fast!=NULL)
        fast=fast->next,slow=slow->next;
        
        node *t=new node();
        t->data=x;
        t->next=slow->next;
        slow->next=t;
        
}
void linked::midhead()
{
        node *fast,*slow,*prev;
        slow=head;
        fast=head;
        prev=slow;
        while(fast!=NULL&&fast->next!=NULL)
        {       prev=slow;
                slow=slow->next;
                fast=fast->next->next;
                
        }
        
        node *p=slow->next;
        prev->next=slow->next;
        slow->next=head;
        head=slow;
        
}
void linked::alternate()
{
        if(head==NULL||head->next==NULL||head->next->next==NULL)
        {
                return ;
        }
      
        node*pre=head;
        while(pre->next!=NULL)
        {
       
        node *a=pre->next;
        node *b=a->next;
        delete a;
        pre->next=b;
        if(pre->next!=NULL)
        pre=pre->next;
        
        }
}
void linked::intersect()
{
        linked a,b;
        a.create();
        b.create();
        
        node *heada=a.returnhead();
        node *headb=b.returnhead();
        node *current,*prev=NULL,*headc;
        
        while(heada!=NULL && headb!=NULL)
        {
                        if(heada->data<headb->data)
                                {
                                        heada=heada->next;
                                } 
                         if(heada->data>headb->data)
                                {
                                        headb=headb->next;
                                }        
                        else
                        {
                        current=new node();
                        current->data=heada->data;
                        current->next=NULL;
                        if(prev!=NULL)
                        {
                        prev->next=current;
                        prev=current;
                        
                        }
                        else
                        {
                        
                        prev=current;
                        headc=prev;
                        }
                        heada=heada->next;
                        headb=headb->next;
                        }
        }
        cout<<"\n";
        while(headc!=NULL)
        {
                cout<<headc->data<<" ";
                headc=headc->next;
        }
        
       
}

void linked::mov2first()
{
        node *p=head,*prev;
        
        while(p->next!=NULL)
       {prev=p;
        p=p->next;
       } 
        prev->next=NULL;
        p->next=head;
        head=p;
}
node* linked::pswapr(node *head)
{
        if(head==NULL || head->next==NULL)
                return head;
        
        node* rem=head->next->next;
        
        node *newhead=head->next;
        
        head->next->next=head;
        
        head->next=pswapr(rem);
        return newhead;
}
void linked::pswapi()
{
        node *p,*q,*r,*s;
        if(head!=NULL &&head->next!=NULL)
        {
                p=head;
                q=head->next->next;
                head=head->next;
                head->next=p;
                p->next=q;
        }
        while(q!=NULL)
        {
                r=q->next;
                if(r!=NULL)
                s=r->next;
                else
                break;
                p->next=r;
                r->next=q;
                q->next=s;
                p=p->next->next;
                q=q->next;
        }
        
}
void linked::uremdep()
{
        node *t=head;
        
        while(t->next!=NULL)
        {
                node *p=t->next;
                node *prev=t;
                while(p!=NULL)
                {
                        if(p->data==t->data)
                        {
                                node *j=p;
                                //if(p->next!=NULL)
                                prev->next=p->next;
                                delete j;
                                
                                p=prev->next;
                        }
                        
                        else
                        {
                                prev=p;
                                
                                p=p->next;
                        }
                        
                }
                if(t->next!=NULL)
                t=t->next;
                else
                break;
        }
}
void linked::remdep()
{
        node *p=head;
        node *t=head->next;
        while(t!=NULL)
        {
               if(p->data==t->data)
               {
                p->next=p->next->next;
                t=p->next; 
               }
               else
               {
                p=t;
                t=t->next;
               }
                
        }
}
void linked ::printrec(node * p)
{
       if(p==NULL)
       return ;
       
       printrec(p->next);
       cout<<p->data<<" ";
}

void linked::palin()
{
        stack<node*>s;
        
        node * p=head;
        
        while(p!=NULL)
        {
                s.push(p);
                p=p->next;
        }
        
        p=head;
        
        while(p!=NULL)
        {
                if(s.top()->data!=p->data)
                {
                        cout<<"\n Not a plaindrome!!";
                        return ;
                }
             
                s.pop();
                p=p->next;
        }
        cout<<"\n Given string  palindrome ";
        return ;
        
}
void linked::nfromlast()
{
        int m;
        cout<<"\n Enter the value of m";
        cin>>m;
        
        node *f=head,*l=head;
        
        for(int i=0;i<m;++i)
        
        {
                f=f->next;
        }
        while(f!=NULL)
        {
        f=f->next;
        l=l->next;
        }
        cout<<"REQ ELEMENT IS : ";
        cout<<l->data;
}
void linked::getmid()
{
        node *fast=head,*slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
        slow=slow->next;
        fast=fast->next->next;
        
        }
      
       
        cout<<"MId element is : ";
        cout<<slow->data;
        
        
        
}
void linked::getfromindex()
{
        int t;
        cout<<"\n Enter index \n";
        cin>>t;
        if(t>=n)
        {
        cout<<"\n       INVALID INDEX";
        }
        node *p=head;
        for(int i=0;i<t;++i)
        {
           p=p->next;     
        }
        cout<<"  "<<p->data;
}
void linked::display()
{
       node *u=head;
        cout<<"\n";
        if(head==NULL)
        {
        cout<<"\nempty list";
        return ;
        }
       
       while(u->next!=NULL)
        {
                cout<<u->data<<"->";
                u=u->next;
        }
        cout<<u->data;
}
void linked::insertbeg()
{
        n++;
        node *u=new node();
        
        cout<<"\n Enter data";
        cin>>u->data;
        
        u->next=head;
        head=u;
     
        
}
void linked::delet()
{
        int y;
        cout<<"\n Enter value to be deleted";
        cin>>y;
        
        node * t=head;
        node *p;
        
        if(t->data==y)
        {
        p=head;
        head=head->next;
        delete p;
        }
        else
        {
        while(t->next!=NULL && t->next->data!=y)
        t=t->next;
        
        if(t->next!=NULL )
        {
                node *d=t->next;
                t->next=t->next->next;
                delete d;
        }
        else
        {
        cout<<"\n NOT FOUND";
        return;
        }
        
        }
        
}
void linked::insertend()
{
        node *u=new node(),*p=head;
        n++;
        cout<<"\n Enter data";
        cin>>u->data;
        u->next=NULL;
        
        while(p->next!=NULL)
        p=p->next;
        
        p->next=u;
        
}
void linked::insertaftervalue()
{
        int g;
        n++;
        cout<<"\n Enter value after which new value is to be inserted";
        cin>>g;
        
        node *u=new node(),*p=head;
        
        cout<<"\n Enter data";
        cin>>u->data;
        u->next=NULL;
        
        while(p->next!=NULL&&p->next->data!=g)
        {
        p=p->next;
                
        }
       
        if(p->next!=NULL)
        {
        p=p->next;
        u->next=p->next;
        p->next=u;
        }
        else 
        cout<<"\nNOT FOUND";
        
}
void linked::insertatpos()
{
        
        node * p=head;
        int pos;
        cout<<"\n Enter the pos";
        cin>>pos;
        if(pos>n)
        {
        cout<<"\n please insert pos between 1 and "<<n<<" !!";
        return ;
        }
        if(pos==1)
        {
        insertbeg();
        return ;
        }
        else if(pos==n+1)
        {
        insertend();
        return;
        }
        else
        {
        for(int i=1;i<pos-1;++i )
        {
                p=p->next;
        }
         node *u=new node();
        cout<<"\n Enter data";
        cin>>u->data;
        u->next=NULL;
        
        u->next=p->next;
        p->next=u;
        n++;
        }
        
}
void linked :: create()
{
      end=NULL;
     
      
      cout<<"\nEnter the number of nodes ";
      cin>>n;
      
      int k;
      node * g,*p;
      head=NULL;
     g=NULL;
     p=NULL;
      
      if(n>0)
      {
      cout<<"\n Enter data ";
       head=new node();
      cin>>head->data;
      head->next=NULL;
      
      p=head;
      
      for(int i=1;i<n;++i)
      {
        cin>>k;
        g=new node();
        g->data=k;
        g->next=NULL;
        p->next=g;
        p=p->next;
        if(i==3)
        {
        rand=g;
        }
        
      }
     /* if loop is to be created 
     g->next=head;*/
     if(n>1)
     end=g;
       else
       end=head;
      }
      }
      
void linked::lengthit()
{
        int k=0;
        node *y=head;
        
        while(y!=NULL)
        {k++;
        y=y->next;
        }
        
        cout<<"\n Length is : "<<k;
        
        
}
      
void linked::lengthrec(node *y)
{
        
    if(y==NULL)
    {
           cout<<"\n Length is : "<<n1;
           return ;
    } 
    n1++;
    lengthrec(y->next) ;  
}    

void linked::isearch(int r)
{
        node *t=head;
        
        for(int i=0;t!=NULL;i++)
        {
                if(t->data==r)
                {
                        cout<<"NUMBER FOUND AT LOCATION "<<i+1;
                        return ;
                }
                t=t->next;
        }
        cout<<"NOT FOUND !!!";
}

void linked::recsearch(int r,node* y)
{
         if(y==NULL)
        {
                cout<<"\nnot found";
                return ;
        }
        
        if(y->data==r)
        {
                cout<<"\n Number found at location "<<n1+1;
                return ;
        
        }
     
        n1++;
        
        recsearch(r,y->next);
}
void linked::swap()
{
        int x,y,m=0;
        
        cout<<"\n Enter the nodes to be swapped(enter data in node) ";
        cin>>x>>y;
        
        node *p=head;
        
        
       
        
        while(p->next!=NULL &&p->data!=x&& p->next->data!=x)
        {
        p=p->next;
        }
        if(p->next==NULL&&p->data!=x)
        {
            cout<<"\n number not found! : " <<x;
            return ;
                
        }
        lev1:
        node *q=head,*r;
      
        
        while(q->next!=NULL &&q->data!=y&& q->next->data!=y)
        {
        q=q->next;
        }
        if(q->next==NULL&&q->data!=y)
        {
            cout<<"\n number not found! : " <<y;
            return;
                
        }
        lev2:
       if(p->data!=x&& q->data!=y)
       {
        node *r=p->next;
        node *s=q->next;
        node *t=r->next;
        node *j=s->next;
        
        s->next=t;
        p->next=s;
        
        r->next=j;
        q->next=r;
        }
        else
        {
                if(p->data==x)
                {     
                      node *r=q->next;
                      node *s=r->next;
                      r->next=p->next;
                      head=r;
                      p->next=s;
                      q->next=p;
                        
                }
                if(q->data==x)
                {
                      node *r=p->next;
                      node *s=r->next;
                      r->next=q->next;
                      head=r;
                      q->next=s;
                      p->next=q;
                        
                }
        }
        
        
      }
      
void linked::revit()
{
        node *curr=head,*prev=NULL,*nex;
        
        while(curr!=NULL)
        {
                nex=curr->next;
                curr->next=prev;
                
                prev=curr;
                curr=nex;
        }
        
        head=prev;
        
}
void linked::revrec(node *head)
{
        node *first,*rest;
        
        if(head==NULL)
        return ;
        
        first=head;
        rest=first->next;
        
        if(rest==NULL)
        return ;
        
        revrec(rest);
        
        first->next->next=first;
        first->next=NULL;
        
        cout<<rest->data;
        head=rest;
        
        //display();
}
node* linked::returnhead()
{
        return head;
}  

void linked::detectloop()
{
        node *p=head;
        
       set<node *>s1;
        //unordered_set<node*>s;
        
        while(p!=NULL)
        {
                if(s1.find(p)!=s1.end())
                {
                        cout<<"\n LOOP detected!";
                        return ;
                }
                
                s1.insert(p);
                p=p->next;
        }
        cout<<"\n NO LOOP!!";
}
void linked :: ipoint()
{
         linked a,b;
       
        a.create();
        b.create();
       b.end->next=a.rand;
       
        //a.display();
       // cout<<"\n";
        //b.display();
        //cout<<"\n";
      // cout<<a.end->data<<"  "<<a.rand->data;;
       
      //cout<<"\n"<<b.end->data;
        node *heada=a.returnhead();
       node *headb=b.returnhead();
        while(heada!=NULL)
        {
                node *s=headb;
                while(s->next!=NULL)
                {
                        if(s->next==heada)
                        {
                                cout<<"\n Intersection point is "<<heada->data;
                                return ;
                        }
                        s=s->next;
                }
                heada=heada->next;
        }
}
void linked::mergeit()
{
        linked a,b;
        a.create();
        b.create();
        
        node *heada=a.returnhead();
        node *headb=b.returnhead();
        node *current=NULL;
       
       
        if(heada==NULL)
        {
                current=headb;
                
                node *p=current;
                cout<<"\n Merged list : ";
                while(p!=NULL)
                {
                        cout<<p->data<<" ";
                        p=p->next;
                }
                return;
                
        }
        if(headb==NULL)
        {
                current=heada;
                
                  
                node *p=current;
                cout<<"\n Merged list : ";
                while(p!=NULL)
                {
                        cout<<p->data<<"  ";
                        p=p->next;
                }
               return;
        }
        node* headc;
        if(heada->data<headb->data)
        {
                headc=heada;
                current =headc;
                heada=heada->next;
        }
        else
        {
                headc=headb;
                current=headc;
                headb=headb->next;
                
        }
        
        while(heada!=NULL&&headb!=NULL)
        {
                if(heada->data<headb->data)
                {
                        current->next=heada;
                        heada=heada->next;
                        current=current->next;
                        
                }  
                else
                
                 {
                        current->next=headb;
                        headb=headb->next;
                        current=current->next;
                        
                }  
                
                              
        }
        
        if(heada!=NULL)
        {
                current->next=heada;
                
        }
        
        if(headb!=NULL)
        {
                current->next=headb;
        }
        cout<<"\n Merged List : ";
        while(headc!=NULL)
        {
        cout<<headc->data<<" ";
        headc=headc->next;
        }
        return ;
}
node* linked::mergecur(node *heada,node* headb)
{
        node* headc=NULL;
        if(heada==NULL)
        return headb;
        if(headb==NULL)
        return heada;
        
        if(heada->data<headb->data)
        {
        headc=heada;
        headc->next=mergecur(heada->next,headb);
        }
        else
        {
        headc=headb;
        headc->next=mergecur(heada,headb->next);
        }
}
void linked::mer1()
{
         linked a,b;
        a.create();
        b.create();
        node *s;
        node *heada=a.returnhead();
        node *headb=b.returnhead();
        node *headc=NULL;
        s=mergecur(heada,headb);
        cout<<"\n Merged list : ";
        while(s!=NULL)
        {
            cout<<s->data<<" ";
            s=s->next;    
        }
        
}
int main()
{

        linked l;
        node *r1;
        int r;
        while(1)
        {
        cout<<"\n \t Main Menu";
        
        cout<<"\n 1.Press 1 for creation";
        cout<<"\n 2.Press 2 for display";
        cout<<"\n 3.Press 3 for insertion";
        cout<<"\n 4.Press 4 for deletion";
        cout<<"\n 5.Press 5 for Finding length of list";
        cout<<"\n 6.Press 6 for  Searching an element";
        cout<<"\n 7.Press 7 for swapping nodes without swappping data";
        cout<<"\n 8.Press 8 for searching element at any particular index (starting with 0)";
        cout<<"\n 9.Press 9 for finding middle element";
        cout<<"\n10.Press 10 for nth element from the end";
        cout<<"\n11.Press 11 for reversing a linked list";
        cout<<"\n12.Press 12 for detecting loop";
        cout<<"\n13.Press 13 for merging list";
        cout<<"\n14.Press 14 for detecting palindromes";
        cout<<"\n15.Press 15 for getting intersection of two singly linked list";
        cout<<"\n16.Press 16 for Printing list in recursive order";
        cout<<"\n17.Press 17 for Removing duplicate enteries(sorted list)";
        cout<<"\n18.Press 18 for Removing duplicate enteries(unsorted list)";
        cout<<"\n19.Press 19 for pairwise swapping of elements";
        cout<<"\n20.Press 20 for moving last element to the first elemnt of list ";
        cout<<"\n21.Press 21 to find intersection of two lists";
        cout<<"\n22.press 22 for removing alternate nodes ";
        cout<<"\n23.Press 23 for making middle element as head";
        cout<<"\n24.Press 24 for insert an elemnt at nth place from end";
        cout<<"\n25.Press 25 for sorting a list of 0's 1's 2's";
        cout<<"\n26.Press 26 for Reverse a linked list in groups of k";
        cout<<"\n27.Press 27 for exit";
        
        
        int ch,ch1;
        
        cin>>ch;
        
        
        char p;
       
        switch(ch)
        {
                case 1:         
                          l.create();
                          break;
                case 2 :
                          l.display();
                          break;
                case 3:
                        cout<<"\na.for insertion at begining";
                        cout<<"\nb.for insertion in end";
                        cout<<"\nc.for insertion at any particular position ";
                        cin>>p;
                        switch(p)
                        {
                                case 'a': l.insertbeg();
                                        break;
                                case 'b': l.insertend();
                                        break;
                                case 'c': cout<<"\n1.for insert after any particular val ";
                                        cout<<"\n2.for insert at any desired position";
                                        cin>>ch1;
                                        switch(ch1)
                                        {
                                        case 1:l.insertaftervalue();
                                                break;
                                        case 2:l.insertatpos();
                                                break;
                                        }
                                          break;      
                        }
                        break;
                   case 4:
                                l.delet();
                                break;
                case 5: 
                                cout<<"\n1. for iterative";
                                cout<<"\n2. for recursive";
                                cin>>ch1;
                                switch(ch1)
                                {
                                        case 1:l.lengthit();
                                                break;
                                        case 2: l.n1=0;
                                                l.lengthrec(l.returnhead());
                                                break;
                                }
                                break;
              case 6:   cout<<"\n Enter value to be searched";
                        cin>>r;
                        cout<<"\n1. for iterative search";
                        cout<<"\n2. for  recursive search";
                        cin>>ch1;
                        switch(ch1)
                        {
                                case 1:l.isearch(r);
                                        break;
                               case 2:  l.n1=0;
                                        l.recsearch(r,l.returnhead());
                                        break;
                        }
                        break;
              case 7:     l.swap();
                                break;
              case 8:     l.getfromindex();
                                break;
              case 9:     l.getmid();
                                break;
              case 10:    l.nfromlast();
                        break;
              case 11:    
                        cout<<"\n 1.for iterative";
                        cout<<"\n 2.for recursive ";
                        cin>>ch1;
                        switch(ch1)
                        {
                                case 1:l.revit();
                                        break;
                                case 2: //l.revrec(l.returnhead());  //*******************************************//
                                        break;  
                        }
                        break;
             case 12: //l.returnhhead()->next->next->next->next=head;
                       l.detectloop();
                        break;
             case 13:   cout<<"\n1.Press 1 for iterative";
                        cout<<"\n2.Press 2 for recursive";
                        cin>>ch1;
                        switch(ch1)
                        {
                                case 1:l.mergeit();
                                     
                                        break;
                                 case 2: l.mer1();
                                                break;
                                     
                        }
                        break;
            case 14:    l.palin();
                        break;
            case 15:    l.ipoint();
                                break;
            case 16:  l.printrec(l.returnhead());
                        break;  
            case 17:  l.remdep();
                        break;  
            case 18:l.uremdep();
                        break;         
            case 19: cout<<"\n1.Press 1 for iterative  ";
                     cout<<"\n2.Press 2 for recursive ";
                     cin>>ch;
                     switch(ch)
                     {
                        case 1:l.pswapi();
                                break;
                        case 2://r1=l.returnhead();
                               //  r1 =l.pswapr(l.returnhead());
                                break;
                     }
                     break;
         case 20:
                        l.mov2first();
                        break;  
         case 21: l.intersect();
                        break;
         case 22:l.alternate();
                        break;
         case 23:l.midhead();
                break;
         case 24:l.insnend();
                break;
         case 25:l.sort012();
                        break;
         case 26:l.revgroup();
                        break;
         
         case 27:return 0;
                                
          }
        }
        
}
