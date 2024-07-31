#include <iostream>
#include "Library.h"
#include "Database.h"

void userMenu(Library& library, User& user);
void adminMenu(Library& library, Admin& admin);

int main() {
    Library library;

    // Load data from database
    library.getUsers() = Database::loadUsers();
    library.getBooks() = Database::loadBooks();

    int choice;
    std::cout << "Welcome to the Library Management System\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Admin Login\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 1) {
        std::string name, password;
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Enter your password: ";
        std::cin >> password;
        library.registerUser(name, password);
    } else if (choice == 2) {
        std::string name, password;
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Enter your password: ";
        std::cin >> password;
        User* user = library.loginUser(name, password);
        if (user) {
            userMenu(library, *user);
        } else {
            std::cout << "Invalid credentials\n";
        }
    } else if (choice == 3) {
        std::string name, password;
        std::cout << "Enter admin name: ";
        std::cin >> name;
        std::cout << "Enter admin password: ";
        std::cin >> password;
        Admin* admin = library.loginAdmin(name, password);
        if (admin) {
            adminMenu(library, *admin);
        } else {
            std::cout << "Invalid credentials\n";
        }
    } else if (choice == 4) {
        // Save data to database
        Database::saveUsers(library.getUsers());
        Database::saveBooks(library.getBooks());
        std::cout << "Exiting...\n";
        return 0;
    } else {
        std::cout << "Invalid choice\n";
    }

    return 0;
}

void userMenu(Library& library, User& user) {
    int choice;
    do {
        std::cout << "User Menu\n";
        std::cout << "1. View Books\n";
        std::cout << "2. Borrow Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            for (const auto& book : library.getBooks()) {
                std::cout << book.getId() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getYear() << " " << (book.isBorrowed() ? "Borrowed" : "Available") << "\n";
            }
        } else if (choice == 2) {
            int bookId;
            std::cout << "Enter book ID: ";
            std::cin >> bookId;
            for (auto& book : library.getBooks()) {
                if (book.getId() == bookId) {
                    user.borrowBook(book);
                    std::cout << "Book borrowed\n";
                }
            }
        } else if (choice == 3) {
            int bookId;
            std::cout << "Enter book ID: ";
            std::cin >> bookId;
            for (auto& book : library.getBooks()) {
                if (book.getId() == bookId) {
                    user.returnBook(book);
                    std::cout << "Book returned\n";
                }
            }
        }
    } while (choice != 4);
}

void adminMenu(Library& library, Admin& admin) {
    int choice;
    do {
        std::cout << "Admin Menu\n";
        std::cout << "1. View Books\n";
        std::cout << "2. Add Book\n";
        std::cout << "3. Remove Book\n";
        std::cout << "4. View Users\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            for (const auto& book : library.getBooks()) {
                std::cout << book.getId() << " " << book.getTitle() << " " << book.getAuthor() << " " << book.getYear() << " " << (book.isBorrowed() ? "Borrowed" : "Available") << "\n";
            }
        } else if (choice == 2) {
            int id, year;
            std::string title, author;
            std::cout << "Enter book ID: ";
            std::cin >> id;
            std::cout << "Enter book title: ";
            std::cin >> title;
            std::cout << "Enter book author: ";
            std::cin >> author;
            std::cout << "Enter book year: ";
            std::cin >> year;
            admin.addBook(Book(id, title, author, year));
            std::cout << "Book added\n";
        } else if (choice == 3) {
            int bookId;
            std::cout << "Enter book ID: ";
            std::cin >> bookId;
            for (auto& book : library.getBooks()) {
                if (book.getId() == bookId) {
                    admin.removeBook(book);
                    std::cout << "Book removed\n";
                }
            }
        } else if (choice == 4) {
            for (const auto& user : library.getUsers()) {
                std::cout << user.getId() << " " << user.getName() << "\n";
            }
        }
    } while (choice != 5);
}
