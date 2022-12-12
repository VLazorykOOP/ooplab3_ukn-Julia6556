#include<iostream>
using namespace std;
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>
#include"cube_class.hpp"

void PutCubes(int count);//˜˜˜˜˜˜
void PutCubes();//˜˜ ˜˜˜˜˜
void PutCubes(int count, int code);//˜ ˜˜˜˜˜

int main(){
	srand(time(NULL));
	
	int choose = 0;//˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜˜
	int count = 0;//˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜
	cout<<"Cube program\n\nWhat you will do? (1 - Enter cubes from keyboard, 2 - Put cubes randomly, 3 - Read cubes from file cubes.txt)\n>> ";
	cin>>choose;//˜˜˜˜˜ ˜˜˜˜˜
	if(choose==1 || choose==2){//˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜
		do{//˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ - ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜
			cout<<"\nHow many cubes you need?\n>>"; cin>>count;
			if(count<=0) cout<<"\nCount must be >0!\n";
		}while(count<=0);
	}
	
	switch(choose){
		case 1://˜˜˜˜˜
			PutCubes(count, 1);
			break;
		case 2://˜˜˜˜˜˜
			PutCubes(count);
			break;
		case 3://˜˜˜˜
			PutCubes();
			break;
		default:
			cout<<"\nOops! Wrong choose!\n";
			break;
	}
	
	cin.get(); cin.get();
	return 0;
}

void PutCubes(int count){
	//˜˜˜˜˜˜
	Cube A;
	for(int i = 0; i < count; i++){
		A.RandomCube();//˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜
		cout<<"\nCube #"<<i+1<<"\n";
		A.PrintCube();//˜˜˜˜˜˜˜
		cout<<"\n----------------------------------\n";
	}
}

void PutCubes(int count, int code){
	//˜˜˜˜˜
	Cube A;
	float side; string str;//˜˜˜˜˜˜˜ ˜ ˜˜˜˜
	for(int i = 0; i < count; i++){
		cout<<"\nCube #"<<i+1<<"\n";
		cout<<"Side: "; cin>>side;//˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜ ˜˜˜˜
		cout<<"Color: "; cin>>str;
		A.SetColor(str);//˜˜˜˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜
		A.SetSide(side);
		cout<<"\n----------------------------------\n";
		A.PrintCube();//˜˜˜˜˜˜˜ ˜˜˜˜˜˜
		cout<<"\n----------------------------------\n";
	}
}

void PutCubes(){
	//˜˜˜˜
	Cube A;
	ifstream file;//˜˜˜˜
	file.open("cubes.txt");
	int i = 0;//˜˜˜˜˜ ˜˜˜˜
	string str;//˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜
	
	while(file>>str){//˜˜˜˜ ˜˜ ˜˜˜˜˜ ˜˜˜˜ - ˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜
		A.SetSide(stof(str));//˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜ ˜ ˜˜˜˜˜
		file>>str;//˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ - ˜˜˜˜
		A.SetColor(str);//˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜
		cout<<"\nCube #"<<i+1<<"\n";
		A.PrintCube();//˜˜˜˜˜˜˜ ˜˜˜
		cout<<"\n----------------------------------\n";
		i++;
	}
	
	file.close();
}