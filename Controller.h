#pragma once
#include <vector>
#include "Repository.h"
#include "Watchlist.h"
#include "MovieValidator.h"
#include "CSVWatchlist.h"

class Controller
{
private:
    Repository repo;
    FileWatchlist* watchlist;
    MovieValidator validator;

public:
    //constructor - creates a new controller
    Controller(const Repository& r, FileWatchlist* p, MovieValidator v) : repo{ r }, watchlist{ p }, validator{ v } {}

    /* Adds a movie
    Input: title, genre, yearOfRelease, nrOfLikes, trailer - information about the movie
    Output: 0 - if the movie was added
    1 - otherwise
    */
    void addMovieToRepoCtrl(const std::string& title, const std::string& genre, int yearOfRelease, int nrOfLikes, const std::string& trailer, int duration);

    /*	Updates a movie
    Input: oldTitle, oldYearOfRelease - info about the movie to bee updated
    newTitle, newGenre, newOldYearOfRelease, newNrOfLikes, newTrailer - inf about the new movie
    Output: 0 - if the movie was updated
    1 - otherwise
    */
    void updateMovieInRepoCtrl(const std::string& oldTitle, int oldYearOfRelease, const std::string& newTitle, const std::string& newGenre, int newYearOfRelease, int newNrOfLikes, const std::string& newTrailer, int duration);

    /*	Deletes a movie
    Input: title, yearOfRelease - info about the movie to be deleted
    Output: 0 - if the movie was deleted
    1 - otherwise
    */
    void removeMovieFromRepoCtrl(const std::string& title, int yearOfRelease);

    std::vector<Movie>& displayMoviesRepoCtrl();

    //User mode
    std::vector<Movie> displayMoviesByGenreCtrl(const std::string& genre);
    Movie displayCurrentMovie(const std::vector<Movie>& moviesByGenre, int currentIndex);
    int nextMovieIndex(const std::vector<Movie>& moviesByGenre, int currentIndex);
    void addToWatchlist(const std::vector<Movie>& moviesByGenre, int currentIndex);
    std::vector<Movie>& getWachlistCtrl();
    int deleteFromWatchlistCtrl(const std::string& title, int yearOfRelease);

    void saveWatchlist();
    void openWatchlist();

    Repository& getRepo() { return this->repo; }
};

