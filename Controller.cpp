#include "Controller.h"
#include <iostream>

void Controller::addMovieToRepoCtrl(const std::string& title, const std::string& genre, int yearOfRelease, int nrOfLikes, const std::string& trailer, int duration) {
    Movie m{ title, genre, yearOfRelease, nrOfLikes, trailer, duration };
    this->validator.validate(m);
    this->repo.addMovie(m);
}

void Controller::updateMovieInRepoCtrl(const std::string& oldTitle, int oldYearOfRelease, const std::string& newTitle, const std::string& newGenre, int newYearOfRelease, int newNrOfLikes, const std::string& newTrailer, int newDuration) {
    Movie oldM{ oldTitle, "", oldYearOfRelease, 0, "", 0 };
    Movie newM{ newTitle, newGenre, newYearOfRelease, newNrOfLikes, newTrailer, newDuration };
    this->validator.validate(newM);
    this->repo.updateMovie(oldM, newM);
}

void Controller::removeMovieFromRepoCtrl(const std::string& title, int yearOfRelease) {
    Movie m{ title, "", yearOfRelease, 0, "", 0 };

    this->repo.deleteMovie(m);
}

Movie Controller::displayCurrentMovie(const std::vector<Movie>& moviesByGenre, int currentIndex) {
    return moviesByGenre[currentIndex];
}

std::vector<Movie>& Controller::displayMoviesRepoCtrl() {
    return this->repo.displayMovies();
}

std::vector<Movie> Controller::displayMoviesByGenreCtrl(const std::string& genre) {
    std::vector<Movie> moviesByGenre;
    std::vector<Movie> moviesRepo = this->repo.displayMovies();
    for (unsigned int i = 0; i < moviesRepo.size(); i++)
        if (moviesRepo[i].getGenre() == genre)
            moviesByGenre.push_back(moviesRepo[i]);
    return moviesByGenre;
}

int Controller::nextMovieIndex(const std::vector<Movie>& moviesByGenre, int currentIndex) {
    if (currentIndex == moviesByGenre.size() - 1) return 0;
    return currentIndex + 1;
}

void Controller::addToWatchlist(const std::vector<Movie>& moviesByGenre, int currentIndex) {
    Movie m = moviesByGenre[currentIndex];
    this->watchlist->addMovie(m);
}

std::vector<Movie>& Controller::getWachlistCtrl() {
    return this->watchlist->getWatchlist();
}

int Controller::deleteFromWatchlistCtrl(const std::string& title, int yearOfRelease) {
    Movie m{ title, "", yearOfRelease, 0, "", 0 };

    int result = this->watchlist->deleteMovie(m);
    return result;
}

void Controller::saveWatchlist() {
    if (this->watchlist == nullptr)
        return;
    this->watchlist->writeToFile();

}

void Controller::openWatchlist() {
    if (this->watchlist == nullptr)
        return;
    this->watchlist->displayWatchlist();
}