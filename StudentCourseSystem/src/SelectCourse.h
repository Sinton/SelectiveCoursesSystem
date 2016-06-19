#ifndef _SELECT_COURSE_H
#define _SELECT_COURSE_H
#include "header.h"

class SelectCourse
{
public:

	// set����
	void setRecordId(string recordId){ this->recordId = recordId; }
	void setCourseId(string courseId){ this->courseId = courseId; }
	void setUid(string uid){ this->uid = uid; }
	void setCourseName(string courseName){ this->courseName = courseName; }
	void setCourseGrade(string courseGrade){ this->courseGrade = courseGrade; }

	// get����
	string getRecordId(){ return recordId; }
	string getCourseId(){ return courseId; }
	string getUid(){ return uid; }
	string getCourseName(){ return courseName; }
	string getCourseGrade(){ return courseGrade; }

	void createRecord();     // ���ѡ�μ�¼
	void updateRecord();     // ����ѡ�μ�¼
	void deleteRecord();     // ɾ��ѡ�μ�¼
	void showAllOptionalCourse();// ��ȡȫ����ѡ�γ�
	void showAllRecords();		 // ��ȡȫ����ѡ�γ�
	SelectCourse();
	~SelectCourse();
private:
	string recordId;   // ѡ�μ�¼���
	string courseId;   // �γ̱��
	string uid;        // ѡ��ѧ��ѧ��
	string courseName; // ��ѡ�γ�����
	string courseGrade;// ��ѡ�γ̳ɼ�
};

#endif