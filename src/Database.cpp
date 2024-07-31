#include "Database.h"

void Database::saveUsers(const std::vector<User>& users) {
    std::ofstream file("users.txt");
    for (const auto& user : users) {
        file << user.getId() << " " << user.getName() << " " << user.getPassword() << "\n";
    }
    file.close();
}

std::vector<User> Database::loadUsers() {
    std::vector<User> users;
    std::ifstream file("users.txt");
    int id;
    std::string name, password;
    while (file >> id >> name >> password) {
        users.push_back(User(id, name, password));
    }
    file.close();
    return users;
}

void Database::saveAdmins(const std::vector<Admin>& admins) {
    std::ofstream file("admins.txt");
    for (const auto& admin : admins) {
        file << admin.getId() << " " << admin.getName() << " " << admin.getPassword() << "\n";
    }
    file.close();
}

std::vector<Admin> Database::loadAdmins() {
    std::vector<Admin> admins;
    std::ifstream file("admins.txt");
    int id;
    std::string name, password;
    while (file >> id >> name >> password) {
        admins.push_back(Admin(id, name, password));
    }
    file.close();
    return admins;
}

void Database::saveBooks(const std::vector<Book>& books) {
    std::ofstream file("books.txt");
    for (const auto& book : books) {
        file << book.getId() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getYear() << " " << book.isBorrowed() << "\n";
    }
    file.close();
}

std::vector<Book> Database::loadBooks() {
    std::vector<Book> books;
    std::ifstream file("books.txt");
    int id, year;
    std::string title, author;
    bool borrowed;
    while (file >> id >> title >> author >> year >> borrowed) {
        books.push_back(Book(id, title, author, year, borrowed));
    }
    file.close();
    return books;
}
