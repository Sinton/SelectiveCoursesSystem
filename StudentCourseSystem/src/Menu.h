class Menu
{
public:
	friend char choose(char i);
	friend int inputNumber();
	static string identity;
	static void systemMenu();      // ���˵�
	static void isBack();          // �������˵�
	static void chooseRole();      // ѡ���ɫ
	static void studentMenu();     // ѧ���˵�
	static void ManagerMenu();     // ����Ա�˵�
	static void selectCourseMenu();// ѡ�β˵�
	static void courseInfoMenu();  // �γ���Ϣ��ѯ
	static void studentInfoMenu(); // ѧ����Ϣ��ѯ
	Menu();
	~Menu();
private:
};