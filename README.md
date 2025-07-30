# C Program with Custom Software Icon (Windows)

This project demonstrates how to create a basic Windows application using the C programming language and set a custom `.ico` file as the application icon.

## 🧱 Features

- Windows GUI application
- Custom icon in the title bar and taskbar
- Minimal and clean structure

## 📁 Project Structure

```

project/
│
├── main.c            # Main C source code with window creation
├── resource.rc       # Resource script defining the icon
├── app\_icon.ico      # Custom .ico file used as the application icon

````

## 🖼️ Icon Setup

The icon is added through a Windows resource file (`.rc`) and loaded in the C code using the Windows API.

---

### 🔧 Code Example

#### `main.c`

```c
#include <windows.h>

#define IDI_APP_ICON 101

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyAppWindowClass";
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(
        wc.lpszClassName,
        "C App with Icon",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}
````

#### `resource.rc`

```rc
#define IDI_APP_ICON 101
IDI_APP_ICON ICON "app_icon.ico"
```

> Place your `.ico` file in the same directory as the source files and name it `app_icon.ico`.

---

## 🛠️ Build Instructions

Make sure you're using a Windows-compatible compiler like **MinGW**.

### Step 1: Compile the resource file

```bash
windres resource.rc -o resource.res
```

### Step 2: Compile the C source code with the resource

```bash
gcc main.c resource.res -o MyApp.exe -mwindows
```

> `-mwindows` is required to avoid opening a console window for GUI apps.

---

## ✅ Result

After running `MyApp.exe`, you’ll see a window with the custom icon in the top-left corner and taskbar.

---

## 📌 Notes

* Only works on Windows.
* Icon must be in `.ico` format.
* The resource ID (`IDI_APP_ICON`) must match in both `.rc` and C code.

---

## 📄 License

This project is open-source and free to use for educational or personal purposes.
