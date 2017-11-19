#include "cutRod.h"

/**
 * ��̬�滮����Ҫ����ϸ�������˳�򣬶�ÿ��������ֻ���һ�Σ����������������
 * �´�ʹ��ʱֻ����ұ���Ľ��
 */

size_t memorizedCutRod(const vector<int>& _price, const size_t _length)
{
	vector<int> r(_length + 1, numeric_limits<int>::min());
	return memorizedCutRodAux(_price, _length, r);
}

size_t memorizedCutRodAux(const vector<int>& _price, const size_t _length, vector<int>& r)
{
	int _max = 0;
	/*��������ֵ��֪��ֱ�ӷ������ֵ*/
	if (r[_length] >= 0)
	{
		return r[_length];
	}
	/**/
	if (_length == 0)
	{
		_max = 0;
	}
	else
	{
		_max = numeric_limits<int>::min();
		
		for (int i = 1; i <= _length; i++)
		{
			/*�ֹܽ���i�磬��ʣ��n-i������Ž�*/
			int aux = _price[i - 1] + memorizedCutRodAux(_price, _length - i, r);
			_max = max(_max, aux);
		}
	}
	/*nӢ��ֹ����Ž�Ϊq*/
	r[_length] = _max;
	return _max;
}

size_t bottomUpCutRod(const vector<int>& _price, const size_t _length)
{
	vector<int> r(_length + 1, 0);
	/*r[0]*��һ���߽�*/
	r[0] = 0;

	/*��1~nӢ��ֹܵ����Ž�*/
	for (int i = 1; i <= _length; ++i)
	{
		/*��1~iӢ��ֹܵ����Ž�*/
		int _max = numeric_limits<int>::min();
		for (int j = 1; j <= i; ++j)
		{
			/*�ֹܽ���j�磬��ʣ��n-j������Ž�*/
			int temp = _price[j - 1] + r[i - j];
			_max = max(_max, temp);
		}
		r[i] = _max;
	}
	return r[_length];
}

void extendedBottomUpCutRod(const vector<int>& _price, const size_t _length, vector<int>& _optimal, vector<int>& _s)
{
	
	_optimal[0] = 0;
	/*��1~nӢ��ֹܵ����Ž�*/
	for (int i = 1; i <= _length; ++i)
	{
		/*��1~iӢ��ֹܵ����Ž�*/
		int _max = numeric_limits<int>::min();
		for (int j = 1; j <= i; ++j)
		{
			if (_max < _price[j - 1] + _optimal[i - j])
			{
				_max = _price[j - 1] + _optimal[i - j];
				_s[i] = j;
			}
		}
		_optimal[i] = _max;
	}
	//return _optimal[_length];
}

void printCutRodSolution(const vector<int>& _price, const size_t _length)
{
	vector<int> firstCut(_length + 1, 0);
	vector<int> optimal(_length + 1, 0);
	extendedBottomUpCutRod(_price, _length, optimal, firstCut);
	cout << "best cutting is ";
	int restLength = _length;
	while (restLength > 0)
	{
		cout << firstCut[restLength] << " ";
		restLength = restLength - firstCut[restLength];	
	}
	cout << endl << "price is " << optimal[_length] << endl;
}
