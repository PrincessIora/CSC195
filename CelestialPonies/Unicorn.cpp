#include "Unicorn.h"


Unicorn::Unicorn() : hornLength(10.0f), auraColor("silver"), magicType("arcane") {}

void Unicorn::Read(istream& in) {
    Pony::Read(in);


    if(&in == &cin){
        cout << "Enter Horn Length (in cm): ";
        cin >> hornLength;

        cout << "Enter Aura Color: ";
        cin >> auraColor;

        cout << "Enter Magic Type: ";
        cin >> magicType;
    }
    else {
        string label;
        getline(in, label); hornLength = stof(label.substr(label.find(":") + 2));
        getline(in, label); auraColor = label.substr(label.find(":") + 2);
        getline(in, label); magicType = label.substr(label.find(":") + 2);
    }
}

void Unicorn::Write(ostream& out) const {
    Pony::Write(out);

    out << "Horn Length:    " << hornLength << " cm\n";
    out << "Aura Color:     " << auraColor << "\n";
    out << "Magic Type:     " << magicType << "\n";
}

istream& operator>>(istream& in, Unicorn& unicorn) {
    unicorn.Read(in);
    return in;
}

ostream& operator<<(ostream& out, const Unicorn& unicorn) {
    unicorn.Write(out);
    return out;
}
