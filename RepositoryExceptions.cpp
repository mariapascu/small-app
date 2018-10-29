#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
    return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char * RepositoryException::what()
{
    return this->message.c_str();
}

const char * DuplicateMovieException::what()
{
    return "There is another movie with the same title and year of release!";
}

const char * NoMovieException::what()
{
    return "There is no movie to match the input!";
}