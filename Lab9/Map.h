#pragma once
#include <cstdint>
#include <cstdlib>


template<typename K, typename V>
class MapTuple {
	public:
	K& key;
	V& value;
	int index;
};

template<typename K, typename V>
class MapIterator {
	public:
	K* key;
	V* value;
	int index;
	MapIterator<K,V>& operator++(){
		key++;
		value++;
		index++;
		return *this;
	}
	bool operator!=(MapIterator<K,V>& r){
		return index != r.index;
	}
	MapTuple<K,V> operator*(){
		return MapTuple<K,V>{*key,*value,index};
	}
};

template<typename K, typename V>
class Map{
	K* keys;
	V* vals;
	int count;

	public:
	Map() {
		keys = (K*)malloc(0);
		vals = (V*)malloc(0);
		count = 0;
	}
	~Map(){
		free(keys);
		free(vals);
	}
	MapIterator<K,V> begin() { return MapIterator<K,V>{&keys[0],&vals[0],0}; }
	MapIterator<K,V> end() { return MapIterator<K,V>{nullptr,nullptr,count}; }
	V& operator[](const K& key){
		for(uintptr_t j=0; j<count; j++)
			if(keys[j] == key) return vals[j];
		count++;
		keys = (K*)realloc(keys, sizeof(K)*count);
		keys[count-1] = key;
		vals = (V*)realloc(vals, sizeof(V)*count);
		return vals[count-1];
	}
	void Set(const K& key, const V& value){
		for(uintptr_t j=0; j<count; j++)
			if(keys[j] == key){
				vals[j] = value;
				return;
			}
		count++;
		keys = (K*)realloc(keys, sizeof(K)*count);
		keys[count-1] = key;
		vals = (V*)realloc(vals, sizeof(V)*count);
		vals[count-1] = value;
	}
	bool Get(const K& key, V& value){
		for(uintptr_t j=0; j<count; j++){
			if(keys[j] == key) {
				value = vals[j];
				return true;
			}
		}
		return false;
	}
	int Count() { return count; };
	void Clear(){
		count = 0;
		keys = (K*)realloc(keys,0);
		vals = (V*)realloc(vals,0);
	}
	bool Delete(const K& key){
		for(uintptr_t j=0; j<count; j++){
			if(keys[j] == key) {
				for(int i=j; i<count-1; i++){
					keys[i] = keys[i+1];
					vals[i] = vals[i+1];
				}
				count--;
				keys = (K*)realloc(keys,sizeof(K)*count);
				vals = (V*)realloc(vals,sizeof(V)*count);
				return true;
			}
		}
		return false;

	}	
	bool Includes(const Map<K,V>& map){
		for(int i=0; i<map.count; i++){
			bool exists = false;
			for(int j=0; j<count; j++){
				if(map.keys[i] == keys[j]) exists = true;
			}
			if(!exists) return false;
		}
		return true;
	}
};
