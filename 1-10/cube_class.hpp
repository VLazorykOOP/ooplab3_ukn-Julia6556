class Cube{
	private:
		float side_len;//�������
		string color;//����
	public:
		//setters
		void SetSide(float a){
			if(a>0)//�������� ������� �� ������ 0
				side_len = a;
			else
				cout<<"\nWrong side! Must be >0!\n";
		}
		void SetColor(string c){
			//��������� ���������� ���������� �����, ������ ������ ����������, ���� ��� - �������� ������
			if(c=="White" || c=="Black" || c=="Red" || c=="Blue" || c=="Green" || c=="Yellow" || c=="Orange" || c=="Purpure" || c=="Gold" || c=="Silver" || c=="Scarlet" || c=="Violet")
				color = c;
			else
				cout<<"\nWrong color! Enter White / Black / Red / Blue / Green / Yellow / Orange / Purpure / Gold / Silver / Scarlet / Violet!\n";
		}
		
		//getters
		float GetSide(){return side_len;}
		string GetColor(){return color;}
		
		//constructors
		Cube(){
			//default
			side_len = 0;
			color = "White";
		}
		Cube(float side, string clr){
			//parametral
			if(side>0)	side_len = side;
			else		side = 0;
			//���� ������� ���������� - ������ � ��� 0
			if(clr=="White" || clr=="Black" || clr=="Red" || clr=="Blue" || clr=="Green" || clr=="Yellow" || clr=="Orange" || clr=="Purpure" || clr=="Gold" || clr=="Silver" || clr=="Scarlet" || clr=="Violet")
						color = clr;
			else		color = "White";
			//���� ���� ������������ - ������ �����
		}
		
		//functions
		float func_S(){//������� ����������� ����
			return (side_len*side_len)*6;
		}
		float func_V(){//����� ����
			return side_len*side_len*side_len;
		}
		float func_Diag(){//���������� ��������� ����
			return sqrt( pow(sqrt((pow(side_len,2)) + pow(side_len,2)), 2) + pow(side_len,2) );
		}
		float func_V_sphere(){//����� �������� �����
			return (4 * pow(side_len/2, 3) * 3.14159)/3;
		}
		void PrintCube(){//������� �� ����� ��� ��������� ����
			cout<<"\n    \tSide: "<<side_len<<";\tColor: "<<color<<";\n";
			cout<<"    \tS = "<<func_S()<<";\tV(cube) = "<<func_V()<<";\n    \tDiag = "<<func_Diag()<<";\t V(sphere inside) = "<<func_V_sphere()<<";\n";
		}
		void RandomCube(){//������ ��� ��������
			side_len = (float)(rand()%9000+1000)/100;//����� �� 10.00 �� 99.99
			int col = rand()%12;//������ ����� �� 12 ������
			switch(col){
				case 0:
					color = "White"; break;
				case 1:
					color = "Black"; break;
				case 2:
					color = "Red"; break;
				case 3:
					color = "Blue"; break;
				case 4:
					color = "Green"; break;
				case 5:
					color = "Yellow"; break;
				case 6:
					color = "Orange"; break;
				case 7:
					color = "Purpure"; break;
				case 8:
					color = "Gold"; break;
				case 9:
					color = "Silver"; break;
				case 10:
					color = "Scarlet"; break;
				case 11:
					color = "Violet"; break;
			}
		}
};