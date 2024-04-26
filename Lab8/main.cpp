#include <cctype>
#include <cstdint>
#include <functional>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <map>
#include <utility>


bool CompareEntries(std::pair<std::string,int> l, std::pair<std::string,int> r){
	if(l.second == r.second) return l.first.compare(r.first) > 0;
	else return l.second < r.second;
}

int main(int argc, char** argv) {
	if(argc < 2){
		std::cout << "Enter a file name";
		return 1;
	}
	if(argc > 2){
		std::cout << "Too many arguments!";
		return 1;
	}
	std::ifstream input(argv[1]);
	std::string str;
	getline(input, str);
	input.close();
	uintptr_t start = 0;
	uintptr_t len = 0;
	char delim[] = " ,?!.";
	std::map<std::string, uintptr_t> m;
	while(start < str.length()-1){
		start = str.find_first_not_of(delim, start);
		len = str.find_first_of(delim, start)-start;
		std::string substr = str.substr(start, len);
		for(auto& i: substr) i = tolower(i);
		if(m.find(substr) == m.end()) m.emplace(substr, 1);
		else m[substr]++;
		start += len;
	}
	std::priority_queue<std::pair<std::string, int>,
		std::vector<std::pair<std::string, int>>,
		std::function<bool(std::pair<std::string,int>,std::pair<std::string,int>)>>
			queue(CompareEntries);
	for(auto i: m){
		queue.push(i);
	}
	for(; !queue.empty(); queue.pop()){
		std::cout << queue.top().first << " => " << queue.top().second << '\n';
	}
}
