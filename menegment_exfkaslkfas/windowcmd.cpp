#include <windows.h> // Для работы с Windows API

void setConsoleSize(int width, int height) {

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // Получаем текущие размеры окна

    // Изменяем размер окна
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void lockConsoleResize() {
    HWND console = GetConsoleWindow();
    // Убираем кнопки изменения размера
    LONG style = GetWindowLong(console, GWL_STYLE);
    style &= ~WS_SIZEBOX; // Убираем возможность растягивать окно
    style &= ~WS_MAXIMIZEBOX; // Убираем кнопку максимизации
    SetWindowLong(console, GWL_STYLE, style);

    // Фиксируем размер буфера консоли (запрет прокрутки)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
    SMALL_RECT rect = bufferInfo.srWindow;

    // Устанавливаем размеры буфера равными окну
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

void useRus()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}