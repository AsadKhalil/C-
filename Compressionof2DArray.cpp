//#include <iostream>
//using namespace std;
//
//int* InputArrayWithSizeMinusOne(int& size)
//{
//
//	int count = 0;
//	cout << "Please enter size:";
//	cin >> size;
//	int *ptr = new int[size];
//	for (int *i = ptr; i<size + ptr - 1; i++, count++)
//	{
//		cout << "Enter " << count + 1 << " ELEMENT of the array now=";
//		cin >> *i;
//	}
//	*(ptr + size - 1) = -1;
//	return ptr;
//}
//void OutputArray(int* myArray, const int& size)
//{
//
//	for (int *i = myArray; i<size + myArray; i++)
//	{
//		cout << *i << "	";
//	}
//}
//int *Compress1DArray(int *orignialArray, int &originolSize, int &commpressedSized)
//{
//	commpressedSized = 1; int previous = *orignialArray;
//	for (int *i = orignialArray + 1; i<originolSize + orignialArray; i++)
//		if (*i != previous)
//		{
//			commpressedSized++;
//			previous = *i;
//		}
//
//	int *ptr = new int[commpressedSized];
//	int *end = orignialArray + originolSize;
//	*ptr = *orignialArray;
//	for (int *p = ptr, *q = orignialArray + 1; q<end; q++)
//		if (*q != *p)
//		{
//			p++;
//			*p = *q; 
//		}
// 
//	return ptr;
//}
//void Test1DCompressArray()
//{
//	int size = 10, commpressedSized = 0;
//	int *ptr = InputArrayWithSizeMinusOne(size);
//
//	int * qtr = Compress1DArray(ptr, size, commpressedSized);
//	cout << "\n\nCompressed-Array : ";
//	OutputArray(qtr, commpressedSized);
//	cout << "\nNew-Size-Array=" << commpressedSized << endl << endl; cout << "\n\Originol-Array : ";
//	OutputArray(ptr, size);
//}
//
//
//void DisplayCompressed2DArray(int** matrix, const int& rows)
//{
//	for (int i = 0; i<rows; i++)
//	{
//		for (int j = 0; matrix[i][j] != -1; j++)
//			cout << matrix[i][j] << "	";
//		cout << -1 << endl;
//	}
//}
//void DeallocateMemory(int** matrix, int rows)
//{
//
//	for (int i = 0; i<rows; i++)
//		delete[] matrix[i];
//	delete[] matrix;
//}
//
//
//
////Q6 Allocate-Q6
//int **Allocate_Input(int &rows)
//{
//	cout << "Rows=";
//	cin >> rows;
//	int **matrix = new int *[rows];
//	for (int i = 0; i<rows; i++)
//	{
//		int c = 0;
//		matrix[i] = InputArrayWithSizeMinusOne(c);
//		//compressingArray 
//	}
//	return matrix;
//}
//int getSizeofColumnEdingWithMinusOne(int *arr)
//{
//	int count = 1;
//	for (; arr[count-1] != -1; count++);
//	return count;
//}
//int **Compress2DArray(int **&org, int n)
//{
//	int **compressed = new int*[n];
//	for (int i = 0; i<n; i++)
//	{
//		int c = getSizeofColumnEdingWithMinusOne(org[i]);
//		int compressedSizeOfColumn = 0;
//		compressed[i] = Compress1DArray(org[i], c, compressedSizeOfColumn);
//	}
//	return compressed;
//}
//int main()
//{
//	//Test1DCompressArray();
//
//	int n;
//	int ** matrix = Allocate_Input(n);
//	cout << "**********ORIGINOL Array*******\n";
//	DisplayCompressed2DArray(matrix, n);
//	int ** compressedMatrix = Compress2DArray(matrix, n);
//	cout << "**********COMPRESSED Array*******\n";
//	DisplayCompressed2DArray(compressedMatrix, n);
//	system("pause");
//	return 0;
//}