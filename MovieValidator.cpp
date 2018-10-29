#include "MovieValidator.h"

std::vector<std::string> MovieException::getErrors() const {
    return this->errors;
}

void MovieValidator::validate(const Movie & m) {
    std::vector<std::string> errors;
    if (m.getTitle().size() < 2)
        errors.push_back("The title name cannot be less than 2 characters!\n");
    if (m.getGenre().size() < 3)
        errors.push_back("The genre cannot be less than 3 characters!\n");
    if (m.getDuration() == 0)
        errors.push_back("The duration cannot be 0!\n");

    // search for "www" or "http" at the beginning of the source string
    size_t posWww = m.getTrailer().find("www");
    size_t posHttp = m.getTrailer().find("http");
    if (posWww != 0 && posHttp != 0)
        errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

    if (errors.size() > 0)
        throw MovieException(errors);
}

