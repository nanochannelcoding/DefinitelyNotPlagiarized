#ifndef DEFINITELYNOTPLAGIARIZED_BATTLEINTERFACE_H
#define DEFINITELYNOTPLAGIARIZED_BATTLEINTERFACE_H
#ifndef BATTLEINTERFACE_H
#define BATTLEINTERFACE_H

#include "SubCreature.h"
#include "Battle.h"

class BattleInterface {
private:
    // ARRAY: Provides the three available creature choices.
    SubCreature creatures[3] = {
        {"Flameling", "Fire", 18, 12, 16, "Flame Burst", 6, "Flame Shield"},
        {"Leafling", "Grass", 14, 18, 12, "Vine Strike", 5, "Nature Guard"},
        {"Aquafin", "Water", 16, 14, 18, "Water Jet", 7, "Aqua Shield"}
    };

    SubCreature* chooseCreature(int player) {
        int choice;

        cout << "\nPlayer " << player << ", choose your creature:\n";

        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << creatures[i].getName()
                 << " (" << creatures[i].getSpecies() << ")"
                 << " | HP: 30"
                 << " | Attack: " << creatures[i].getAttack()
                 << " | Defense: " << creatures[i].getDefense()
                 << " | Speed: " << creatures[i].getSpeed() << "\n";
        }

        cout << "Choice: ";

        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter 1, 2, or 3: ";
        }

        return &creatures[choice - 1];
    }

public:
    void start() {
        cout << "===== BATTLE SIMULATOR =====\n";

        // Independent creature choices for each player
        SubCreature playerCreatures[3] = {
            creatures[0], creatures[1], creatures[2]
        };
        SubCreature enemyCreatures[3] = {
            creatures[0], creatures[1], creatures[2]
        };

        SubCreature* p = chooseCreature(1);
        int pIndex = p - creatures;

        SubCreature* e = chooseCreature(2);
        int eIndex = e - creatures;

        // Give each player an independent creature object
        SubCreature player = playerCreatures[pIndex];
        SubCreature enemy = enemyCreatures[eIndex];

        Battle battle(&player, &enemy);
        battle.startBattle();
    }
};

#endif


#endif //DEFINITELYNOTPLAGIARIZED_BATTLEINTERFACE_H
