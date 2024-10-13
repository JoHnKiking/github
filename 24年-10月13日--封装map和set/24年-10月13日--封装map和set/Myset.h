#include"RBTree.h"

using namespace std;

namespace my {
	template<class K>
	class set {
		struct SetKeyOfT {
			const K& operator()(const K& key) {
				return key;
			}
		}; 
	public:
		typedef typename RBTree<K, const K, SetKeyOfT>::Iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::Const_Iterator const_iterator;

		iterator begin() {
			return _t.Begin();
		}
		iterator end() {
			return _t.End();
		}
		const_iterator begin() const{
			return _t.Begin();
		}
		const_iterator end() const{
			return _t.End();
		}
		bool insert(const K& key) {
			return _t.Insert(key);
		}
	private:
		RBTree<K, const K, SetKeyOfT> _t;
	};
}


