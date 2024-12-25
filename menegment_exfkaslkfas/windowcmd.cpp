#include <windows.h> // ��� ������ � Windows API

void setConsoleSize(int width, int height) {

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // �������� ������� ������� ����

    // �������� ������ ����
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void lockConsoleResize() {
    HWND console = GetConsoleWindow();
    // ������� ������ ��������� �������
    LONG style = GetWindowLong(console, GWL_STYLE);
    style &= ~WS_SIZEBOX; // ������� ����������� ����������� ����
    style &= ~WS_MAXIMIZEBOX; // ������� ������ ������������
    SetWindowLong(console, GWL_STYLE, style);

    // ��������� ������ ������ ������� (������ ���������)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
    SMALL_RECT rect = bufferInfo.srWindow;

    // ������������� ������� ������ ������� ����
    SetConsoleScreenBufferSize(hConsole, {
        static_cast<SHORT>(rect.Right - rect.Left + 1),
        static_cast<SHORT>(rect.Bottom - rect.Top + 1)
        });
}

void setColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = backgroundColor * 16 + textColor;
    SetConsoleTextAttribute(hConsole, color);
}