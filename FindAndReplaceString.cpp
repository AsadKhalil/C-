//#include <iostream>
//using namespace std;
//char* FindAndReplaceString(char* str, char* toFind, char* toReplace)
//{
//	bool flag;
//	int findcount = 0, count = 0, strCount = 0;
//	char*result = new char[80];
//
//	while (str[strCount] != '\0')
//	{
//		strCount++;
//	}
//
//
//	while (toReplace[count] != '\0')
//	{
//		count++;
//	}
//
//	while (toFind[findcount] != '\0')
//	{
//		findcount++;
//	}
//	int y = 0;
//	for (int j = 0; j < strCount; j++)
//	{
//		int a = 0;
//		flag = true;
//
//		if (str[j] == toFind[a] || str[j] == toFind[a] + 32)
//		{
//			a++;
//
//			int b = j + 1;
//
//			while (toFind[a] != '\0')
//			{
//				if (toFind[a] != str[b])
//				{
//					flag = false;
//				}
//				a++, b++;
//			}
//			if (flag == true)
//			{
//				int i = j + 1;
//
//				for (int g = 0; g < count; g++, y++)
//				{
//					result[y] = toReplace[g];
//				}
//				j = findcount + j - 1;
//			}
//		}
//		else
//		{
//
//			result[y++] = str[j];
//
//		}
//		if (j >= strCount)
//		{
//			break;
//		}
//
//	}
//	result[y] = '\0';
//
//	return result;
//}
//int main()
//{
//	char buffer[80];
//	cout << "Enter your string:\n";
//	cin.getline(buffer, 80);
//	int count = 0;
//	while (buffer[count] != '\0')
//	{
//		count++;
//	}
//
//	char*str = new char[count + 1];
//	int i;
//	for (i = 0; i < count; i++)
//	{
//		str[i] = buffer[i];
//	}
//	str[i] = '\0';
//
//
//	char toFind[40];
//	char toReplace[40];
//	cout << "Enter your word you want to change:\n ";
//	cin >> toFind;
//	cout << "Enter your word you want to change with:\n ";
//	cin >> toReplace;
//
//	char*result = FindAndReplaceString(str, toFind, toReplace);
//	cout << result << endl;
//	system("pause");
//}
