#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<string, vector<string>> states;
    states["start"] = {"0", "1"};
    states["0"] = {"NOISE", "end"};
    states["1"] = {"10", "NOISE"};
    states["10"] = {"100~", "NOISE"};
    states["100~"] = {"100~", "100~1"};
    states["100~1"] = {"0", "100~1~"};
    states["100~1~"] = {"?0", "100~1~"};
    states["?0"] = {"100~", "end"};
    states["end"] = {"0", "1"};

    string sound;
    cin >> sound;

    string currState = "start";

    for (auto s: sound) {
        currState = states[currState][s - '0'];
        if (currState == "NOISE")
            break;
    }

    if (currState == "end" or currState == "100~1" or currState == "100~1~")
        cout << "SUBMARINE";
    else
        cout << "NOISE";

    return 0;
}