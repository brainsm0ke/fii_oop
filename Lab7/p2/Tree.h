#pragma once
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class TreeNode {
	TreeNode<T>* node;
	uintptr_t c;
	public:
	T val;
	TreeNode<T>(){
		c = 0;
		node = nullptr;
	}
	TreeNode(T v) {
		val = v;
		c = 0;
		node = nullptr;
	}
	~TreeNode() {
		for(int i=0; i<c; i++){
			node[i].~TreeNode<T>();
		}
		free(node);
	}
	void add_node(T v) {
		c++;
		if(c == 1){
			node = (TreeNode<T>*)malloc(sizeof(TreeNode<T>) * c);
			node[0] = TreeNode<T>(v);
		} else {
			node = (TreeNode<T>*)realloc(node, sizeof(TreeNode<T>) * c);
			node[c-1] = TreeNode<T>(v);
		}
	}
	void delete_node(uintptr_t index){
		node[index].~TreeNode<T>();
		for(uintptr_t i=index; i<c-1; i++){
			node[i] = node[i+1];
		}
		node = (TreeNode<T>*)realloc(node, sizeof(TreeNode<T>) * (--c));
	}
	TreeNode<T>* get_node(uintptr_t index){
		if(index < c){
			return &node[index];
		} else
			throw std::out_of_range("index out of range");
	}
	TreeNode<T>* find(bool (*f)(T)){
		if(f(val)){
			return this;
		}
		TreeNode<T>* result;
		for(uintptr_t i=0; i<c; i++){
			result = node[i].find(f);
			if(result != nullptr)
				return result;
		}
		return nullptr;
	}
	void insert_node(uintptr_t index, T v){
		if(index < c){
			node = (TreeNode<T>*)realloc(node, sizeof(TreeNode<T>) * ++c);
			for(uintptr_t i=c-1; i>index; i--){
				node[i] = node[i-1];
			}
			node[index] = TreeNode<T>(v);
		} else 
			throw std::out_of_range("index out of range");
	}
	void sort( bool (*f)(T,T) ) { 
		if(f == nullptr){
			for(uintptr_t i=0; i<c; i++){
				for(uintptr_t j=0; j<c-i-1; j++){
					if( node[j+1].val < node[j].val ){
						TreeNode<T> temp;
						temp = node[j+1];
						node[j+1] = node[j];
						node[j] = temp;
					}
				}
			}
		} else {
			for(uintptr_t i=0; i<c; i++){
				for(uintptr_t j=0; j<c-i-1; j++){
					if( f(node[j+1].val,node[j].val) == true ){
						TreeNode<T> temp;
						temp = node[j+1];
						node[j+1] = node[j];
						node[j] = temp;
					}
				}
			}
		}
	}
	uintptr_t count() {
		uintptr_t count = c;
		for(uintptr_t i=0; i<c; i++){
			count += node[i].count();
		}
		return count;
	};
};

template<typename T>
class Tree {
	public:
	TreeNode<T> root;
	Tree(T v){
		root = TreeNode<T>(v);
	}
	void add_node(TreeNode<T>* parent, T val){
		if(parent == nullptr){
			root.add_node(val);
		} else {
			parent->add_node(val);
		}
	}
	TreeNode<T>* get_node(TreeNode<T>* node, uintptr_t index){
		if (node == nullptr){
			return root.get_node(index);
		} else {
			return node->get_node(index);
		}
	}
	void delete_node(TreeNode<T>* node, uintptr_t index){
		if (node == nullptr){
			root.delete_node(index);
		} else
			node->delete_node(index);
	}
	TreeNode<T>* find(bool (*f)(T)){
		return root.find(f);
	}
	void insert(TreeNode<T>* parent, uintptr_t index, T val){
		if (parent == nullptr){
			root.insert_node(index, val);
		} else {
			parent->insert_node(index, val);
		}
	}
	void sort(TreeNode<T>* node, bool (*f)(T,T)){
		if(node == nullptr){
			root.sort(f);
		} else {
			node->sort(f);
		}
	}
	uintptr_t count(){
		return root.count();
	}
};
