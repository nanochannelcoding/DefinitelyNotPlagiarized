#ifndef DEFINITELYNOTPLAGIARIZED_MOVESET_H
#define DEFINITELYNOTPLAGIARIZED_MOVESET_H
#ifndef MOVESET_H
#define MOVESET_H
#include <string>
using namespace std;

class Creature; // Forward declaration

// ENCAPSULATION: Private attributes store information about each move.
class MoveSet {
private:
    string name;
    int attack, heal, defense;

public:
    MoveSet(string n, int a, int h, int d)
        : name(n), attack(a), heal(h), defense(d) {}
    // DATA ABSTRACTION: Getters provide access without exposing private attributes.
    string getName() const { return name; }
    int getAttack() const { return attack; }
    int getHeal() const { return heal; }
    int getDefense() const { return defense; }
    // OPERATOR OVERLOADING: Allows two MoveSet objects to be compared using ==.
    bool operator==(const MoveSet& m) const {
        return name == m.name && attack == m.attack &&
               heal == m.heal && defense == m.defense;
    }
    // FRIEND FUNCTION: Declared here and given access to Creature's private attributes.
    static void faint(Creature&, Creature&);
};

#endif
#endif //DEFINITELYNOTPLAGIARIZED_MOVESET_H