#include "Pegasus.h"

Pegasus::Pegasus() : wingspan(2.5f), flightSpeed(80.0f) {}

void Pegasus::Read(istream& in) {
    Pony::Read(in);

    if (&in == &cin) {

        cout << "Enter Wingspan (in cm): ";
        cin >> wingspan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Flight Speed (km/h): ";
        cin >>  flightSpeed;
    }
    else {
        string label;
        getline(in, label); wingspan = stof(label.substr(label.find(":") + 2));
        getline(in, label); flightSpeed = stof(label.substr(label.find(":") + 2));

    }
}

void Pegasus::Write(ostream& out) const {
    Pony::Write(out);

    out << "Wingspan: " << wingspan << " cm \n";
    out << "Flight Speed: " << flightSpeed << " km/h \n";
}

istream& operator>>(istream& in, Pegasus& pegasus) {
    pegasus.Read(in);
    return in;
}

ostream& operator<<(ostream& out, const Pegasus& pegasus) {
    pegasus.Write(out);
    return out;
}
