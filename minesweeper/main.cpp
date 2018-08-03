#include<iostream>
#include<ctime>
#include <conio.h>
using namespace std;

class unit
{
public :
	unit()
	{
		key = 'x';
		close_key = 0;
	}
	void set_bomb()
	{
		close_key = 9;
	}
	void set_flag()
	{
		key = '^';
	}
	void set_close_key()
	{
		close_key ++;
	}
	void unset_close_key()
	{
		close_key--;
	}
	void close_key_null()
	{
		close_key = 0;
	}
	void step_key()
	{
		key = 'r';
	}
	void set_key()
	{
		key = 'x';
	}
	char get_key()
	{
		return key;
	}
	int get_close_key()
	{
		return close_key;
	}
	void open_close_key()
	{
		key = char(48 + close_key) ;
	}
	bool check()
	{
		if (key == char(48 + close_key))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
private:
	int close_key;
	char key;
};

struct open
{
	open* next;
	int num;
};

void main()
{
	int size,bombs;
	int steps;
	unit* cell;
	int step_player = 0;
	

	srand(time(0));

	cout << "Hello , player)" << endl;

	cout << "Enter size of cell :";
	cin >> size;
	cout << "Enter amount bombs :";
	cin >> bombs;
	cout << "Lets play !"<<endl;

	system("pause");

	steps = ((size*size) - bombs);

	cell = new unit[(size*size)];

	

	for (int i = 0; i < bombs; i++)
	{
		int x;

		do
		{
			x = (rand() % (size*size));
		}
		while(cell[x].get_close_key()==9);

		cell[x].set_bomb();
	}

	//cell[2].set_bomb();



	for (int i = 0; i < (size *size); i++)
	{

		if (cell[i].get_close_key() == 9)
		{

			if (((i + size) < (size*size)) && (cell[i+size].get_close_key()!=9))
			{
				cell[i + size].set_close_key();
			}
			if (((i - size) >= 0) && (cell[i - size].get_close_key() != 9))
			{
				cell[i - size].set_close_key();
			}

			for (int j = (i - (size + 1)); j <= (i + (size - 1)); j += size)
			{
				if (i%size == 0)
				{
					break;
				}
				else
				{
					if (((j >= 0) && (j < (size*size))) && (cell[j].get_close_key() != 9))
					{
						cell[j].set_close_key();
					}
				}
			}

			for (int j = (i - (size - 1)); j <= (i + (size + 1)); j += size)
			{
				if ((i+1)%size == 0)
				{
					break;
				}
				else
				{
					if ((j >= 0) && (j < (size*size)) && (cell[j].get_close_key() != 9))
					{
						cell[j].set_close_key();
					}
				}
			}

		}
	}


	

	while (1)
	{
		
		char ch;
		bool bo=0,flag=0;
		int fl = 0;
		int st = 0;
		//int code;
		
		system("cls");

		for (int i = 0; i < (size *size); i++)
		{
			if ((cell[i].get_close_key() == 9) && (cell[i].get_key() == '^'))
			{
				fl++;
			}
			if ((cell[i].get_key() != 'x') && (cell[i].get_key() != '^'))
			{
				st++;
			}
			if (i == step_player)
			{
				if (cell[i].get_key() == 'x')
				{
					bo = 1;

				}
				if (cell[i].get_key() == '^')
				{
					flag = 1;
					
				}
				else
				{
					cell[i].step_key();
				}

				

			}
			
			cout << cell[i].get_key();

			if (((i+1)%size == 0))
			{
				cout << endl;
			}
		}
		
		if (fl == bombs && st == ((size*size) - bombs))
		{
			system("cls");
			cout << "YOU WIIIIN!!!!" << endl;
			system("pause");
			char choys;
			cout << "Do you want replay ? \n   y/n  ";
			cin >> choys;
			
			delete[]cell;

			if (choys == 'y')
			{
				main();
			}
			else
			{
				return;
			}

		}

		ch = getch();
		//code = static_cast<int>(ch);
		switch(ch)
		{
		case ('w') :

			if (bo)
			{
				cell[step_player].set_key(); 
			}
			else
			{
				cell[step_player].open_close_key();
			}

			if (flag)
			{
				cell[step_player].set_flag();
			}

			if (step_player < (size))
			{
				step_player += size*(size - 1);
			}
			else
			{
				step_player -= size;

			}

			break; 

		case ('s') :

			if (bo)
			{
				cell[step_player].set_key();
			}
			else
			{
				cell[step_player].open_close_key();
			}

			if (flag)
			{
				cell[step_player].set_flag();
			}

			if (step_player > ((size*size - 1)-size))
			{
				step_player -= size*(size - 1);
			}
			else
			{
				step_player += size;

			}

			break;

		case ('a') :

			if (bo)
			{
				cell[step_player].set_key();
			}
			else
			{
				cell[step_player].open_close_key();
			}

			if (flag)
			{
				cell[step_player].set_flag();
			}


			if (step_player%size == 0)
			{
				step_player += (size - 1);
			}
			else
			{
				step_player--;
			}

			break;

		case ('d') :

			if (bo)
			{
				cell[step_player].set_key();
			}
			else
			{
				cell[step_player].open_close_key();
			}

			if (flag)
			{
				cell[step_player].set_flag();
			}

			if ((step_player + 1) % size == 0)
			{
				step_player -= (size - 1);
			}
			else
			{
				step_player++;
			}

			break;

		case (' ') :


			if (cell[step_player].get_close_key() == 9)
			{
				cout << endl << "You Looooooooose" << endl;
				system("pause");
				system("cls");
				char choys;
				cout << "Do you want replay ? \n   y/n  ";
				cin >> choys;

				delete[]cell;

				if (choys == 'y')
				{
					main();
				}
				else
				{
					return;
				}
			}

			if (bo)
			{
				cell[step_player].open_close_key();
			}

			if (cell[step_player].get_close_key() == 0)
			{
				int point = step_player;
				open* op=new open;
				open* head = op;
				open* buf = NULL;
				op->num = point;
				op->next = NULL;
				while (op)
				{

					if (((point - size) >= 0)  )
					{
						if (cell[point - size].get_close_key() == 0 && !cell[point - size].check() )
						{
							buf = op;
							op = new open;
							op->num = (point - size);
							buf->next = op;
							op->next = NULL;
						}

						cell[point - size].open_close_key();
					}

					if ((point + size) < (size*size) )
					{
						if (cell[point + size].get_close_key() == 0 && !cell[point + size].check())
						{
							buf = op;
							op = new open;
							op->num = (point + size);
							buf->next = op;
							op->next = NULL;
						}

						cell[point + size].open_close_key();
					}


					if ((point + 1) < (size*size) && (((point+1)%size) != 0) )
					{

						if (cell[point + 1].get_close_key() == 0 && !cell[point + 1].check())
						{
							buf = op;
							op = new open;
							op->num = (point + 1);
							buf->next = op;
							op->next = NULL;
						}

						cell[point + 1].open_close_key();

					}

					if (((point - 1) >= 0) && ((point%size) != 0) )
					{

						if (cell[point - 1].get_close_key() == 0 && !cell[point - 1].check())
						{
							buf = op;
							op = new open;
							op->num = (point - 1);
							buf->next = op;
							op->next = NULL;
						}

						cell[point - 1].open_close_key();

					}

					if (op->num == point)
					{
						op = head;

						while (op)
						{
							buf = op->next;
							delete op;
							op = buf;
						}
						goto stop;

					}
					else
					{
						buf = head->next;
						delete head;
						head = buf;
						point = head->num;
					}





				}
			}
				//steps--;
		stop:;
			break;

		case('f'):

			if (bo)
			{
				cell[step_player].set_flag();
			}
			else
			{
				if (cell[step_player].get_key() == '^')
				{
					cell[step_player].set_key();
				}
			}

			break;

		default:
			cout << "it's wrong key"<<endl;
			system("pause");
			break;

		}

	}
}