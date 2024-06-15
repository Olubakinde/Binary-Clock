#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include "display.h"

#define WHITE 0xFFFF
#define RED   0xF800  // Red color
#define GREEN 0x07E0  // Green color
#define BLUE  0x001F  // Blue color
#define BLACK 0x0000

pi_framebuffer_t *fb;

int open_display(void) {
    if (fb == NULL) {
        fb = getFrameBuffer();
        if (fb == NULL) {
            fprintf(stderr, "Error: Couldn't open display.\n");
            return 0;
        }
        display_colons();
        return 1;
    } else {
        fprintf(stderr, "Error: Display already opened.\n");
        return 0;
    }
}

void display_time(int hours, int minutes, int seconds) {
    clearFrameBuffer(fb, BLACK);
    display_hours(hours);
    display_minutes(minutes);
    display_seconds(seconds);
    display_colons();
//    updateFrameBuffer(fb); // Make sure to update the framebuffer after making changes
}

void display_colons(void){
    sense_fb_bitmap_t *bm = fb->bitmap;
//     pi_framebuffer_t *fb = getFrameBuffer();
    bm->pixel[2][1] = WHITE;
    bm->pixel[2][2] = WHITE;
    bm->pixel[1][1] = WHITE;
    bm->pixel[1][2] = WHITE;
 //   bm->pixel[1][3] = WHITE;
    bm->pixel[1][4] = WHITE;
    bm->pixel[1][5] = WHITE;
    bm->pixel[2][4] = WHITE;
    bm->pixel[2][5] = WHITE;
    bm->pixel[4][5] = WHITE;
    bm->pixel[5][5] = WHITE;
    bm->pixel[5][4] = WHITE;
    bm->pixel[4][4] = WHITE;
    bm->pixel[4][1] = WHITE;
    bm->pixel[5][1] = WHITE;
    bm->pixel[4][2] = WHITE;
    bm->pixel[5][2] = WHITE;
}

void display_hours(int hours) {
    sense_fb_bitmap_t *bm = fb->bitmap;
    int binary_hours[5] = {0};

    // Convert hours to binary
    for (int i = 4; i >= 0; i--) {
        binary_hours[i] = hours % 2;
        hours /= 2;
    }

    // Display binary representation of hours in RED color
    for (int i = 0; i < 5; i++) {
        if (binary_hours[i] == 1)
            bm->pixel[0][i+1] = RED; // Display horizontally
    }
}

void display_minutes(int minutes) {
    sense_fb_bitmap_t *bm = fb->bitmap;
    int binary_minutes[6] = {0};

    // Convert minutes to binary
    for (int i = 5; i >= 0; i--) {
        binary_minutes[i] = minutes % 2;
        minutes /= 2;
    }

    // Display binary representation of minutes in GREEN color
    for (int i = 0; i < 6; i++) {
        if (binary_minutes[i] == 1)
            bm->pixel[3][i+1] = GREEN; // Display horizontally
    }
}


void display_seconds(int seconds) {
    sense_fb_bitmap_t *bm = fb->bitmap;
    int binary_seconds[6] = {0};

    // Convert seconds to binary
    for (int i = 5; i >= 0; i--) {
        binary_seconds[i] = seconds % 2;
        seconds /= 2;
    }

    // Display binary representation of seconds in BLUE color
    for (int i = 0; i < 6; i++) {
        if (binary_seconds[i] == 1)
            bm->pixel[6][i+1] = BLUE;
    }
}

void close_display(void) {
    if (fb != NULL) {
        clearFrameBuffer(fb, BLACK);
        fb = NULL;
    }
}
