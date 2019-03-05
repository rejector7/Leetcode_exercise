#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>

/*
brute force
*/
class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		int len = words.size();
		vector<vector<int>>res;
		if (len <= 0)
			return res;
		for (int i = 0; i < len; i++)
			for (int j = i + 1; j < len; j++) {
				if (isPalindrome(words[i], words[j])) {
					vector<int> vec;
					vec.push_back(i);
					vec.push_back(j);
					res.push_back(vec);
				}
				if (isPalindrome(words[j], words[i])) {
					vector<int> vec;
					vec.push_back(j);
					vec.push_back(i);
					res.push_back(vec);
				}
			}
		return res;

	}
private:
	bool isPalindrome(string w1, string w2) {
		string s = w1 + w2;
		for (int i = 0; i < s.size()/2; i++) {
			if (s[i] == s[s.size() - i - 1]) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
};

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>>res;
		map<string, int>map_str;
		for (int i = 0; i < words.size(); i++)
			map_str[words[i]] = i;

		for (int j = 0; j < words.size(); j++) {
			reverse(words[j].begin(), words[j].end());
			int len = words[j].size();
			for (int k = 0; k <= len; k++) {
				string left = words[j].substr(0, k);
				string right = words[j].substr(k);
				/*
				��һ���ж��м���j<len,��Ϊ�˷�ֹ�����жϡ�

				�磺abcd, dcba

				����abcd�ַ���ʱ����reserve��Ȼ�����ߵ�0����ʼ�ָ��dcba���ҵ���
				���ָ���һ��ʱ���õ�������dcba,���ʱ������������
				��Ϊ���ڶԵڶ����ַ���dcba��ʼ����ʱ�����ظ���
				*/
				if (map_str.count(left) && isvalid(right) && (map_str[left] != j) && (k < len))
					res.push_back(vector<int>{map_str[left], j});
				if (map_str.count(right) && isvalid(left) && (map_str[right] != j))
					res.push_back(vector<int>{j, map_str[right]});
			}
		}
		return res;
	}
private:
	bool isvalid(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j) {
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};