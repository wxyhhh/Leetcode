#pragma once
#include <iostream>
#include <unordered_map>
#include <algorithm>


class Solution {
	
public:
	static int lengthOfLongestSubstring(std::string s) {
		int i = 0, j = 0;
		int length = 0;
		std::unordered_map<char, int> myWindow;
		std::unordered_map<char, int>::iterator p;
		while (j < s.size()) {
			p = myWindow.find(s[j]);
			if (p == myWindow.end()) {
				myWindow.insert(std::pair<char, int>(s[j], j));
				j++;
				length = std::max(j - i, length);
			}
			else {
				i = std::max(p->second + 1, i);
				myWindow.erase(p);
			}
		}
		return length;
	}
};