#include <iostream>
#include <vector>

using namespace std;

int lowerBit(int n)
{
	return n & -n;
}

struct ArbolBinarioIndexado
{
	vector<int> A;
	vector<int> Tree;

	ArbolBinarioIndexado(const vector<int> &A) : A(A), Tree(A.size(), 0)
	{
		for (int i = 1; i < Tree.size(); i++)
			fill(i, A[i - 1]);
	}
	int query(int a)
	{
		if (a > Tree.size() - 1)
		{
			return 0;
		}
		else
		{
			return query(a, Tree[a]);
		}
	}
	void update(int index, int nValue)
	{
		fill(index, nValue - Tree[index]);
	}
	void fill(int index, int nValue)
	{
		if (index > 0 && index < Tree.size())
		{
			Tree[index] += nValue;
			int hijo = buscarHijo(index);
			if (hijo > 0)
			{
				fill(hijo, nValue);
			}
		}
		else
		{
			return;
		}
	}

private:
	int query(int a, int val)
	{
		int padre = buscarPadre(a);
		if (padre > 0)
			return query(padre, val + Tree[padre]);
		else
			return val;
	}
	int buscarPadre(int index)
	{
		return index -= lowerBit(index);
	}
	int buscarHijo(int index)
	{
		int result = index += lowerBit(index);
		if (result <= Tree.size())
			return result;
		return 0;
	}
};

int main()
{
	int tamano = 0;
	int ops = 0;

	cin >> tamano >> ops;

	vector<int> nums(tamano + 1, 0);
	vector<int> perms(tamano + 1, 0);

	for (int i = 1; i <= tamano; i++)
	{
		cin >> perms[i];
	}

	ArbolBinarioIndexado fenwick(nums);
	ArbolBinarioIndexado fenwickPerm(nums);

	for (int i = 0; i < ops; i++)
	{
		int op = 0;
		int left = 0;
		int right = 0;

		cin >> op >> left >> right;

		if (op == 0 || op == 1)
		{
			int val = 0;
			cin >> val;
			for (int j = left; j <= right; j++)
			{
				// Fenwick normal
				int index = 0;
				if (op == 0)
				{
					index = j;
				}
				else
				{
					index = perms[j];
				}
				fenwick.fill(index, val);
				// Fenwick permutado
				index = 0;
				if (op == 0)
				{
					index = perms[j];
				}
				else
				{
					index = j;
				}
				fenwickPerm.fill(index, val);
			}
		}
		else
		{
			int res = 0;
			if (op == 2)
			{
				if (left == 1)
				{
					res = fenwick.query(right);
				}
				else
				{
					res = fenwick.query(right) - fenwick.query(left - 1);
				}
			}
			else
			{
				if (left == 1)
				{
					res = fenwickPerm.query(right);
				}
				else
				{
					res = fenwickPerm.query(right) - fenwickPerm.query(left - 1);
				}
			}

			cout << res << "\n";
		}
	}
	return 0;
}
