// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
//
// void print_string(std::string statement, int cardNum, int captures);
//
// void mostTimingCaptures(std::vector<std::string> lines){
//     /* Enter your code here. Read input from a list of lines. Print output to STDOUT.*/
//
//
//     int cardNum = 0;
//     int captures = 0;
//     print_string("TIMING CARD:", cardNum, captures);
// }
// /*
// Return the (card number, total amount captured)
// for the card that has the largest captured amount denoted as the
// sum of amounts from positive capture events along with the total amount captured
// If no card exists, return (-1, -1).
//  */
// void mostOverCaptured(std::vector<std::string> lines){
//     /* Enter your code here. Read input from a list of lines. Print output to STDOUT.*/
//     int cardNum = 0;
//     int capturedAmount = 0;
//     print_string("OVERCAPTURED CARD:", cardNum, capturedAmount);
// }
//
// /*
// Print the (card number, # of negative captures)
// Find the cards with the most negative captures.
// If no card exists, return (-1, -1).
// */
// void mostNegativeCaptures(std::vector<std::string> lines){
//     /* Enter your code here. Read input from a list of lines. Print output to STDOUT.*/
//     int cardNum = 0;
//     int captures = 0;
//     print_string("NEGATIVE CARD:", cardNum, captures);
// }
//
// void print_string(std::string statement, int cardNum, int captures){
//     cout << statement << " " << cardNum << " " << captures << endl;
// }
//
// int main() {
//     std::vector<std::string> input;
//
//     for (std::string line; std::getline(std::cin, line);) {
//         input.push_back(line);
//     }
//
//     mostTimingCaptures(input);
//     mostOverCaptured(input);
//     mostNegativeCaptures(input);
//     return 0;
// }




#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <limits>

using namespace std;

void print_string(const string& statement, int cardNum, int captures) {
    cout << statement << " " << cardNum << " " << captures << std::endl;
}

// Define a struct to store card information
struct CardInfo {
    int card_id;
    int auth_limit;
    int capture_total;
    int non_active_captures;
    int negative_captures_total;
    int negative_captures;
};

string toupper_string(string in) {
    string out;
    for (char c: in) {
        out += toupper(c);
    }
    return out;
}

map<int, CardInfo> parse_events(const std::vector<std::string>& lines) {
    map<int, CardInfo> cards_info;

    int current_card_id = -1;

    for (const string& line : lines) {
        istringstream iss(line);
        string date, time, action, timestamp;
        iss >> date >> time >> action;
        // cout << "date: " << date << endl;
        // cout << "time: " << time << endl;
        // cout << "action: " << action << endl;

        if (toupper_string(action) == "CARD") {
            char c;
            string auth;
            int card_id, auth_limit;
            iss >> c >> card_id >> auth >> auth_limit;
            current_card_id = card_id;
            CardInfo info {card_id, auth_limit};
            cards_info[card_id] = info;
        } else if (toupper_string(action) == "CAPTURE") {
            int capture_amount;
            iss >> capture_amount;

            CardInfo& info = cards_info[current_card_id];

            if (capture_amount > 0) {
                info.capture_total += capture_amount;
                if (stoi(time.substr(0, 2)) <= 7 || (stoi(time.substr(0, 2)) >= 22)) {
                    info.non_active_captures++;
                }
            } else if (capture_amount < 0) {
                info.negative_captures++;
                info.negative_captures_total += capture_amount;
            }

        }
    }

    return cards_info;
}

void mostTimingCaptures(const vector<std::string>& lines) {
    map<int, CardInfo> card_info = parse_events(lines);

    int cardNum = -1;
    int captures = 0;

    for (auto entry : card_info) {
        CardInfo info = entry.second;
        if (info.non_active_captures > captures) {
            captures = info.non_active_captures;
            cardNum = info.card_id;
        }
    }

    if (captures == 0) {
        captures = -1;
    }

    print_string("TIMING CARD:", cardNum, captures);
}

void mostOverCaptured(const vector<std::string>& lines) {
    map<int, CardInfo> card_info = parse_events(lines);

    int cardNum = -1;
    int capturedAmount = 0;

    for (auto entry : card_info) {
        CardInfo info = entry.second;
        if (info.capture_total > info.auth_limit && info.capture_total > capturedAmount) {
            capturedAmount = info.capture_total;
            cardNum = info.card_id;
        }
    }

    if (capturedAmount == 0) {
        capturedAmount = -1;
    }

    print_string("OVERCAPTURED CARD:", cardNum, capturedAmount);
}

void mostNegativeCaptures(const vector<std::string>& lines) {
    map<int, CardInfo> card_info = parse_events(lines);

    int cardNum = -1;
    int captures = 0;

    for (const auto& entry : card_info) {
        const CardInfo& info = entry.second;
        if (info.negative_captures > captures) {
            captures = info.negative_captures;
            cardNum = info.card_id;
        }
    }

    if (captures == 0) {
        captures = -1;
    }

    print_string("NEGATIVE CARD:", cardNum, captures);
}

int main() {
    vector<std::string> input;

    for (string line; std::getline(std::cin, line);) {
        input.push_back(line);
    }

    mostTimingCaptures(input);
    mostOverCaptured(input);
    mostNegativeCaptures(input);

    return 0;
}


