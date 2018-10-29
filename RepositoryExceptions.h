#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
    std::string message;

public:
    FileException(const std::string& msg);
    virtual const char* what();
};

class RepositoryException : public std::exception
{
protected:
    std::string message;

public:
    RepositoryException();
    RepositoryException(const std::string& msg);
    virtual ~RepositoryException() {}
    virtual const char* what();
};

class DuplicateMovieException : public RepositoryException
{
    const char* what();
};

class NoMovieException : public RepositoryException
{
    const char* what();
};