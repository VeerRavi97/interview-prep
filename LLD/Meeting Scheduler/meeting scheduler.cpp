// Design Meeting Scheduler. Here there are n given meeting rooms. Book a meeting in any meeting room at given interval(starting time, end time). Also send notifications to all person who are invited for meeting.
// You should use calender for tracking date and time. And also history of all the meetings which are booked and meeting room.
// write an API for client who will give date and time and API should return meeting room with booked scheduled time. client should also query for history of last 20 booked meetings.
// Is meeting room available? etc

#include <iostream>
#include <vector>
using namespace std;

// forward declarations
class Date;
class Attendee;
class SchedulerApp;
class Meeting;
class MeetingRoom;
class Room;
class Calender;
class EmailService;

class Time
{
public:
    int hh;
    int mm;
    Time(int hh, int mm) : hh(hh), mm(mm){};
};

class Date
{
public:
    int day;
    int month;
    Date(int day, int month) : day(day), month(month){};
};

class when
{
public:
    Time time;
    Date date;
    when(Time &time, Date &date) : time(time), date(date){};
};

class Attendee // who
{
    string name;
    string email;
    Attendee(string name, string email) : name(name), email(email){};
};

class MeetingRoom // where
{
    string name;
    string rid;

public:
    bool isAvailable(when start, when end)
    {
        return true;
    }
};

class Meeting
{
public:
    unsigned int id;
    when from;
    when to;
    MeetingRoom where;
    vector<Attendee> attendees;
    EmailService emailService;
    Meeting(MeetingRoom where, when from, when to) : from(from), to(to), where(where)
    {
        this->id = generateId();
    }
    int generateId() { return id++; };
};

class EmailService
{
public:
    EmailService() {}
    bool sendEmail(vector<Attendee> &attendees)
    {
        //  Amazon SES
    }
};

class Utility
{
public:
    static bool doesOverlap(pair<int, int> &a, pair<int, int> &b)
    {
        return (b.second > a.first || b.first < a.second);
    }
    static bool doesTimeOverlap(Meeting meeting, when from, when to)
    {
        bool sameDay = (meeting.from.date.day == to.date.day && meeting.to.date.day == to.date.day);
        bool sameMonth = (meeting.from.date.month == to.date.month && meeting.to.date.month == to.date.month);
        pair<int, int> start, end;
        start.first = meeting.from.time.hh * 60 + meeting.from.time.mm;
        start.second = meeting.to.time.hh * 60 + meeting.to.time.mm;
        end.first = from.time.hh * 60 + from.time.mm;
        end.second = to.time.hh * 60 + to.time.mm;
        return (sameMonth && sameDay && doesOverlap(start, end));
    }
};

class Calender

{
    vector<Meeting> meetings;

public:
    Calendar() {}
    bool checkAvailability(when from, when to)
    {
        for (Meeting meeting : meetings)
        {
            if (Utility::doesTimeOverlap(meeting, from, to))
                return false;
        }
        return true;
    }
    Meeting scheduleNewMeeting(when from, when to)
    {
        Meeting meeting = new Meeting(room, start, end);
        meetings.add(meeting);
        return meeting;
    }
};

class SchedulerService
{
    const int MAX_HISTORICAL_MEETING_STORAGE;
    vector<MeetingRoom> meetingRooms;
    vector<Meeting> historyOfMeetings;
    int scheduled;
    int noOfRooms;

public:
    SchedulerService(int n, int max_entries) : noOfRooms(n), MAX_HISTORICAL_MEETING_STORAGE(max_entries)
    {
        meetingRooms.reserve(noOfRooms);
        historyOfMeetings.reserve(MAX_HISTORICAL_MEETING_STORAGE);
        scheduled = 0;
    }
    Meeting book(when from, when to)
    {

        for (MeetingRoom room : meetingRooms)
        {
            if (room.isAvailable(from, to))
            {
                Meeting meeting = room.scheduleMeeting(start, end);
                saveToHistory(meeting);
                return meeting;
            }
        }
    }
    void saveToHistory(Meeting meeting)
    {
        if (historySize == MAX_HISTORICAL_MEETING_STORAGE)
        {
            history[0] = null;
            for (int i = 1; i < MAX_HISTORICAL_MEETING_STORAGE; i++)
            {
                history[i - 1] = history[i];
            }
        }

        history[historySize++] = meeting;
    }

    void invite(Meeting meeting, List<Attendee> attendees){
        meeting.invi

    };
}