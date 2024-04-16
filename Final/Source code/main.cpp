#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Movie{
    private:
        int movieCode;
        string movieName;
        string director;
        float duration;
        float baseTicketPrice;
    public:
        Movie(int code, const string& name, const string& dir, float dur, float price) : movieCode(code), movieName(name), director(dir), duration(dur), baseTicketPrice(price){}
        int getMovieCode() const{ 
            return movieCode; 
        }
        string getMovieName() const{ 
            return movieName; 
        }
        string getDirector() const{ 
            return director; 
        }
        float getDuration() const{ 
            return duration; 
        }
        float getBaseTicketPrice() const{ 
            return baseTicketPrice; 
        }
};

class Customer{
    private:
        int customerCode;
        string customerName;
        string phoneNumber;
    public:
        Customer(int code, const string& name, const string& phone) : customerCode(code), customerName(name), phoneNumber(phone){}
        int getCustomerCode() const{ 
            return customerCode; 
        }
        string getCustomerName() const{ 
            return customerName; 
        }
        string getPhoneNumber() const{ 
            return phoneNumber; 
        }
};

class Ticket{
    private:
        int ticketCode;
        Movie* movie;
        Customer* customer;
        int seatNumber;
        string showDateTime;
        float ticketPrice;
        string typeTicket;
        string typePeople;
    public:
        Ticket(int code, Movie* m, Customer* c, int seat, const string& dateTime, float price) : ticketCode(code), movie(m), customer(c), seatNumber(seat), showDateTime(dateTime), ticketPrice(price){}
        ~Ticket(){
            if(movie){
                movie = nullptr;
                delete movie;
            }
            if(customer){
                customer = nullptr;
                delete customer;
            }
        }
        int getTicketCode() const{ 
            return ticketCode; 
        }
        const Movie* getMovie() const{ 
            return movie; 
        }
        const Customer* getCustomer() const{ 
            return customer; 
        }
        int getSeatNumber() const{ 
            return seatNumber; 
        }
        string getShowDateTime() const{ 
            return showDateTime; 
        }
        float getTicketPrice() const{ 
            return ticketPrice; 
        }

        void printTicketInfo() const{
            cout << "Ticket Code: " << ticketCode << endl;
            cout << "Movie: " << movie -> getMovieName() << endl;
            cout << "Customer: " << customer -> getCustomerName() << endl;
            cout << "Seat Number: " << seatNumber << endl;
            cout << "Show Date and Time: " << showDateTime << endl;
            cout << "Ticket Price: $" << fixed << setprecision(2) << ticketPrice << endl << endl;
        }
};

class TicketManager{
    private:
        vector<Ticket> tickets;
        static int ticketCount;
    public:
        TicketManager(){}
        Ticket sellTicket(Movie* movie, Customer* customer, int seat, const string& dateTime, const string& typeTicket, const string& typePeople);
        const Ticket* findTicketByCode(int code) const;
        float calculateTotalRevenue() const;
        static int getNextTicketCode(){ 
            return ++ticketCount; 
        }
};

int TicketManager::ticketCount = 0;

Ticket TicketManager::sellTicket(Movie* movie, Customer* customer, int seat, const string& dateTime, const string& typeTicket, const string& typePeople){
    float ticketPrice = 0.0;

    if (typeTicket == "CT") // Cuối tuần
        ticketPrice = movie -> getBaseTicketPrice() * 1.3;
    else if (typeTicket == "D") // Vé ban đêm (Trong tuần)
        ticketPrice = movie -> getBaseTicketPrice() * 1.1;
    else if (typeTicket == "S") // Vé ban ngày (Trong tuần)
        ticketPrice = (movie -> getBaseTicketPrice() * 1.1) * 0.7; 
    else // Default
        ticketPrice = movie -> getBaseTicketPrice();

    if(typePeople == "Student")
        ticketPrice *= 0.7;
    else if(typePeople == "VIP")
        ticketPrice *= 0.85;

    Ticket newTicket(getNextTicketCode(), movie, customer, seat, dateTime, ticketPrice);
    tickets.push_back(newTicket);
    return newTicket;
}

const Ticket* TicketManager::findTicketByCode(int code) const{
    for (int i = 0; i < tickets.size(); i++)
        if (tickets[i].getTicketCode() == code)
            return &tickets[i];

    return nullptr;
}

float TicketManager::calculateTotalRevenue() const{
    float totalRevenue = 0.0;
    for (int i = 0; i < tickets.size(); i++)
        totalRevenue += tickets[i].getTicketPrice();
    return totalRevenue;
}

int main(){
    Movie movie1(1, "Inception", "Christopher Nolan", 2.5, 10.0);
    Movie movie2(2, "The Dark Knight", "Christopher Nolan", 2.75, 12.0);

    Customer customer1(101, "John Doe", "123456789");
    Customer customer2(102, "Jane Doe", "987654321");

    TicketManager ticketManager;

    Ticket ticket1 = ticketManager.sellTicket(&movie1, &customer1, 1, "18h 25/12/2023", "D", "Normal");
    Ticket ticket2 = ticketManager.sellTicket(&movie2, &customer2, 2, "20h 25/12/2023", "D", "Normal");

    cout << "Ticket Information:" << endl;
    cout << "----------------------------------------" << endl;
    ticket1.printTicketInfo();
    cout << "----------------------------------------" << endl;
    ticket2.printTicketInfo();
    cout << "----------------------------------------" << endl;

    const Ticket* foundTicket = ticketManager.findTicketByCode(ticket1.getTicketCode());
    
    if (foundTicket){
        cout << "Found Ticket Information by Code: " << ticket1.getTicketCode() << endl;
        cout << "----------------------------------------" << endl;
        foundTicket -> printTicketInfo();
        cout << "----------------------------------------" << endl;
    } 
    else
        cout << "Ticket not found!" << endl;

    float totalRevenue = ticketManager.calculateTotalRevenue();
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << "" << endl;

    Movie movie3(3, "Attack On Titan", "Mappa", 3.0, 15.0);
    Movie movie4(4, "One piece", "Oda", 3.5, 16.0);

    Customer customer3(103, "Binz", "772136644");
    Customer customer4(104, "Big Daddy", "187305273");

    Ticket discountedTicketStudent = ticketManager.sellTicket(&movie3, &customer3, 3, "14h 25/12/2023", "CT", "Student");
    Ticket discountedTicketVIP = ticketManager.sellTicket(&movie4, &customer4, 4, "10h 25/12/2023", "S", "VIP");

    cout << endl << endl << "Discounted Ticket Information:" << endl;
    cout << "----------------------------------------" << endl;
    discountedTicketStudent.printTicketInfo();
    cout << "----------------------------------------" << endl;
    discountedTicketVIP.printTicketInfo();
    cout << "----------------------------------------" << endl;

    cout << "Updated Ticket Information:" << endl;
    cout << "----------------------------------------" << endl;
    ticket1.printTicketInfo();
    cout << "----------------------------------------" << endl;
    ticket2.printTicketInfo();
    cout << "----------------------------------------" << endl;
    discountedTicketStudent.printTicketInfo();
    cout << "----------------------------------------" << endl;
    discountedTicketVIP.printTicketInfo();
    cout << "----------------------------------------" << endl;

    float totalRevenue2 = ticketManager.calculateTotalRevenue();
    cout << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue2 << "" << endl;
    return 0;
}