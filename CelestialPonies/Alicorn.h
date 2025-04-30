#pragma once
#include "Pony.h"

class Alicorn : public Pony {
protected:
    float hornLength;
    string auraColor;
    string magicType;

    float wingspan;
    float flightSpeed;

    string regalTitle;

public:
    Alicorn();
    virtual ~Alicorn() {}

    virtual void Read(istream& in) override;
    virtual void Write(ostream& out) const override;

    friend istream& operator>>(istream& in, Alicorn& alicorn);
    friend ostream& operator<<(ostream& out, const Alicorn& alicorn);
};
