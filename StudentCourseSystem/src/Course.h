#include <iostream>
using namespace std;
class Course
{
	int courseId;           // �γ̱��
	string courseName;      // �γ�����
	string courseCredit;    // �γ�ѧ��
	string categoryId;      // �γ��������
	string teacher;         // �ڿν�ʦ
	string courseDepartment;// ����Ժϵ
	string totalPeriod;     // �ܿ�ʱ
	string classPeriod;     // �Ͽο�ʱ
	string labPeriod;       // ʵ���ʱ
	int memberMax;          // ��������
	int memberJoin;         // ��ѡ����
	string startTerm;       // ��ʼ�ڿ�ѧ��
public:
	void createCourse();    // ��ӿγ�
	void updateCourse();    // ���¿γ���Ϣ
	void deleteCourse();    // ɾ���γ�
	void getAllCourse();    // ��ȡȫ���γ�
	Course(){}
	~Course(){}
private:
};