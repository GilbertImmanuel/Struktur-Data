#include <iostream>
using namespace std;

struct crewList{
  string crewmateColor, crewmateRole;

  crewList *prev;
  crewList *next;
};

crewList *head, *tail, *cur, *del, *newNode, *afterNode;

void createCircDLL(string newCrew[2]){
  head = new crewList();
  head->crewmateColor = newCrew[0];
  head->crewmateRole = newCrew[1];
  head->prev = head;
  head->next = head;
  tail = head;
}

void addFirst(string crewmate[2]){
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    newNode = new crewList();
    newNode->crewmateColor = crewmate[0];
    newNode->crewmateRole = crewmate[1];
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

void addLast(string crewmate[2]){
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    newNode = new crewList();
    newNode->crewmateColor = crewmate[0];
    newNode->crewmateRole = crewmate[1];
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

void addMiddle(string crewmate[2], int pos){
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    if( pos == 1 ){
      cout << "Position 1 is not in the middle" << endl;
    }else if( pos < 1 ){
      cout << "Position is out of range." << endl;
    }else{
      newNode = new crewList();
      newNode->crewmateColor = crewmate[0];
      newNode->crewmateRole = crewmate[1];

      cur = head;
      int num = 1;
      while ( num < pos - 1 ){
        cur = cur->next;
        num++;
      }
      afterNode = cur->next;
      cur->next = newNode;
      afterNode->prev = newNode;
      newNode->prev = cur;
      newNode->next = afterNode;
    }
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Create the Linked List first." << endl;
  }else{
    cur = head;
    while( cur->next != head ){
    
      cout << "Crewmate : " << cur->crewmateColor << endl;
      cout << "Role : " << cur->crewmateRole << "\n" <<endl;

    
      cur = cur->next;
    }
    
      cout << "Crewmate : " << cur->crewmateColor << endl;
      cout << "Role : " << cur->crewmateRole << "\n" << endl;
  }
}

int main(){

  string newCrew[2] = {"Red", "Innocent"};
  createCircDLL(newCrew);
  
  printCircular();
  
  cout << "========================================\n" << endl;

  string crewmate[2] = {"Pink", "Imposter"};
  addFirst(crewmate);
  
  printCircular();
  
  cout << "========================================\n" << endl;

  string crewmate2[2] = {"Black", "Engineer"};
  addLast(crewmate2);
  
  printCircular();
  
  cout << "========================================\n" << endl;

  string crewmate3[2] = {"Green", "Innocent"};
  addMiddle(crewmate3, 3);
  
  printCircular();
}
