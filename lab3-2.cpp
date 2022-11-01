
/*
Fatih Sen

Fall 2022

Lab 3

Problem 0.3.2

Description of problem:
 
This object oriented program tracks the Unit Load Delivery (ULD) for airfreight companies.
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Cargo{
private:
    string uldtype;  ///unit load type, container or pallet
    string abbrev;   ///three letters AYF, PAG etc.
    string uldid;
    int aircraft;
    double weight;
    string destination;
public:
    ///constructor prototypes
    Cargo();  ///default constructor prototype, see below main for code
    Cargo(const string uldtype,
          const string abbrev,
          const string uldid,
          const int plane,
          const double weight,
          const string dest);///full constructor

    Cargo(const Cargo& ); // copy constructor prototype
    ~Cargo(); ///Destructor prototype
    ///Mutator (setters) prototypes, six needed
    void setuldtype(string);
    void setabbrev (string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdest(string);

    ///Accessor (getters) prototypes, six needed
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdest() const;

    void input(Cargo *);
    void output(Cargo *);

friend double kilotopound(double weightInKilo); // friend function prototype

}; ///end of class Cargo

// friend function definition
double kilotopound(double weightInKilos) {
    double weightInPounds;
    weightInPounds = weightInKilos * 2.2;
    return weightInPounds;
}
// THATS CLEAN HOMIE

int main()
{
    Cargo c1;  ///create Cargo object on the stack
    c1.input(&c1); // calls input function to get data from user and store in object c1
    c1.output(&c1); // calls output function with the cargo object's address on the stack to display data from object c1

    Cargo c2;  ///create default Cargo object on the stack
    c2.output(&c2); // calls output function with the cargo object's address on the stack to display default data from object c2

    Cargo c3(c1); // create a copy of object c1 and store in object c3
    c3.output(&c3); // calls output function with the cargo object's address on the stack to display copied data from object c3

    return 0;
}
///Default constructor, six assignments needed
    Cargo::Cargo( )
    {
        uldtype = "none";
        abbrev = "none";
        uldid = "";
        aircraft = 700;
        weight = 0;
        destination = "none";
    }
///constructor needs to take six parameters
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
    Cargo::Cargo(const Cargo &origCargoObject) {
        cout << "Copy constructor called." << endl;
        uldtype = origCargoObject.uldtype;
        abbrev = origCargoObject.abbrev;
        uldid = origCargoObject.uldid;
        aircraft = origCargoObject.aircraft;
        weight = origCargoObject.aircraft;
        destination = origCargoObject.destination;
    }

    Cargo::~Cargo() // destructor
    {
        cout << "Cargo destructor called\n";
    }
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
        string scale;
        cin >> scale; // Grabs whatever is after the numerical weight (kilograms or pounds)
        if (scale == "Kilograms") weight = kilotopound(wt); // If the input is in kilograms, it converts it to pounds
        else weight = wt; // If the input is in pounds, it just stores it
    }
    void Cargo::setdest(string dest)
    {
        destination = dest;
    }
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
    void Cargo::output(Cargo *cargoObject)///need to output six pieces of data
    {
        cout << setw(19) << "Unit load type: " << getuldtype() << endl;
        cout << setw(19) << "Abbreviation: " << getabbrev() << endl;
        cout << setw(19) << "Unit load id: " << getabbrev() << getuldid() << endl;
        cout << setw(19) << "Aircraft: " << getaircraft() << endl;
        cout << setw(19) << "Weight: " << getweight() << endl;
        cout << setw(19) << "Destination: " << getdest() << endl;
        cout << "-----------------------" << endl;
    return;
    }
    void Cargo::input(Cargo *cargoObject) ///need to input six pieces of data
    {
///local variables for load from keyboard
        string type;
        string abrv;
        string did;
        int plane;
        double wt;
        string dest;

        cout << "Please input load information\n";

        cout << "Container or Pallet?: ";
        getline(cin,type);
        setuldtype(type);

        cout << "Please input abbreviation 3 characters: ";
        getline(cin, abrv);
        setabbrev(abrv);

        cout << "Please input unit load id: " << abrv;
        getline(cin, did);
        setuldid(did);

        cout << "Please enter aircraft type, 3 digits: ";
        cin >> plane;
        setaircraft(plane);

        cout << "Please enter weight in pounds or kilograms (i.e. \"32 Pounds\"): ";
        cin >> wt;
        setweight(wt);

        cout << "Please enter the cargo destination: ";
        cin >> dest;
        setdest(dest);
        return;
    }

