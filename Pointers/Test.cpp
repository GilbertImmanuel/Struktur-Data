#include <iostream>
using namespace std;

int main(){
	string quote = "You know Robert LewanGOALski?";
	string *ptr = &quote;
	cout << "Quote: " << quote << endl;
	cout << "Address: " << ptr << endl;
	cout << "*ptr: " << *ptr << endl;
	
	//manipulation
	
	*ptr = "How about Leon SCOREtzka?";
	cout << "Quote: " << quote << endl;
	cout << "Address: " << ptr << endl;
	
	return 0;
}
