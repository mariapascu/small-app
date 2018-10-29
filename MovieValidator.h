#pragma once
#include "Movie.h"
#include <vector>
#include <string>

class MovieException
{
private:
    std::vector<std::string> errors;
public:
    MovieException(const std::vector<std::string>& _errors) : errors{ _errors } {}
    std::vector<std::string> getErrors() const;
};

class MovieValidator
{
public:
    MovieValidator() {}
    static void validate(const Movie & m);
};

