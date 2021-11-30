#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Include(const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n'))
			return true;
	return false;
}

char* Change(char* str)
{
	if (strlen(str) < 2)
		return str;

	char* tmp = new char[strlen(str) * 3 / 2 + 1];
	char* t = tmp;

	tmp[0] = '\0';

	int i = 0;
	while (str[i + 1] != 0)
	{
		if (str[i] == 'n' && str[i + 1] == 'o')
		{
			strcat(t, "***");
			t += 3;
			i += 2;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';

	strcpy(str, tmp);

	return tmp;
}

int main()
{
	char str[101];

	cout << "Enter string: ";
	cin.getline(str, 100);

	if (Include(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	char* dest = new char[151];
	dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}
