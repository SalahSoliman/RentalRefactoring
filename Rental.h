#pragma once

#include "Movie.h"

class Rental
{
private:
	Movie *movie;
	size_t daysRented;

public:
	Rental(Movie *movie, size_t daysRented);
	~Rental(void);

	size_t getDaysRented(void)
	{
		return daysRented;
	}
	Movie *getMovie(void)
	{
		return &movie;
	}
};
