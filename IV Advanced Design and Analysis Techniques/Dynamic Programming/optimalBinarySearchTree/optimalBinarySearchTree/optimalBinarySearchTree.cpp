#include "optimalBinarySearchTree.h"

void optimalBst(const vector<float>& _p, const vector<float>& _q, size_t n, 
	vector<vector<float>>& _e, vector<vector<size_t>>& _r)
{
	// ��ʼ��
	_e.resize(n + 1, vector<float>(n + 1, 0));
	vector<vector<float>> w(n + 1, vector<float>(n + 1, 0));
	_r.resize(n, vector<size_t>(n, 0));

	// Ϊֻ�����ؼ���di���������ñ߽�����
	for (int32_t i = 0; i < n + 1; ++i)
	{
		_e[i+1][i] = _q[i];
		w[i+1][i] = _q[i];
	}

	// len��ki��kj�����ġ����ȡ�
	for (int32_t len = 0; len < n; ++len)
	{
		for (int32_t i = 0; i < n - len; ++i)
		{
			int32_t j = i + len;
			_e[i + 1][j + 1] = INT32_MAX;//numeric_limits<int32_t>::max();

			// ki��kj+1�������������� = ki��kj�������������� + kj+1�ڵ�������ɹ�Ƶ�� + kj+1�ڵ������ʧ��Ƶ��
			w[i][j+1] = w[i][j] + _p[j+1] + _q[j+1];
			for (int32_t r = i; r < j + 1; ++r)
			{
				int32_t t = _e[i + 1][r - 1] + _e[r + 1][j + 1] + w[i + 1][j + 1];
				if (t < _e[i + 1][j + 1])
				{
					_e[i + 1][j + 1] = t;
					_r[i][j] = r;
				}
			}
		}
	}
}
