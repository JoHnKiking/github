#include"RBTree.h"

using namespace std;

namespace my {
	template<class K, class V>
	class map {
		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::Const_Iterator const_iterator;

		iterator begin() {
			return _t.Begin();
		}
		iterator end() {
			return _t.End();
		}
		const_iterator begin() const {
			return _t.Begin();
		}
		const_iterator end() const {
			return _t.End();
		}
		bool insert(const pair<K, V>& key) {
			return _t.Insert(key);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}