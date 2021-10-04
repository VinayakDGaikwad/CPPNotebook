//#include<iostream>
//
//using namespace std;
//
//int main() {
//			
//	int p1[] = {89,90, 10, 100, 200 };
//	const char p2[] = {'f','g','w','q','h'};
//	float p3[] = { 23.4,23.5,785.56,67.56,78.789 };
//
//
//	int  i, * ptr;
//	ptr = &p1[4];
//
//	for (i = 5; i > 0; i--) {
//		printf("Address of int[%d] = %x\n", i, ptr);
//		printf("Value of int[%d] = %d\n", i, *ptr);
//		ptr--;
//	}
//
//	const char* ptr2;
//	ptr2 = &p2[4];
//	for (i = 5; i > 0; i--) {
//		printf("Address of char[%d] = %x\n", i, ptr2);
//		printf("Value of char[%d] = %d\n", i, *ptr2);
//		ptr2--;
//	}
//
//	float* ptr3;
//	ptr3 = &p3[4];
//	for (i = 5; i > 0; i--) {
//		printf("Address of float[%d] = %x\n", i, ptr3);
//		printf("Value of float[%d] = %d\n", i, *ptr3);
//		ptr3--;
//	}
//
//}