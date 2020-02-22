@echo on
mbed compile --flash
copy .\BUILD\NUCLEO_F412ZG\GCC_ARM\*.bin .\ /Y
