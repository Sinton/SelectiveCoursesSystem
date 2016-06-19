#include "Course.h"
#include "Student.h"
#include "SelectCourse.h"
#include "SelectCourseDao.h"
#include "Menu.h"

void SelectCourse::createRecord(vector<Course> selectCourses)
{
	SelectCourse selectCourse;
	cout << "������γ̱�Ž���ѡ��: ";
	string cid = inputString();
	for (vector<Course>::iterator iter = selectCourses.begin(); iter != selectCourses.end(); iter++)
	{
		if (iter->getCourseId() == cid)
		{
			selectCourse.courseId = iter->getCourseId();
			selectCourse.uid = Student::loginUid;
			selectCourse.courseName = iter->getCourseName();
			selectCourse.courseCredit = iter->getCourseCredit();
		}
	}
	SelectCourseDao selectCourseDao;
	selectCourseDao.addRecord(selectCourse);
	// ���¿γ�ѡ������
	system("pause");
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
	vector<Course> selectCourses = selectCourseDao.getOptionalCourses(Student::loginUid);
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
	cout << "�Ƿ�Ҫ����ѡ�� (y / n): ";
	if ("y" == inputString())
		SelectCourse::createRecord(selectCourses);
}

void SelectCourse::showAllRecords()
{
	SelectCourseDao selectCourseDao;
	vector<Course> selectCourses = selectCourseDao.getRecords(Student::loginUid);
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