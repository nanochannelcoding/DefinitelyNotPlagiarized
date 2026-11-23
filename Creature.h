#ifndef DEFINITELYNOTPLAGIARIZED_CREATURE_H
#define DEFINITELYNOTPLAGIARIZED_CREATURE_H
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "MoveSet.h"

// ABSTRACT CLASS: Creature is a parent class that cannot be instantiated directly.
class Creature {
private:
    string name;
    int hp = 30, attack, defense, speed;
    // STL VECTOR: Stores the moves belonging to each creature.
    vector<MoveSet> moves;
    // FRIEND FUNCTION: Allows MoveSet::faint() to access private attributes.
    friend void MoveSet::faint(Creature&, Creature&);

public:
    Creature(string n, int a, int d, int s)
        : name(n), attack(a), defense(d), speed(s) {}
    // VIRTUAL DESTRUCTOR: Supports safe destruction through base-class pointers.
    virtual ~Creature() = default;

    void takeDamage(int damage) {
        hp = max(0, hp - damage);
        cout << name << " takes " << damage << " damage!\n";
    }

    void boostDefense(int amount) {
        defense = min(20, defense + amount);
        cout << name << "'s defense is now " << defense << "!\n";
    }

    void heal(int amount) { hp = min(30, hp + amount); }
    void addMove(MoveSet m) { moves.push_back(m); }
    // DATA ABSTRACTION: Public getters control access to private attributes.
    string getName() const { return name; }
    int getHealth() const { return hp; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getSpeed() const { return speed; }

    const vector<MoveSet>& getMoves() const { return moves; }
    // PURE VIRTUAL FUNCTIONS: Must be implemented by derived classes.
    // These also make Creature an ABSTRACT CLASS.
    virtual string getSpecies() const = 0;
    virtual void useSpecialAbility() = 0;
};
// FRIEND FUNCTION DEFINITION: Checks whether either creature has fainted.
void MoveSet::faint(Creature& a, Creature& b) {
    if (a.hp == 0) cout << a.name << " fainted!\n";
    if (b.hp == 0) cout << b.name << " fainted!\n";
}

#endif
#endif //DEFINITELYNOTPLAGIARIZED_CREATURE_H