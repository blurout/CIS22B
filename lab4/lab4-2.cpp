
/*
Fatih Sen

Fall 2022

Lab 3

Problem 0.3.2 & 0.3.1

Description of problem:

This object oriented program tracks the Unit Load Delivery (ULD) for airfreight companies using OOP methodology.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
class Cargo
{
private:
    string uldtype; /// unit load type, container or pallet
    string abbrev;  /// three letters AYF, PAG etc.
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
    /// constructor prototypes
    Cargo(); /// default constructor prototype, see below main for code
    Cargo(const string uldtype,
          const string abbrev,
          const string uldid,
          const int plane,
          const double weight,
          const string dest); /// full constructor

    Cargo(const Cargo &); // copy constructor prototype
    ~Cargo();             /// Destructor prototype
    /// Mutator (setters) prototypes, six needed
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdest(string);

    /// Accessor (getters) prototypes, six needed
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdest() const;

    void output(Cargo *);

    // == overload operator friend function prototype
    friend bool operator==(const Cargo &c1, const Cargo &c2);

}; /// end of class Cargo
bool operator==(const Cargo &c1, const Cargo &c2)
{
    if (c1.uldtype == c2.uldtype && c1.abbrev == c2.abbrev)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void input();

int main()
{
    /*
    calls input function to get data from file and store in object of class cargo
    uses output to print data from each line of file
    */
    input();
    return 0;
}

// input function definition
void input() /// need to input six pieces of data
{
    ifstream inputFile;
    inputFile.open("cardata4.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    Cargo temp;

    string uldtype;
    string abbrev;
    string uldid;
    int aircraft;
    double weight;
    string destination;

    string line;
    while (inputFile.peek() != EOF)
    {
        getline(inputFile, line);
        stringstream currentCargo(line);
        currentCargo >> uldtype >> abbrev >> uldid >> aircraft >> weight >> destination;
        temp.setuldtype(uldtype);
        temp.setabbrev(abbrev);
        temp.setuldid(uldid);
        temp.setaircraft(aircraft);
        temp.setweight(weight);
        temp.setdest(destination);

        temp.output(&temp);
    }

    inputFile.close();
    return;
}

/// Default constructor, six assignments needed
Cargo::Cargo()
{
    uldtype = "none";
    abbrev = "none";
    uldid = "";
    aircraft = 700;
    weight = 0;
    destination = "none";
}
/// constructor needs to take six parameters
Cargo::Cargo(const string type,
             const string abrv,
             const string did,
             const int plane,
             const double wt,
             const string dest)
{
    uldtype = type;
    abbrev = abrv;
    uldid = did;
    aircraft = plane;
    weight = wt;
    destination = dest;
}
/// copy constructor definition
Cargo::Cargo(const Cargo &origCargoObject)
{
    cout << "Copy constructor called." << endl;
    uldtype = origCargoObject.uldtype;
    abbrev = origCargoObject.abbrev;
    uldid = origCargoObject.uldid;
    aircraft = origCargoObject.aircraft;
    weight = origCargoObject.weight;
    destination = origCargoObject.destination;
}

Cargo::~Cargo() // destructor
{
    cout << "Cargo destructor called\n";
}
// Mutator (setters) definitions, six needed
void Cargo::setuldtype(string type)
{
    uldtype = type;
}
void Cargo::setabbrev(string abrv)
{
    abbrev = abrv;
}
void Cargo::setuldid(string did)
{
    uldid = did;
}
void Cargo::setaircraft(int plane)
{
    aircraft = plane;
}
void Cargo::setweight(double wt)
{
    weight = wt; // If the input is in pounds, it just stores it
}
void Cargo::setdest(string dest)
{
    destination = dest;
}
// Accessor (getters) definitions, six needed
string Cargo::getuldtype() const
{
    return uldtype;
}
string Cargo::getabbrev() const
{
    return abbrev;
}
string Cargo::getuldid() const
{
    return uldid;
}
int Cargo::getaircraft() const
{
    return aircraft;
}
double Cargo::getweight() const
{
    return weight;
}
string Cargo::getdest() const
{
    return destination;
}
// output function definition
void Cargo::output(Cargo *cargoObject) /// need to output six pieces of data
{
    cout << "Unit load type: " << setw(5) << left << getuldtype() << endl;
    cout << "Abbreviation:   " << setw(5) << left << getabbrev() << endl;
    cout << "Unit load id:   " << setw(5) << left << getuldid() << endl;
    cout << "Aircraft:       " << setw(5) << left << getaircraft() << endl;
    cout << "Weight:         " << setw(4) << left << fixed << setprecision(2) << getweight() << " pounds" << endl;
    cout << "Destination:    " << setw(5) << left << getdest() << endl;
    cout << "-----------------------" << endl;
    return;
}
