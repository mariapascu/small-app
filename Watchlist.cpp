#include "Watchlist.h"

void Watchlist::addMovie(const Movie& m) {
    this->watchlist.push_back(m);
}

int Watchlist::deleteMovie(const Movie& m) {
    int index = findMovieIndex(m);
    if (index == -1) return 1;

    this->watchlist.erase(this->watchlist.begin() + index);
    return 0;
}

int Watchlist::findMovieIndex(const Movie& m) {
    if (this->watchlist.size() == 0)
        return -1;

    for (unsigned int i = 0; i < this->watchlist.size(); i++) {
        Movie& mov = this->watchlist[i];
        if (m.getTitle() == mov.getTitle() && m.getYearOfRelease() == mov.getYearOfRelease())
            return i;
    }
    return -1;
}

std::vector<Movie>& Watchlist::getWatchlist() {
    return this->watchlist;
}
