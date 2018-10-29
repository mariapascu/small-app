#pragma once
#include "FileWatchlist.h"

class HTMLWatchlist : public FileWatchlist
{
public:
    HTMLWatchlist(const std::string& filename) : FileWatchlist{ filename } {}

    void writeToFile() override;

    void displayWatchlist() const override;
};

