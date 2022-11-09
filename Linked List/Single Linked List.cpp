#include <iostream>
using namespace std;

struct Data{
	
	string nama, asal;
	int umur;
	
	Data *next;
	
};

Data *head, *tail, *cur, *newNode, *del, *before;

//Create single linked list
void createSingleLinkedList(string nama, string asal, int umur){
	head = new Data();
	head->nama = nama;
	head->asal = asal;
	head->umur = umur;
	head->next = NULL;
	tail = head;
}

//Print single linked list
int countSingleLinkedList(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

//Insert FirstNode
void insertFirst(string nama, string asal, int umur){
	newNode = new Data();
	newNode->nama = nama;
	newNode->asal = asal;
	newNode->umur = umur;
	newNode->next = head;
	head = newNode;
}

//Insert LastNode
void insertLast(string nama, string asal, int umur){
	newNode = new Data();
	newNode->nama = nama;
	newNode->asal = asal;
	newNode->umur = umur;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

//Insert Middle
void insertMiddle(string nama, string asal, int umur, int pos){
	if(pos < 1 || pos > countSingleLinkedList() ){
		cout << "Posisi diluar jangkauan\n" << endl;
	}else if(pos == 1){
		cout << "Posisi bukan posisi tengah\n" << endl;
	}else{
		newNode = new Data();
		newNode->nama = nama;
    	newNode->asal = asal;
		newNode->umur = umur;

    // tranversing
    cur = head;
    int num = 1;
    while(num < pos - 1){
    	cur = cur->next;
    	num++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
	}
}

//Erase First
void eraseFirst(){
	
	del = head;
	head = head->next;
	delete del;
}


//Erase Last
void eraseLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}

//Erase middle
void eraseMiddle(int pos){
	if(pos < 1 || pos > countSingleLinkedList()){
		cout << "Posisi diluar jangkauan" << endl;
	}else if(pos == 1){
		cout << "Posisi bukan posisi tengah" << endl;
	}else{
		int num = 1;
    	cur = head;
    	while(num <= pos){
    	if(num == pos-1){
    		before = cur;
    	}
    	if(num == pos){
    		del = cur;
    	}
    	cur = cur->next;
    	num++;
    	}
    	before->next = cur;
    	delete del;
	}
}

//Change the first Single linked list
void changeFirst(string nama, string asal, int umur){
	head->nama = nama;
	head->asal = asal;
	head->umur = umur;
}

//Change the last Single linked list
void changeLast(string nama, string asal, int umur){
	tail->nama = nama;
	tail->asal = asal;
	tail->umur = umur;
}

//Change the middle Single linked list
void changeMiddle(string nama, string asal, int umur, int pos){
  if(pos < 1 || pos > countSingleLinkedList()){
    cout << "Posisi diluar jangkauan" << endl;
  }else if(pos == 1 || pos == countSingleLinkedList()){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    cur = head;
    int num = 1;
    while(num < pos){
      cur = cur->next;
      num++;
    }
    cur->nama = nama;
    cur->asal = asal;
    cur->umur = umur;
  }
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout << "Nama: " << cur->nama << endl;
		cout << "Asal: " << cur->asal << endl;
		cout << "Umur: " << cur->umur << endl << endl;
		
		cur = cur->next;
	}

}

int main(){
	
	createSingleLinkedList("Jonathan", "Canada", 26);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;

	insertFirst("Muller", "Germany", 34);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;

	insertLast("Mount", "England", 22);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	eraseFirst();
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;

	insertLast("Rodrygo", "Brazil", 20);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	eraseLast();
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	changeFirst("Ruben", "Portugal", 26);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	changeLast("Vinicius", "Brazil", 21);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	insertMiddle("Buffon", "Italy", 42, 2);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	insertMiddle("Haaland", "Denmark", 22, 2);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	eraseMiddle(3);
	printSingleLinkedList();
	
	cout << "=================================\n" << endl;
	
	changeMiddle("Kvaratskhelia", "Georgia", 21, 2);
	printSingleLinkedList();
	
}
