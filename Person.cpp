#include <C:\Users\Alexandr\source\repos\DigitalDocuments\Person.h>
#include <string>
#include <ctime>

using namespace std;

// PERSON CLASS DEFENITION

string firstName_;
string surname_;
string secondName_;
string birthDate;
char gender_;

Person::Person(const string& firstName, const string& surname, const string& secondName, const string& birthDate, const char& gender) :
	firstName_{ firstName },
	surname_{ surname },
	secondName_{ secondName },
	birthDate_ {birthDate},
	gender_{ gender } {}

string& Person::getFirstName()
{
	return firstName_;
}

string& Person::getSurname()
{
	return surname_;
}

string& Person::getSecondName()
{
	return secondName_;
}

string& Person::getBirthDate()
{
	return birthDate_;
}

char& Person::getGender()
{
	return gender_;
}

void Person::setFirstName(const string newFirstName)
{
	firstName_ = newFirstName;
}

void Person::setSurname(const string newSurname)
{
	surname_ = newSurname;
}

void Person::setSecondName(const string newSecondName)
{
	secondName_ = newSecondName;
}

void Person::setGender(const char newGender)
{
	gender_ = newGender;
}

// INTERNAL CLASS BUILDER 

Person::Builder& Person::Builder::setFirstName(const string& firstName)
{
	firstName_ = firstName;
		
	return *this;
}

Person::Builder& Person::Builder::setSurname(const string& surname)
{
	surname_ = surname;

	return *this;
}

Person::Builder& Person::Builder::setSecondName(const string& secondName)
{
	secondName_ = secondName;

	return *this;
}

Person::Builder& Person::Builder::setBirthDate(const int& year, const int& month, const int& day)
{
	birthDate_ = *_getDateStr(year, month, day);

	return *this;
}

Person::Builder& Person::Builder::setGender(const char& gender)
{
	gender_ = gender;

	return *this;
}

// INTERNAL METHOD FOR CAST tm DATE INTO STRING
string* Person::Builder::_getDateStr(const int& year, const int& month, const int& day) const
{
	tm* birthDate = new tm();
	birthDate->tm_year = year - 1900;
	birthDate->tm_mon = month - 1;
	birthDate->tm_mday = day;

	char* buffer = new char[80];
	strftime(buffer, 80, "%Y-%m-%d", birthDate);

	delete birthDate;

	return new string(buffer);
}

Person* Person::Builder::build() const
{
	return new Person(firstName_, surname_, secondName_, birthDate_, gender_);
}

