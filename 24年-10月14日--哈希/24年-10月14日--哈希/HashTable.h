#pragma once
#define _CRT_SECURE_NO_WARNINGS 1



#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>


using namespace std;

enum State {
	EXIST,
	EMPTY,
	DELETE
};

template<class K, class V> 
struct HashData {
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K, class V>
class HashTable {
public:
	HashTable()
		:_tables(11)
		, _n(0)
	{}

	bool Insert(const pair<K, V>& kv) {
		// 负载因子 >= 0.7 扩容
		if (_n * 10 / _tables.size() >= 7) {
			// 法1
			//vector<HashData<K, V>> newtables(_tables.size() * 2);
			//for (auto& data : _tables) {
			//	// 旧表的数据映射到新表
			//	if (data._state == EXIST) {
			//		size_t hash0 = data.kv.first % newtables.size();
			//	}
			//}
			//_tables.swap(newtables);

			// 法2
			HashTable<K, V> newht;
			newht._tables.resize(_tables.size() * 2);
			for (auto& data : _tables) {
				// 旧表的数据映射到新表
				if (data._state == EXIST) {
					newht.Insert(data._kv);
				}
			}
			_tables.swap(newht._tables);
		}


		size_t hash0 = kv.first % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		int flag = 1;
		while (_tables[hashi]._state == EXIST) {
			// 二次线性探测
			/*hashi = (hash0 + i * i * flag) % _tables.size();
			if (flag == 1) {
				flag = -1;
			}
			else {
				++i;
				flag = 1;
			}*/

			// 线性探测
			hashi = (hash0 + i++) % tables.size();
		}
		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;
		return true;
	}

	HashData<K, V>* Find(const K& key) {
		size_t hash0 = key % _tables.size();
		size_t hashi = hash0;
		size_t i = 1;
		while (_tables[hashi]._state != EMPTY) {
			if (_tables[hashi]._kv.first == key) {
				return &_tables[hashi];
			}
			// 线性探测
			hashi = (hash0 + i++) % _tables.size();
		}
		return nullptr;
	}

	bool Erase(const K& key) {
		HashData<K, V>* ret = Find(key);
		if (ret) {
			ret->_state == DELETE;
			return true;
		}
		else return false;
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n = 0;
};
