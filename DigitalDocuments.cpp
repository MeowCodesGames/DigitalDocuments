#include <iostream>
#include <C:\Users\Alexandr\source\repos\DigitalDocuments\Person.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>

using namespace std;
using namespace sql;

int main() {
	Person::Builder* builder = new Person::Builder;
	Person* man = builder->setFirstName("Alex")
		.setSurname("Guz")
		.setSecondName("Alekseevich")
		.setGender('M')
		.setBirthDate(2000, 3, 5)
		.build();

	cout << man->getFirstName() << '\n';
	cout << man->getBirthDate();

	Driver* driver;
	Connection* connection;

	driver = get_driver_instance();

	connection = driver->connect("tcp://127.0.0.1:3306", "root", "41lohafe");
	connection->setSchema("sys");

	Statement* stmt = connection->createStatement();

	stmt->execute("CREATE DATABASE IF NOT EXISTS person;");
	stmt->execute("USE person;");
	stmt->execute("CREATE TABLE IF NOT EXISTS basicInformation(id INT NOT NULL AUTO_INCREMENT, FirstName VARCHAR(30), Surname VARCHAR(30), SecondName VARCHAR(30), Gender VARCHAR(10), BirthDate DATE);");

	string* firstNameToInsert = &man->getFirstName();
	string* surnameToInsert = &man->getSurname();
	string* secondNameToInsert = &man->getSecondName();
	string* birthDateToInsert = &man->getBirthDate();
	char* genderToInsert = &man->getGender();

	stmt->execute("INSERT INTO persons(FirstName, Surname, SecondName, Gender, BirthDate) VALUES('" +
		*firstNameToInsert + "', '" + *surnameToInsert + "', '" + *secondNameToInsert +
		"', '" + *genderToInsert + "', '" + *birthDateToInsert + "');");


	return 0;
}
