class Menu
{
public:
	friend char choose(char i);
	friend int inputNumber();
	static string identity;
	static void isBack();          // �������˵�
	static void chooseRole();      // ѡ���ɫ
	static void studentMenu();     // ѧ���˵�
	static void systemMenu();      // ����ϵͳ�˵�
	static void selectCourseMenu();// ѡ�β˵�
	static void courseInfoSearchMenu();  // �γ���Ϣ��ѯ�˵�
	static void studentInfoSearchMenu(); // ѧ����Ϣ��ѯ�˵�
	Menu();
	~Menu();
private:
};