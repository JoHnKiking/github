#pragma once

namespace bit{
	template<class K>
	class unordered_set {
		struct SetKeyOfF {
			const K& operator() (const K& key) {
				return key;
			}
		}
	public:
		bool insert(const K& key) {
			return _ht.Insert(key);
		}

	private:
		hash_backet:
	};
}