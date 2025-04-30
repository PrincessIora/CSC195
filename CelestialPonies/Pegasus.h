#pragma once
#include "Pony.h"

class Pegasus : public Pony {
protected:
    float wingspan;         // in meters
    float flightSpeed; // soaring/darting/gliding/etc.

public:
    Pegasus();
    virtual ~Pegasus() {}

    virtual void Read(istream& in) override;
    virtual void Write(ostream& out) const override;

    friend istream& operator>>(istream& in, Pegasus& pegasus);
    friend ostream& operator<<(ostream& out, const Pegasus& pegasus);
};
