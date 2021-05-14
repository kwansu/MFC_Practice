#pragma once


#define MAX(var, max)	((var < max) ? var : max)
#define MIN(var, min)	((var > min) ? var : min)
#define MINMAX(var, min, max)	(MAX(MIN(var, min), max))

//절대값
#define ABS(var)	((var > 0) ? var : -var)
//값의 부호 1, -1
#define MARK(var)	((var > 0) ? 1 : -1)