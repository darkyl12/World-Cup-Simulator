
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

string match(string a, string b) {
    return (rand() % 2 == 0) ? a : b;
}

vector<string> playRound(vector<string> teams) {
    vector<string> next;
    for (int i = 0; i < teams.size(); i += 2) {
        string winner = match(teams[i], teams[i + 1]);
        cout << winner << " wins: " << teams[i] << " vs " << teams[i + 1] << endl;
        next.push_back(winner);
    }
    return next;
}

int main() {
    srand(time(0));

    vector<string> teams = {
        "Qatar","Senegal","Netherlands","Ecuador",
        "England","Iran","USA","Wales",
        "Argentina","Saudi Arabia","Mexico","Poland",
        "France","Australia","Denmark","Tunisia"
    };

    cout << "=== WORLD CUP SIMULATOR ===\n\n";

    cout << "--- ROUND OF 16 ---\n";
    teams = playRound(teams);

    cout << "\n--- QUARTER FINAL ---\n";
    teams = playRound(teams);

    cout << "\n--- SEMI FINAL ---\n";
    teams = playRound(teams);

    cout << "\n--- FINAL ---\n";
    string winner = match(teams[0], teams[1]);

    cout << "\n🏆 WINNER: " << winner << endl;

    return 0;
}
