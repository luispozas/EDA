//LUIS POZAS PALOMO - EDA - 06
#include <iostream>
#include <string>
using namespace std;

#include "stack.h"

char opuesto(char c){
	switch (c) {
		case ']': return '[';
		case '}': return '{';
		case ')': return '(';
	}
}

bool equilibrada(string const& word){
	stack<char> pila;
	for(int i = 0; i < word.size(); i++){
		if(word[i] == '[' || word[i] == '{' || word[i] == '(') pila.push(word[i]);
		else if(word[i] == ']' || word[i] == '}' || word[i] == ')') {
			if(pila.empty()) return false;
			else {
				if(pila.top() != opuesto(word[i])) return false;
				else pila.pop();
			}
		}
	}
	if(!pila.empty()) return false;
	return true;
}

bool resuelveCaso(){
	string word;
	getline(cin, word);
	if(!cin) return false;
	if(equilibrada(word)) cout << "SI\n";
	else cout << "NO\n";
	return true;
}

int main(){
	while(resuelveCaso());
}