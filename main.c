#include <stdio.h>
#include <unistd.h>
#include "display.h"

int main(void) {
    int hours, minutes, seconds;

    if (!open_display()) {
        fprintf(stderr, "Error opening display.\n");
        return 1;
    }

    while (scanf("%d:%d:%d", &hours, &minutes, &seconds) == 3) {
        display_time(hours, minutes, seconds);
        sleep(1);
    }

    close_display();
    return 0;
}
