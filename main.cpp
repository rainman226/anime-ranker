#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int calculateTotalPoints(string team, map<string, map<string, int>> results) {
    int total_points = 0;
    for (auto const& opponent : results[team]) {
        total_points += opponent.second;
    }
    return total_points;
}

// Trim whitespace characters from beginning and end of string
void trim(string& str) {
    // Find first non-whitespace character from beginning of string
    auto first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == string::npos) {
        // String is all whitespace, so clear it
        str.clear();
        return;
    }

    // Find last non-whitespace character from end of string
    auto last = str.find_last_not_of(" \t\n\r\f\v");

    // Erase whitespace from beginning and end of string
    str.erase(last + 1);
    str.erase(0, first);
}

int main() {
    // initialize the map of teams and their results against other teams
    map<string, map<string, int>> results;

    // read the team names from the file and add them to the map
    ifstream teams_file("teams.txt");
    if (teams_file.is_open()) {
    string team_name;
    while (getline(teams_file, team_name)) {
         // trim leading and trailing whitespace characters
        trim(team_name);
        // check that the team name is not empty
        if (!team_name.empty()) {
            // add an empty record for this team to the map
            results[team_name] = map<string, int>();
        }
    }
    teams_file.close();
    } else {
        cout << "Error: could not open teams file" << endl;
        return 1;
    }

    // add some sample results
    results["Team A"]["Team B"] = 3; // Team A beat Team B
    results["Team B"]["Team A"] = 0; // Team B lost to Team A
    results["Team A"]["Team C"] = 1; // Team A drew with Team C
    results["Team C"]["Team A"] = 1; // Team C drew with Team A
    results["Team B"]["Team C"] = 3; // Team B beat Team C
    results["Team C"]["Team B"] = 0; // Team C lost to Team B

    // create a vector of pairs containing each team's name and total points
    vector<pair<string, int>> teams;
    for (auto const& team : results) {
        string team_name = team.first;
        int total_points = calculateTotalPoints(team_name, results);
        teams.push_back(make_pair(team_name, total_points));
    }

    // sort the vector based on total points
    sort(teams.begin(), teams.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // print out the teams in order of their points
    for (auto const& team : teams) {
        string team_name = team.first;
        int total_points = team.second;
        cout << team_name << ": " << total_points << " points" << endl;
    }

    return 0;
}
