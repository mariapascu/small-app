#pragma once
#include "Watchlist.h"

class FileWatchlist : public Watchlist
{
protected:
    std::string filename;
public:
    FileWatchlist(const std::string& filename);
    virtual ~FileWatchlist() {}

    virtual void writeToFile() = 0;
    virtual void displayWatchlist() const = 0;

};

