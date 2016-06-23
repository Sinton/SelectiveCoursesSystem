#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H
#include <vector>
#include "DBHelper.h"
#include "Course.h"

class CourseDao : public DBHelper
{
public:
	static string memberJoin;

	vector<Course> getAllCourses();			        // ��ȡ���пγ�
	vector<Course> getCourseByName(string name);    // ��ȡ���ƿγ������µ�ȫ���γ�
	vector<Course> getCourseByCredit(string credit);// ��ȡָ��ѧ���µ�ȫ���γ�
	void addCourse(Course course);                  // ��ӿγ�
	void removeCourse();                            // ɾ���γ�
	void updateMemberJoin(string courseId);         // ���¿γ�ѡ������
	void getMemberJoin(string courseId);            // ��ȡ�γ�ѡ������
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ }

private:
	static int callBackGetAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
	static int callBackGetMemberJoin(void *, int argc, char **argv, char **colName);
};

#endif