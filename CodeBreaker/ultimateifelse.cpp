#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    if (N == 1) {
        cout << "one" << endl;
    } else if (N == 9) {
        cout << 9 << endl;
    } else if (S == "hello") {
        cout << "world" << endl;
    } else if (S == "world" && N == 3) {
        cout << "andss" << endl;
    } else if (S == "hmm" || N == 20) {
        cout << "sus" << endl;
    } else if (S.length() > 5) {
        cout << "long" << endl;
    } else if (S.length() == N) {
        cout << "equal" << endl;
    } else if (N % 2 == 0) {
        cout << "222222222222222222222" << endl;
    } else {
        cout << "clown" << endl;
    }

    return 0;
}
