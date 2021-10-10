//#include<iostream>
//
//using namespace std;
//
//class matrix {
//    void getInput() {
//        do {
//            cout << "Rows = ";
//            cin >> row;
//            cout << "Columns = ";
//            cin >> col;
//            if (row < 1 || col < 1 || row > 10 || col > 10) {
//                cout << "Invalid entries. Min size = 1x1 and max size = 10x10.\n";
//            }
//        } while (row < 1 || col < 1 || row > 10 || col > 10);
//
//        cout << "Remember to enter matrix entries from top-left to bottom-right.\n";
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < col; j++) {
//                cout << "Matrix Entry (" << i << "," << j << ") = ";
//                cin >> matrix[i][j];
//            }
//        }
//    }
//};