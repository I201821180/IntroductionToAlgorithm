#include "cutRod.h"

/**
 * ��̬�滮����Ҫ����ϸ�������˳�򣬶�ÿ��������ֻ���һ�Σ����������������
 * �´�ʹ��ʱֻ����ұ���Ľ��
 */

size_t memorizedCutRod(const vector<int>& p, size_t n)
{
	vector<int> r(n+1, numeric_limits<int>::min());
	return memorizedCutRodAux(p, n, r);
}

size_t memorizedCutRodAux(const vector<int>& p, size_t n, vector<int>& r)
{
	int q = 0;
	/*��������ֵ��֪��ֱ�ӷ������ֵ*/
	if (r[n] >= 0)
	{
		return r[n];
	}
	/**/
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = numeric_limits<int>::min();
		
		for (int i = 1; i <= n; i++)
		{
			/*�ֹܽ���i�磬��ʣ��n-i������Ž�*/
			int aux = p[i - 1] + memorizedCutRodAux(p, n - i, r);
			q = max(q, aux);
		}
	}
	/*nӢ��ֹ����Ž�Ϊq*/
	r[n] = q;
	return q;
}

size_t bottomMemorizedCutRod(const vector<int>& p, size_t n)
{
	vector<int> r(n + 1, 0);
	/*r[0]*��һ���߽�*/
	r[0] = 0;

	/*��1~nӢ��ֹܵ����Ž�*/
	for (int i = 1; i <= n; ++i)
	{
		/*��1~iӢ��ֹܵ����Ž�*/
		int q = numeric_limits<int>::min();
		for (int j = 1; j <= i; ++j)
		{
			/*�ֹܽ���j�磬��ʣ��n-j������Ž�*/
			int temp = p[j - 1] + r[i - j];
			q = max(q, temp);
		}
		r[i] = q;
	}
	return r[n];
}
