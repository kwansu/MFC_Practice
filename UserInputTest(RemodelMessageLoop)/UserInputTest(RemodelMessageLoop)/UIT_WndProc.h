#pragma once

#include "UIT_Std.h"
#include <windowsx.h>

HRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
void Cls_OnDestroy(HWND hwnd);
void Cls_OnPaint(HWND hwnd);
void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
void Cls_OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags);
void Cls_OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
void Cls_OnRButtonUp(HWND hwnd, int x, int y, UINT flags);
void Cls_OnMouseMove(HWND hwnd, int x, int y, UINT keyFlags);
void Cls_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);

extern BOOL g_bRunGame;
extern HBITMAP g_hBmp_player, g_hBmp_NPC;