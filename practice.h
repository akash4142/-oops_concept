#ifndef SDDS_PRACTICE_H
#define SDDS_PRACTICE_H

using namespace std;
namespace sdds {
	class employee {
		char* name;     
		int emp_no;
		int salary;
	public:
		employee();
		employee(const char* name, int num,int salary);
		employee(const employee& a);

		int returnsal();
        
		void display(ostream& os);
		void modifyname(char* modifyname);
		void readdata(istream& is);

		employee& operator+=(int sal);
		employee& operator++();
		employee& operator++(int);
		int operator+( const employee right);
		employee& operator=(const employee& e);
	    operator bool()const;

		~employee();
	};
	
	bool operator==(employee& e1, employee& e2);
	std::istream& operator>>(std::istream& is, employee& e);
	ostream& operator<<(ostream& os, employee& e);
}

#endif