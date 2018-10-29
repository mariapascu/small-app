#pragma once
#include <vector>
#include "Movie.h"

class Repository
{
private:
    std::vector<Movie> movies;
    std::string filename;
public:
    //default constructor - creates a new repository
    Repository(const std::string& filename);

    /* Adds a movie to the repository
    Input: m - Movie
    Output: 0 - if the movie was added to the repository
    1 - if the movie could not be added, because it already existed
    */
    void addMovie(const Movie& m);

    /* Finds the index of a movie in the movies vector
    Input: m - Movie
    Output: the index of the movie m, -1 if the movie m does not exist
    */
    int findMovieIndex(const Movie& m);

    /*	Updates movie oldM with the movie newM in the repository
    Input: oldM - old Movie, newM - new Movie
    Output: 0 - if the movie was updated
    1 - if the movie was not updated, because it does not exist
    */
    void updateMovie(const Movie& oldM, const Movie& newM);

    /*	Deletes a movie from the repository
    Input: m - Movie
    Output: 0 - if the movie was deleted
    1 - if the movie could not be deleted, because it does not exist
    */
    void deleteMovie(const Movie& m);

    std::vector<Movie>& displayMovies();

    std::vector<Movie> getMovies() { return this->movies; }
private:
    void readFromFile();
    void writeToFile();
};

