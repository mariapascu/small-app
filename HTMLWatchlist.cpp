#include "HTMLWatchlist.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"

using namespace std;

void HTMLWatchlist::writeToFile()
{
    ofstream f(this->filename);

    if (!f.is_open())
        throw FileException("The file could not be opened!");
    f << "<!DOCTYPE html> \n";
    f << "<html> \n";
    f << "<head> \n";
    f << "<title>Watchlist</title> \n";
    f << "</head> \n";
    f << "<body> \n";
    f << "<table border = " <<1 <<"> \n";
    f << "<tr> \n";
    f << "<td>Title</td> \n";
    f << "<td>Genre</td> \n";
    f << "<td>Year of release</td> \n";
    f << "<td>Likes</td> \n";
    f << "<td>Trailer</td> \n";
    f << "<td>Duration</td> \n";
    f << "</tr> \n";
    for (const auto & m : this->watchlist) {
        f << "<tr> \n";
        f << "<td>" << m.getTitle() << "</td> \n";
        f << "<td>" << m.getGenre() << "</td> \n";
        f << "<td>" << m.getYearOfRelease() << "</td> \n";
        f << "<td>" << m.getNrOfLikes() << "</td> \n";
        f << "<td><a href =" << m.getTrailer() << ">Link</a></td>";
        f << "<td>" << m.getDuration() << "</td> \n";
        f << "</tr> \n";
    }
    f << "</table> \n";
    f << "</body> \n";
    f << "</html> \n";
    f.close();
}

void HTMLWatchlist::displayWatchlist() const
{
    string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
    //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
    ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
