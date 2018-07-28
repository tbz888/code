#include <iostream>
#include <string>
using namespace std;

//character occurance statistics 
int main(){
	string operand;
	cin >> operand;
	int chn[26];
	for (int i = 0; i < 26; ++i)
		chn[i] = 0;
	for (int i = 0; i < operand.size(); ++i){
		++chn[operand[i] - 'a'];	//essential statement
	}	
	for (int i = 0; i < 26; ++i)
		cout << (char)('a' + (char)i) <<  " X " << chn[i] << endl;
	return 0;
}

