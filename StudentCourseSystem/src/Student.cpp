#include <iostream>
#include "header.h"
#include "Student.h"
#include "Menu.h"
#include "StudentDao.h"

using namespace std;

Student::Student()
{
	uid = "";
	name = "";
	sex = "";
	credit = 0;
	grade = "";
	major = "";
	department = "";
}

Student::~Student()
{

}

int Student::login()
{
	system("cls");	
	//while (vStu.empty())
	//{
	//	cout << "��ϵͳ��δ��¼ѧ����Ϣ!���ܵ��룬��¼�������Ϣ!\n";
	//	system("pause");
	//	//StuPutin();
	//}
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t       ѧ����¼" << endl;
		for (int i = 0; i < 80; i++)
			cout << "*";
		cout << "\t������ѧ��:";
		string uid = inputString();
		StudentDao studentDao;
		studentDao.getStudentByUid(uid);
		system("pause");
		if (uid == "111")
		{
			cout << "\t\t\t\t��¼�ɹ�!\n\n";
			system("pause");
			system("cls");
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n";
			cout << "\t\t\tѧ�Ŵ���!����������!\n";
			system("pause");
		}
	}
}