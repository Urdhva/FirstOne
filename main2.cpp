/*Make a program for managing books in a library along with its author
It must be capable of viewing a specific book and it's author, all the books, add a book and delete a book
*/

#include <iostream>     //for cin, cout
#include <string>       //for std::string
#include <array>        //for resize()
#include <vector>       //for std::vector
#include <iomanip>      //

struct book     //defines type "book"
{
    std::string name{};
    std::string author{};
};

std::vector<book> library;

void addBook()      //adds book to library
{
    book novel{};
    std::cout << "Enter the name of the book : ";
    std::cin >> std::ws;
    std::getline(std::cin, novel.name);
    std::cout << "Enter the name of the author : ";
    std::getline(std::cin, novel.author);
    library.resize(std::size(library) + 1);
    library[(std::size(library) - 1)] = novel;
    std::cout << "You have entered the book " << library[(std::size(library) - 1)].name << " by " << 
        library[(std::size(library) - 1)].author << std::endl;
}

void showLibrary()      //shows books in library
{
    for(auto element : library)
    {
        std::cout << std::left;
        std::cout << std::setw(7) << "Name" << ": " << element.name << std::endl;
        std::cout << std::setw(7) << "Author" << ": " << element.author << std::endl;
    }
}

int main()
{   
    std::cout << "Welcome to this Library program\n";
    
    bool continueProgram{true};
    char action{};

    while (continueProgram == true)
    {
        std::cout << "To view library, press 1; To add a book, press 2; To exit the program, press 3 : ";
        std::cin >> action;

        if(action == '1')
        {
            showLibrary();
        }
        else if(action == '2')
        {
            addBook();
            std::cout << "Would you like to add another book (yes/no)? ";
            std::string answer{};
            std::cin >> answer;
            while((answer == "yes") || (answer == "y"))
            {
                addBook();
                std::cout << "Do you want to add a book to the library? (yes/no) : ";
                std::cin >> answer;
            }
        }
        else if(action == '3')
        {
            continueProgram = false;
        }
        else if((action != '1') || (action =! '2') || (action != '3'))
        {
            std::cout << "You have entered an invalid action. Please try again\n";
        }

    }
    std::cout << "You have exited the program\n";
    
    return 0;
}