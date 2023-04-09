#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Create an unordered map to store team names and points
    unordered_map<string, int> teamPoints;

    // Add teams and initial points to the map
    teamPoints["Team A"] = 0;
    teamPoints["Team B"] = 0;
    teamPoints["Team C"] = 0;

    // Simulate a match where Team A wins and add 3 points to their total
    teamPoints["Team A"] += 3;

    // Simulate a draw between Team B and Team C and add 1 point to each team's total
    teamPoints["Team B"] += 1;
    teamPoints["Team C"] += 1;

    // Print out the current points for each team
    for (auto it = teamPoints.begin(); it != teamPoints.end(); ++it) {
        cout << it->first << " : " << it->second << " points" << endl;
    }

    return 0;
}
