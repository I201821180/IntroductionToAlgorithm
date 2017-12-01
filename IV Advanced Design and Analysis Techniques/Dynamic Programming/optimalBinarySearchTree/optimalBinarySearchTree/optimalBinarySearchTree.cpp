#include "optimalBinarySearchTree.h"

#define RANGE(_i, _from, _to) \
	for(int32_t _i = _from; _i < _to +1; ++_i)


void optimalBst(const vector<float>& _p, const vector<float>& _q, size_t _n, 
	vector<vector<float>>& _e, vector<vector<size_t>>& _r)
{
	// ��ʼ��
	_e.resize(_n + 2, vector<float>(_n + 1, 0));
	vector<vector<float>> w(_n + 2, vector<float>(_n + 1, 0));
	_r.resize(_n + 1, vector<size_t>(_n + 1, 0));

	// Ϊֻ�����ؼ���di���������ñ߽�����
	for (int32_t i = 1; i < _n + 2; ++i)
	{
		_e[i][i-1] = _q[i-1];
		w[i][i-1] = _q[i-1];
	}

	// len��ki~kj�����ġ����ȡ�
	//for (int32_t len = 1; len < _n + 1; ++len)
	RANGE(len, 1, _n)
	{
		//for (int32_t i = 1; i < _n - len + 2; ++i)
		// i��������ʼ��λ��
		// ���㳤��Ϊlen��ki��kj������������������
		RANGE(i, 1, _n - len + 1)
		{
			int32_t j = i + len - 1;
			_e[i][j] = FLT_MAX;//numeric_limits<int32_t>::max();

			// ki��kj+1�������������� = ki��kj�������������� + kj+1�ڵ�������ɹ�Ƶ�� + kj+1�ڵ������ʧ��Ƶ��
			w[i][j] = w[i][j - 1] + _p[j - 1] + _q[j];

			// ѡȡ���ڵ㣬ȡ���Ÿ��ڵ�
			for (int32_t r = i; r < j + 1; ++r)
			{
				/** ki~kj�������������� = ki~kr-1�������������������� 
				 *                     + kr+1~kj�������������������� 
				 *                     + ki~kj������Ϊ�������1�������ӵ���������
				 * ��������˼�ǣ���ki~kr-1�ڵ㵥���ó����ܴﵽ����������
				 * �������1����˼�ǣ�ki~kr-1�ڵ㹹�ɵĶ�����������kr�ڵ����������ki~kr-1�ڵ���Ⱦ�����1
				 */
				float t = _e[i][r - 1] + _e[r + 1][j] + w[i][j];
				if (t < _e[i][j])
				{
					_e[i][j] = t;
					_r[i][j] = r;
				}
			}
		}
	}
}

// ȥ��e��r��δʹ�õĿռ�
void optimalBstRe(const vector<float>& _p, const vector<float>& _q, size_t _n,
	vector<vector<float>>& _e, vector<vector<size_t>>& _r)
{
	// ��ʼ��
	_e.resize(_n + 1, vector<float>(_n + 1, 0));
	vector<vector<float>> w(_n + 1, vector<float>(_n + 1, 0));
	_r.resize(_n, vector<size_t>(_n, 0));

	// Ϊֻ�����ؼ���di���������ñ߽�����
	for (int32_t i = 0; i < _n + 1; ++i)
	{
		_e[i][i] = _q[i];
		w[i][i] = _q[i];
	}

	// len��ki��kj�����ġ����ȡ�
	//for (int32_t len = 1; len < _n + 1; ++len)
	RANGE(len, 1, _n)
	{
		//for (int32_t i = 1; i < _n - len + 2; ++i)
		RANGE(i, 0, _n - len)
		{
			int32_t j = i + len;
			_e[i][j] = FLT_MAX;//numeric_limits<int32_t>::max();

			// ki��kj+1�������������� = ki��kj�������������� + kj+1�ڵ�������ɹ�Ƶ�� + kj+1�ڵ������ʧ��Ƶ��
			w[i][j] = w[i][j - 1] + _p[j - 1] + _q[j];
			// ѡȡ���ڵ㣬
			for (int32_t r = i + 1; r < j + 1; ++r)
			{
				float t = _e[i][r - 1] + _e[r][j] + w[i][j];
				if (t < _e[i][j])
				{
					_e[i][j] = t;
					_r[i][j - 1] = r;
				}
			}
		}
	}
}
