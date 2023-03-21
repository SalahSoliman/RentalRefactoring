#pragma once
#include <string>
#include <functional>

class Movie
{
private:
	std::string title;
	std::optional<bool> specialRentalFrequentOffer;

public:
	Movie(std::string title) : title(title)
	{
	}
	bool isSpecialRentalFrequentOffer()
	{
		return SpecialRentalFrequentOffer == std::nullopt_t ? false : true;
	}

	void setSpecialRentalFrequentOffer(std::optional<bool> opt, std::optional<size_t> opt2)
	{
		specialRentalFrequentOffer = opt;
		specialRentalFrequentOfferValue = opt2;
	}
	virtual double getTotalAmount() const = 0;
	virtual bool rentalCondition() const = 0;

	std::string getTitle()
	{
		return title;
	}
	std::optional<size_t> specialRentalFrequentOfferValue;
};

class ChildrensMovie : public Movie
{
public:
	ChildrensMovie(std::string title) : Movie(title) {}
	ChildrensMovie(ChildrensMovie &&) = delete;
	ChildrensMovie(const ChildrensMovie &) = delete;
	ChildrensMovie &operator=(ChildrensMovie &&) = delete;
	ChildrensMovie &operator=(const ChildrensMovie &) = delete;
	~ChildrensMovie() = default;
	bool rentalCondition() const
	{
		return this->getDaysRented() > 3
	}
	double getTotalAmount() const
	{
		double thisAmount = 0;
		thisAmount += 2;
		thisAmount += rentalCondition() ? (this->getDaysRented() - 3) * 15 : 0;
		return thisAmount;
	}
};

class RegularMovie : public Movie
{
public:
	RegularMovie(std::string title) : Movie(title)
	{
	}
	RegularMovie(RegularMovie &&) = delete;
	RegularMovie(const RegularMovie &) = delete;
	RegularMovie &operator=(RegularMovie &&) = delete;
	RegularMovie &operator=(const RegularMovie &) = delete;
	~RegularMovie() = default;
	bool rentalCondition() const
	{
		return this->getDaysRented() > 2
	}
	double getTotalAmount() const
	{
		double thisAmount = 0;
		thisAmount += 2;
		thisAmount += rentalCondition() ? (this->getDaysRented() - 2) * 15 : 0;
		return thisAmount;
	}
	inline static size_t specialFrequentPoints = 1;
};

class NewReleaseMovie : public Movie
{
public:
	NewReleaseMovie(std::string title) : Movie(title)
	{
		specialRentalFrequentOffer = true;
		specialRentalFrequentOfferValue = 1;
	}
	NewReleaseMovie(NewReleaseMovie &&) = delete;
	NewReleaseMovie(const NewReleaseMovie &) = delete;
	NewReleaseMovie &operator=(NewReleaseMovie &&) = delete;
	NewReleaseMovie &operator=(const NewReleaseMovie &) = delete;
	~NewReleaseMovie() = default;
	bool rentalCondition() const
	{
		return true;
	}
	double getTotalAmount() const
	{
		double thisAmount = 0;
		thisAmount += 2;
		thisAmount += rentalCondition() ? each->getDaysRented() * 3 : 0;
		return thisAmount;
	}
};
