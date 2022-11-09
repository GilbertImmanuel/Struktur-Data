#include <iostream>
using namespace std;

struct userData{
	string name, id;
	userData *prev;
	userData *next;
};

userData *head, *tail, *cur, *newNode, *del, *afterNode;
	
void createDLL(string data[2]){
	head = new userData();
	head->name = data[0];
	head->id = data [1];
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}

int countDLL()
{
  if( head == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = head;
    int sum = 0;
    while( cur != NULL ){
      sum++;      

      cur = cur->next;
    }
    return sum;
  }
}

void addFirst(string data[2]){
		if (head == NULL ){
		cout << "Double Linked List has not been formed.";
	}
	else{
		newNode = new userData();
		newNode->name = data[0];
		newNode->id = data [1];
		newNode->prev = NULL;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void addLast(string data[2]){
		if (head == NULL ){
		cout << "Double Linked List has not been formed.";
	}
	else{
		newNode = new userData();
		newNode->name = data[0];
		newNode->id = data [1];
		newNode->prev = tail;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

void addMiddle(string data[2], int pos){
		if (head == NULL ){
		cout << "Double Linked List has not been formed.";
	}
	else{
		if( pos == 1 ){
      		cout << "Position 1 is not the middle position." << endl;
    	}else if( pos < 1 || pos > countDLL() ){
			cout << "Position is out of range." << endl;
    	}else{
      		newNode = new userData();
      		newNode->name = data[0];
      		newNode->id = data[1];
      		
      	cur = head;
      	int num = 1;
      	while(num <  pos - 1){
        	cur = cur->next;
        	num++;
      	}

      	afterNode = cur->next;
      	newNode->prev = cur;
      	newNode->next = afterNode;
      	cur->next = newNode;
      	afterNode->prev = newNode;
    	}	
  	}
}

void printDLL(){
	if (head == NULL ){
		cout << "Double Linked List has not been formed.";
	}
	else{
		cur = head;
		while( cur != NULL ){
			cout << "Name: " << cur->name << endl;
			cout << "ID: " << cur->id << "\n" << endl;
		
		cur = cur->next;
		}
	}
}

int main(){
	
	string newData[2] = {"Fransiskus Benjamin", "5027211056"};
	createDLL(newData);

	printDLL();
	
	cout << "========================================\n" << endl;
	
	string data2[2] = {"Muhammad Ilham Yumna", "5027211024"};
	addFirst( data2 );
	
	printDLL();
	
	cout << "========================================\n" << endl;
	
	string data3[2] = {"Wisnu Adjie Saka", "5027211051"};
	addLast( data3 );
	
	printDLL();
	
	cout << "========================================\n" << endl;
	
	string data4[2] = {"Aloysius Bataona Manullang", "5027211008"};
	addMiddle( data4, 3 );
	
	printDLL();
}
