#!/bin/bash

gcc \
	-o gpio_morse \
	-lwiringPi \
	-std=c99 \
	-Wall \
	-Werror \
	gpio_morse.c

