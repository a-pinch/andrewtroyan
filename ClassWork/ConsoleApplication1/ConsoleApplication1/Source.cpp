#include <iostream>
#include <io.h>
#include <direct.h>
#include <fstream>

using namespace std;

struct Student
{
	char name[16];
	int age;
	int sn;

	void serialize()
	{
		FILE* pF = fopen("","wb");
		if (pF)
		{
			fwrite(this, sizeof(Student), 1, pF);
			fclose(pF);
		}
	}

	void deserialize()
	{
		FILE* pF = fopen("", "wb");
		if (pF)
		{
			fread(this, sizeof(Student), 1, pF);
			fclose(pF);
		}
	}
};


void CopyFile(const char* oldName, const char* newName)
{
	FILE* pF = fopen(oldName, "rb");
	if (!pF)
		return;

	FILE* pF_copy = fopen(newName, "wb");
	if (!pF_copy)
	{
		fclose(pF);
		return;
	}

	char ch;

	while (!(ch = fgetc(pF)))
		fputc(ch, pF_copy);

}

int main()
{
	//_finddata_t fd;

	//_mkdir("D:\\test\\t\\..\\_mkdir");

	//long hFile = _findfirst("D:\\test\\t\\..\\*", &fd);

	//if (hFile != -1)
	//{
	//	do{
	//		cout << fd.name << " ";
	//		cout << ((fd.attrib & _A_SUBDIR) ? "DIR" : "FILE") << endl;
	//	}
	//	while (-1 != _findnext(hFile, &fd));

	//	_findclose(hFile);
	//}

	//ofstream f_o1("D:\\test\\AZ.txt", ios::out);
	//int arr1[5] = {};
	//int arr2[5];
	//f_o1 << "text" << 200 << "a" << endl;
	//f_o1.write((const char *)arr1, sizeof(arr1));
	//f_o1.close();

	//ifstream f_i1("D:\\test\\AZ.txt", ios::in);
	//f_i1.read((char *)arr2, sizeof(arr2));
	//f_i1.close();

	ofstream f_o("D:\\test\\f_o.txt", ios::out);
	if (!f_o.is_open())
		cout << "f_o don't exist" << endl;
	
	ifstream f_i("D:\\test\\f_i.txt", ios::in);
	if (!f_i.is_open())
	{
		cout << "f_i don't exist" << endl;
		f_o.close();
	}

	char ch;
	while (!f_i.eof() && f_i.good())
	{
		f_i.get(ch);
		f_o.put(ch);
	}

	f_i.close();
	f_o.close();

	return 0;
}