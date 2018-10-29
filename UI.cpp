#include "UI.h"
#include "MovieValidator.h"
#include "RepositoryExceptions.h"
#include <iostream>

using namespace std;

void UI::run() {
    while (true) {
        UI::printMenu();
        int command{ 0 };
        cout << "Input the command: ";
        cin >> command;
        cin.ignore();
        //Administrator mode
        if (command == 1) {
            while (true) {
                UI::printAdminMenu();
                int commandAdmin{ 0 };
                cout << "Input the command: ";
                cin >> commandAdmin;
                cin.ignore();
                if (commandAdmin == 1) {
                    this->addMovieToRepo();
                }
                else if (commandAdmin == 2) {
                    this->removeMovieFromRepo();
                }
                else if (commandAdmin == 3) {
                    this->updateMovieInRepo();
                }
                else if (commandAdmin == 4) {
                    this->displayMoviesRepo();
                }
                else if (commandAdmin == 5) {
                    this->displayMoviesDurationRepo();
                }
                else if (commandAdmin == 0) {
                    break;
                }
                else
                    cout << "Invalid command!\n";

            }
        }
            //User mode
        else if (command == 2) {
            while (true) {
                UI::printUserMenu();
                int userCommand{ 0 };
                cout << "Input the command: ";
                cin >> userCommand;
                cin.ignore();
                std::vector<Movie> moviesByGenre;
                int currentIndex{ 0 };
                while (userCommand <= 3 && userCommand >= 1) {

                    if (userCommand == 1) {
                        moviesByGenre = this->displayMoviesByGenre();
                        if (moviesByGenre.size() == 0)
                            cout << "Nothing to show! \n";
                        else {
                            Movie m = this->ctrl.displayCurrentMovie(moviesByGenre, currentIndex);
                            cout << m.getTitle() << ' ' << m.getGenre() << ' ' << m.getYearOfRelease() << ' ' << m.getNrOfLikes() << ' ' << " likes\n";
                            m.play();
                        }
                    }
                    else if (userCommand == 2) {
                        if (moviesByGenre.size() == 0)
                            cout << "Nothing to add! \n";
                        else {
                            this->ctrl.addToWatchlist(moviesByGenre, currentIndex);
                        }
                    }
                    else if (userCommand == 3) {
                        if (moviesByGenre.size() == 0)
                            cout << "Nothing to show! \n";
                        else {
                            currentIndex = this->ctrl.nextMovieIndex(moviesByGenre, currentIndex);
                            Movie m = this->ctrl.displayCurrentMovie(moviesByGenre, currentIndex);
                            cout << m.getTitle() << ' ' << m.getGenre() << ' ' << m.getYearOfRelease() << ' ' << m.getNrOfLikes() << ' ' << " likes\n";
                            m.play();
                        }

                    }
                    UI::printUserMenu();
                    cout << "Input the command: ";
                    cin >> userCommand;
                    cin.ignore();

                }
                if (userCommand == 4) {
                    int result = this->deleteFromWatchlist();
                    if (result == 0) {
                        cout << "Movie removed from watchlist.\n";
                    }
                    else
                        cout << "Movie could not be deleted. \n";
                }
                else if (userCommand == 5) {
                    this->displayWatchlist();
                }
                else if (userCommand == 6) {
                    this->saveWatchlistToFile();
                }
                else if (userCommand == 7) {
                    this->ctrl.openWatchlist();
                }
                else if (userCommand == 0) {
                    break;
                }
                else
                    cout << "Invalid command!\n";
            }
        }
        else if (command == 0) {
            cout << "Goodbye!";
            break;
        }
        else
            cout << "Invalid command!\n";
    }
}

void UI::saveWatchlistToFile() {
    try
    {
        this->ctrl.saveWatchlist();

        if (this->ctrl.getWachlistCtrl().size() == 0)
        {
            cout << "Playlist cannot be displayed!" << endl;
            return;
        }
    }
    catch (FileException& e)
    {
        cout << e.what() << endl;
    }
}

std::vector<Movie> UI::displayMoviesByGenre() {
    cout << "Enter the genre: ";
    std::string genre;
    getline(cin, genre);
    return this->ctrl.displayMoviesByGenreCtrl(genre);
}

int UI::deleteFromWatchlist() {
    cout << "Enter the title: ";
    std::string title;
    getline(cin, title);
    cout << "Enter the year of release: ";
    int yearOfRelease{ 0 };
    cin >> yearOfRelease;
    cin.ignore();

    int result = this->ctrl.deleteFromWatchlistCtrl(title, yearOfRelease);
    cout << "Would you like to give a like?(0 - yes/1 - no)";
    int option;
    cin >> option;
    cin.ignore();
    if (option == 0) {
        Movie m{ title, "", yearOfRelease, 0, "", 0 };
        int index = this->ctrl.getRepo().findMovieIndex(m);
        Movie newM = this->ctrl.getRepo().getMovies()[index];
        this->ctrl.updateMovieInRepoCtrl(m.getTitle(), m.getYearOfRelease(), newM.getTitle(), newM.getGenre(), newM.getYearOfRelease(), newM.getNrOfLikes() + 1, newM.getTrailer(), newM.getDuration());
    }

    return result;
}

