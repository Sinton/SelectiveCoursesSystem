#ifndef _SELECT_COURSE_DAO_H
#define _SELECT_COURSE_DAO_H
#include <vector>
#include "Course.h"
#include "SelectCourse.h"
#include "DBHelper.h"

class SelectCourseDao : public DBHelper
{
public:
	vector<Course> getOptionalCourses(string uid);      // ��ȡ��ѡ�γ�
	vector<Course> getRecords(string uid);              // ��ȡѡ�μ�¼
	void addRecord(SelectCourse selectCourse);          // ���ѡ�μ�¼
	void removeRecord();					            // ɾ��ѡ�μ�¼
	SelectCourseDao(){ openDB(DB_NAME); }
	~SelectCourseDao(){ }

private:
	static int callBackGetRecords(void *, int elementCount, char **element, char **colName);
	static int callBackGetOptionalCourses(void *, int elementCount, char **element, char **colName);
};

#endif