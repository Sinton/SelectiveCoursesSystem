#include "Course.h"
#include "CourseDao.h"
#include "Menu.h"

vector<Course> courses;
vector<Course> Course::courseVector = courses;

void Course::createCourse()
{

}

void Course::updateCourse()
{

}

void Course::deleteCourse()
{

}

void Course::showAllCourses()
{
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
		cout << "�γ̱�ţ�" << iter->courseId << '\t'
			<< "�γ����ƣ�" << iter->courseName << '\t' << endl
			<< "�γ�ѧ�֣�" << iter->courseCredit << '\t'
			<< "�γ����ʣ�" << iter->property << '\t' << endl
			<< "�ڿ���ʦ��" << iter->teacher << '\t'
			<< "����Ժϵ��" << iter->courseDepartment << '\t' << endl
			<< "��ѧʱ��" << iter->totalPeriod << '\t'
			<< "�ڿ�ѧʱ��" << iter->classPeriod << '\t' << endl
			<< "ʵ��ѧʱ��" << iter->labPeriod << '\t'
			<< "�������ޣ�" << iter->memberMax << '\t' << endl
			<< "��ѡ������" << iter->memberJoin << '\t'
			<< "�Ͽ�ѧ��" << iter->startTerm << endl
			<< "\n===================================================\n" << endl;
	}
	system("pause");
}

Course::Course()
{

}

Course::~Course()
{

}