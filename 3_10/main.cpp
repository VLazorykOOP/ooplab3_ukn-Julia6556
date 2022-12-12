#include<iostream>
using namespace std;

#include"Vector.hpp"
#include"Matrix.hpp"

int main(){
	cout<<"Matrix and Vector program test\n-------------------------------\n\n";
	
	MVector V1;
	MVector V2(10);
	MVector V3(10,5,'=');
	MVector V4(V3);
	
	//=============================CONSTRUCTORS TEST
	cout<<"Default Vector V1:\n";
	V1.Show(); cout<<"|<- its for understand the number of spaces\n------------------------------\n";
	
	cout<<"\nVector V2(10):\n";
	V2.Show(); cout<<"|<- its for understand the number of spaces\n------------------------------\n";
	
	cout<<"\nVector V3(10,5,=):\n";
	V3.Show(); cout<<"\n------------------------------\n";
	
	cout<<"\nVector V4(V3):\n";
	V4.Show(); cout<<"\n------------------------------\n";
	//=================================END CONSTR TEST
	
	//=================================OPERATORS TEST
	cout<<"\nOperator == test:\n"; //task with size n (for memory)
	if(V3==V4) cout<<"V3 = V4 true";
	else cout<<"V3 = V4 false!!!";
	if(V3==V1) cout<<"\nV3 = V1 true";
	else cout<<"\nV3 = V1 false!!!";
	cout<<"\n------------------------------\n";
	
	cout<<"\nOperator != test:\n";
	if(V3!=V4) cout<<"V3 != V4 true";
	else cout<<"V3 != V4 false!!!";
	if(V3!=V1) cout<<"\nV3 != V1 true";
	else cout<<"\nV3 != V1 false!!!";
	cout<<"\n------------------------------\n";
	
	cout<<"\nOperator > test:\n";
	if(V3>V4) cout<<"V3 > V4 true";
	else cout<<"V3 > V4 false!!!";
	if(V3>V1) cout<<"\nV3 > V1 true";
	else cout<<"\nV3 > V1 false!!!";
	cout<<"\n------------------------------\n";
	
	cout<<"\nOperator < test:\n";
	if(V3<V4) cout<<"V3 < V4 true";
	else cout<<"V3 < V4 false!!!";
	if(V3<V1) cout<<"\nV3 < V1 true";
	else cout<<"\nV3 < V1 false!!!";
	cout<<"\n------------------------------\n";
	//=======================================END OPERATORS TEST
	
	//============================================GET/SET TEST
	cout<<"\nSet element '#' in V3 ind 3:\n";
	V3.SetByInd(3,'#');
	V3.Show();
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind 2 V3:\n"<<V3.GetFromInd(2);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind 3 V3:\n"<<V3.GetFromInd(3);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind -4 V3:\n"<<V3.GetFromInd(-4);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind 22 V3:\n"<<V3.GetFromInd(22);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet size V1:\n"<<V1.GetSize();
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet size V3:\n"<<V3.GetSize();
	cout<<"\n------------------------------\n";
	//===========================================END GET/SET TEST
	
	//=================================================BIT MASK TEST
	cout<<"\nBit mask for V3 using '*' us argument:\n";
	cout<<"Before: "; V3.Show();
	cout<<"\nAfter encoding: "; V3.BitMask('*'); V3.Show();
	cout<<"\nDencoding: "; V3.BitMask('*'); V3.Show();
	cout<<"\n------------------------------\n";
	//=====================================================
	
	
	cout<<"\n\n===============================MATRIX TESTS===========================\n\n";
	
	MMatrix M1;
	MMatrix M2(10);
	MMatrix M3(10,5,'%'); //here is char 
	MMatrix M4(M3);
	
	//=============================CONSTRUCTORS TEST
	cout<<"Default Matrix M1:\n"; //default parametr
	M1.Show(); cout<<"\n------------------------------\n";
	
	cout<<"\nM2(10):\n";
	M2.Show(); cout<<"\n------------------------------\n";
	
	cout<<"\nM3(10,5,=):\n";
	M3.Show(); cout<<"\n------------------------------\n";
	
	cout<<"\nM4(M3):\n";
	M4.Show(); cout<<"\n------------------------------\n";
	//=================================END CONSTR TEST
	
	
	//=================================OPERATORS TEST
	cout<<"\nOperator == test:\n";
	if(M3==M4) cout<<"M3 = M4 true";
	else cout<<"M3 = M4 false!!!";
	if(M3==M1) cout<<"\nM3 = M1 true";
	else cout<<"\nM3 = M1 false!!!";
	cout<<"\n------------------------------\n";
	
	cout<<"\nOperator != test:\n";
	if(M3!=M4) cout<<"M3 != M4 true";
	else cout<<"M3 != M4 false!!!";
	if(M3!=M1) cout<<"\nM3 != M1 true";
	else cout<<"\nM3 != M1 false!!!"; //!= not equally
	cout<<"\n------------------------------\n";
	
	cout<<"\nOperator > test:\n";
	if(M3>M4) cout<<"M3 > M4 true";
	else cout<<"M3 > M4 false!!!";
	if(M3>M1) cout<<"\nM3 > M1 true";
	else cout<<"\nM3 > M1 false!!!";
	cout<<"\n------------------------------\n";
	
	cout<<"\nOperator < test:\n";
	if(M3<M4) cout<<"M3 < M4 true";
	else cout<<"M3 < M4 false!!!";
	if(M3<M1) cout<<"\nM3 < M1 true";
	else cout<<"\nM3 < M1 false!!!";
	cout<<"\n------------------------------\n";
	//=======================================END OPERATORS TEST
	
	//============================================GET/SET TEST
	cout<<"\nSet element '#' in M3 ind 3,3:\n";
	M3.SetByInd(3,3,'#');
	M3.Show();
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind 2,3 M3:\n"<<M3.GetFromInd(2,3);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind 3,3 M3:\n"<<M3.GetFromInd(3,3);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind -4,2 V3:\n"<<M3.GetFromInd(-4,2);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet element with ind 2,22 V3:\n"<<M3.GetFromInd(2,22);
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet size M1:\n"<<M1.GetSize();
	cout<<"\n------------------------------\n";
	
	cout<<"\nGet size M3:\n"<<M3.GetSize();
	cout<<"\n------------------------------\n";
	//===========================================END GET/SET TEST
	
	//=================================================BIT MASK TEST
	cout<<"\nBit mask for M3 using '*' us argument:\n";
	cout<<"Before: \n"; M3.Show();
	cout<<"\nAfter encoding: \n"; M3.BitMask('*'); M3.Show(); //where bitmask is bit position
	cout<<"\nDencoding: \n"; M3.BitMask('*'); M3.Show();
	cout<<"\n------------------------------\n";
	//=====================================================
	
	cin.get(); cin.get();
	return 0;
}