#ifndef _COURSE_H
#define _COURSE_H
#include "header.h"

class Course
{
public:
	//��¼�γ���Ϣ
	static vector<Course> courseVector;

	// set����
	void setCourseId(string courseId){ this->courseId = courseId; }
	void setCourseName(string courseName){ this->courseName = courseName; }
	void setCourseCredit(string courseCredit){ this->courseCredit = courseCredit; }
	void setProperty(string property){ this->property = property; }
	void setTeacher(string teacher){ this->teacher = teacher; }
	void setCourseDepartment(string courseDepartment){ this->courseDepartment = courseDepartment; }
	void setTotalPeriod(string totalPeriod){ this->totalPeriod = totalPeriod; }
	void setClassPeriod(string classPeriod){ this->classPeriod = classPeriod; }
	void setLabPeriod(string labPeriod){ this->labPeriod = labPeriod; }
	void setMemberMax(string memberMax){ this->memberMax = memberMax; }
	void setMemberJoin(string memberJoin){ this->memberJoin = memberJoin; }
	void setStartTerm(string startTerm){ this->startTerm = startTerm; }

	// get����
	string getCourseId(){ return courseId; }
	string getCourseName(){ return courseName; }
	string getCourseCredit(){ return courseCredit; }
	string getProperty(){ return property; }
	string getTeacher(){ return teacher; }
	string getCourseDepartment(){ return courseDepartment; }
	string getTotalPeriod(){ return totalPeriod; }
	string getClassPeriod(){ return classPeriod; }
	string getLabPeriod(){ return labPeriod; }
	string getMemberMax(){ return memberMax; }
	string getMemberJoin(){ return memberJoin; }
	string getStartTerm(){ return startTerm; }

	void createCourse();     // ��ӿγ�
	void updateCourse();     // ���¿γ���Ϣ
	void modifyMemberJoin(string courseId); // ���¿γ���Ϣ
	void deleteCourse();     // ɾ���γ�
	void showAllCourses();   // ��ʾȫ���γ�
	void showCoursesByName(string name);    // ���տγ����Ʋ��ҿγ�
	void showCoursesByCredit(string credit);// ���տγ�ѧ�ֲ��ҿγ�
	Course();
	~Course();
private:
	string courseId;           // �γ̱��
	string courseName;         // �γ�����
	string courseCredit;       // �γ�ѧ��
	string property;           // �γ�����
	string teacher;            // �ڿν�ʦ
	string courseDepartment;   // ����Ժϵ
	string totalPeriod;        // �ܿ�ʱ
	string classPeriod;        // �Ͽο�ʱ
	string labPeriod;          // ʵ���ʱ
	string memberMax;          // ��������
	string memberJoin;         // ��ѡ����
	string startTerm;          // ��ʼ�ڿ�ѧ��
};

#endif