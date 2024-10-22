#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>


using namespace std;

inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}

enum State {
	EXIST,
	EMPTY,
	DELETE
};

template<class K>
struct HashFunc {
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};



template<class K, class V>
struct HashData {
	pair<K, V> _kv;
	State _state = EMPTY;
};

template<class K, class V, class Hash = HashFunc<K>>
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

		Hash hash;
		size_t hash0 = hash(kv.first) % _tables.size();

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
			hashi = (hash0 + i++) % _tables.size();
		}
		_tables[hashi]._kv = kv;
		_tables[hashi]._state = EXIST;
		++_n;
		return true;
	}

	HashData<K, V>* Find(const K& key) {
		Hash hash;
		size_t hash0 = hash(key) % _tables.size();
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
