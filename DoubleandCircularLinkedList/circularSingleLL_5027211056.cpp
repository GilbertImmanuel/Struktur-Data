#include <iostream>
using namespace std;

struct Footballers{
  string name, role, team;

  Footballers *next;
};

Footballers *head, *tail, *newNode, *cur, *del;

void createCircSLL(string dataBaru[3]){

  head = new Footballers();
  head->name = dataBaru[0];
  head->role = dataBaru[1];
  head->team = dataBaru[2];
  tail = head;
  tail->next = head;

}

void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    newNode = new Footballers();
    newNode->name = data[0];
    newNode->role = data[1];
    newNode->team = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    newNode = new Footballers();
    newNode->name = data[0];
    newNode->role = data[1];
    newNode->team = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string data[3], int pos)
{
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    if( pos == 1 ){
      cout << "Position 1 is not in the middle." << endl;
    }else{
      newNode = new Footballers();
      newNode->name = data[0];
      newNode->role = data[1];
      newNode->team = data[2];

      int num = 1;
      cur = head;
      while (num < pos - 1)
      {
        cur = cur->next;
        num++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}

void printCircular()
{
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    cur = head;
    while (cur->next != head)
    {
      cout << "Name: " << cur->name << endl;
	  cout << "Position: " <<cur->role<< endl;
	  cout << "Club: " <<cur->team << "\n" << endl;
      cur = cur->next;
    }
    cout << "Name: " << cur->name << endl;
	cout << "Position: " << cur->role <<  endl;
	cout << "Club: " <<cur->team << "\n" << endl;
    cout << "===================================" << endl;
  }
}


int main(){
  string dataBaru[3] = {"Vinicius Jr", "Left Wing", "Real Madrid"};
  createCircSLL(dataBaru);

  printCircular();

  string data[3] = {"Lionel Messi", "Right Wing", "Paris Saint Germain"};
  addFirst(data);

  printCircular();

  string data2[3] = {"Zlatan Ibrahimovic", "Striker", "AC Milan"};
  addLast(data2);

  printCircular();

  string data3[3] = {"Nico Shlotterbeck", "Centre Back", "Borrusia Dortmund"};
  addMiddle(data3, 5);

  printCircular();
}

