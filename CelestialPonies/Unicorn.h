#pragma once
#include "Pony.h"

class Unicorn : public Pony {
protected:
    float hornLength;      // in cm
    string auraColor; // for magical types
    string magicType;

public:
    Unicorn();
    virtual ~Unicorn() {}

    virtual void Read(istream& in) override;
    virtual void Write(ostream& out) const override;

    friend istream& operator>>(istream& in, Unicorn& unicorn);
    friend ostream& operator<<(ostream& out, const Unicorn& unicorn);
};