void UI::removeMovieFromRepo() {
    cout << "Enter the title: ";
    std::string title;
    getline(cin, title);
    cout << "Enter the year of release: ";
    int yearOfRelease{ 0 };
    cin >> yearOfRelease;
    cin.ignore();
    try
    {
        this->ctrl.removeMovieFromRepoCtrl(title, yearOfRelease);
        cout << "Movie deleted. \n";
    }
    catch (MovieException& e)
    {
        for (const auto & s : e.getErrors())
            cout << s;
    }
    catch (RepositoryException& e)
    {
        cout << e.what() << endl;
    }
    catch (FileException& e)
    {
        cout << e.what() << endl;
    }
}

void UI::updateMovieInRepo() {
    //old movie
    cout << "Enter the old title: ";
    std::string oldTitle;
    getline(cin, oldTitle);
    cout << "Enter the year of release: ";
    int oldYearOfRelease{ 0 };
    cin >> oldYearOfRelease;
    cin.ignore();

    //new movie
    cout << "Enter the new title: ";
    std::string newTitle;
    getline(cin, newTitle);
    cout << "Enter the new genre: ";
    std::string newGenre;
    getline(cin, newGenre);
    cout << "Enter the new year of release: ";
    int newYearOfRelease{ 0 };
    cin >> newYearOfRelease;
    cin.ignore();
    cout << "Enter the new number of likes: ";
    int newNrOfLikes{ 0 };
    cin >> newNrOfLikes;
    cin.ignore();
    cout << "Enter the new trailer link: ";
    std::string newTrailer;
    getline(cin, newTrailer);
    cout << "Enter the new duration: ";
    int newDuration;
    cin >> newDuration;
    cin.ignore();
    try
    {
        this->ctrl.updateMovieInRepoCtrl(oldTitle, oldYearOfRelease, newTitle, newGenre, newYearOfRelease, newNrOfLikes, newTrailer, newDuration);
        cout << "Movi updated. \n";
    }
    catch (MovieException& e)
    {
        for (const auto & s : e.getErrors())
            cout << s;
    }
    catch (RepositoryException& e)
    {
        cout << e.what() << endl;
    }
    catch (FileException& e)
    {
        cout << e.what() << endl;
    }
}

void UI::addMovieToRepo() {
    cout << "Enter the title: ";
    std::string title;
    getline(cin, title);
    cout << "Enter the genre: ";
    std::string genre;
    getline(cin, genre);
    cout << "Enter the year of release: ";
    int yearOfRelease{ 0 };
    cin >> yearOfRelease;
    cin.ignore();
    cout << "Enter the number of likes: ";
    int nrOfLikes{ 0 };
    cin >> nrOfLikes;
    cin.ignore();
    cout << "Enter the trailer link: ";
    std::string trailer;
    getline(cin, trailer);
    cout << "Enter the duration: ";
    int duration;
    cin >> duration;
    cin.ignore();
    try
    {
        this->ctrl.addMovieToRepoCtrl(title, genre, yearOfRelease, nrOfLikes, trailer, duration);
        cout << "Movie added.\n";
    }
    catch (MovieException& e)
    {
        for (const auto & s : e.getErrors())
            cout << s;
    }
    catch (RepositoryException& e)
    {
        cout << e.what() << endl;
    }
    catch (FileException& e)
    {
        cout << e.what() << endl;
    }
}

void UI::displayMoviesRepo() {
    std::vector<Movie>& v = this->ctrl.displayMoviesRepoCtrl();
    for (const auto & m : v) {
        cout << m << endl;
    }
}

void UI::displayMoviesDurationRepo() {
    int duration{ 0 };
    cout << "Enter the duration: ";
    cin >> duration;
    cin.ignore();
    std::vector<Movie>& v = this->ctrl.displayMoviesRepoCtrl();
    for (const auto & m : v) {
        if (m < duration)
            cout << m << endl;
    }
}

void UI::displayWatchlist() {
    std::vector<Movie>& watchlist = this->ctrl.getWachlistCtrl();
    for (const auto & m : watchlist) {
        cout << m << endl;
    }

}

void UI::printMenu() {
    cout << "1 - Administrator mode. \n";
    cout << "2 - User mode. \n";
    cout << "0 - Exit. \n";
}

void UI::printAdminMenu() {
    cout << "1 - Add a movie. \n";
    cout << "2 - Delete a movie. \n";
    cout << "3 - Update a movie. \n";
    cout << "4 - Display the movies. \n";
    cout << "5 - Display the movies with the duration less than a given duration. \n";
    cout << "0 - Back. \n";
}

void UI::printUserMenu() {
    cout << "1 - Display the movies with a given genre. \n";
    cout << "2 - Add the current movie to the watchlist. \n";
    cout << "3 - Display the next movie. \n";
    cout << "4 - Delete a movie from the watchlist. \n";
    cout << "5 - Display the watchlist. \n";
    cout << "6 - Save the watchlist to file. \n";
    cout << "7 - Display the watchlist in file. \n";
    cout << "0 - Back. \n";
}