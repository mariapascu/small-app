#pragma once
#include "Controller.h"

class UI
{
private:
    Controller ctrl;
public:
    //constructor - creates a new UI
    UI(const Controller& c) : ctrl{ c } {}

    void run();
private:
    static void printMenu();
    static void printAdminMenu();
    static void printUserMenu();

    void addMovieToRepo();
    void updateMovieInRepo();
    void removeMovieFromRepo();

    std::vector<Movie> displayMoviesByGenre();
    void displayMoviesRepo();
    void displayWatchlist();
    int deleteFromWatchlist();

    void saveWatchlistToFile();

    void displayMoviesDurationRepo();
};

