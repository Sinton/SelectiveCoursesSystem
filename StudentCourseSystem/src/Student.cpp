#include "Student.h"
#include "StudentDao.h"
#include "Menu.h"

vector<Student> stu_vec;
vector<Student> Student::vStudents = stu_vec;
vector<Student>::iterator Student::iterStudent = vStudents.begin();
string Student::loginUid = "";

void Student::login()
{
	
	cout << "������ѧ��: ";
	loginUid = inputString();
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(loginUid);
	if (studentDao.checkUidExits(loginUid))
		Menu::studentMenu();
	else
	{
		cout << "ѧ�Ŵ���!" << endl;
		this->login();
	}
}

void Student::createStudent()
{
	Student student;
	cout << "������ѧ�ţ�" << endl;
	student.setUid(inputString());
	cout << "������������" << endl;
	student.setName(inputString());
	cout << "�������Ա�" << endl;
	student.setSex(inputString());
	cout << "�����뼨�㣺" << endl;
	student.setCredit(inputString());
	cout << "�������꼶��" << endl;
	student.setGrade(inputString());
	cout << "������רҵ��" << endl;
	student.setMajor(inputString());
	cout << "������Ժϵ��" << endl;
	student.setDepartment(inputString());
	StudentDao studentDao;
	studentDao.addStudent(student);
}

void Student::updateStudent()
{

}

void Student::deleteStudent()
{

}

void Student::showStudentByUid(string uid)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByUid(uid);
	vector<string>::iterator iterator;
	// ��ӡ��ȡ����ѧ����Ϣ
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << iterator->data() << endl;
	system("pause");
}

void Student::showStudentByName(string name)
{
	StudentDao studentDao;
	vector<string> studentInfo = studentDao.getStudentByName(name);
	vector<string>::iterator iterator;
	// ��ӡ��ȡ����ѧ����Ϣ
	for (iterator = studentInfo.begin(); iterator != studentInfo.end(); iterator++)
		cout << iterator->data() << endl;
	system("pause");
}

void Student::showAllStudents()
{
	StudentDao studentDao;
	vector<Student> students = studentDao.getAllStudents();
	if (students.empty())
	{
		cout << "û�м�¼�γ���Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\n�γ���Ϣ���£�\n" << endl;
	for (vector<Student>::iterator iter = students.begin(); iter != students.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "ѧ�ţ�" << iter->getUid() << endl
			<< "������" << iter->getName() << endl
			<< "�Ա�" << iter->getSex() << endl
			<< "���㣺" << iter->getCredit() << endl
			<< "�꼶��" << iter->getGrade() << endl
			<< "רҵ��" << iter->getMajor() << endl
			<< "Ժϵ��" << iter->getDepartment() << endl << endl;
	}
	system("pause");
}

Student::Student()
{
	uid = "";
	name = "";
	sex = "";
	credit = "";
	grade = "";
	major = "";
	department = "";
}

Student::~Student()
{
}