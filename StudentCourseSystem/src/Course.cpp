#include "Course.h"
#include "CourseDao.h"
#include "Menu.h"

vector<Course> courses;
vector<Course> Course::courseVector = courses;

void Course::createCourse()
{
	Course course;
	cout << "请输入课程名称：";
	course.courseName = inputString();
	cout << "请输入课程学分：";
	course.courseCredit = inputString();
	cout << "请输入课程性质：";
	course.property = inputString();
	cout << "请输入课程授课教师：";
	course.teacher = inputString();
	cout << "请输入课程所属院系：";
	course.courseDepartment = inputString();
	cout << "请输入课程总学时：";
	course.totalPeriod = inputString();
	cout << "请输入课程授课学时：";
	course.classPeriod = inputString();
	cout << "请输入课程实验学时：";
	course.labPeriod = inputString();
	cout << "请输入课程选课人数上限：";
	course.memberMax = inputString();
	cout << "请输入课程已选人数：";
	course.memberJoin = inputString();
	cout << "请输入课程开课学期：";
	course.startTerm = inputString();
	CourseDao courseDao;
	courseDao.addCourse(course);
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
		cout << "没有记录课程信息!\n";
		system("pause");
		return;
	}
	cout << "\n课程信息如下：\n" << endl;
	for (vector<Course>::iterator iter = courseVector.begin(); iter != courseVector.end(); iter++)
	{
		cout << "=========================================================\n"
			<< "课程编号：" << iter->courseId << "\t\t"
			<< "课程名称：" << iter->courseName << endl
			<< "课程学分：" << iter->courseCredit << "\t\t"
			<< "课程性质：" << iter->property << endl
			<< "授课老师：" << iter->teacher << "　\t"
			<< "开课院系：" << iter->courseDepartment << endl
			<< "总学时：" << iter->totalPeriod << "\t\t"
			<< "授课学时：" << iter->classPeriod << endl
			<< "实验学时：" << iter->labPeriod << "\t\t"
			<< "人数上限：" << iter->memberMax << endl
			<< "已选人数：" << iter->memberJoin << "\t\t"
			<< "上课学期：" << iter->startTerm << endl << endl;
	}
	system("pause");
}

Course::Course()
{

}

Course::~Course()
{

}