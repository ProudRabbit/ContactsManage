#include <iostream>
#include <string>

#define M 100
using namespace std;

struct Info
{
	string name;
	int age;
	int sex;
	string phone;
	string address;
};

struct InfoList
{
	struct Info sumInfo[M];
	int size;
};

int isExist(struct InfoList* p, string name);
void showmenu()
{
	cout << "*************************" << endl;
	cout << "**** 1�����������Ϣ ****" << endl;
	cout << "**** 2����ʾ������Ϣ ****" << endl;
	cout << "**** 3����ѯ������Ϣ ****" << endl;
	cout << "**** 4���޸�������Ϣ ****" << endl;
	cout << "**** 5��ɾ��������Ϣ ****" << endl;
	cout << "**** 6�����������Ϣ ****" << endl;
	cout << "**** 0���˳�ϵͳ ****" << endl;
	cout << "*************************" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}


void add(struct InfoList* p)
{
	cout << "����������" << endl;
	string name;
	cin >> name;
	p->sumInfo[p->size].name = name;
	cout << "����������" << endl;
	int age;
	cin >> age;
	p->sumInfo[p->size].age = age;
	cout << "�������Ա�1--�У�2--Ů" << endl;
	int sex;
	cin >> sex;
	p->sumInfo[p->size].sex = sex;
	string phone;
	cout << "������绰" << endl;
	cin >> phone;
	p->sumInfo[p->size].phone = phone;
	string address;
	cout << "�������ַ" << endl;
	cin >> address;
	p->sumInfo[p->size].address = address;

	(p->size)++;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}



void show(const struct InfoList* p)
{
	if (p->size == 0)
	{
		cout << "û��������Ϣ" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "������" << p->sumInfo[i].name << "\t";
			cout << "���䣺" << p->sumInfo[i].age << "\t";
			cout << "�Ա�" << ((p->sumInfo[i].sex == 1) ? "��" : "Ů") << "\t";
			cout << "���룺" << p->sumInfo[i].phone << "\t";
			cout << "��ַ��" << p->sumInfo[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

void research(struct InfoList* p)
{
	cout << "��������Ҫ����������������" << endl;
	string name;
	cin >> name;
	int x;
	x = isExist(p, name);
	if (x != -1)
	{
		cout << "������" << p->sumInfo[x].name << "\t";
		cout << "���䣺" << p->sumInfo[x].age << "\t";
		cout << "�Ա�" << ((p->sumInfo[x].sex == 1) ? "��" : "Ů") << "\t";
		cout << "���룺" << p->sumInfo[x].phone << "\t";
		cout << "��ַ��" << p->sumInfo[x].address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void alter(struct InfoList* p)
{
	cout << "������Ҫ�޸ĵ�����" << endl;
	string name;

	cin >> name;
	int x = isExist(p, name);
	if (x != -1)
	{
		cout << "����������" << endl;
		string name;
		cin >> name;
		p->sumInfo[x].name = name;
		cout << "����������" << endl;
		int age;
		cin >> age;
		p->sumInfo[x].age = age;
		cout << "�������Ա�1--�У�2--Ů" << endl;
		int sex;
		cin >> sex;
		p->sumInfo[x].sex = sex;
		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		p->sumInfo[x].phone = phone;
		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		p->sumInfo[x].address = address;

		cout << "�޸����" << endl;
	}
	else
	{
		cout << "���޴���,���������룺" << endl;
	}
	system("pause");
	system("cls");
}

void delet(struct InfoList* p)
{
	cout << "����������Ҫɾ�����˵�������" << endl;
	string name;
	cin >> name;
	int x = isExist(p, name);
	if (x != -1)
	{
		for (int i = x; i < p->size - 1; i++)
		{
			p->sumInfo[x] = p->sumInfo[x + 1];
		}
		(p->size)--;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

int isExist(struct InfoList* p, string name)
{
	for (int i = 0; i < p->size; i++)
	{
		if ((p->sumInfo[i].name) == name)
			return i;
	}
	return -1;
}

int main()
{
	struct InfoList presonal;
	presonal.size = 0;

	int select(0);

	while (true)
	{
		showmenu();

		cin >> select;

		switch (select)
		{
		case 1:add(&presonal);
			break;
		case 2:show(&presonal);
			break;
		case 3:research(&presonal);
			break;
		case 4:alter(&presonal);
			break;
		case 5:delet(&presonal);
			break;
		case 6:presonal.size = 0;
			cout << "��Ϣ�����" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "��л����ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
