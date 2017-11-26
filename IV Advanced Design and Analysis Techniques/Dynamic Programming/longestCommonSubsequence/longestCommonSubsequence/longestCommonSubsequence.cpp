#include "longestCommonSubsequence.h"

template<typename T>
void lcsLength(const vector<T>& _x, const vector<T>& _y, vector<vector<int32_t>>& _b, vector<vector<int32_t>>& _c)
{
	const int32_t oblique = 0;
	const int32_t up = 1;
	const int32_t left = -1;
	size_t xlen = _x.size();
	size_t ylen = _y.size();
	_b.resize(xlen, vector<int32_t>(ylen, 0));
	_c.resize(xlen+1, vector<int32_t>(ylen + 1, 0));


	// ����X��ǰ׺Xi��Y��ǰ׺Yj�е������������
	for (size_t i = 0; i < xlen; ++i)
	{
		for (size_t j = 0; j < ylen; ++j)
		{
			// ǰ׺ĩβ���
			if (_x[i] == _y[j])
			{
				// ���������г��ȼ�1
				_c[i+1][j+1] = _c[i][j] + 1;
				// ��Ƿ���
				_b[i][j] = oblique;
			}
			// Xi��Yj+1�Ĺ��������г��ȴ���Xi+1��Yj�Ĺ��������г���
			else if (_c[i][j+1] >= _c[i+1][j])
			{
				_c[i+1][j+1] = _c[i][j+1];
				_b[i][j] = up;
			}
			else
			{
				_c[i+1][j+1] = _c[i+1][j];
				_b[i][j] = left;
			}
		}
	}
}

template<typename T>
void printLcs(const vector<vector<int32_t>>& _b, const vector<T>& _x, int _i, int _j)
{
	const int32_t oblique = 0;
	const int32_t up = 1;
	if (_i < 0 || _j < 0)
	{
		return;
	}
	if (_b[_i][_j] == oblique)
	{
		printLcs(_b, _x, _i - 1, _j - 1);
		cout << _x[_i] << " ";
	}
	else if (_b[_i][_j] == up)
	{
		printLcs(_b, _x, _i - 1, _j);
	}
	else
	{
		printLcs(_b, _x, _i, _j - 1);
	}
}

template void lcsLength<string>(const vector<string>& _x, 
	const vector<string>& _y, vector<vector<int32_t>>& _b, vector<vector<int32_t>>& _c);

template void printLcs<string>(const vector<vector<int32_t>>& _b,
	const vector<string>& _x, int _i, int _j);