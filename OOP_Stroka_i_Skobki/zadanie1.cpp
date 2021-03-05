#include<iostream>
#include<string>
using namespace std;
int SerchAllPar(string any);
bool InArr(int anyArr[], const int size, int Index);
int main() {
	cout << "Enter your mathematical expression including parentheses: " << endl;
	string Expr{ "" };
	getline(cin, Expr);
	cout << Expr.length() << endl;
	int Rez = SerchAllPar(Expr);
	if (Rez == -1) { cout << "Parentheses not found" << endl; }
	else if (Rez==Expr.length()) { 
		cout << "Your mathematical expression is true"<<endl<<endl<<Expr<<endl; }
	else {
		cout << "Your mathematical expression is true up to: ";
		for (int i = 0; i < (int)Expr.length(); i++) {
			if (i != Rez) cout << Expr[i];
			else break;
		}
	}
	return 0;
}
int SerchAllPar(string any) {
	int i{ 0 }, j{ 0 }, iArr{ 0 };
	const int sizeArr = 100;
	int Arr[sizeArr];
	if (any.find(")") == string::npos && any.find("(") == string::npos) {
		if (any.find("}") == string::npos && any.find("{") == string::npos) {
			if (any.find("]") == string::npos && any.find("[") == string::npos) return -1;
		}
	}
	if(any.find(")") == string::npos&& any.find("]") == string::npos&& any.find("}") == string::npos){
		for (i = 0; i < (int)any.length(); i++) {
			if (any[i] == '(' || any[i] == '{' || any[i] == '[') return i;
		}
	}
	else {
		for (i = 0; i < (int)any.length(); i++) {
			if (any[i] == ')' || any[i] == ']' || any[i] == '}') {
				if (any[i] == ')') {
					for (j = i; j >= 0; j--) {
						if (any[j] == '(') {
							Arr[iArr] = i;
							Arr[iArr + 1] = j;
							iArr++; break;
						}
						else if (any[j] == '[' || any[j] == ']' || any[j] == '{' || any[j] == '}' || j == 0) { return i; break; }
						else continue;
					}
				}
				if (any[i] == '}') {
					for (j = i; j >= 0; j--) {
						if (InArr(Arr, sizeArr, j)) continue;
						else {
							if (any[j] == '{') {
								Arr[iArr] = i;
								Arr[iArr + 1] = j;
								iArr++; break;
							}
							else if (any[j] == '[' || any[j] == ']' || any[j] == '(' || any[j] == ')' || j == 0) { return i; break;	}
							else continue;
						};
					}
				}
				if (any[i] == ']') {
					for (j = i; j >= 0; j--) {
						if (InArr(Arr, sizeArr, j)) continue;
						else {
							if (any[j] == '[') {
								Arr[iArr] = i;
								Arr[iArr + 1] = j;
								iArr++; break;
							}
							else if (any[j] == '{' || any[j] == '}' || any[j] == '(' || any[j] == ')' || j == 0) { return i; break; }
							else continue;
						};
					}
				}
				if (any[i] == ';') return i;
			}
			else continue;
		}
	}
	cout << i << endl;
};
bool InArr(int anyArr[], const int size, int Index) {
	int temp{ 0 };
	for (int i = 0; i < size; i++) {
		if (anyArr[i] == Index) ++temp;
		else continue;
	}
	return temp;
};