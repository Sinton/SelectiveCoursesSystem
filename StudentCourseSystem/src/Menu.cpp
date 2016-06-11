#include "header.h"
#include "Menu.h"
#include "Student.h"
#include "Course.h"

string Menu::identity = "";

void Menu::systemMenu()
{
	system("cls");
	cout << "\n\t\t\t       ϵͳ����˵�" << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl;
	cout << "1.¼��γ�\t5.¼��ѧ��" << endl;
	cout << "2.��ѯ�γ�\t6.��ѯѧ��" << endl;
	cout << "3.ɾ���γ�\t7.ɾ��ѧ��" << endl;
	cout << "4.�޸Ŀγ�\t8.�˳�ϵͳ" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ���ܣ�(1~8)" << endl;
	switch (choose('8'))
	{
	case '1':
	{
		Course course;
		course.createCourse();
		break;
	}
	case '2':
	{
		break;
	}
	case '3':
	{
		break;
	}
	case '4':
	{
		break;
	}
	case '5':
	{
		Student student;
		student.createStudent();
		break;
	}
	case '6':
	{
		break;
	}
	case '7':
	{
		break;
	}
	case '8':
	{
		break;
	}
	}
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
	cout << endl;
	cout << "1.ѧ����¼" << endl;
	cout << "2.�������ϵͳ" << endl;
	cout << "3.�˳�ϵͳ\n" << endl;
	cout << endl;
	for (int i = 0; i < 80; i++)
		cout << "*";
	cout << endl << "��ѡ���ܣ�(1~3)" << endl;
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
		systemMenu();
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
	cout << endl << "��ѡ���ܣ�(1~5):";
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
{
}

Menu::~Menu()
{
}