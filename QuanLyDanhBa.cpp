#include <bits/stdc++.h>

class Contact 
{
private:
    std::string name;
    std::string phoneNumber;
public:
    Contact(const std::string& name, const std::string& phoneNumber)
        : name(name), phoneNumber(phoneNumber) {}

    // Phuong thuc de in lien he
    void printContact() const {
        std::cout << "Ten: " << name << "\tSo dien thoai: " << phoneNumber << std::endl;
    }

    // Getter cho ten
    std::string getName() const {
        return name;
    }

    // Setter cho so dien thoai
    void setPhoneNumber(const std::string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
};

class AddressBook 
{
private:
    std::vector<Contact> contacts;
public:
    // Them lien he moi vao danh ba
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    // In tat ca cac lien he trong danh ba
    void printContacts() const {
        if (contacts.empty()) {
            std::cout << "Danh ba rong." << std::endl;
            return;
        }

        std::cout << "\nTat ca cac lien he:" << std::endl;
        for (const Contact& contact : contacts) {
            contact.printContact();
        }
    }

    // Tim kiem lien he theo ten
    Contact findContact(const std::string& name) const {
        for (const Contact& contact : contacts) {
            if (contact.getName() == name) {
                return contact;
            }
        }
        // Tra ve mot lien he rong neu khong tim thay
        return Contact("", "");
    }

    // Chuc nang de chu dong them lien he tu nguoi dung
    void addContactFromUserInput() {
        std::string name, phoneNumber;
        std::cout << "Nhap ten lien he: ";
        std::getline(std::cin, name);
        std::cout << "Nhap so dien thoai: ";
        std::getline(std::cin, phoneNumber);

        Contact newContact(name, phoneNumber);
        addContact(newContact);

        std::cout << "Lien he da duoc them thanh cong!" << std::endl;
    }

    // Chuc nang de xoa lien he tu danh ba
    void deleteContact(const std::string& name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(),
                                 [name](const Contact& contact) { return contact.getName() == name; });

        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "Lien he da duoc xoa thanh cong!" << std::endl;
        } else {
            std::cout << "Khong tim thay lien he de xoa." << std::endl;
        }
    }

    // Chuc nang de chinh sua thong tin lien he
    void editContact(const std::string& name) {
        auto it = std::find_if(contacts.begin(), contacts.end(),
                               [name](const Contact& contact) { return contact.getName() == name; });

        if (it != contacts.end()) {
            std::string newPhoneNumber;
            std::cout << "Nhap so dien thoai moi cho lien he " << name << ": ";
            std::getline(std::cin, newPhoneNumber);

            it->setPhoneNumber(newPhoneNumber);

            std::cout << "Thong tin lien he da duoc cap nhat thanh cong!" << std::endl;
        } else {
            std::cout << "Khong tim thay lien he de chinh sua." << std::endl;
        }
    }
};

int main() {
    AddressBook myAddressBook;
    int choice;

    do {
        // Hien thi
        std::cout << "\nMenu:\n";
        std::cout << "1. Them lien he\n";
        std::cout << "2. Hien thi tat ca lien he\n";
        std::cout << "3. Tim kiem lien he\n";
        std::cout << "4. Xoa lien he\n";
        std::cout << "5. Chinh sua thong tin lien he\n";
        std::cout << "6. Thoat\n";
        std::cout << "Nhap lua chon cua ban: ";
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                myAddressBook.addContactFromUserInput();
                break;
            case 2:
                myAddressBook.printContacts();
                break;
            case 3:
                {
                    std::string searchName;
                    std::cout << "\nNhap ten can tim kiem: ";
                    std::getline(std::cin, searchName);
                    Contact foundContact = myAddressBook.findContact(searchName);
                    if (foundContact.getName() != "") {
                        std::cout << "\nLien he duoc tim thay:" << std::endl;
                        foundContact.printContact();
                    } else {
                        std::cout << "\nKhong tim thay lien he." << std::endl;
                    }
                }
                break;
            case 4:
                {
                    std::string deleteName;
                    std::cout << "\nNhap ten lien he can xoa: ";
                    std::getline(std::cin, deleteName);
                    myAddressBook.deleteContact(deleteName);
                }
                break;
            case 5:
                {
                    std::string editName;
                    std::cout << "\nNhap ten lien he can chinh sua: ";
                    std::getline(std::cin, editName);
                    myAddressBook.editContact(editName);
                }
                break;
            case 6:
                std::cout << "Thoat chuong trinh. Tam biet!" << std::endl;
                break;
            default:
                std::cout << "Lua chon khong hop le. Vui long thu lai." << std::endl;
                break;
        }

    } while (choice != 6);

    return 0;
}

