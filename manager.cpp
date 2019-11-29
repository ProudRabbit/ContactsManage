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
	cout << "**** 1、添加人物信息 ****" << endl;
	cout << "**** 2、显示人物信息 ****" << endl;
	cout << "**** 3、查询人物信息 ****" << endl;
	cout << "**** 4、修改人物信息 ****" << endl;
	cout << "**** 5、删除人物信息 ****" << endl;
	cout << "**** 6、清空人物信息 ****" << endl;
	cout << "**** 0、退出系统 ****" << endl;
	cout << "*************************" << endl;
	cout << "请选择您的操作" << endl;
}


void add(struct InfoList* p)
{
	cout << "请输入姓名" << endl;
	string name;
	cin >> name;
	p->sumInfo[p->size].name = name;
	cout << "请输入年龄" << endl;
	int age;
	cin >> age;
	p->sumInfo[p->size].age = age;
	cout << "请输入性别：1--男，2--女" << endl;
	int sex;
	cin >> sex;
	p->sumInfo[p->size].sex = sex;
	string phone;
	cout << "请输入电话" << endl;
	cin >> phone;
	p->sumInfo[p->size].phone = phone;
	string address;
	cout << "请输入地址" << endl;
	cin >> address;
	p->sumInfo[p->size].address = address;

	(p->size)++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}



void show(const struct InfoList* p)
{
	if (p->size == 0)
	{
		cout << "没有人物信息" << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "姓名：" << p->sumInfo[i].name << "\t";
			cout << "年龄：" << p->sumInfo[i].age << "\t";
			cout << "性别：" << ((p->sumInfo[i].sex == 1) ? "男" : "女") << "\t";
			cout << "号码：" << p->sumInfo[i].phone << "\t";
			cout << "地址：" << p->sumInfo[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

void research(struct InfoList* p)
{
	cout << "请输入您要搜索的人物姓名：" << endl;
	string name;
	cin >> name;
	int x;
	x = isExist(p, name);
	if (x != -1)
	{
		cout << "姓名：" << p->sumInfo[x].name << "\t";
		cout << "年龄：" << p->sumInfo[x].age << "\t";
		cout << "性别：" << ((p->sumInfo[x].sex == 1) ? "男" : "女") << "\t";
		cout << "号码：" << p->sumInfo[x].phone << "\t";
		cout << "地址：" << p->sumInfo[x].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void alter(struct InfoList* p)
{
	cout << "请输入要修改的人名" << endl;
	string name;

	cin >> name;
	int x = isExist(p, name);
	if (x != -1)
	{
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		p->sumInfo[x].name = name;
		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		p->sumInfo[x].age = age;
		cout << "请输入性别：1--男，2--女" << endl;
		int sex;
		cin >> sex;
		p->sumInfo[x].sex = sex;
		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		p->sumInfo[x].phone = phone;
		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		p->sumInfo[x].address = address;

		cout << "修改完成" << endl;
	}
	else
	{
		cout << "查无此人,请重新输入：" << endl;
	}
	system("pause");
	system("cls");
}

void delet(struct InfoList* p)
{
	cout << "请输入你需要删除的人的姓名：" << endl;
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
		cout << "查无此人" << endl;
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
			cout << "信息已清空" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "感谢您的使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
