#include "address_book.pb.h"
#include <iostream>
#include <fstream>

void listPeople(const tutorial::AddressBook& address_book) {
	for (int i = 0; i < address_book.people_size(); i++) {
		const tutorial::Person& person = address_book.people(i);

		std::cout << "Person ID: " << person.id() << std::endl;
		std::cout << "Name: " << person.name() << std::endl;

		for (int j = 0; j < person.phones_size(); j++) {
			const tutorial::Person::PhoneNumber& phone_number = person.phones(j);

			switch (phone_number.type()) {
			case tutorial::Person::MOBILE:
				std::cout << "  Mobile phone #: ";
				break;
			case tutorial::Person::HOME:
				std::cout << "  Home phone #: ";
				break;
			case tutorial::Person::WORK:
				std::cout << "  Work phone #: ";
				break;
			}
			std::cout << phone_number.number() << std::endl;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE\n";
		return -1;
	}

	tutorial::AddressBook address_book;
	std::fstream input(argv[1], std::ios::in | std::ios::binary);
	if (!address_book.ParseFromIstream(&input)) {
		std::cerr << "Failed to parse address book.\n";
		return -1;
	}

	listPeople(address_book);

	return 0;
}
