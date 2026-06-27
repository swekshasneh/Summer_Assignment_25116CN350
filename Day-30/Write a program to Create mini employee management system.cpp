
#include <bits/stdc++.h>
using namespace std;

struct Employee {
	int id;
	string name;
	string dept;
	double salary;
};

vector<Employee> employees;
const string DATAFILE = "employees.txt";

void load()
{
	employees.clear();
	ifstream fin(DATAFILE);
	if(!fin) return;
	Employee e;
	while(fin >> e.id) {
		fin >> ws;
		getline(fin, e.name);
		getline(fin, e.dept);
		fin >> e.salary;
		fin >> ws;
		employees.push_back(e);
	}
}

void save()
{
	ofstream fout(DATAFILE);
	for(auto &e: employees) {
		fout << e.id << '\n';
		fout << e.name << '\n';
		fout << e.dept << '\n';
		fout << e.salary << '\n';
	}
}

int findIndexById(int id)
{
	for(size_t i=0;i<employees.size();++i) if(employees[i].id==id) return (int)i;
	return -1;
}

void addEmployee()
{
	Employee e;
	cout << "Enter id: "; if(!(cin>>e.id)) return;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if(findIndexById(e.id) != -1) { cout<<"ID already exists\n"; return; }
	cout << "Enter name: "; getline(cin, e.name);
	cout << "Enter department: "; getline(cin, e.dept);
	cout << "Enter salary: "; cin >> e.salary; cin.ignore();
	employees.push_back(e);
	save();
	cout << "Added.\n";
}

void listEmployees()
{
	if(employees.empty()) { cout<<"No employees.\n"; return; }
	cout<<"ID\tName\tDepartment\tSalary\n";
	for(auto &e: employees) cout<<e.id<<"\t"<<e.name<<"\t"<<e.dept<<"\t"<<e.salary<<"\n";
}

void searchEmployee()
{
	int id; cout<<"Enter id to search: "; if(!(cin>>id)) return; int idx=findIndexById(id);
	if(idx==-1) cout<<"Not found\n";
	else {
		auto &e = employees[idx];
		cout<<"ID:"<<e.id<<"\nName:"<<e.name<<"\nDept:"<<e.dept<<"\nSalary:"<<e.salary<<"\n";
	}
}

void updateEmployee()
{
	int id; cout<<"Enter id to update: "; if(!(cin>>id)) return; int idx=findIndexById(id);
	if(idx==-1) { cout<<"Not found\n"; return; }
	cin.ignore();
	cout<<"Enter new name: "; getline(cin, employees[idx].name);
	cout<<"Enter new dept: "; getline(cin, employees[idx].dept);
	cout<<"Enter new salary: "; cin>>employees[idx].salary; cin.ignore();
	save(); cout<<"Updated.\n";
}

void deleteEmployee()
{
	int id; cout<<"Enter id to delete: "; if(!(cin>>id)) return; int idx=findIndexById(id);
	if(idx==-1) { cout<<"Not found\n"; return; }
	employees.erase(employees.begin()+idx);
	save(); cout<<"Deleted.\n";
}

int main()
{
	load();
	while(true){
		cout<<"\nMini Employee Management System\n";
		cout<<"1. Add 2. List 3. Search 4. Update 5. Delete 6. Exit\n";
		cout<<"Choice: "; int c; if(!(cin>>c)) break; cin.ignore();
		switch(c){
			case 1: addEmployee(); break;
			case 2: listEmployees(); break;
			case 3: searchEmployee(); break;
			case 4: updateEmployee(); break;
			case 5: deleteEmployee(); break;
			case 6: cout<<"Bye\n"; return 0;
			default: cout<<"Invalid\n";
		}
	}
	return 0;
}
