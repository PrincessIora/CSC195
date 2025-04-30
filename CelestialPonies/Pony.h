#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pony {
protected:
    string name;
    int lifespan;
	string coatColor; // color of the coat
    string coatTexture;  // glossy, matte, shimmer, flecked
    int height;
    int weight;
	string Texture;       // coat color
    string tailStyle;    // braided, flowing, curled, cropped
    string soundProfile; // bell-like, galloping thunder, whisper wind
    string accessories;  // crown, saddle, hoofwear

public:
    Pony();
    virtual ~Pony() {}

    virtual void Read(istream& in);
    virtual void Write(ostream& out) const;

    friend istream& operator>>(istream& in, Pony& pony);
    friend ostream& operator<<(ostream& out, const Pony& pony);
    string GetName() const { return name; }
};
