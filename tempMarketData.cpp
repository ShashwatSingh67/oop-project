#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    vector<string> names(50);
    string line;

    // === Read stock names (first line) ===
    getline(cin, line);
    for (char &c : line) if (c == ',') c = ' ';
    stringstream ss_names(line);
    for (int i = 0; i < 50 && ss_names >> names[i]; i++) {
        optional: cout << names[i] << endl;
    }

    // === Read stock price data ===
    vector<vector<double>> stock_data(50); // 50 stocks
    int day = 0;

    while (getline(cin, line)) { // each line = one day’s data
        if (line.empty()) continue;

        for (char &c : line) if (c == ',') c = ' ';
        stringstream ss(line);

        double price;
        int stock_id = 0;
        while (ss >> price && stock_id < 50) {
            stock_data[stock_id].push_back(price);
            stock_id++;
        }
        day++;
    }

    

    cout << "Loaded " << day << " days of data for " << stock_data.size() << " stocks.\n";
    cout << "Example: " << names[1] << " on day 3 = " << stock_data[1][2] << endl;

    return 0;
}
// Access: stock_data[stock_id][day]
