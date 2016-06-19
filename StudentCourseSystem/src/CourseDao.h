#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H
#include <vector>
#include "DBHelper.h"
#include "Course.h"

class CourseDao
{
public:
	static string memberJoin;

	int openDB(const char *path);
	int closeDB();
	vector<Course> getAllCourses();			// ��ȡ���пγ�
	vector<Course> getCourseByName(string name);
	vector<Course> getCourseByCredit(string credit);
	void addCourse(Course course);          // ��ӿγ�
	void removeCourse();                    // ɾ���γ�
	void updateMemberJoin(string courseId); // ���¿γ�ѡ������
	void getMemberJoin(string courseId);    // ��ȡ�γ�ѡ������
	CourseDao(){ openDB(DB_NAME); }
	~CourseDao(){ closeDB(); }

private:
	sqlite3 *sqliteDb;	    // ���ݿ��ָ��
	char* errorMsg;			// ������Ϣ
	bool isClose;			// �ر����ݵı�ʶ

	static int callBackGetAllCourses(void *, int argc, char **argv, char **colName);
	static int callBackAddCourse(void *, int argc, char **argv, char **colName);
	static int callBackRemoveCourse(void *, int argc, char **argv, char **colName);
	static int callBackGetMemberJoin(void *, int argc, char **argv, char **colName);
};

#endif