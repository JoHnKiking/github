#pragma once
#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;

// 请完成哈希表的如下操作
// 哈希函数采用除留余数法﻿
template<class K>
struct HashFunc {
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};

// 哈希表中支持字符串的操作
template<>
struct HashFunc<string> {
	size_t operator()(const string& key) {
		size_t hash = 0;
		for (auto e : key) {
			hash *= 31;
			hash += e;
		}
		return hash;
	}
};

// 以下采用开放定址法，即线性探测解决冲突
namespace open_address {
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

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable {
	public:
		HashTable() {
			_tables.resize(10);
		}

		

		bool Insert(const pair<K, V>& kv) {
			// 扩容
			if (_n * 10 >= _tables.size() * 7) {
				HashTable<K, V> NewHash;
				NewHash._tables.resize(_tables.size() * 2);
				for (auto kvv : _tables) {
					if (kvv._state == EXIST) {
						NewHash.Insert(kvv._kv);
					}
				}
				_tables.swap(NewHash._tables);
			}
		

			// 插入
			size_t hash0 =kv.first % _tables.size();
			size_t hashi = hash0;
			size_t i = 0;
			while (_tables[hashi]._state == EXIST) {
				hashi = (hash0 + ++i) % _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;
			return true;
		}

		// 查找
		HashData<K, V>* Find(const K& key) {
			int hash0 = key % _tables.size();
			int hashi = hash0;
			int i = 0;
			while (_tables[hashi]._state != EMPTY) {
				if (_tables[hashi]._kv.first = key) {
					return&_tables[hashi];
				}
				hashi = (hash0 + ++i) % _tables.size();
			}
			return nullptr;
		}

		// 删除
		bool Erase(const K& key)
		{
			int hash0 = key % _tables.size();
			int hashi = hash0;
			int i = 0;
			while (_tables[hashi]._state != EMPTY) {
				if (_tables[hashi]._kv.first = key) {
					_tables[hashi]._state = DELETE;
					return true;
				}
				hashi = (hash0 + ++i) % _tables.size();
			}
			return false;
		}

		// 遍历
		void Print() {
			for (const auto& e : _tables) {
				if (e._state == EXIST) cout << e._kv.second << " ";
			}
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;  // 表中存储数据个数
	};
}


// 实现完成后，请对整形和字符串完成测试

