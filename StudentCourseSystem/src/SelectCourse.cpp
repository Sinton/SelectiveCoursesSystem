#include "Course.h"
#include "Student.h"
#include "SelectCourse.h"
#include "SelectCourseDao.h"
#include "Menu.h"

void SelectCourse::createRecord()
{
	cout << "������γ̱�Ž���ѡ��: ";
}

void SelectCourse::updateRecord()
{

}

void SelectCourse::deleteRecord()
{

}

void SelectCourse::showAllOptionalCourse()
{
	SelectCourseDao selectCourseDao;
	vector<Course> selectCourses = selectCourseDao.getOptionalCourses(Student::uid);
	if (selectCourses.empty())
	{
		cout << "û�м�¼�γ���Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\n�γ���Ϣ���£�\n" << endl;
	for (vector<Course>::iterator iter = selectCourses.begin(); iter != selectCourses.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "�γ̱�ţ�" << iter->getCourseId() << "\t\t"
			<< "�γ����ƣ�" << iter->getCourseName() << endl
			<< "�γ�ѧ�֣�" << iter->getCourseCredit() << "\t\t"
			<< "�γ����ʣ�" << iter->getProperty() << endl
			<< "�ڿ���ʦ��" << iter->getTeacher() << "��\t"
			<< "����Ժϵ��" << iter->getCourseDepartment() << endl
			<< "��ѧʱ��" << iter->getTotalPeriod() << "\t\t"
			<< "�ڿ�ѧʱ��" << iter->getClassPeriod() << endl
			<< "ʵ��ѧʱ��" << iter->getLabPeriod() << "\t\t"
			<< "�������ޣ�" << iter->getMemberMax() << endl
			<< "��ѡ������" << iter->getMemberJoin() << "\t\t"
			<< "�Ͽ�ѧ�ڣ�" << iter->getStartTerm() << endl << endl;
	}
	system("pause");
}

void SelectCourse::showAllRecords()
{
	SelectCourseDao selectCourseDao;
	vector<Course> selectCourses = selectCourseDao.getRecords(Student::uid);
	if (selectCourses.empty())
	{
		cout << "û�м�¼�γ���Ϣ!\n";
		system("pause");
		return;
	}
	cout << "\n�γ���Ϣ���£�\n" << endl;
	for (vector<Course>::iterator iter = selectCourses.begin(); iter != selectCourses.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "�γ����ƣ�" << iter->getCourseName() << "\t\t"
			<< "�γ�ѧ�֣�" << iter->getCourseCredit() << endl << endl;
	}
	system("pause");
}

SelectCourse::SelectCourse()
{
}

SelectCourse::~SelectCourse()
{
}