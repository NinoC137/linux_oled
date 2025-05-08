#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#include "ssd1306_i2c.h"
#include "oled_fonts.h"

volatile sig_atomic_t stop = 0;

void handle_shutdown(int sig){
    ssd1306_command(SSD1306_DISPLAYOFF);
    stop = 1;
}

int main(){
    signal(SIGINT, handle_shutdown);

    ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
    char status_buffer[128*4] = {0};
    int byte_read = 0;

    while(!stop){
        // get_system_status(status_buffer, sizeof(status_buffer));
        byte_read = get_top_info(status_buffer, sizeof(status_buffer));
        status_buffer[byte_read] = '\0';

        ssd1306_clearDisplay();
        // ssd1306_drawString(status_buffer);
        ssd1306_drawBuffer(status_buffer, sizeof(status_buffer));
        ssd1306_display();
        delay(1000);
    }

    return 0;
}