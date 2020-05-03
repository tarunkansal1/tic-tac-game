#include <iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

/*void print_matrix_i()
{
	cout << "    " << "|" << "    " << "|" << "    " << std::endl;
	cout << "    " << "|" << "    " << "|" << "    " << std::endl;
	cout << "____|___" ;
	cout << "_|______" << std::endl;
	cout << "    " << "|" << "    " << "|" << "    " << std::endl;
	cout << "    " << "|" << "    " << "|" << "    " << std::endl;
	cout << "____|___";
	cout << "_|______" << std::endl;
	cout << "    " << "|" << "    " << "|" << "    " << std::endl;
	cout << "    " << "|" << "    " << "|" << "    " << std::endl;
	cout << "Enter box number. (1-9)";
}*/
void print_v(char v[3][3])
{
		cout << "     " << "|" << "     " << "|" << "     " << std::endl;
		cout << "  " << v[0][0] << "  " << "|" << "  " << v[0][1] << "  " << "|" << "  " << v[0][2] << "  "<< std::endl;
		cout << "     " << "|" << "     " << "|" << "     " << std::endl;
		cout << "_____|___";
		cout << "__|______" << std::endl;
		cout << "     " << "|" << "     " << "|" << "     " << std::endl;
		cout << "  " << v[1][0] << "  " << "|" << "  " << v[1][1] << "  " << "|" << "  " << v[1][2] << "  " << std::endl;
		cout << "     " << "|" << "     " << "|" << "     " << std::endl;
		cout << "_____|___";
		cout << "__|______" << std::endl;
		cout << "     " << "|" << "     " << "|" << "     " << std::endl;
		cout << "  " << v[2][0] << "  " << "|" << "  " << v[2][1] << "  " << "|" << "  " << v[2][2] << "  " << std::endl;
		cout << "     " << "|" << "     " << "|" << "     " << std::endl;
	
	cout << "Enter box number .";
}
/*
void print_v(char *v)
{
	for (int i=0;i<3;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << *((v+i*3)+j) << " ";
		}
		cout << std::endl;
	}
	cout << "Enter the value of box." << std::endl;
}*/
int geti(int box)
{
	if (box % 3 == 0)
		return ((box / 3) - 1);
	else
		return (box / 3);
}
int getj(int box)
{
	if (box == 1 || box == 4 || box == 7)
		return 0;
	else if (box == 2 || box == 5 || box == 8)
		return 1;
	else
		return 2;
}
int check(int box, char* v,int i,int j)
{
	if (*((v + i * 3) + j) == 'X' || *((v + i * 3) + j) == 'O')
	{
		return 0;
	}
	else
		return 1;
}
char check_res(char v[3][3])
{
	if (v[0][0] == v[0][1]&&v[0][0] == v[0][2])
		return v[0][0];
	else if (v[1][0] == v[1][1]&&v[1][0] == v[1][2])
		return v[1][0];
	else if (v[2][0] == v[2][1]&&v[2][0] == v[2][2])
		return v[2][0];
	else if (v[0][0] == v[1][0]&&v[0][0] == v[2][0])
		return v[0][0];
	else if (v[0][1] == v[1][1]&&v[0][1] == v[2][1])
		return v[0][1];
	else if (v[0][2] == v[1][2]&&v[0][2] == v[2][2])
		return v[0][2];
	else if (v[0][0] == v[1][1]&&v[0][0] == v[2][2])
		return v[0][0];
	else if (v[0][2] == v[1][1]&&v[0][2] == v[2][0])
		return v[0][2];
	else
		return 'z';
}
int main()
{
	int i=0,turn=0,box,check1,t=0;
	char check_r;
	char v[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	while (i<9)
	{
		//check_r = check_res(v);
		print_v(v);
		cin >> box;
		int x = geti(box);
		int y = getj(box);
		check1 = check(box, (char*)v,x,y);
		if (check1 == 0)
		{
			system("cls");
			cout << "Enter another number." << std::endl;
			check1 = 1;
			continue;
		}

		system("cls");
		if (turn == 0)
			v[x][y] = 'X';
		else
			v[x][y] = 'O';
		turn = !turn;
		i++;
		check_r = check_res(v);

		if (check_r == 'z')
			continue;
		else if (check_r == 'X')
		{
			cout << "Winner is X.!!!!" << std::endl;
			break;
			//return 0;
		}
		else if (check_r == 'O')
		{
			cout << "Winner is O.!!!!!" << std::endl;
			//return 0;
			break;
		}
	
	}
	print_v(v);
	cout << "DRAW" << std::endl;
	system("pause");
	//return 0;
	std::cin.get();

}