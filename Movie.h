#pragma once
#include <string>
#include <iostream>
#include <vector>

class Movie
{
private:
    std::string title;
    std::string genre;
    int yearOfRelease;
    int nrOfLikes;
    std::string trailer;
    int duration;

public:
    //default constructor
    Movie();

    //constructor with parameters
    Movie(const std::string& title, const std::string& genre, const int yearOfRelease, const int nrOfLikes, const std::string& trailer, int duration);
    Movie(const Movie& m);
    Movie& operator = (const Movie& m);
    //getters
    std::string getTitle() const { return this->title; }
    std::string getGenre() const { return this->genre; }
    int getYearOfRelease() const { return this->yearOfRelease; }
    int getNrOfLikes() const { return this->nrOfLikes; }
    std::string getTrailer() const { return this->trailer; }
    int getDuration() const { return this->duration; }


    /*	Checks if 2 movies are identical. Two movies are identical if they have the same title and year of release.
    Input: m1, m2 - Movies
    Output: true - if the movies are identical
    false - otherwise
    */
    bool equalMovies(const Movie& m);

    void play();

    bool operator < (int duration) const { return this->duration < duration; };

    friend std::istream& operator >> (std::istream& is, Movie & m);

    friend std::ostream& operator << (std::ostream& os, const Movie & m);
private:
    static std::vector<std::string> tokenize(const std::string& str, char delimiter);
};

