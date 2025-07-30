#include "icon.h"

void setAppIcon(HINSTANCE hInstance, WNDCLASSEX *wc) {
    wc->hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
    wc->hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
}
