#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"
#include "SelectCourse.h"

string Menu::identity = "";

void Menu::systemMenu()
{
	system("cls");
	cout << "\n\t\t\t       ϵͳ����˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.¼��γ�" << endl;
	cout << "2.¼��ѧ��" << endl;
	cout << "3.��ѯ�γ�" << endl;
	cout << "4.��ѯѧ��" << endl;
	cout << "5.�˳�ϵͳ" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~5): ";
	switch (choose('5')) 
	{
	case '1':
	{
		Course course;
		course.createCourse();
		break;
	}
	case '2':
	{
		Student student;
		student.createStudent();
		break;
	}
	case '3':
	{
		Menu::courseInfoSearchMenu();
		break;
	}
	case '4':
	{
		Menu::studentInfoSearchMenu();
		break;
	}
	default:
		break;
	}
}

void Menu::isBack()
{
	cout << "\n\t\t\t       �Ƿ񷵻����˵���" << endl;
	cout << endl;
	cout << "1.��" << endl;
	cout << "2.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~2): ";
	char choose = inputChar();
	while (choose != '1' && choose != '2')
	{
		cout << "\nѡ�����!����ѡ��:";
		choose = inputChar();
	}
	if (choose == '1')
	{
		if (identity == "ѧ��")
			Menu::studentMenu();
		else
			Menu::systemMenu();
	}
	else
	{
		exit(0);
	}
}

void Menu::chooseRole()
{
	cout << "\n\t\t\t       ��ӭʹ��ѧ��ѡ��ϵͳ" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.ѧ����¼" << endl;
	cout << "2.�������ϵͳ" << endl;
	cout << "3.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~3): ";
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
		Menu::systemMenu();
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
	cout << endl;
	cout << "1.��ʼѡ��" << endl;
	cout << "2.�鿴ȫ���γ�" << endl;
	cout << "3.��ѯ�γ�" << endl;
	cout << "4.�޸�����" << endl;
	cout << "5.�˳�ϵͳ" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~5): ";
	switch (choose('5'))
	{
	case'1':
	{
		Menu::selectCourseMenu();
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
		Menu::courseInfoSearchMenu();
		break;
	}
	case'4':
	{
		break;
	}
	default:
		break;
	}
}

void Menu::selectCourseMenu()
{
	system("cls");
	cout << "\n\t\t\t       ѡ�β˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.���ȫ����ѡ�γ�" << endl;
	cout << "2.���ȫ����ѡ�γ�" << endl;
	cout << "3.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n" << endl;
	cout << "��ѡ����(1~3): ";
	switch (choose('3'))
	{
	case '1':
	{
		SelectCourse selectCourse;
		selectCourse.showAllOptionalCourse();
		break;
	}
	case '2':
	{
		SelectCourse selectCourse;
		selectCourse.showAllRecords();
		break;
	}
	default:
		break;
	}
}

void Menu::courseInfoSearchMenu()
{
	system("cls");
	cout << "\n\t\t\t       �γ���Ϣ��ѯ�˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.�γ�ѧ��" << endl;
	cout << "2.�γ�����" << endl;
	cout << "3.�鿴ȫ���γ�" << endl;
	cout << "4.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~4): ";
	Course course;
	switch (choose('4'))
	{
	case '1':
	{
		cout << "������Ҫ���ҵĿγ�ѧ�֣�";
		course.showCoursesByCredit(inputString());
		break;
	}
	case '2':
	{
		cout << "������Ҫ���ҵĿγ����ƣ�";
		course.showCoursesByName(inputString());
		break;
	}
	case '3':
	{
		course.showAllCourses();
	}
	default:
		break;
	}
}

void Menu::studentInfoSearchMenu()
{
	system("cls");
	cout << "\n\t\t\t       ѧ����Ϣ��ѯ�˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.ѧ��ѧ��" << endl;
	cout << "2.ѧ������" << endl;
	cout << "3.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~3): ";
	Student student;
	switch (choose('3'))
	{
	case '1':
	{
		cout << "������Ҫ���ҵ�ѧ��ѧ��: ";
		student.showStudentByUid(inputString());
		break;
	}
	case '2':
	{
		cout << "��������ҵ�ѧ������: ";
		student.showStudentByName(inputString());
		break;
	}
	default:
		break;
	}
}

Menu::Menu()
{
}

Menu::~Menu()
{
}