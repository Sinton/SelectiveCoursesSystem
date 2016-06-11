#include "header.h"

class Course
{
public:
	//��¼�γ���Ϣ
	static vector<Course> courseVector;

	// set����
	void setCourseId(int courseId){ this->courseId = courseId; }
	void setCourseName(string courseName){ this->courseName = courseName; }
	void setCourseCredit(string courseCredit){ this->courseCredit = courseCredit; }
	void setProperty(string property){ this->property = property; }
	void setTeacher(string teacher){ this->teacher = teacher; }
	void setCourseDepartment(string courseDepartment){ this->courseDepartment = courseDepartment; }
	void setTotalPeriod(int totalPeriod){ this->totalPeriod = totalPeriod; }
	void setClassPeriod(int classPeriod){ this->classPeriod = classPeriod; }
	void setLabPeriod(int labPeriod){ this->labPeriod = labPeriod; }
	void setMemberMax(int memberMax){ this->memberMax = memberMax; }
	void setMemberJoin(int memberJoin){ this->memberJoin = memberMax; }
	void setStartTerm(string startTerm){ this->startTerm = startTerm; }

	// get����
	int getCourseId(){ return courseId; }
	string getCourseName(){ return courseName; }
	string getCourseCredit(){ return courseCredit; }
	string getProperty(){ return property; }
	string getTeacher(){ return teacher; }
	string getCourseDepartment(){ return courseDepartment; }
	int getTotalPeriod(){ return totalPeriod; }
	int getClassPeriod(){ return classPeriod; }
	int getLabPeriod(){ return labPeriod; }
	int getMemberMax(){ return memberMax; }
	int getMemberJoin(){ return memberJoin; }
	string getStartTerm(){ return startTerm; }

	void createCourse();     // ��ӿγ�
	void updateCourse();     // ���¿γ���Ϣ
	void deleteCourse();     // ɾ���γ�
	void showAllCourses();   // ��ʾȫ���γ�
	Course();
	~Course();
private:
	int courseId;           // �γ̱��
	string courseName;      // �γ�����
	string courseCredit;    // �γ�ѧ��
	string property;        // �γ�����
	string teacher;         // �ڿν�ʦ
	string courseDepartment;// ����Ժϵ
	int totalPeriod;        // �ܿ�ʱ
	int classPeriod;        // �Ͽο�ʱ
	int labPeriod;          // ʵ���ʱ
	int memberMax;          // ��������
	int memberJoin;         // ��ѡ����
	string startTerm;       // ��ʼ�ڿ�ѧ��
};