#pragma once
#include <string>
#include <ctime>

using namespace std;

class Person
{
public:
	class Builder
	{
	public:
		Builder& setFirstName(const string& firstName);
		Builder& setSurname(const string& surname);
		Builder& setSecondName(const string& secondName);
		Builder& setBirthDate(const int& year, const int& month, const int& day);
		Builder& setGender(const char& gender);
		Person* build() const;

	protected:
		string firstName_;
		string surname_;
		string secondName_;
		string birthDate_;
		char gender_;

		string* _getDateStr(const int& year, const int& month, const int& day) const;
	};

	Person(const string& firstName, const string& surname, const string& secondName, const string& birthDate, const char& gender);

	string& getFirstName();
	string& getSurname();
	string& getSecondName();
	string& getBirthDate();
	char& getGender();

	void setFirstName(const string newFirstName);
	void setSurname(const string newSurname);
	void setSecondName(const string newSecondName);
	void setGender(const char newGender);

protected:
	string firstName_;
	string surname_;
	string secondName_;
	string birthDate_;
	char gender_;
};