//#include <iostream> 
//
//using namespace std;
//
//template <class T> class matrix {
//	
//public:
//	T a[10][10], b[10][10], mul[10][10];
//		int r, c, i, j, k;
//
//	void getMatrix() {
//				
//		cout << "enter the number of row=";
//		cin >> r;
//		cout << "enter the number of column=";
//		cin >> c;
//		cout << "enter the first matrix element=\n";
//		for (i = 0; i < r; i++)
//		{
//			for (j = 0; j < c; j++)
//			{
//				cin >> a[i][j];
//			}
//		}
//
//	cout << "enter the second matrix element=\n";
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			cin >> b[i][j];
//		}
//	}
//
//	}
//	void multiplyMatrix() {
//		cout << "multiply of the matrix=\n";
//		for (i = 0; i < r; i++)
//		{
//			for (j = 0; j < c; j++)
//			{
//				mul[i][j] = 0;
//				for (k = 0; k < c; k++)
//				{
//					mul[i][j] += a[i][k] * b[k][j];
//				}
//			}
//		}
//	}
//
//	
//};
//
//int main()
//{
//	int i, j;
//	cout << "Int matrix";
//	matrix<int> int_matrix;
//	int_matrix.getMatrix();
//	int_matrix.multiplyMatrix();
//
//	for (i = 0; i < int_matrix.r; i++)
//	{
//		for (j = 0; j < int_matrix.c; j++)
//		{
//			cout << int_matrix.mul[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	cout << "Double matrix";
//
//	matrix<double> double_matrix;
//	double_matrix.getMatrix();
//	double_matrix.multiplyMatrix();
//
//	for (i = 0; i < double_matrix.r; i++)
//	{
//		for (j = 0; j < double_matrix.c; j++)
//		{
//			cout << double_matrix.mul[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}