#include <iostream>
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    int year;

public:
    Book(const std::string& _title, const std::string& _author, int _year) : title(_title), author(_author), year(_year) {
    }

    virtual ~Book() {
    }

    virtual void displayInfo() = 0; // Абстрактний метод
};

class FictionBook : public Book {
private:
    std::string genre;

public:
    FictionBook(const std::string& _title, const std::string& _author, int _year, const std::string& _genre)
        : Book(_title, _author, _year), genre(_genre) {
    }

    void displayInfo() override {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Genre: " << genre << " (Fiction)" << std::endl;
    }
};

class NonFictionBook : public Book {
private:
    std::string topic;

public:
    NonFictionBook(const std::string& _title, const std::string& _author, int _year, const std::string& _topic)
        : Book(_title, _author, _year), topic(_topic) {
    }

    void displayInfo() override {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Topic: " << topic << " (Non-Fiction)" << std::endl;
    }
};

int main() {
    Book* books[2];

    books[0] = new FictionBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Classic");
    books[1] = new NonFictionBook("Sapiens", "Yuval Noah Harari", 2014, "History");

    for (int i = 0; i < 2; i++) {
        books[i]->displayInfo();
        delete books[i];
        std::cout << std::endl;
    }

    return 0;
}
