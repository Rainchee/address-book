#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//��ϵ�˽ṹ��
struct Person
{
	string m_Name;//����
	int m_Sex;//�Ա� 1.�� 2.Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//��ַ
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б�����ϵ�˵�����
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};
//1�������ϵ��
void addPerson(Addressbooks* abs)
{
	//ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����!" << endl;
		return;
	}
	else
	{
		//�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//����
		abs->m_Size++;
		cout << "��ӳɹ���" << endl;
		system("pause");//������˳�
		system("cls");//����
	}
}
//2����ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex==1?"��":"Ů")<< "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ���ڣ�������ڷ��������о���λ�ã������ڷ���-1
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
//3��ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size-1; i++)//����ǰ��
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4��������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//5���޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string addr;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//6�������ϵ��
void cleanPearson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨ��¼�����" << endl;
	system("pause");
	system("cls");
}
//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨ��¼  *****" << endl;
	cout << "***************************" << endl;
}
int main()
{
	Addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.m_Size = 0;//��ʼ��
	int select = 0;//�û�����
	while (true)
	{
		showMenu();//��ʾ�˵�
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs); 
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPearson(&abs);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}