#pragma once

#define IDB_BITMAP_TOOL                 130
#define ID_TOOL_POINT                   32805
#define ID_TOOL_LINE                    32806
#define ID_TOOL_RECT                    32807
#define ID_TOOL_RECTFILL                32808
#define ID_TOOL_ELLIPSE                 32809
#define ID_TOOL_ELLIPSEFILL             32810
#define ID_TOOL_CUBE					32811
#define ID_TOOL_OLINEO					32816
#define IDC_TOOLBAR                     32813


void OnCreate(HWND, HINSTANCE);
void OnSize(HWND);
void OnPointPressed();
void OnLinePressed();
void OnRectPressed();
void OnRectFPressed();
void OnEllipsePressed();
void OnEllipseFPressed();
void OnCubePressed();
void OnOLineOPressed();
void OnNotify(HWND, LPARAM);