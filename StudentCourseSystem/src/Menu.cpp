#include <iostream>
#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"
#define MAX_ITEM 5

using namespace std;

void Menu::systemMenu()
{
}

void Menu::chooseRole()
{
	cout << "\n\t\t\t       ��ӭʹ��ѧ��ѡ��ϵͳ" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "��ѡ�������ݣ�" << endl;
	cout << "\t1.ѧ��" << endl;
	cout << "\t2.����Ա" << endl;
	cout << "\t3.�˳�ϵͳ" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "��ѡ��1-3�����в���" << endl;
	switch (choose('3'))
	{
		case '1':
		{
			Student student;
			student.login();
			break;
		}
		case '2':
		{
			cout << "===";
			break;
		}
		default:
			break;
	}
}

Menu::Menu()
{}

Menu::~Menu()
{}