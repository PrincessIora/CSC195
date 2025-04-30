#include "Alicorn.h"

Alicorn::Alicorn()
	: hornLength(12.0f), auraColor("royal violet"), magicType("arcane"),
    wingspan(3.2f), flightSpeed(80.0f),
    regalTitle("Princess") {
}
void Alicorn::Read(istream& in) {
    Pony::Read(in); 

    if (&in == &std::cin) {
        cout << "Enter Horn Length (in cm): ";
        in >> hornLength;
        in.ignore();

        cout << "Enter Aura Color: ";
        getline(in, auraColor);

        cout << "Enter Magic Type: ";
        getline(in, magicType);

        cout << "Enter Wingspan (in cm): ";
        in >> wingspan;
        in.ignore();

        cout << "Enter Flight Speed (km/h): ";
        in >> flightSpeed;
		in.ignore();

        cout << "Enter Regal Title (e.g. Princess/Queen/Empress): ";
        getline(in, regalTitle);
    }
    else {
        string line;
        getline(in, line); hornLength = stoi(line.substr(line.find(":") + 2));
        getline(in, line); auraColor = line.substr(line.find(":") + 2);
        getline(in, line); magicType = line.substr(line.find(":") + 2);
        getline(in, line); wingspan = stoi(line.substr(line.find(":") + 2));
        getline(in, line); flightSpeed = stoi(line.substr(line.find(":") + 2));
        getline(in, line); regalTitle = line.substr(line.find(":") + 2);
    }
}

void Alicorn::Write(ostream& out) const {
    Pony::Write(out);

    out << "Horn Length:    " << hornLength << " cm\n";
    out << "Aura Color:     " << auraColor << "\n";
    out << "Magic Type:     " << magicType << "\n";
    out << "Wingspan:       " << wingspan << " cm\n";
    out << "Flight Speed:   " << flightSpeed << "\n";
    out << "Regal Title:    " << regalTitle << "\n";
}

std::istream& operator>>(istream& in, Alicorn& alicorn) {
    alicorn.Read(in);
    return in;
}

std::ostream& operator<<(ostream& out, const Alicorn& alicorn) {
    alicorn.Write(out);
    return out;
}
