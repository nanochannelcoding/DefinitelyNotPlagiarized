#ifndef DEFINITELYNOTPLAGIARIZED_SUBCREATURE_H
#define DEFINITELYNOTPLAGIARIZED_SUBCREATURE_H
#ifndef SUBCREATURE_H
#define SUBCREATURE_H

#include "Creature.h"

// INHERITANCE: SubCreature inherits the attributes and functions of Creature.
class SubCreature : public Creature {
private:
    string type;

public:
    SubCreature(string n, string t, int a, int d, int s,
                string attackName, int power, string defenseName)
        : Creature(n, a, d, s), type(t) {
        addMove(MoveSet(attackName, power, 0, 0));
        addMove(MoveSet(defenseName, 0, 0, 3));
    }
    // POLYMORPHISM: Overrides the parent's virtual function.
    string getSpecies() const override { return type; }
    // POLYMORPHISM: Provides an implementation of the parent's pure virtual function.+ SubCreature(string, string, int, int, int, string, int, string)
    void useSpecialAbility() override {
        cout << getName() << " uses its special ability!\n";
        heal(5);
    }
};

#endif
#endif //DEFINITELYNOTPLAGIARIZED_SUBCREATURE_H