#ifndef _SELECT_COURSE_H
#define _SELECT_COURSE_H
#include "header.h"

class SelectCourse
{
public:

	// set����
	void setRecordId(string recordId){ this->recordId; }
	void setUid(string uid){ this->uid; }
	void setCourseName(string courseName){ this->courseName; }
	void setCourseGrade(string courseGrade){ this->courseGrade; }
	void setGainCredit(string gainCredit){ this->gainCredit; }

	// get����
	string getRecordId(){ return recordId; }
	string getUid(){ return uid; }
	string getCourseName(){ return courseName; }
	string getCourseGrade(){ return courseGrade; }
	string getGainCredit(){ return gainCredit; }

	void createRecord();     // ���ѡ�μ�¼
	void updateRecord();     // ����ѡ�μ�¼
	void deleteRecord();     // ɾ��ѡ�μ�¼
	void showAllOptionalCourse();// ��ȡȫ����ѡ�γ�
	void showAllRecordByUid();   // ��ȡȫ����ѡ�γ�
	SelectCourse();
	~SelectCourse();
private:
	string recordId;   // ѡ�μ�¼���
	string uid;        // ѡ��ѧ��ѧ��
	string courseName; // ��ѡ�γ�����
	string courseGrade;// ��ѡ�γ̳ɼ�
	string gainCredit; // ��õ�ѧ��
};

#endif