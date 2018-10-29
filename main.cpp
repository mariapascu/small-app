#include "UI.h"
#include <iostream>
#include <crtdbg.h>
#include "RepositoryExceptions.h"
#include "CSVWatchlist.h"
#include "HTMLWatchlist.h"

int main() {
    {
        try
        {
            Repository repo("Movies.txt");
            std::cout << "Do you want to store the watchlist in a CSV file or HTML file?(0-CSV, 1-HTML) ";
            int option{ 0 };
            std::cin >> option;
            std::cin.ignore();

            FileWatchlist* p;
            if (option == 0)
                p = new CSVWatchlist{ "Watchlist.csv" };
            else
                p = new HTMLWatchlist{"Watchlist.html"};
            Controller ctrl( repo, p, MovieValidator{} );

            UI ui{ ctrl };

            ui.run();
        }
        catch (FileException&)
        {
            std::cout << "Repository could not be opened!\n";
            system("pause");
            return 1;
        }

    }
    _CrtDumpMemoryLeaks();
    return 0;
}