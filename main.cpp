#include <iostream>
#include <cstdio>
#include <cstring> 
#include "Date.h"
#include "Employee.h"
#include <math.h>

using namespace std;
struct Node_E
{
	Employee Em;
	Node_E* next = NULL;
	Node_E* prev = NULL;
};

Node_E* n;
Node_E* head;
int length = 0;
Node_E* tail;
int r = 0;

void readE();
void print(Node_E* y);
void addE(const char f[20], const char l[20], int s, Date B, Date H);
Node_E *Filters(Node_E* h = head);
bool check_name(string n);
void del(string f,string l);

void readE()
{	
	
	head=tail=n= NULL;
	
	FILE* out;
	if ((out = fopen("Employee.txt", "r")) == NULL) { cout << "\nCont open or find file of Employee ?!!! \n"; exit(1); }

	fscanf(out, "%d\n", &r);
	char F[20];
	char L[20];

	strcpy(F,"F");
	strcpy(L, "L");
	int S=0, D1=0, M1=0, Y1=0, D2=0, M2=0, Y2=0;
	char ch='/';
	
	for(int j=0;j<r;j++)
	{
		fscanf(out, "%s %s %d %d%c%d%c%d %d%c%d%c%d\n", F, L, &S, &D1,&ch, &M1,&ch, &Y1, &D2,&ch, &M2,&ch, &Y2);

		n = new Node_E;
		n->Em.setEmployee(F, L, S, { D1,M1,Y1 }, { D2,M2,Y2 });
		if (j == 0) 
		{
			head=tail = n;
			n->next = NULL;
			n->prev = NULL;
		}
		else
		{
			n->prev = tail;
			tail->next = n;
			n->next = NULL;
			tail = n;
		}
		length++;		
	}
	fclose(out);
}

void print(Node_E *y)
{
	y = head;
	readE();
	
	while(y!=NULL)
	{
		cout << endl << y->Em;
		y = y->next;
	}
	cout << endl;

	if (length == 0) { cout << "There are no Employee\n"; }
}

void print_inf()
{
	FILE* in;
	if ((in = fopen("Employee.txt", "w")) == NULL) { cout << "Cont open or find the path of file of Employee !!"; exit(1); }

	fprintf(in, "%d\n", r);

	char F[20];
	char L[20];
	strcpy(F, "F");
	strcpy(L, "L");
	int S = 0, D1 = 0, M1 = 0, Y1 = 0, D2 = 0, M2 = 0, Y2 = 0;
	char ch = '/';

	Node_E* P_E = head;
	while (P_E != NULL)
	{
		for (int v = 0; v < P_E->Em.get_First_name().size(); v++)
		{
			F[v] = P_E->Em.get_First_name()[v];
		}
		F[P_E->Em.get_First_name().size()] = '\0';

		for (int n = 0; n < P_E->Em.get_Last_name().size(); n++)
		{
			L[n] = P_E->Em.get_Last_name()[n];
		}
		L[P_E->Em.get_Last_name().size()] = '\0';

		fprintf(in, "%s %s %d %d%c%d%c%d %d%c%d%c%d\n", F, L, P_E->Em.get_s(), P_E->Em.get_B_d(), '/', P_E->Em.get_B_m(), '/', P_E->Em.get_B_y(), P_E->Em.get_H_d(), '/', P_E->Em.get_H_m(), '/', P_E->Em.get_H_y());
		P_E = P_E->next;
	}

	fclose(in);
}

void addE(const char f[20],const char l[20], int s,Date B,Date H)
{

	readE();
	r++;
	n = new Node_E;

	n->Em.setEmployee(f, l, s, { H.getday(),H.getmonth(),H.getyear() }, { B.getday(),B.getmonth(),B.getyear() });
	
	tail->next = n;
	n->next = NULL;
	tail = n;

	print_inf();
	
}

