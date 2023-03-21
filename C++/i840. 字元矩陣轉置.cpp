#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<vector<char>> matrix(5, vector<char>(5,'\0'));
	for(int y=0;y<5;y++){
		for(int x=0;x<5;x++){
			cin >> matrix[y][x];
		}
	}
	for(int x=0;x<5;x++){
		for(int y=0;y<5;y++){
			cout << matrix[y][x];
		}
		cout << endl;
	}
	return 0;
}
