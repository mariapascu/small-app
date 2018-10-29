#include "Repository.h"
#include "Movie.h"
#include "RepositoryExceptions.h"
#include <fstream>

Repository::Repository(const std::string& filename) {
    this->filename = filename;
    this->readFromFile();
}

void Repository::addMovie(const Movie& m) {
    int index = findMovieIndex(m);
    if (index != -1)
        throw DuplicateMovieException();

    this->movies.push_back(m);
    this->writeToFile();
}

void Repository::readFromFile() {
    std::ifstream file(this->filename);

    if (!file.is_open())
        throw FileException("The file could not be opened!\n");

    Movie m;
    while (file >> m) {
        this->movies.push_back(m);
    }
    file.close();
}

int Repository::findMovieIndex(const Movie& m) {
    if (movies.size() == 0)
        return -1;

    for (unsigned int i = 0; i < this->movies.size(); i++) {
        Movie& mov = this->movies[i];
        if (m.getTitle() == mov.getTitle() && m.getYearOfRelease() == mov.getYearOfRelease())
            return i;
    }
    return -1;
}

void Repository::updateMovie(const Movie& oldM, const Movie& newM) {
    int index = findMovieIndex(oldM);
    if (index == -1)
        throw NoMovieException();

    this->movies[index] = newM;
    this->writeToFile();
}

void Repository::deleteMovie(const Movie& m) {
    int index = findMovieIndex(m);
    if (index == -1)
        throw NoMovieException();

    this->movies.erase(this->movies.begin() + index);
    this->writeToFile();
}

std::vector<Movie>& Repository::displayMovies() {
    return this->movies;
}

void Repository::writeToFile() {
    std::ofstream file(this->filename);
    if (!file.is_open())
        throw FileException("The file could not be opened!");

    for (auto m : this->movies)
    {
        file << m << std::endl;
    }

    file.close();
}