#include "Book.h"

Book::Book(int id, const std::string& title, const std::string& author, int year)
    : id(id), title(title), author(author), year(year), borrowed(false) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
bool Book::isBorrowed() const { return borrowed; }
void Book::borrowBook() { borrowed = true; }
void Book::returnBook() { borrowed = false; }
