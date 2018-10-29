#include "CSVWatchlist.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void CSVWatchlist::writeToFile()
{
    ofstream f(this->filename);

    if (!f.is_open())
        throw FileException("The file could not be opened!");

    for (auto m : this->watchlist)
        f << m << '\n';

    f.close();
}

void CSVWatchlist::displayWatchlist() const
{
    string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
    //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
    ShellExecuteA(NULL, NULL, "notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
