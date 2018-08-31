checkerboard: checkerboard.c
	gcc checkerboard.c -o checkerboard

.PHONY: clean

clearn:
	$(RM) checkerboard


