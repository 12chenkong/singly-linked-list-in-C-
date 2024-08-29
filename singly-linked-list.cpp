#include<iostream>
#include<stdlib.h>
using namespace std;

 typedef struct node{
	int data;
	struct node*next;
}node;
  node*head;
// create node in singly linked list
 node* createNode(){
 	int choice;
	 head=0;node*newNode,*temp;
	do{
	newNode=(node*)malloc(sizeof(node));
	cout<<"Enter data to the node:";
	cin>>newNode->data;
	newNode->next=0;
	if(head==0){
		temp=head=newNode;
	}else{
		temp->next=newNode;
		temp=newNode;
	}
	cout<<"DO you want to continues (0,1): ";
	cin>>choice;
	}while(choice==1);
	
	 return head;
}

//	display of all value in nodes
void displayNode(node*head){
	node*temp=head;
	if(head==0){
		cout<<"List is empty please add node!"<<endl;
	}else{
		
		while(temp!=0){
	cout<<"Value in node: "<<temp->data<<endl;
	temp=temp->next;
	}
	
	}

}
// insert new node at front in the list
 node* insertAtFront(node* head){
 	node*newnode;
 	if(head==0)
 	cout<<"Cannot insert at front cuz list is empty"<<endl;
 	else{
 		newnode=(node*)malloc(sizeof(node));
  	  cout<<"Enter value to node: "<<endl;
  	  cin>>newnode->data;
  	  newnode->next=head;
     	head=newnode;
     	
	 }
  	
	
  	return head;
  	
  }
  //Inserting newly created noded at the end of node
  node* insertAtEnd(node *head){
  	node*temp=head,*newnode;
  	if(head==0){
  		cout<<"Canno insert at the end cuz list is empty"<<endl;
	  }else{
	  	newnode=(node*)malloc(sizeof(node));
    cout<<"Enter date the last node in the list:"<<endl;
    cin>>newnode->data;
    newnode->next=0;
	    while(temp->next!=0){
	    	temp=temp->next;
		}
		temp->next=newnode;
		cout<<"Insert node successfully"<<endl;
	  }
    
	return head;
    
  }
  //Counting number of nodes in singly linked list 
  int countNodes(node*head){
  	node*temp=head;
  	int count=0;
  	if(head==0)
	  cout<<"Cannot count node cuz list is empty"<<endl;
  	while(temp!=0){
  		temp=temp->next;
  		count++;
	  }
	  return count;
  }
  
  //Inserting node after the given location in linked list
  node* insertAferGivenPosition(node*head){
  	node*temp=head;
  	node* newnode;
  	int i=1,position;
  	if(head==0){
  		cout<<"Cannot insert node cuz list empty"<<endl;
	  }
	  else{
	  	//Call another function that count the nodes in the list
	  	int numOfNodes=countNodes(head);
	  	cout<<"Enter postion of node to enter after: "<<endl;
	  	cin>>position;
	  	if(position>numOfNodes){
	  		cout<<"Invalid position!"<<endl;
	  }else{
	  	
	  	newnode=(node*)malloc(sizeof(newnode));
	  	cout<<"Enter value of node: "<<endl;
	  	cin>>newnode->data;
	  	newnode->next=0;
	  	// finding specific position
	  	while(i<position){
	  		temp=temp->next;
	  		i++;
		  }
		  newnode->next=temp->next;
		  temp->next=newnode;
		  
	  }
	  	
	  }
  	
	  return head;
  }
  // Delete node at the beginning in the list
  node* deleteAtBeginning(node* head){
  		node*temp=head;
  	if(head==0){
  		cout<<"Cannot delete cuz it list is empty"<<endl;
	  }else{
	  	if(head->next==0){
  		head=0;
  		free(temp); 
	  }else{
	  	head=head->next;
  	    free(temp);
	  }
	  
	  }
  
  	return head;
  	
  }
  // Deleting node at the end
  node* deleteFromEnd(node *head){
  	node*temp,*preNode;
  	temp=head;
  	while(temp->next!=0){
  		preNode=temp;
  		temp=temp->next;
	  }
	  // if there is only one node in the list 
	  if(head==temp){
	  	head=0;
	  	free(temp);
	  }else{
	  	preNode->next=0;
	  	free(temp);
	  }
  	return head;
  }
  // Reverse a linked list 
  void reverse(node * head){
  	 node *preNode=0,*currentNode,*nextNode;
  	 currentNode=nextNode=head;
  	 if(head==0){
  	 	cout<<"Cannot reverse node cuz list is empty"<<endl;
	   }else{
	   	 while(nextNode!=0){
  	 	nextNode=nextNode->next;
  	 	currentNode->next=preNode;
  	     preNode=currentNode;
  	     currentNode=nextNode;
	    }
	    head=preNode;
	   }
	   // call display method to display revered liked 
	   displayNode(head);
	   
  	
  }
  
  bool searchNode(node * head,int num){
  	node*temp=head;
  	if(head==0)
  	return false;
  	else{
  		while(temp!=0){
  		if(temp->data==num){
  			return true;
		  }
		  else 
		  temp=temp->next;
	  }
	  
	  }
  	
	  return false;
  }
  
  void option (){
  	cout<<"1.Create nodes:"<<endl;
  	cout<<"2.Display nodes:"<<endl;
  	cout<<"3.Insert node at front:"<<endl;
  	cout<<"4.See total nodes in list:"<<endl;
  	cout<<"5.Insert node at the end:"<<endl;
  	cout<<"6.Insert node after given position"<<endl;
  	cout<<"7.Delete node at the beginning"<<endl;
  	cout<<"8.Delete node at the end"<<endl;
  	cout<<"9.Reverse the linked list"<<endl;
  	cout<<"10.Search node: "<<endl;
  	cout<<"Exit the program"<<endl;
  	
  }
main(){
	 
	int opt=1;
	node *head=0;
	int num;
      
    
	do{
		option();
		cout<<"Chose the option aboave!"<<endl;
		cin>>num;
		
		switch(num){
			case 1:
			head=createNode();
				break;	
			case 2:
				displayNode(head);
			break;	
			case 3:
			head=insertAtFront(head);
				break;
			case 4:{
				int numOfNodes=countNodes(head);
				string re=(numOfNodes>=2)?" are nodes ":" is node ";
				cout<<"There "<<numOfNodes<<re<<endl;
				break;
			}
			case 5:
				insertAtEnd(head);
			break;
			case 6:
				insertAferGivenPosition(head);
				break;
			case 7:
			head=deleteAtBeginning(head);
				break;
			case 8:
			  head=deleteFromEnd(head);
				break;
			case 9:
				reverse(head);
				break;
			case 10:{
				cout<<"Enter node to search: "<<endl;
		    	cin>>num;
		       if(searchNode(head,num)!=false)
		       cout<<"node exist in the list"<<endl;
		       else
		       cout<<"Node does not exit in the list or list emtpy"<<endl;
				break;
			}
			
			break;
			default:
				cout<<"Invlid input Please enter again!"<<endl;
		}
		
	}while(num!=11);

     
     
  }
