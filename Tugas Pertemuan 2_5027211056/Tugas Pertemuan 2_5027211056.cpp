#include <iostream>
#include <string>
#include <array>
using namespace std;

struct Character
{
	string Name;
	int Age;
	float Height;
	string Occupation;
};

int main()
{
	struct Character list_char[20];
	
	list_char[0].Name = "Elysia";
	list_char[0].Age = 22;
	list_char[0].Height = 155.5;
	list_char[0].Occupation = "Model";
	
	list_char[1].Name = "Kevin";
	list_char[1].Age = 25;
	list_char[1].Height = 176.8;
	list_char[1].Occupation = "IT Engineer";
	
	list_char[2].Name = "Kalpas";
	list_char[2].Age = 26;
	list_char[2].Height = 181.2;
	list_char[2].Occupation = "Chef";
	
	list_char[3].Name = "Mobius";
	list_char[3].Age = 29;
	list_char[3].Height = 152.6;
	list_char[3].Occupation = "Chemistry Teacher";
	
	list_char[4].Name = "Sakura";
	list_char[4].Age = 24;
	list_char[4].Height = 169.7;
	list_char[4].Occupation = "Salesman";
	
	list_char[5].Name = "Hua";
	list_char[5].Age = 19;
	list_char[5].Height = 162.4;
	list_char[5].Occupation = "College Student";
	
	list_char[6].Name = "Otto";
	list_char[6].Age = 41;
	list_char[6].Height = 167.3;
	list_char[6].Occupation = "Headmaster";
	
	list_char[7].Name = "Villie";
	list_char[7].Age = 20;
	list_char[7].Height = 164.3;
	list_char[7].Occupation = "Engineer Student";
	
	list_char[8].Name = "Eden";
	list_char[8].Age = 22;
	list_char[8].Height = 166.5;
	list_char[8].Occupation = "Opera Singer";
	
	list_char[9].Name = "Mei";
	list_char[9].Age = 18;
	list_char[9].Height = 167.4;
	list_char[9].Occupation = "Culinary Student";
	
	list_char[10].Name = "Kiana";
	list_char[10].Age = 17;
	list_char[10].Height = 164.7;
	list_char[10].Occupation = "Pianist";
	
	list_char[11].Name = "Bronya";
	list_char[11].Age = 16;
	list_char[11].Height = 152.7;
	list_char[11].Occupation = "Hacker";
	
	list_char[12].Name = "Joyce";
	list_char[12].Age = 31;
	list_char[12].Height = 172.3;
	list_char[12].Occupation = "Physics Teacher";
	
	list_char[13].Name = "Adam";
	list_char[13].Age = 21;
	list_char[13].Height = 172.1;
	list_char[13].Occupation = "Professional Footballer";
	
	list_char[14].Name = "Harry";
	list_char[14].Age = 26;
	list_char[14].Height = 174.2;
	list_char[14].Occupation = "Streamer";
	
	list_char[15].Name = "Aponia";
	list_char[15].Age = 29;
	list_char[15].Height = 177.2;
	list_char[15].Occupation = "Church Nun";
	
	list_char[16].Name = "Lyle";
	list_char[16].Age = 23;
	list_char[16].Height = 179.5;
	list_char[16].Occupation = "Army Lieutenant";
	
	list_char[17].Name = "Christian";
	list_char[17].Age = 33;
	list_char[17].Height = 175.7;
	list_char[17].Occupation = "Actor";
	
	list_char[18].Name = "Tobi";
	list_char[18].Age = 25;
	list_char[18].Height = 169.5;
	list_char[18].Occupation = "Rapper";
	
	list_char[19].Name = "Logan";
	list_char[19].Age = 28;
	list_char[19].Height = 179.4;
	list_char[19].Occupation = "Professional Boxer";
	
	for(int i=0; i<20; i++)
	{
		cout << "========Character "<< i+1 <<"========" << endl;
		cout << "Name : " << list_char[i].Name << endl;
		cout << "Age : " << list_char[i].Age << endl;
		cout << "Height : " << list_char[i].Height << endl;
		cout << "Occupation : "  << list_char[i].Occupation << endl << endl;
	}
	return 0;
}
