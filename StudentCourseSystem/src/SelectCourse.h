#include <iostream>
using namespace std;
class SelectCourse
{
	int recordId;      // ѡ�μ�¼���
	string uid;        // ѡ��ѧ��ѧ��
	string courseName; // ��ѡ�γ�����
	string courseGrade;// ��ѡ�γ̳ɼ�
	string gainCredit; // ��õ�ѧ��
public:
	void createRecord();     // ���ѡ�μ�¼
	void updateRecord();     // ����ѡ�μ�¼
	void deleteRecord();     // ɾ��ѡ�μ�¼
	void getAllRecordByUid();// �鿴��ѡ�γ�
	SelectCourse();
	~SelectCourse();
private:
};
