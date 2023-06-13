#include <iostream>
#include <string>
#include <exception>

class Person
{
	int age;
	int medium_grade;
	int course;
	std::string profession;
	std::string name;
	std::string contact;
	std::string adress;

public:
	Person(std::string studentName, int studentAge, int studentMedium_grade, int studentCourse, std::string studentProfession, std::string studentContact, std::string studentAdress)
	{
		this->name = studentName;
		this->medium_grade = studentMedium_grade;
		this->course = studentCourse;
		this->age = studentAge;
		if (age <= 0)
		{
			throw std::runtime_error("Age must be grather than 0!!!!");
		}
		this->profession = studentProfession;
		this->contact = studentContact;
		this->adress = studentAdress;

	}

	void Display()
	{
		std::cout << " Name- " <<name <<std::endl;
		std::cout << " Course- " << course << std::endl;
		std::cout << " Medium grade-  " << medium_grade << std::endl;
		std::cout << " Age-  " << age << std::endl;
		std::cout << " Profession- " << profession << std::endl;
		std::cout << " Contact-  " << contact << std::endl;
		std::cout << " Adress- " << adress << std::endl;

	}

};

int main(int argc, char** argv)
{

	Person student("Lusine", 21, 97, 4, "Management", "+3745986214", "Yerevan, Tsitsernakaberd 2/1");
	student.Display();

	return 0;
}