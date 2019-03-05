#include<iostream>
using namespace std;

#include<vector>
#include<math.h>
#include<string>
#include<set>
#include<map>
/*
the rule of cow is that
the correct num of chars in the secret...
see the problem example, I cannot explain it clearly.


*/
class Solution {
public:
	string getHint(string secret, string guess) {
		int bull = 0, cow = 0;
		map<char, int>secNum;
		for (int i = 0; i < secret.size(); i++) {
			if (secNum.find(secret[i]) == secNum.end()) {
				secNum.insert(pair<char, int>(secret[i], 1));
			}
			//already exists
			else {
				secNum.find(secret[i])->second += 1;
			}
		}

		
		set<char> sec;
		for (int i = 0; i < secret.size(); i++) {
			sec.insert(secret[i]);
			if (secret[i] == guess[i]) {
				bull++;
				secNum.find(secret[i])->second -= 1;
			}
			else continue;
		}
		/*
		set<char>::iterator it2;
		for (it2 = sec.begin(); it2 != sec.end(); ++it2)
			std::cout << ' ' << *it2;
		*/
		/*
		map<char, int>::iterator it;
		for (it = secNum.begin(); it != secNum.end(); it++) {
			cout << it->second << endl;
		}
		*/
		for (int i = 0; i < guess.size(); i++) {
			if (sec.count(guess[i]) !=0 && secNum.find(guess[i])->second!=0 && secret[i] != guess[i]) {
				secNum.find(guess[i])->second -= 1;
				cow++;
			}
			else continue;
		}
		string res;
		res = to_string(bull).append("A").append(to_string(cow)).append("B");
		return res;
	}
};