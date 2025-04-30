#include "Pony.h"

Pony::Pony() : name("Pony"), lifespan(100), height(145), weight(333), coatTexture("shimmer"), coatColor("blue"), tailStyle("flowing"), soundProfile("galloping thunder"), accessories("none")  {}

void Pony::Read(istream& in) {

    if (&in == &cin) {

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Lifespan in years: ";
        cin >> lifespan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush buffer

        cout << "Enter Height (in cm): ";
        cin >> height;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Weight (in kg): ";
        cin >> weight;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Coat Texture (ex: glossy/matte/shimmer/flecked): ";
        getline(cin, coatTexture);

        cout << "Enter Coat Color: ";
        getline(cin, coatColor);

        cout << "Enter Tail Style (ex: braided/flowing/curled/cropped): ";
        getline(cin, tailStyle);

        cout << "Enter Sound Profile (ex: bell-like/galloping thunder/whisper wind): ";
        getline(cin, soundProfile);

        cout << "Enter Accessories (ex: crown/saddle/hoofwear/none): ";
        getline(cin, accessories);

    }
    else {
        string label;

        getline(in, label); name = label.substr(label.find(":") + 2);
        getline(in, label); lifespan = stoi(label.substr(label.find(":") + 2));
        getline(in, label); height = stoi(label.substr(label.find(":") + 2));
        getline(in, label); weight = stoi(label.substr(label.find(":") + 2));
        getline(in, label); coatTexture = label.substr(label.find(":") + 2);
        getline(in, label); coatColor = label.substr(label.find(":") + 2);
        getline(in, label); tailStyle = label.substr(label.find(":") + 2);
        getline(in, label); soundProfile = label.substr(label.find(":") + 2);
        getline(in, label); accessories = label.substr(label.find(":") + 2);
    }

}


void Pony::Write(ostream& out) const {
    out << "Name:           " << name << "\n";
    out << "Lifespan:       " << lifespan << " years \n";
    out << "Height:         " << height << " cm \n";
    out << "Weight:         " << weight << " kg \n";
    out << "Coat Texture:   " << coatTexture << "\n";
	out << "Coat Color:     " << coatColor << "\n";
    out << "Tail Style:     " << tailStyle << "\n";
    out << "Sound Profile:  " << soundProfile << "\n";
    out << "Accessories:    " << accessories << "\n";
}


istream& operator>>(istream& in, Pony& pony) {
    pony.Read(in);
    return in;
}

ostream& operator<<(ostream& out, const Pony& pony) {
    pony.Write(out);
    return out;
}