Node_E *Filters(Node_E *h)
{
	h = head;
	int filter = 0;
	cout << "\n-------------------------------------------------< Filters >----------------------------------------------------\n";
	cout << "<> To know how birthday is today Enter 1";
	cout << "\n<> To sort Employee by salary equal or bigar Enter 2";
	cout << "\n<> To sort Employee by Hire date <newest or equal> Enter 3";
	cout << "\n------------------------------------------------------";
	cout << "\n\n<> Enter your option: ";
	cin >> filter;
	
	Node_E* fl=NULL;
	Node_E* h_f=NULL;
	Node_E* t_f=NULL;
	if (filter == 1 || filter == 2 || filter == 3)
	{
		int k = 0;
		if (filter == 1) //to know how birthday is today
		{
			k = 0;
			int to=0;
			int mo=0;
			cout << "Enter the day: ";
			cin >> to;
			cout << "\nEnter the month: ";
			cin >> mo;
			cout << endl;

			while(h!=NULL)
			{ 

				if ((h->Em.get_B_d()) == to&& h->Em.get_B_m()==mo)
				{
					fl = new Node_E;
					fl->Em = h->Em;
					if (k == 0)
					{
						h_f = t_f = n;
						n->next = NULL;
					}
					else
					{
						t_f->next = n;
						t_f = n;
						n->next = NULL;
					}
				}
				h = h->next;
				k++;
			}
			if (k == 0) { cout << "\nthier are no Employee is birthday acording to this Date $ \n"; }
		}
		if (filter == 2)//To sort Employee by salary equal or bigar
		{
			k = 0;
			int s=0;
			cout << "\nEnter salary: ";
			cin >> s;
			if (s >= 1)
			{
				while (h != NULL)
				{
					if (h->Em.get_s() >= s)
					{
						fl = new Node_E;
						fl->Em = h->Em;
						if (k == 0)
						{
							t_f = h_f = fl;
							fl->next = NULL;
						}
						else
						{
							tail->next = fl;
							tail = fl;
							fl->next = NULL;
						}
						h = h->next;
						k++;
					}
				}
				cout << "\nThere are no Employee have <" << s << "> or more of salary !\n";
			}
			else
			{
				cout<< "\nwrong salary\n";
			}
		}
		if (filter == 3)//To sort Employee by Hire date
		{
			k = 0;
			Date z;
			cout << "\nEnter Hire date day/month/year like ~7/10/2001~ 7 10 2001------:";
			cin >> z;
			while (h!=NULL)
			{
				if (z.check_big(h->Em.get_H_d(), h->Em.get_H_m(), h->Em.get_H_y()))
				{
					fl = new Node_E;
					if (k==0)
					{
						t_f = h_f = fl;
						fl->next = NULL;
					}
					else
					{
						t_f->next = n;
						t_f = n;
						fl->next = NULL;
					}
					k++;
				}
				h=h->next;
			}
			k++;
			Employee* we = new Employee[k];
			Node_E* arr =h_f;
			for (int i = 0; i < k; i++)
			{
				we[i]=arr->Em;
				arr = arr->next;
			}
		}
		if (k != 0)
		{
			Node_E* y = h_f;
			while (y != NULL)
			{
				cout << endl << y->Em;
				y = y->next;
			}
			cout << endl;
		}
	}
	else// if(filter != 1 || filter != 2 || filter != 3)
	{
		cout << "\nworng input !! \n";
	}
	return h_f;
}

