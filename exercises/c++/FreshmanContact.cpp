#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//what a lonely project 2013-11-11 20:48:12
//Ã∆±ÚÓ» 

//define a data stype - contact
struct contact{
	bool existence;
	int index;
	char name[20];
	char email[35];
	char cellphone[25];
	char qq[15];
};

void deleteperson(contact *person);
void addcontact(int begin, contact *person);
void quit(contact *person);
void findname(contact *person);
void findemail(contact *person);
void findcellphone(contact *person);
void findqq(contact *person);
void findall(contact *person);

//load the data
int main(){
	contact person[20];
	int begin = 0;
	
	for (int i = 0; i < 20; ++i){
		person[i].existence = 0;
	}
	
	//read the data from the saved text
	ifstream fin;
	fin.open("contact.txt");
	for (int i = 0; i < 20; ++i){
		person[i].index = -1;
	}
	for (int i = 0; i < 20; ++i){
		char invalue;
		fin >> invalue;
		fin >> person[i].name;
		fin >> person[i].email;
		fin >> person[i].cellphone;
		fin >> person[i].qq;
		if (fin.get() == EOF)
			break;
		++begin;
		person[i].existence = 1;
	}
	
	//interface
	fmain:
	cout << "-- Main menu --" << endl;
	cout << "1. add a contact" << endl;
	cout << "2. find contacts" << endl;
	cout << "3. delete a contact" << endl;
	cout << "9. exit" << endl;
	
	int selection;
	cin >> selection;
	switch (selection){
	case 1:	
		addcontact(begin, person);
		goto fmain;
		break;
	case 2:
	//find contacts
		cout << "-- Find contacts --" << endl;
		cout << "1. Find by name" << endl;
		cout << "2. Find by email" << endl;
		cout << "3. Find by cellphone" << endl;
		cout << "4. Find by QQ" << endl;
		cout << "5. Find all" << endl;
		int choice;
		cin >> choice;
	
		switch (choice){
			case 1:
				findname(person);
				break;
			case 2:
				findemail(person);
				break;
			case 3:
				findcellphone(person);
				break;
			case 4:
				findqq(person);
				break;
			case 5:
				findall(person);
				break;
			default:
				cout << "Wrong choice" << endl;
				break;
		}
		
		goto fmain;
		break;
	case 3:
		deleteperson(person);
		goto fmain;
		break;
	case 9:
		quit(person);
		break;
	default:
		cout << "Wrong choice" << endl;
		goto fmain;
		return 0;
	}
}

//exit the program
void quit(contact *person){
	cout << "-- Exit --" << endl;
	cout << "1. exit without save" << endl;
	cout << "2. save and exit" << endl;
	int choice;
	cin >> choice;
	if (1 == choice)	return;
	ofstream fout;
	fout.open("contact.txt");	//open the file
	
	//write the data into a text
	int i = 0, t = 0;
	while (i < 20){
		if (person[i].existence){
			fout << i + 1 << endl;
			fout << person[i].name << endl;
			fout << person[i].email << endl;
			fout << person[i].cellphone << endl;
			fout << person[i].qq << endl;
			++t;
		}	
		++i;
	}
	if (!t){
		fout << "0" << endl;
	}
	fout.close();//close the file
}

bool compare(char a[20], char b[20]){	//search a in b from b's the first character
	for (int k = 0; a[k] != '\0'; ++k){
		if (a[k] != b[k])	return 0;
	}
	return 1;
}

//add a contact
void addcontact(int begin, contact *person){
	static int times = begin;
	cout << "-- Add a contact --" << endl;
	cout << "name:";
	cin >> person[times].name;
	cout << "email:";
	cin >> person[times].email;
	cout << "cellphone:";
	cin >> person[times].cellphone;
	cout << "QQ:";
	cin >> person[times].qq;
	for (int i = 0; i < 20; ++i){
		if ((person[i].existence) && (compare(person[times].name, person[i].name))){
			cout << "Error: name already exists" << endl;
			return;
		}
	}
	person[times].existence = 1;
}

