#include "User.h"

User::User(int id, const std::string& name, const std::string& password)
    : id(id), name(name), password(password) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
bool User::checkPassword(const std::string& password) const { return this->password == password; }
void User::borrowBook(Book& book) {
    if (!book.isBorrowed()) {
        book.borrowBook();
        borrowedBooks.push_back(book);
    }
}
void User::returnBook(Book& book) {
    book.returnBook();
    borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), book), borrowedBooks.end());
}
std::vector<Book> User::getBorrowedBooks() const { return borrowedBooks; }
