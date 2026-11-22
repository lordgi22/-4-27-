#include <list>
#include "Book.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

int main() {
    int count;
    std::ifstream input("C:/Users/forti/OneDrive/Desktop/test111.txt");
    if (!input.is_open()) {
        std::cout << "File is not found" << '\n';
        return 1;
    }
    input >> count;
    if (!input || count < 0) {
        std::cout << "Invalid book count" << '\n';
        return 1;
    }
    std::string author;
    std::string title;
    std::string publisher;
    int year;
    int pages;
    std::list<Book> books;
    input.ignore();
    for (int j = 0; j < count; j++) {
        std::getline(input, author);
        std::getline(input, title);
        std::getline(input, publisher);
        input >> year;
        input >> pages;
        input.ignore();
        Book b(author, title, publisher, year, pages);
        books.push_back(b);
    }
    std::ofstream output("C:/Users/forti/OneDrive/Desktop/output1.txt");
    if (!output.is_open()) {
        std::cout << "Cannot open output.txt" << '\n';
        return 1;
    }
    // Записываем исходный список
    output << "Original list:" << '\n';
    for (auto it = books.begin(); it != books.end(); ++it) {
        output << *it << '\n';
    }
    // Сортируем список
    books.sort();
    // Записываем отсортированный список
    output << "Sorted list:" << '\n';
    for (auto it = books.begin(); it != books.end(); ++it) {
        output << *it << '\n';
    }
    for (auto it = books.begin(); it != books.end(); ++it) {
        std::cout << *it << '\n';
    }
    // Копируем список в вектор
    std::vector<Book> copiedBooks;
    std::copy(books.begin(), books.end(), std::back_inserter(copiedBooks));
    for (std::size_t i = 0; i < copiedBooks.size(); i++) {
        std::cout << copiedBooks[i] << '\n';
    }
    // Записываем вектор
    output << "Copied vector:" << '\n';
    for (std::size_t i = 0; i < copiedBooks.size(); i++) {
        output << copiedBooks[i] << '\n';
    }
    if (!output) {
        std::cout << "Error writing output.txt" << '\n';
        return 1;
    }
    std::cout << "Done!" << '\n';
    return 0;
}