bool check_name(string n)
{
	for (int i = 0; i < n.size(); i++)
	{
		if ((n[i]>='a' && n[i]<='z' ) || (n[i] >= 'A' && n[i] <= 'Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return NULL;
}
/*
void add(int id, string name)
{
	Node* n = new Node;
	n->id = id;
	n->name = name;
	if (length == 0)
	{
		head = last = n;
		n->next = NULL;
	}
	else
	{
		last->next = n;
		n->next = NULL;
		last = n;
	}
	length++;
}
void add_pos(int pos,int id,string name)
{
	if (pos<0 || pos>length)
	{
		cout << "\nwhat the heail u doing !!\n";
	}
	else
	{
		Node* n = new Node;
		Node* p=head;
		n->id = id;
		n->name = name;
		if (pos == 0)
		{
			Node *x=head;
			head = n;
			n->next = x;
			//return;
		}
		else if (pos == length)
		{
			last->next = n;
			last = n;
			n->next = NULL;
		}
		else
		{
			for (int i = 1; i < pos; i++)
			{
				p = p->next;
			}
			n->next = p->next;
			p->next = n;
		}
	}
	length++;
}

*/

void del(string f,string l)
{
	int s = 0;
	
	Node_E* t=tail;
	
	Node_E* hl = NULL;
	

	Node_E* d=NULL;
	Node_E* p1 = NULL;
	Node_E* d2=NULL;

	if ((head->Em.get_First_name() == f && head->Em.get_Last_name() == l))
	{
		
		s++;
		p1 = head;
		head = head->next;
		delete p1;
	}
	else if ((tail->Em.get_First_name() == f && tail->Em.get_Last_name() == l))
	{
		
		s++;

		d = tail;
		tail = tail->prev;;
		delete d;
		tail->next = NULL;
	}
	else
	{
		Node_E* sr = head;
		while (head != NULL)
		{
			if (head->Em.get_First_name() == f && head->Em.get_Last_name() == l)
			{
				s++;
				Node_E* d3 = head;
				head->prev->next = head->next;
				delete d3;
				break;
			}
			head = head->next;
		}
		head = sr;
	}
	
	if (s==1)
	{
		r--;
		print_inf();
		cout << "\nDelete sucsesfuly\n";
	}
	else
	{
		cout << "\nther is no employee of this name !\n";
	}
	
}


int add(int num)
{

	int  count = 0;
	for (int i = 0; i <= num; i++)
	{
		count =count+ i;
	}
	return count;

}

void rec(int n)
{
	if (n == 0)
	{
		return;
	}
	rec(n = n / 10);
	cout <<n%10<<endl;
	
}
int main()
{
	rec(12345678);


	
	readE();
	char f[20];
	char l[20];
	int s;
	Date b;
	Date h;
	char  menu = 0;
	while (menu != '5')
	{
		cout << "\n------------------------------------------------< welcome >-------------------------------------------------------------\n";
		cout << "\n<> To print all Employee Enter 1 \n";
		cout << "<> To see the option of filter on Emplloyees enter 2\n";
		cout << "<> To add an Employee Enter 3 \n";
		cout << "<> To delet an  Employee Enter 4 \n";
		cout << "<> Enter 5 to exit \n";
		cout << "-----------------------------------------------------------------------------------------------------------------------";
		cout << "\nEnter your choise: ";
		cin >> menu;
		if (menu == '1'   || menu == '2' || menu == '3' || menu == '4' || menu == '5')
		{
			if (menu == '1') 
			{ print(NULL); }
			if (menu == '2')
			{
				//Filtre(the array you want to make a flter on it,size of array)
				Filters(head);
			}
			if (menu == '3')
			{
				cout << "\n-----------------------------------------< Add Employee >-------------------------------------------------------\n";
				cout << "\nEnter the first name: ";
				cin >> f;
				if (!check_name(f))
				{
					cout << "wrong name !";
					cout << "\nRenter the first name: ";
					cin >> f;
				}
				cout << "\nEnter the last name: ";
				cin >> l;
				if (!check_name(l))
				{
					cout << "wrong name !";
					cout << "\nEnter the last name: ";
					cin >> l;
				}
				cout << "\nEnter Salare: ";
				cin >> s;
				if (!(s >= 1))
				{
					cout << "\nwrong salary !\n";
					cout << "\nEnter Salare: ";
					cin >> s;
				}
				cout << "\nEnter Birth date day/month/year like ~7/10/2001~ 7 10 2001 : ";
				cin >> b;
				if (!(b.check_D(b)))
				{
					cout << "\nwrong Date !\n";
					cout << "\nRenter Birth date day/month/year like ~7/10/2001~ 7 10 2001 : ";
					cin >> b;
				}
				cout << "\nEnter Enter Hire date date day/month/year like ~7/10/2001~ 7 10 2001 : ";
				cin >> h;
				if (!(h.check_D(h)))
				{
					cout << "\nwrong Date !\n";
					cout << "\nRenter Birth Hire day/month/year like ~7/10/2001~ 7 10 2001 : ";
					cin >> b;
				}
				if ((check_name(l)) && (check_name(f)) && (s >= 1) && (b.check_D(b)) && (h.check_D(h)))
				{
					addE(f, l, s, h, b);
				}
				else
				{
					cout << "\nWrong input ! tray agian ! \n";
				}
			}
			if (menu == '4') //Delete Employee
			{
				string f,l;
				cout << "\nEnter first name of Employee: ";
				cin >> f;
				cout << "\nEnter last name of Employee: ";
				cin>> l;

				if(check_name(f) && check_name(l)){ del(f,l); }
				else
				{
					cout << "\nwromg name !\n";
				}
			}
		}
		else
		{
			cout << "\nValid Enput !!\n";
		}
		
	}
	
}