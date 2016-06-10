#include <iostream>
#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"

using namespace std;

string Menu::identity = "";

void Menu::systemMenu()
{

}

void Menu::isBack()
{
	cout << "\n\n\t�Ƿ񷵻����˵���\n\n\t 1.��\n\n\t 2.�˳�ϵͳ\n\n��ѡ��:";
	char choose = inputChar();
	while (choose != '1' && choose != '2')
	{
		cout << "\nѡ�����!����ѡ��:";
		choose = inputChar();
	}
	if (choose == '1')
	{
		if (identity == "ѧ��")
			studentMenu();
	}
}

void Menu::chooseRole()
{
	cout << "\n\t\t\t       ��ӭʹ��ѧ��ѡ��ϵͳ" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "1.ѧ����¼" << endl;
	cout << "2.����Ա��¼" << endl;
	cout << "3.�˳�ϵͳ\n" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "��ѡ��1-3�����в���" << endl;
	switch (choose('3'))
	{
	case '1':
	{
		identity = "ѧ��";
		Student student;
		student.login();
		break;
	}
	case '2':
	{
		identity = "����Ա";
		ManagerMenu();
		break;
	}
	default:
		break;
	}
}

void Menu::studentMenu()
{
	system("cls");
	cout << "\n\t\t\t       ѧ���˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n1.��ʼѡ��" << endl;
	cout << "2.����γ���Ϣ" << endl;
	cout << "3.��ѯ�γ�" << endl;
	cout << "4.�޸�����" << endl;
	cout << "5.�˳�ϵͳ\n" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n��ѡ����(1~5):";
	switch (choose('5'))
	{
		case'1':
		{
			selectCourseMenu();
			break;
		}
		case'2':
		{
			Course course;
			course.showAllCourses();
			break;
		}
		case'3':
		{
			break;
		}
		case'4':
		{
			break;
		}
	}
}

void Menu::ManagerMenu()
{

}

void Menu::selectCourseMenu()
{
	system("cls");

}

void Menu::courseInfoMenu()
{

}

void Menu::studentInfoMenu()
{

}

Menu::Menu()
{}

Menu::~Menu()
{}