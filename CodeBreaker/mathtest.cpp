#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) if (num % i == 0) return false;
    return true;
}

string numberToWords(int num) {
    string words;
    vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> teens = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    vector<string> tens = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (num >= 10000) {
        words += tens[num / 10000] + " ";
        num %= 10000;
        words += ones[num / 1000] + " thousand ";
        num %= 1000;
    }

    if (num >= 1000) {
        words += ones[num / 1000] + " thousand ";
        num %= 1000;
    }
    
    if (num >= 100) {
        words += ones[num / 100] + " hundred ";
        num %= 100;
    }

    if (num >= 20) {
        words += tens[num / 10] + " ";
        num %= 10;
    }

    if (num >= 11 && num <= 19) {
        words += teens[num - 10] + " ";
        num = 0;
    }

    if (num >= 1 && num <= 9) {
        words += ones[num] + " ";
    }

    return words;
}

int main() {
    int N, S;
    cin >> N >> S;
	
	int guess;
	for (int num = 1; num <= 100000; num++) {
		if (isPrime(num)) {
			N--;
			if (N == 0) {
				guess = num;
				break;
			}
		}
	}
	
	string correctAnswer = numberToWords(guess);
	correctAnswer[0] = toupper(correctAnswer[0]);
	correctAnswer = correctAnswer.substr(0, correctAnswer.size() - 1);
	cout << correctAnswer << '\n';
	
    for (int i = 0; i < S; i++) {
        string answer; cin >> answer;
        if (correctAnswer == answer) cout << "Correct!\n";
        else cout << "Wrong!\n";
    }
}