void findall(contact *person){
	int amout = 0;
	
	for (int i = 0; i < 20; ++i){
		if (person[i].existence)
			++amout;
	}

	if (!amout){
		cout << "Not found" << endl;
		return;
	}
	
	for (int k = 0; k < 20; ++k){
		if (person[k].existence){
			if (person[k].index < 0)
				person[k].index = k + 1;
			cout << person[k].index << ". "
				<< person[k].name << ", "
				<< "Email:" << person[k].email << ", "
				<< "Cellphone:" << person[k].cellphone << ", "
				<< "QQ:" << person[k].qq << endl;
		}
	}
	return;
}

void findqq(contact *person){
	cout << "-- Find contacts by QQ --" << endl;
	cout << "QQ:";
	char QQ[15];
	cin >> QQ;
	int sum = 0;
	for (int k = 0; k < 20; ++k){
		if (person[k].existence){
			if (compare(person[k].qq, QQ)){
				++sum;
				person[k].index = sum;
				cout << person[k].index << ". "
					<< person[k].name << ", "
					<< "Email:" << person[k].email << ", "
					<< "Cellphone:" << person[k].cellphone << ", "
					<< "QQ:" << person[k].qq << endl;				
			}
		}
	}
	if (!sum)
		cout << "Not found" << endl;
}

void findcellphone(contact *person){
	cout << "-- Find contacts by cell --" << endl;
	cout << "cell:";
	char QQ[15];
	cin >> QQ;
	int sum = 0;
	for (int k = 0; k < 20; ++k){
		if (person[k].existence){
			if (compare(person[k].cellphone, QQ)){
				++sum;
				person[k].index = sum;
				cout << person[k].index << ". "
					<< person[k].name << ", "
					<< "Email:" << person[k].email << ", "
					<< "Cellphone:" << person[k].cellphone << ", "
					<< "QQ:" << person[k].qq << endl;				
			}
		}
	}
	if (!sum)
		cout << "Not found" << endl;
}

void findname(contact *person){
	cout << "-- Find contacts by name --" << endl;
	cout << "name:";
	char QQ[15];
	cin >> QQ;
	int sum = 0;
	for (int k = 0; k < 20; ++k){
		if (person[k].existence){
			if (compare(person[k].name, QQ)){
				++sum;
				person[k].index = sum;
				cout << person[k].index << ". "
					<< person[k].name << ", "
					<< "Email:" << person[k].email << ", "
					<< "Cellphone:" << person[k].cellphone << ", "
					<< "QQ:" << person[k].qq << endl;				
			}
		}
	}
	if (!sum)
		cout << "Not found" << endl;
}

void findemail(contact *person){
	cout << "-- Find contacts by email --" << endl;
	cout << "email:";
	char QQ[15];
	cin >> QQ;
	int sum = 0;
	for (int k = 0; k < 20; ++k){
		if (person[k].existence){
			if (compare(person[k].email, QQ)){
				++sum;
				person[k].index = sum;
				cout << person[k].index << ". "
					<< person[k].name << ", "
					<< "Email:" << person[k].email << ", "
					<< "Cellphone:" << person[k].cellphone << ", "
					<< "QQ:" << person[k].qq << endl;				
			}
		}
	}
	if (!sum)
		cout << "Not found" << endl;
}

void deleteperson(contact *person){
	cout << "-- Delete a contact--" << endl;
	cout << "Contact index:";												
	int id = 0, n = 0;
	cin >> id;
	for (int k = 0; k < 20; ++k){
		if (person[k].index > 0 && id == person[k].index){
			++n;
			person[k].existence = 0;
			cout << "Deleted: "
					<< person[k].index << ". "
					<< person[k].name << ", "
					<< "Email:" << person[k].email << ", "
					<< "Cellphone:" << person[k].cellphone << ", "
					<< "QQ:" << person[k].qq << endl;	
			--person[k + 1].index;
			return;
		}
	}
	
	if (!n){
		cout << "Error: failed to delete" << endl;
		cout << "Please 'Find' again to set indexes" << endl;
	}
}
