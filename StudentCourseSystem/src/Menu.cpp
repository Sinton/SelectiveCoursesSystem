#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"
#include "SelectCourse.h"

string Menu::identity = "";

void Menu::adminMenu()
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
	cout << "5.���ز˵�" << endl;
	cout << "6.�˳�ϵͳ" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~6): ";
	switch (choose('6')) 
	{
	case '1':
	{
		Course course;
		course.createCourse();
		system("pause");
		Menu::adminMenu();
		break;
	}
	case '2':
	{
		Student student;
		student.createStudent();
		system("pause");
		Menu::adminMenu();
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
	case '5':
	{
		Menu::isBack();
		break;
	}
	default:
		break;
	}
}

void Menu::isBack()
{
	system("cls");
	cout << "\n\t\t\t       ���ز˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.�������˵�" << endl;
	cout << "2.����ϵͳ�˵�" << endl;
	cout << endl;
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
	switch (choose)
	{
	case '1':
	{
		if (identity == "ѧ��")
			Menu::studentMenu();
		else
			Menu::adminMenu();
	}
	case '2':
	{
		Menu::chooseRole();
	}
	default:
		break;
	}
}

void Menu::chooseRole()
{
	system("cls");
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
		cout << "���������Ա����: ";
		while ("admin" != inputString())
			cout << "�����������������: ";
		identity = "����Ա";
		Menu::adminMenu();
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
	cout << "2.�鿴��������" << endl;
	cout << "3.��ѯ�γ�" << endl;
	cout << "4.���ز˵�" << endl;
	cout << "5.�˳�ϵͳ" << endl;
	cout << endl;
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
		Student student;
		student.showStudentByUid(Student::loginUid);
		Menu::studentMenu();
		break;
	}
	case'3':
	{
		Menu::courseInfoSearchMenu();
		break;
	}
	case'4':
	{
		Menu::isBack();
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
	cout << "3.���ز˵�" << endl;
	cout << "4.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << "\n" << endl;
	cout << "��ѡ����(1~4): ";
	switch (choose('4'))
	{
	case '1':
	{
		SelectCourse selectCourse;
		selectCourse.showAllOptionalCourse();
		Menu::selectCourseMenu();
		break;
	}
	case '2':
	{
		SelectCourse selectCourse;
		selectCourse.showAllRecords();
		Menu::selectCourseMenu();
		break;
	}
	case '3':
	{
		Menu::isBack();
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
	cout << "4.���ز˵�" << endl;
	cout << "5.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~5): ";
	Course course;
	switch (choose('5'))
	{
	case '1':
	{
		cout << "������Ҫ���ҵĿγ�ѧ�֣�";
		course.showCoursesByCredit(inputString());
		Menu::courseInfoSearchMenu();
		break;
	}
	case '2':
	{
		cout << "������Ҫ���ҵĿγ����ƣ�";
		course.showCoursesByName(inputString());
		Menu::courseInfoSearchMenu();
		break;
	}
	case '3':
	{
		course.showAllCourses();
		Menu::courseInfoSearchMenu();
	}
	case '4':
	{
		Menu::isBack();
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
	cout << "3.�鿴ȫ��ѧ��" << endl;
	cout << "4.���ز˵�" << endl;
	cout << "5.�˳�ϵͳ" << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ����(1~5): ";
	Student student;
	switch (choose('5'))
	{
	case '1':
	{
		cout << "������Ҫ���ҵ�ѧ��ѧ��: ";
		student.showStudentByUid(inputString());
		Menu::studentInfoSearchMenu();
		break;
	}
	case '2':
	{
		cout << "��������ҵ�ѧ������: ";
		student.showStudentByName(inputString());
		Menu::studentInfoSearchMenu();
		break;
	}
	case '3':
	{
		student.showAllStudents();
		Menu::studentInfoSearchMenu();
		break;
	}
	case '4':
	{
		Menu::isBack();
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