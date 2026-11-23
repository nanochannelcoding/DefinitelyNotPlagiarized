#ifndef DEFINITELYNOTPLAGIARIZED_BATTLE_H
#define DEFINITELYNOTPLAGIARIZED_BATTLE_H
#ifndef BATTLE_H
#define BATTLE_H

#include <list>
#include <stack>
#include "Creature.h"
#include "BattleState.h"

// ENCAPSULATION: Battle's internal data is private.
class Battle {
private:
    // POLYMORPHISM: Base-class pointers can reference derived SubCreature objects.
    Creature* player;
    Creature* enemy;
    bool pDefending = false, eDefending = false;

    // STL LIST: Stores previous battle states.
    list<BattleState> history;

    bool effective(string a, string d) {
        return (a == "Fire" && d == "Grass") ||
               (a == "Grass" && d == "Water") ||
               (a == "Water" && d == "Fire");
    }

    void saveState() {
        BattleState s;
        s.playerHP = player->getHealth();
        s.enemyHP = enemy->getHealth();
        s.playerDefense = player->getDefense();
        s.enemyDefense = enemy->getDefense();
        history.push_back(s);
    }

    void takeTurn(Creature* a, Creature* d, bool& defending) {
        const auto& moves = a->getMoves();
        int choice;

        cout << "\n" << a->getName() << "'s turn!\n"
             << "1. " << moves[0].getName() << " (Attack)\n"
             << "2. " << moves[1].getName() << " (Defend)\n"
             << "Choose: ";

        while (!(cin >> choice) || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter 1 or 2: ";
        }

        MoveSet m = moves[choice - 1];

        cout << a->getName() << " uses " << m.getName() << "!\n";

        if (choice == 2) {
            a->boostDefense(m.getDefense());
            defending = true;
        } else {
            int damage = m.getAttack();

            if (effective(a->getSpecies(), d->getSpecies())) {
                damage *= 2;
                cout << "Super effective!\n";
            }

            if (defending) {
                damage /= 2;
                defending = false;
                cout << d->getName() << " blocks half the damage!\n";
            }

            d->takeDamage(damage);
        }

        MoveSet::faint(*player, *enemy);
    }

public:
    Battle(Creature* p, Creature* e) : player(p), enemy(e) {}

    bool checkWinner() const {
        return player->getHealth() == 0 || enemy->getHealth() == 0;
    }

    void startBattle() {
        cout << "\n========== BATTLE START ==========\n"
             << player->getName() << " vs " << enemy->getName() << "\n";

        stack<int> turns;

        while (!checkWinner()) {
            while (!turns.empty()) turns.pop();

            if (player->getSpeed() >= enemy->getSpeed()) {
                turns.push(2);
                turns.push(1);
            } else {
                turns.push(1);
                turns.push(2);
            }

            while (!turns.empty() && !checkWinner()) {
                saveState();

                if (turns.top() == 1)
                    takeTurn(player, enemy, eDefending);
                else
                    takeTurn(enemy, player, pDefending);

                turns.pop();
            }

            cout << "\n" << player->getName() << " HP: "
                 << player->getHealth() << "/30\n"
                 << enemy->getName() << " HP: "
                 << enemy->getHealth() << "/30\n";
        }

        cout << "\n========== BATTLE END ==========\n"
             << (player->getHealth() > 0 ? player->getName() : enemy->getName())
             << " wins!\n";
    }
};

#endif
#endif //DEFINITELYNOTPLAGIARIZED_BATTLE_H