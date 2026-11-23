#ifndef DEFINITELYNOTPLAGIARIZED_BATTLESTATE_H
#define DEFINITELYNOTPLAGIARIZED_BATTLESTATE_H

#ifndef BATTLESTATE_H
#define BATTLESTATE_H

class Battle;
// ENCAPSULATION: Stores battle information privately.
class BattleState {
private:
    int playerHP, enemyHP;
    int playerDefense, enemyDefense;
    // FRIEND CLASS: Allows Battle to access BattleState's private attributes.
    friend class Battle;

public:
    // Default constructor initializes all battle statistics to zero.
    BattleState()
        : playerHP(0), enemyHP(0),
          playerDefense(0), enemyDefense(0) {}
};

#endif
#endif