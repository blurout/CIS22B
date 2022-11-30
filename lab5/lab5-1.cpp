/*
Fatih Sen

Fall 2022

Lab 5

Problem 0.5.1

Description of problem:

This object oriented program tracks the Unit Load Delivery (ULD) for airfreight companies using OOP methodology.
Included is file input and terminal output.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

const double maxload737 = 46000.00;
const double maxload767 = 116000.00;

class Cargo {
    protected:
        string uldtype;
        string abbrev;
        string uldid;
        int aircraft;
        double weight;
        string destination;
    public:
    // default constructor prototype
    Cargo();

    // Full constructor prototype
    Cargo(
        const string &uldtype,
        const string &abbrev,
        const string &uldid,
        const int &aircraft,
        const double &weight,
        const string &destination
        );
    // Destructor Prototype
    ~Cargo();

    // setters prototypes
    void setuldtype(string);
    void setabrv(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);

    // getters prototypes
    string getuldtype() const;
    string getabrv() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    virtual void maxweight(); // pure virtual function

    void output(); // output function
}; // end of Cargo class

class Boeing737 : public Cargo { //derived from cargo class
    private:
        int total737wt;
    public:
        Boeing737(); // default constructor
        Boeing737(
            const string &uldtype,
            const string &abbrev,
            const string &uldid,
            const int &aircraft,
            const double &weight,
            const string &destination
            ); // full constructor
        ~Boeing737(); // destructor
        void maxweight(double&, double, string); // override maxweight function from cargo class
};

class Boeing767 : public Cargo { //derived from cargo class
    private:
        int total767wt;
    public:
        Boeing767(); // default constructor
        Boeing767(
            const string &uldtype,
            const string &abbrev,
            const string &uldid,
            const int &aircraft,
            const double &weight,
            const string &destination
            ); // full constructor
        ~Boeing767(); // destructor
        void maxweight(double&, double, string); // override maxweight function from cargo class
};

void input();
void checkPlane(int);
void checkType(string);
void checkAbrv(string, int);
void vectorPrint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767);

int main()
{
    input();
    return 0;
}

Cargo :: Cargo() {
    uldtype = "none";
    abbrev = "none";
    uldid = "none";
    aircraft = 700;
    weight = 0.0;
    destination = "none";
}

Cargo :: Cargo
(
    const string &uld,
    const string &abrv,
    const string &id,
    const int &plane,
    const double &wt,
    const string &dest
) 
{
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = plane;
    weight = wt;
    destination = dest;
}

Cargo::~Cargo() {}

// setters definitions
void Cargo::setuldtype(string uld) {
    uldtype = uld;
}
void Cargo::setabrv(string abrv) {
    abbrev = abrv;
}
void Cargo::setuldid(string id) {
    uldid = id;
}
void Cargo::setaircraft(int plane) {
    aircraft = plane;
}
void Cargo::setweight(double wt) {
    weight = wt;
}
void Cargo::setdestination(string dest) {
    destination = dest;
}

// getters definitions
string Cargo::getuldtype() const {
    return uldtype;
}
string Cargo::getabrv() const {
    return abbrev;
}
string Cargo::getuldid() const {
    return uldid;
}
int Cargo::getaircraft() const {
    return aircraft;
}
double Cargo::getweight() const {
    return weight;
}
string Cargo::getdestination() const {
    return destination;
}

Boeing737 :: Boeing737
(
    const string &uld,
    const string &abrv,
    const string &id,
    const int &plane,
    const double &wt,
    const string &dest
) 
{
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = plane;
    weight = wt;
    destination = dest;
}
// 737 destructor
Boeing737::~Boeing737() {}

Boeing767 :: Boeing767
(
    const string &uld,
    const string &abrv,
    const string &id,
    const int &plane,
    const double &wt,
    const string &dest
) 
{
    uldtype = uld;
    abbrev = abrv;
    uldid = id;
    aircraft = plane;
    weight = wt;
    destination = dest;
}
// 767 destructor
Boeing767::~Boeing767() {}

void Cargo::maxweight() {}

void Boeing737::maxweight(double &total737wt, double wt, string id) {
    if (total737wt > maxload737) {
        total737wt -= wt; // remove weight from total
        cout << id;
        throw runtime_error(" exceeds 737 max weight, rejected\n\n");
    }
}

void Boeing767::maxweight(double &total767wt, double wt, string id) {
    if (total767wt > maxload767) {
        total767wt -= wt; // remove weight from total
        cout << id;
        throw runtime_error(" exceeds 767 max weight, rejected\n\n");
    }
}

void Cargo::output() {
    cout << fixed << showpoint << setprecision(2);
    cout << setw(19) << "ULD Type: " << uldtype << endl;
    cout << setw(19) << "ULD Abbreviation: " << abbrev << endl;
    cout << setw(19) << "ULD ID: " << uldid << endl;
    cout << setw(19) << "Aircraft: " << aircraft << endl;
    cout << setw(19) << "Weight: " << weight << endl;
    cout << setw(19) << "Destination: " << destination << endl;
}

void input() {
    vector <Boeing737> vectorptr737;
    vector <Boeing767> vectorptr767;
    string type, abrv, id, dest;
    int plane;
    double wt;
    double total737wt = 0.0;
    double total767wt = 0.0;

    string datafile;
    ifstream inputFile;

    do {
        try
        {
            inputFile.clear();
            cout << "Enter the name of the input file: ";
            getline(cin, datafile);
            inputFile.open(datafile.c_str());
            if (!inputFile) {
                cout << datafile << ": "; // display file name;
                throw runtime_error(" bad file name, try again\n");
            }
        }
        catch(runtime_error &e)
        {
            cout << e.what();
        }
    } while (!inputFile);

    while (inputFile >> type)
    {
        try{
            inputFile >> abrv;
            inputFile >> id ;
            inputFile >> plane; 
            inputFile >> wt;
            inputFile >> dest;

            checkType(type);
            checkAbrv(abrv, plane);
            checkPlane(plane);

            if (plane == 737) {
                total737wt += wt;
                Boeing737 obj737(type, abrv, id, plane, wt, dest); // constructor from Boeing737 class
                obj737.maxweight(total737wt, wt, id); // check weight
                vectorptr737.push_back(obj737); // add to vector
            }
            if (plane == 767) {
                total767wt += wt;
                Boeing767 obj767(type, abrv, id, plane, wt, dest); // constructor from Boeing767 class
                obj767.maxweight(total767wt, wt, id); // check weight
                vectorptr767.push_back(obj767); // add to vector
            }
        }
        catch(runtime_error &e)
        {
            cout << e.what();
        }
    }
    inputFile.close();
    vectorPrint(vectorptr737, vectorptr767);
    cout << "\ntotal weight of 737 cargo: " << total737wt << "pounds" << endl;
    cout << "\ntotal weight of 767 cargo: " << total767wt << "pounds" << endl;
}

void checkType(string type) {
    if (type != "Pallet" && type != "Container") {
        cout << type << ": ";
        throw runtime_error("Invalid ULD type not Container or Pallet, rejected\n\n");
    }
}

void checkAbrv(string abrv, int plane) {
    if (plane == 737) {
        if (abrv != "AYF" &&
            abrv != "AYK" &&
            abrv != "AAA" &&
            abrv != "AYY" &&
            abrv != "PAG" &&
            abrv != "PMC" &&
            abrv != "PLA" ) 
            {

            cout << abrv << ": ";
            throw runtime_error("Invalid type for 737, rejected\n\n");
            
            }
    }
    else if (plane == 767) {
        if (abrv != "AKE" &&
            abrv != "APE" &&
            abrv != "AKC" &&
            abrv != "AQP" &&
            abrv != "AQF" &&
            abrv != "AAP" &&
            abrv != "P1P" &&
            abrv != "P6P" )
            {

            cout << abrv << ": ";
            throw runtime_error("Invalid type for 767, rejected\n\n");

            }
    }
}

void checkPlane(int plane) {
    if (plane != 737 && plane != 767) {
        cout << plane << ": ";
        throw runtime_error("Invalid aircraft not 737 or 767, rejected\n\n");
    }
}

void vectorPrint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767) {
    for (int i = 0; i < vectorptr737.size(); i++) {
        cout << "\n737 Cargo Unit Number " << i + 1 << endl;
        cout << fixed << showpoint << setprecision(2) << left;
        cout << setw(20) << "Cargo Type: " << vectorptr737[i].getuldtype() << endl;
        cout << setw(20) << "Abbreviation: " << vectorptr737[i].getabrv() << endl;
        cout << setw(20) << "Unit ID: " << vectorptr737[i].getuldid() << endl;
        cout << setw(20) << "Aircraft: " << vectorptr737[i].getaircraft() << endl;
        cout << setw(20) << "Weight: " << vectorptr737[i].getweight() << endl;
        cout << setw(20) << "Destination: " << vectorptr737[i].getdestination() << endl;
    }

    for (int i = 0; i < vectorptr767.size(); i++) {
        cout << "\n767 Cargo Unit Number " << i + 1 << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << setw(20) << "Cargo Type: " << vectorptr767[i].getuldtype() << endl;
        cout << setw(20) << "Abbreviation: " << vectorptr767[i].getabrv() << endl;
        cout << setw(20) << "Unit ID: " << vectorptr767[i].getuldid() << endl;
        cout << setw(20) << "Aircraft: " << vectorptr767[i].getaircraft() << endl;
        cout << setw(20) << "Weight: " << vectorptr767[i].getweight() << endl;
        cout << setw(20) << "Destination: " << vectorptr767[i].getdestination() << endl;
    }
}