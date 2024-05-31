#include <cstdint>
#include <exception>
#include <string>
#include <vector>
#include <iostream>

class date {
	public:
		uint8_t day : 5;
		uint8_t month : 4;
		uint32_t year : 23;
};

class Contact {
	private:
		virtual void method(){}
	public:
		std::string name;
};

class Friend: virtual public Contact {
	public:
		date dateOfBirth;
		std::string phoneNumber;
		std::string address;
};

class Acquaintance: virtual public Contact {
	public:
		std::string phoneNumber;
};

class Colleague: virtual public Contact {
	public:
		uint32_t phoneNumber;
		std::string companyName;
		std::string address;
};

class AddressBook {
	std::vector<Contact*> contacts;
	public:
		Contact* searchByName(const std::string& name){
			for(auto x: contacts){
				if(x->name == name){
					return x;
				}
			}
			return nullptr;
		}
		std::vector<Friend*> listOfFriends(){
			std::vector<Friend*> friends;
			for(auto x: contacts){
				try {
					friends.push_back(dynamic_cast<Friend*>(x));
				} catch(const std::exception& e) {}
			}
			return friends;
		}
		void deleteByName(const std::string&name){
			for(auto x=contacts.begin(); x != contacts.end(); x++){
				if((*x)->name == name){
					contacts.erase(x);
					break;
				}
			}
		}
		void addContact(Contact* contact){
			contacts.push_back(contact);
		}

};

int main(){
	Friend robert;
	robert.name = "Robert";
	robert.dateOfBirth.day = 20;
	robert.dateOfBirth.month = 3;
	robert.dateOfBirth.year = 1999;
	robert.phoneNumber = "01234567890";
	robert.address = "some street";
	Acquaintance guy;
	guy.name = "Guy";
	guy.phoneNumber = "9876543210";
	AddressBook book;
	book.addContact(&robert);
	book.addContact(&guy);
	std::cout << dynamic_cast<Acquaintance*>(book.searchByName("Guy"))->phoneNumber;
}
