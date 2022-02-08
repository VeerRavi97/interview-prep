#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// forward declarations
class CinemaHall;
class Movie;
class Date;
class Address;
class Audi;
class Show;
class Movies;
class Account;
class Member;
class Search;

class BMSService
{

	vector<CinemaHall> cinemas;

public:
	vector<Movie> getMovies(Date date, string city);
	vector<CinemaHall> getCinemalHalls(string city);
};
class CinemaHall
{

	int cinemaHallId;
	string cinemaHallName;

	Address address;

	vector<Audi> audiList;

public:
	unordered_map<Date, Movies> getMovies(vector<Date> dateList);
	unordered_map<Date, Show> getShows(vector<Date> dateList);
};

class Date
{
	int month;
	int day;

public:
	Date(int month, int day) : month(month), day(day){};
};

class Address
{

	int pinCode; //ZipCode
	string street;
	string city;
	string state;
	string country;
};

class Audi
{

	int audiId;
	string audiName;
	int totalSeats;
	vector<Show> shows;
};
class Show
{

	int showId;
	Movie movie;
	Date startTime;
	Date endTime;
	CinemaHall cinemaPlayedAt;
	vector<Seat> seats; // seats booked for that show
};
class Seat
{
	int seatId;
	SeatType seatType;
	SeatStatus seatStatus;
	double price;
};
enum SeatType
{

	DELUX,
	VIP,
	ECONOMY,
	OTHER,

};

enum SeatStatus
{

	BOOKED,
	AVAILABLE,
	RESERVED,
	NOT_AVAILABLE,

};

class Movie
{

	string movieName;
	int movieId;
	int durationInMins;
	string language;
	Genre genre;
	Date releaseDate;
	unordered_map<string, vector<Show>> cityShowMap;
};

enum Genre
{
	SCI_FI,
	DRAMA,
	ROM_COM,
	FANTASY,
};
class User
{

	int userId;
	Search searchObj;
};

class SystemMember : public User
{

	Account account;
	string name;
	string email;
	Address address;
};

class Member : public SystemMember
{

public:
	Booking makeBooking(Booking booking);
	vector<Booking> getBooking();
};

class Admin : public SystemMember
{

public:
	bool addMovie(Movie moivie);
	bool addShow(Show show);
};

class Account
{

	string userName;
	string password;
};

class Search
{

public:
	vector<Movie> searchMoviesByNames(string name);
	vector<Movie> searchMoviesByGenre(Genre genre);
	vector<Movie> searchMoviesByLanguage(string language);
	vector<Movie> searchMoviesByDate(Date releaseDate);
};

class Booking
{

	string bookingId;
	Date bookingDate;
	Member member;
	Audi audi;
	Show show;
	BookingStatus bookingStatus;
	double totalAmount;
	vector<Seat> seats;
	Payment paymentObj;

public:
	bool makePayment(Payment payment);
};

class Payment
{

	double amount;
	Date paymentDate;
	int transactionId;
	PaymentStatus paymentStatus;
};

enum BookingStatus
{

	REQUESTED,
	PENDING,
	CONFIRMED,
	CANCELLED,
};

enum PaymentStatus
{

	UNPAID,
	PENDING,
	COMPLETED,
	DECLINED,
	CANCELLED,
	REFUNDED,

};
