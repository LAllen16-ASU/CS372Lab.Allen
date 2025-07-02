#pragma once
#include <iostream>
#include <assert.h>
#include <functional>

template <typename T>
class Tree 
{
	struct Node
	{
		Node(std::shared_ptr<const Node> left, T val, std::shared_ptr<const Node> right) : _left(left), _val(val), _right(right) {}
		std::shared_ptr<const Node> _left;
		T _val;
		std::shared_ptr<const Node> _right;
	};

	explicit Tree(std::shared_ptr<const Node> node) : _root(node) {}

private:
	std::shared_ptr<const Node> _root;

public:
	Tree() : _root(nullptr) {}
	Tree(Tree const& other) = default;
	Tree& operator=(Tree const& other) = default;
	~Tree() = default;
	Tree(Tree&& other) = default;
	Tree& operator=(Tree&& other) = default;

	Tree(Tree left, T val, Tree right) : _root(std::make_shared<Node>(left._root, val, right._root)) {}

	Tree(std::initializer_list<T> init)
	{
		Tree t;
		for (T v : init)
		{
			t = t.insert(v);
		}
		_root = t._root;
	}

	bool isEmpty() const { return !_root; }

	size_t size() const
	{
		if (isEmpty()) return 0;
		return 1 + left().size() + right().size();
	}

	T root() const
	{
		assert(!isEmpty());
		return _root->_val;
	}

	Tree left() const
	{
		assert(!isEmpty());
		return Tree(_root->_left);
	}

	Tree right() const
	{
		assert(!isEmpty());
		return Tree(_root->_right);
	}

	template <typename Compare=std::greater<T>>
	Tree insert(T x, Compare comp = std::greater<T>()) const
	{
		if (isEmpty())
		{
			return Tree(Tree(), x, Tree());
		}
		T y = root();
		if (comp(x, y))
		{
			return Tree(left().insert(x, comp), y, right());
		}
		else if (comp(y, x))
		{
			return Tree(left(), y, right().insert(x, comp));
		}
		else
		{
			return *this;
		}
	}

	template <typename Compare=std::greater<T>>
	bool member(T x, Compare comp = std::greater<T>()) const
	{
		if (isEmpty())
		{
			return false;
		}
		T y = root();
		if (comp(x, y))
		{
			return left().member(x, comp);
		}
		else if (comp(y, x))
		{
			return right().member(x, comp);
		}
		else
		{
			return true;
		}
	}

	void preorder(std::function<void(T)> visit) const
	{
		if (isEmpty())
		{
			return;
		}
		T contents = root();
		visit(contents);
		left().preorder(visit);
		right().preorder(visit);
	}

	void inorder(std::function<void(T)> visit) const
	{
		if (isEmpty())
		{
			return;
		}
		left().inorder(visit);
		T contents = root();
		visit(contents);
		right().inorder(visit);
	}

	void postorder(std::function<void(T)> visit) const
	{
		if (isEmpty())
		{
			return;
		}
		left().postorder(visit);
		right().postorder(visit);
		T contents = root();
		visit(contents);
	}

	
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree)
{
	if (tree.isEmpty())
	{
		os << "[]";
		return os;
	}
	os << "[";
	tree.preorder([&os](T val) { os << val << " ";});
	os << "]";
	return os;
}

