// LINKEDLIST 😆
#include <iostream>
using namespace std;

class Node{
    private:
         int data;
         Node* next;
    public:
    	
    Node()
	{
        data = 0;
        next = NULL;
    }
    
    Node(int data )
	{
        setData(data);
       next = NULL;  
	}
	
    void setData(int data)
	{
        this -> data = data;
    }
    
    void setNext(Node* next)
	{
        this -> next = next;
    }
    
    int getData()
	{
        return data;
    }
    
    Node* getNext()
	{
        return next;
    }
};

class LinkedList{
    private:
    Node *head;
    
    public:
    LinkedList()
	{
        head = NULL;
    }
	
	 bool isEmpty()
	{ 
      return (head==NULL);
    }
    
    void insertAtBegin(int val)
	{
         if(isEmpty())
		 {
            head = new Node(val);
         }
         else{
        
            Node* t = new Node(val);
            t->setNext(head);
            head = t;
       }
    }
    
    void insertAtLast(int val)
	{
    	Node* t1 = new Node(val);
    	if(isEmpty()){
    		head = t1;
		}
		else{
			Node* temp = head;
			while(temp -> getNext() != NULL){
				temp = temp -> getNext();
			}
			temp -> setNext(t1);
		}
	}
	
	 void removeFromBegin()
	{
    	Node* t = head -> getNext();
    	delete head;
    	head = t;
	}
	
	void removeFromLast()
	{
		Node* t1 = head;
		Node* t2 = head -> getNext();
		while(t2 -> getNext() != NULL){
			t1 = t1 -> getNext();
			t2 = t2 -> getNext();
			delete t2;
		}
		t1 -> setNext(NULL);
	}
	
	  int getLength()
	{
        int count = 0;
        if(!isEmpty()){
            Node* temp = head;
            while(temp != NULL){
                temp = temp -> getNext();
                count++;
            }
        }
        return count;
    }
    
	 void getFirstElement()
	{
    	cout << "\nFirst Element is: "<< head -> getData();
	}
	
	void getLastElement()
	{
		if(head != NULL){
			while(head -> getNext() != NULL){
				head = head -> getNext();
			}
		}
		cout << head -> getNext();
	}
  
    void printAllElements()
	{
        if(!isEmpty()){
            Node* temp = head;
            while(temp != NULL){
                cout << temp -> getData() << ' ';
                temp = temp -> getNext();
            }
        }
    }
};
int main() 
{
    LinkedList L1;
   // cout << L1.isEmpty()<< endl;   
    L1.insertAtBegin(5);
    L1.insertAtBegin(10);
    L1.insertAtBegin(15);
    L1.insertAtBegin(20);
    L1.insertAtBegin(25);
    L1.insertAtBegin(30);
    cout << "Length is:" <<L1.getLength() <<endl;   
    L1.printAllElements();
    L1.removeFromBegin();
    L1.getFirstElement();
    cout << "\n Last Element:";
	L1.getLastElement();
 
}