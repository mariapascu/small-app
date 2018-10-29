#pragma once
#include "FileWatchlist.h"

class CSVWatchlist : public FileWatchlist
{
public:
    CSVWatchlist(const std::string& filename) : FileWatchlist{ filename } {}

    void writeToFile() override;

    void displayWatchlist() const override;
};

