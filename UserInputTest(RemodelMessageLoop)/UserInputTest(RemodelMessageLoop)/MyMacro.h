#pragma once


#define MAX(var, max)	((var < max) ? var : max)
#define MIN(var, min)	((var > min) ? var : min)
#define MINMAX(var, min, max)	(MAX(MIN(var, min), max))

//���밪
#define ABS(var)	((var > 0) ? var : -var)
//���� ��ȣ 1, -1
#define MARK(var)	((var > 0) ? 1 : -1)

//�߽� x, y�� ���� ������ r�� �׸�.
inline void SetCenterRect(RECT* lprt, int x, int y, int r)
{
	lprt->left = x - r;
	lprt->top = y - r;
	lprt->right = x + r;
	lprt->bottom = y + r;
}

inline BOOL PtInRectCheck(RECT* lprt, int x, int y)
{
	if (lprt->left > x || lprt->right < x
		|| lprt->bottom < y || lprt->top > y)
		return FALSE;

	return TRUE;
}