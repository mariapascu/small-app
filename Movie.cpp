#include "Movie.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <shellapi.h>

Movie::Movie() : title(""), genre(""), yearOfRelease(0), nrOfLikes(0), trailer(""), duration(0) {}

Movie::Movie(const Movie& m) {
    this->title = m.title;
    this->genre = m.genre;
    this->yearOfRelease = m.yearOfRelease;
    this->nrOfLikes = m.nrOfLikes;
    this->trailer = m.trailer;
    this->duration = m.duration;
}

Movie& Movie::operator = (const Movie& m) {
    this->title = m.title;
    this->genre = m.genre;
    this->yearOfRelease = m.yearOfRelease;
    this->nrOfLikes = m.nrOfLikes;
    this->trailer = m.trailer;
    this->duration = m.duration;
    return *this;
}

Movie::Movie(const std::string& title, const std::string& genre, const int yearOfRelease, const int nrOfLikes, const std::string& trailer, int duration) {
    this->title = title;
    this->genre = genre;
    this->yearOfRelease = yearOfRelease;
    this->nrOfLikes = nrOfLikes;
    this->trailer = trailer;
    this->duration = duration;
}

bool Movie::equalMovies(const Movie& m) {
    if (this->title == m.title && this->yearOfRelease == m.yearOfRelease)
        return true;
    return false;
}

void Movie::play() {
    //ShellExecuteA(NULL, NULL, "chrome.exe", this->trailer.c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::vector<std::string> Movie::tokenize(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

std::istream& operator >> (std::istream& is, Movie & m) {
    std::string line;
    getline(is, line);
    std::vector<std::string> tokens = Movie::tokenize(line, ',');
    if (tokens.size() != 6) // make sure all the song data was valid
        return is;

    m.title = tokens[0];
    m.genre = tokens[1];
    m.yearOfRelease = stoi(tokens[2]);
    m.nrOfLikes = stoi(tokens[3]);
    m.trailer = tokens[4];
    m.duration = stoi(tokens[5]);
    return is;

}

std::ostream& operator << (std::ostream& os, const Movie & m) {
    os << m.getTitle() << ',' << m.getGenre() << ',' << m.getYearOfRelease() << ',' << m.getNrOfLikes() << " likes," << m.getTrailer() << "," << m.getDuration() << " minutes";
    return os;
}