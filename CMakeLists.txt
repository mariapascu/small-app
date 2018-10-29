cmake_minimum_required(VERSION 3.9)
project(lab_9_3)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab_9_3 main.cpp Controller.cpp Controller.h CSVWatchlist.cpp CSVWatchlist.h FileWatchlist.cpp FileWatchlist.h HTMLWatchlist.cpp HTMLWatchlist.h Movie.cpp Movie.h MovieValidator.cpp MovieValidator.h Repository.cpp Repository.h RepositoryExceptions.cpp RepositoryExceptions.h UI.cpp UI.h Watchlist.cpp Watchlist.h)