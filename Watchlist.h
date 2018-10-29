#pragma once
#include <vector>
#include "Movie.h"

class Watchlist
{
protected:
    std::vector<Movie> watchlist;
public:
    void addMovie(const Movie& m);
    int deleteMovie(const Movie& m);
    int findMovieIndex(const Movie& m);
    std::vector<Movie>& getWatchlist();
};

