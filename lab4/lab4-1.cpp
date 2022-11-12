
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

    void input(Cargo *);
    void output(Cargo *);

    friend double kilotopound(double weightInKilo); // friend function prototype

    // == overload operator friend function prototype
    friend bool operator==(const Cargo &c1, const Cargo &c2);

}; /// end of class Cargo

// friend function definition
double kilotopound(double weightInKilos)
{
    double weightInPounds;
    weightInPounds = weightInKilos * 2.2;
    return weightInPounds;
}

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

int main()
{
    Cargo c1;      /// create Cargo object on the stack
    c1.input(&c1); // calls input function to get data from user and store in object c1
    cout << "unit 1" << endl;
    c1.output(&c1); // calls output function with the cargo object's address on the stack to display data from object c1

    Cargo c2(c1); // create a copy of object c1 and store in object c3
    cout << "unit 2" << endl;
    c2.output(&c2); // calls output function with the cargo object's address on the stack to display copied data from object c3

    Cargo c3; /// create default Cargo object on the stack
    cout << "unit 3" << endl;
    c3.output(&c3); // calls output function with the cargo object's address on the stack to display default data from object c2

    // == overload operator test
    if (c1 == c2)
    cout << "\n unit1 is the same as unit2\n" << endl;
    else
    cout << " \nunit1 is not the same as unit2\n" << endl;
    if (c2 == c3)
    cout << " \nunit2 is the same as unit3\n" << endl;
    else
    cout << " \nunit2 is not the same as unit3\n" << endl;

    return 0;
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
    char scale;
    cout << "Enter the weight scale (K for kilo, P for pound): ";
    cin >> scale; // Grabs whatever is after the numerical weight (kilograms or pounds)
    if (tolower(scale) == 'k') weight = kilotopound(wt); // If the input is in kilograms, it converts it to pounds
    else weight = wt; // If the input is in pounds, it just stores it
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
    cout << "Unit load id:   " << setw(5) << left << getabbrev() + getuldid() << endl;
    cout << "Aircraft:       " << setw(5) << left << getaircraft() << endl;
    cout << "Weight:         " << setw(4) << left << fixed << setprecision(2) << getweight() << " pounds" << endl;
    cout << "Destination:    " << setw(5) << left << getdest() << endl;
    cout << "-----------------------" << endl;
    return;
}
// input function definition
void Cargo::input(Cargo *cargoObject) /// need to input six pieces of data
{
    /// local variables for load from keyboard
    string type;
    string abrv;
    string did;
    int plane;
    double wt;
    string dest;

    cout << "Please input load information\n";

    cout << "Container or Pallet?: ";
    getline(cin, type);
    setuldtype(type);

    cout << "Please input abbreviation 3 characters: ";
    cin >> abrv;
    setabbrev(abrv);

    cout << "Please input unit load id: " << abrv;
    cin >> did;
    setuldid(did);

    cout << "Please enter aircraft type, 3 digits: ";
    cin >> plane;
    setaircraft(plane);

    cout << "Please enter weight: ";
    cin >> wt;
    setweight(wt);

    cout << "Please enter the cargo destination: ";
    cin >> dest;
    setdest(dest);
    return;
}
