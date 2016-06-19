#include "Course.h"
#include "CourseDao.h"
#include "Menu.h"

vector<Course> courses;
vector<Course> Course::courseVector = courses;

void Course::createCourse()
{
	Course course;
	cout << "������γ����ƣ�";
	course.courseName = inputString();
	cout << "������γ�ѧ�֣�";
	course.courseCredit = inputString();
	cout << "������γ����ʣ�";
	course.property = inputString();
	cout << "������γ��ڿν�ʦ��";
	course.teacher = inputString();
	cout << "������γ�����Ժϵ��";
	course.courseDepartment = inputString();
	cout << "������γ���ѧʱ��";
	course.totalPeriod = inputString();
	cout << "������γ��ڿ�ѧʱ��";
	course.classPeriod = inputString();
	cout << "������γ�ʵ��ѧʱ��";
	course.labPeriod = inputString();
	cout << "������γ�ѡ���������ޣ�";
	course.memberMax = inputString();
	cout << "������γ���ѡ������";
	course.memberJoin = inputString();
	cout << "������γ̿���ѧ�ڣ�";
	course.startTerm = inputString();
	CourseDao courseDao;
	courseDao.addCourse(course);
}

void Course::updateCourse()
{
}

void Course::modifyMemberJoin(string courseId)
{
	CourseDao courseDao;
	courseDao.updateMemberJoin(courseId);
}

void Course::deleteCourse()
{
}

void Course::showAllCourses()
{
	courseVector.clear();
	CourseDao courseDao;
	Course::courseVector = courseDao.getAllCourses();
	if (courseVector.empty())
	{
		cout << "û�м�¼�γ���Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\n�γ���Ϣ���£�\n" << endl;
	for (vector<Course>::iterator iter = courseVector.begin(); iter != courseVector.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "�γ̱�ţ�" << iter->courseId << "\t\t"
			<< "�γ����ƣ�" << iter->courseName << endl
			<< "�γ�ѧ�֣�" << iter->courseCredit << "\t\t"
			<< "�γ����ʣ�" << iter->property << endl
			<< "�ڿ���ʦ��" << iter->teacher << "��\t"
			<< "����Ժϵ��" << iter->courseDepartment << endl
			<< "��ѧʱ��" << iter->totalPeriod << "\t\t"
			<< "�ڿ�ѧʱ��" << iter->classPeriod << endl
			<< "ʵ��ѧʱ��" << iter->labPeriod << "\t\t"
			<< "�������ޣ�" << iter->memberMax << endl
			<< "��ѡ������" << iter->memberJoin << "\t\t"
			<< "�Ͽ�ѧ�ڣ�" << iter->startTerm << endl << endl;
	}
	this->showCourseElectiveDetail();
	system("pause");
}

void Course::showCoursesByName(string name)
{
	courseVector.clear();
	CourseDao courseDao;
	Course::courseVector = courseDao.getCourseByName(name);
	if (courseVector.empty())
	{
		cout << "�Ҳ����γ�����Ϊ" << name << "�Ŀγ���Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\n�γ���Ϣ���£�\n" << endl;
	for (vector<Course>::iterator iter = courseVector.begin(); iter != courseVector.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "�γ̱�ţ�" << iter->courseId << "\t\t"
			<< "�γ����ƣ�" << iter->courseName << endl
			<< "�γ�ѧ�֣�" << iter->courseCredit << "\t\t"
			<< "�γ����ʣ�" << iter->property << endl
			<< "�ڿ���ʦ��" << iter->teacher << "��\t"
			<< "����Ժϵ��" << iter->courseDepartment << endl
			<< "��ѧʱ��" << iter->totalPeriod << "\t\t"
			<< "�ڿ�ѧʱ��" << iter->classPeriod << endl
			<< "ʵ��ѧʱ��" << iter->labPeriod << "\t\t"
			<< "�������ޣ�" << iter->memberMax << endl
			<< "��ѡ������" << iter->memberJoin << "\t\t"
			<< "�Ͽ�ѧ�ڣ�" << iter->startTerm << endl << endl;
	}
	this->showCourseElectiveDetail();
	system("pause");
}

void Course::showCoursesByCredit(string credit)
{
	courseVector.clear();
	CourseDao courseDao;
	Course::courseVector = courseDao.getCourseByCredit(credit);
	if (courseVector.empty())
	{
		cout << "�Ҳ����γ�ѧ��Ϊ" << credit << "�Ŀγ���Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\n�γ���Ϣ���£�\n" << endl;
	for (vector<Course>::iterator iter = courseVector.begin(); iter != courseVector.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "�γ̱�ţ�" << iter->courseId << "\t\t"
			<< "�γ����ƣ�" << iter->courseName << endl
			<< "�γ�ѧ�֣�" << iter->courseCredit << "\t\t"
			<< "�γ����ʣ�" << iter->property << endl
			<< "�ڿ���ʦ��" << iter->teacher << "��\t"
			<< "����Ժϵ��" << iter->courseDepartment << endl
			<< "��ѧʱ��" << iter->totalPeriod << "\t\t"
			<< "�ڿ�ѧʱ��" << iter->classPeriod << endl
			<< "ʵ��ѧʱ��" << iter->labPeriod << "\t\t"
			<< "�������ޣ�" << iter->memberMax << endl
			<< "��ѡ������" << iter->memberJoin << "\t\t"
			<< "�Ͽ�ѧ�ڣ�" << iter->startTerm << endl << endl;
	}
	this->showCourseElectiveDetail();
	system("pause");
}

void Course::showCourseElectiveDetail()
{
	cout << "�Ƿ�Ҫ�鿴�γ̵�ѡ����� (y / n): ";
	while ("y" == inputString())
	{
		cout << "����γ̱��ID�鿴: ";
		CourseDao courseDao;
		courseDao.getMemberJoin(inputString());
		cout << endl << "����" << CourseDao::memberJoin << "��ѡ���˸ÿγ�" << endl << endl;
		cout << "�Ƿ�����鿴 (y / n): ";
	}
}

Course::Course()
{
}

Course::~Course()
{
}