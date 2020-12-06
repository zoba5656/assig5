#include<iostream>
#include<string>
#include<malloc.h>
#define null 0
#define size_stack 10
#define size_queue 10
using namespace std;

//*******Lnked List *****//
struct node{
	int val;
	node *next;
};
typedef node *ptr;

ptr new_node(){
	ptr p=(ptr)malloc(sizeof(node));
	return p; 
}
//function of add in first for linked list
void add_first(ptr &li, int n){
	ptr p=new_node();
	p->val = n;
	p->next = li;
	li=p;
}

//function of add in middle for linked list
void add_node(ptr &li, int n){
	ptr p=new_node();
	p->val = n;
	p->next = li->next;
	li->next=p;
}


//function of add in last for linked list
void add_last(ptr &li, int n){
	ptr p=new_node();
	p->val = n;
	p->next = null;
	ptr t=li;
	while(t->next!=null){
		t=t->next;
	}
	t->next =p;
}

//function of delete first node in linked list

void del_first(ptr &li){
	ptr p = li;
	li=p->next;
	free(p);
}

//function of delete node in middle for linked list
void del_node(ptr &li){
	ptr p=li->next;
	li->next=p->next;
	free(p);
}

//function of delete last node in linked list
void del_last(ptr &li){
	ptr p,n;
	p=li;
	while(p->next!=null){
		n=p;
		p=p->next;
	}
	n->next =null;
}

//function for count lenght of linked list
int Count(ptr &q)
{
	ptr p;
	p=q;
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

//function for search element in linked list
void search(ptr li,int s){
	ptr p =li;
	bool t =false;
	while(p!=null){
		if(p->val==s){
			cout<<"element is found";
			t=true;
			break;
		}
		p=p->next;
	}
	if(t)
	cout<<"element not found";
} 

//function of display list for linked list
void show(ptr li){
	ptr t = li;
	while(t!=null){
		cout<<t->val<<endl;
		t= t->next;
	}
}

//****** Stack ****//
class stack{
	private:
		int top;
		int data[size_stack];
	public:
	stack(){
		top = -1;
	}
//function of add in stack	
	void push(int n){
		if(top==size_stack-1){
			cout<<"full stack";
		} 
		else{
		top++;
		data[top] = n;	
		}
	}
//function of delete in stack
	void pop(){
		if(top==-1){
			cout<<"stack is empty \n";
		} else{
			top--;
		}
	}
//function of display stack
	void show_stack(){
		for(int i=top;i>=0;i--){
			cout<<data[i]<<endl;
		}
	}	
};

//****** Queue ****//
struct queue{
	int data[size_queue];
	int front,rear;
};
//function of add in queue
void add(queue &q,int num){
	if(q.rear==size_queue)
	cout<<"queue is full";
	else
	q.data[q.rear++]=num;
	
}

//function of delete in queue
void del(queue &q){
	if(q.front==q.rear)
	 cout<<"queue is empty";
	 else
	 	cout<<"the deleted nomber is : "<<q.data[q.front++]<<endl;
	 
	 
}

//function of display queue
void show_queue(queue &q){
	if(q.front==q.rear)
	cout<<"queue is empty \n";
	else{
		for(int i=q.front;i<q.rear;i++)
		cout<<"  "<<q.data[i]<<"  ";
	}
}

int main (void)
{
	char s;
	cout<<"Choose one of the types of data structure to be dealt with in data entry : \n";
	cout<<"A/ linked list \n"<<"B/ stack \n"<<"C/ queue \n";
	cout<<"Enter A  or B  or  C :  ";
	cin>>s;
	if(s=='A'){
	ptr n1=new_node();
	ptr n2=new_node();
	ptr n3=new_node();
	ptr list = n1;
	
	n1->val = 10;
	n1->next = n2;
	
	n2->val = 8;
	n2->next = n3;
	
	n3->val = 6;
	n3->next = null;
	
	cout<<"This is linked list \n";
	show(list);
	cout<<"\n Choose what do you want : \n";
	cout<<" D/Add element    E/Delet element    F/Lenght of linked list    G/Search for a specific element    H/Display list";
	char l;
	cout<<"\n Enter D   or   E   or   F   G   or   H : ";
	cin>>l;
	
	if(l=='D'){
	cout<<"\n 1/ add element in first linked \n 2/ add element after any element in linked \n 3/ add element after in last linked \n";
	int n;
	cout<<"\n Enter 1  or  2  or  3  :  ";
	cin>>n;
	if(n==1){
	int b;
	cout<<"Enter number do you want add in first :  ";
	cin>>b;
	add_first(list,b);
	cout<<"This is linked list after add \n";
	show(list);
	}
	else if(n==2){
	int b;
	cout<<"Enter number do you want add in middle :  ";
	cin>>b;
	add_node(n1,b);
	cout<<"This is linked list after add \n";
	show(list);
	}
	else if(n==3){
	int b;
	cout<<"Enter number do you want add in last :  ";
	cin>>b;
	add_last(list,b);
	cout<<"This is linked list after add \n";
	show(list);
	}
	}
	
	
	else if(l=='E'){
		
		cout<<"\n 1/ delete element in first linked \n 2/ delete element after any element in linked \n 3/ delete element after in last linked \n";
	int n;
	cout<<"\n Enter 1  or  2  or  3  :  ";
	cin>>n;
	if(n==1){
    del_first(list);
	cout<<"This is linked list after add \n";
	show(list);
	}
	else if(n==2){
	del_node(n1);
	cout<<"This is linked list after add \n";
	show(list);
	}
	else if(n==3){
	del_last(list);
	cout<<"This is linked list after add \n";
	show(list);
		
	}

	
	}
	else if(l=='F'){
		cout<<"The lenght of linked list is : "<<Count(list);
	}
	
	else if(l=='G'){
		int b;
		cout<<"Enter element do you want search it :  ";
		cin>>b;
		search(list,b);
	}
	else if(l=='H'){
		show(list);
	}
	
}
else if(s=='B'){
	char l;
	 int e;
 stack s;
 s.push(100);
 s.push(90);
 s.push(80);
 s.push(70);
 cout<<"This is element of stack \n";
 s.show_stack();
 cout<<"\n Choose what do you want : \n";
 cout<<" D/Add element    E/Delet element";
 cout<<"\n Enter D   or   E :   ";
 cin>>l;
 if(l=='D'){
 	cout<<"\n Enter element do you add :  ";
 	cin>>e;
 	s.push(e);
 	cout<<"This is element of stack after add \n";
 	 s.show_stack();
 }
 else if(l=='E'){
 	
  s.pop();	
  cout<<"This is element of stack after delete \n";
  s.show_stack();
 }
 
}
else if(s=='C'){
	char l;
	int e;
 queue q1;
  q1.front = 0;
  q1.rear = 0;
  
  add(q1,30);
  add(q1,31);
  add(q1,33);
  
  cout<<"This is element of queue \n";
  show_queue(q1);
  
  cout<<"\n Choose what do you want : \n";
 cout<<" D/Add element    E/Delet element";
 cout<<"\n Enter D   or   E :   ";
 cin>>l;
 
  if(l=='D'){
 	cout<<"\n Enter element do you add :  ";
 	cin>>e;
 	 add(q1,e);
 	cout<<"This is element of queue after add \n";
 	 show_queue(q1);
 }
 else if(l=='E'){
 del(q1);	
  cout<<"This is element of queue after delete \n";
  show_queue(q1);
 }
 
}
}
