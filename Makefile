all:
	# gcc oled_display.c get_system_info.c ssd1306_i2c.c -lwiringPi -li2c -o oled_display
	gcc oled_display.c get_system_info.c ssd1306_i2c.c -li2c -o oled_display