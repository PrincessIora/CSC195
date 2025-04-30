#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Pony.h"
#include "Unicorn.h"
#include "Pegasus.h"
#include "Alicorn.h"

enum PonyType {
    BASE_PONY = 0,
    UNICORN = 1,
    PEGASUS = 2,
    ALICORN = 3
};

class Sanctuary {
private:
    vector<shared_ptr<Pony>> ponies;

public:
    Sanctuary();
    ~Sanctuary();

    void AddPony(shared_ptr<Pony> pony);
    void DisplayAll() const;
    void DisplayByName(const string& name) const;
    void DisplayByType(PonyType type) const;

    void Load(const string& filename);
    void Save(const string& filename) const;

    void Clear();
};
