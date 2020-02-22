#include "mbed.h"
// NOTE: Need "target.components_add": ["SD"] in json project file!
// This adds the filesystem driver below for SD cards in a project
#include "SDBlockDevice.h"
#include "FATFileSystem.h"
Serial pc(USBTX,USBRX); //change for your mbed serial port
SDBlockDevice sd(PC_12, PC_11, PC_10, PC_9);
FATFileSystem fs("SD");
char filereadchar=0;
 
int main()
{
    sd.init();
    fs.mount(&sd);
// open and write a message in a new file
    FILE* fw = fopen("/SD/hi.txt", "w");
    if(fw == NULL) {
        error("Could not open new file for write\n\r");
    }
    printf("Writing to SD file: hello SD Card!\n\r");
    fprintf(fw, "hello SD card!\n\r");
    fclose(fw);
    printf("\nFile closed for write\n\n\r");
// open and read back file characters to serial for test
    FILE* fr = fopen("/SD/hi.txt", "r");
    if(fr == NULL) {
        error("Could not open new file for read\n\r");
    }
    printf("Reading back from new file: ");
    while(fscanf(fr,"%c",&filereadchar) == 1) {
        printf("\%c",filereadchar);
    }
    fclose(fr);
    sd.deinit();
    fs.unmount();
    printf("\nSD demo complete\n\r");
}

/* #include "mbed.h"
 
#if defined (DEVICE_CAN) || defined(DOXYGEN_ONLY)
 
DigitalOut led1(LED1);
DigitalOut led2(LED2);

CAN can1(PB_8, PB_9); //CAN RX_pin , TX_pin 
CAN can2(PB_12, PB_13); //CAN RX_pin , TX_pin 
char counter = 0;
 
int main() {
    printf("main()\r\n");
    CANMessage msg;
	printf("can1 speed SET: %d\r\n", can1.frequency(10000));
	printf("can2 speed SET: %d\r\n", can2.frequency(10000));
	
    while(1) {
        printf("loop()\r\n");
		can1.write(CANMessage(1337, &counter, 1));
		counter++;
		led1 = !led1;
		wait(0.2);
        if(can2.read(msg)) {
            printf("Message received: %d\r\n", msg.data[0]);
            led2 = !led2;
        } 
        wait(1.0);
    }
}
 
#else
  #error CAN NOT SUPPORTED
  
#endif */

/* #include "mbed.h"
#include "USBSerial.h"
 
//Virtual serial port over USB
USBSerial serial;
 
int main(void) {
 
    while(1)
    {
        serial.printf("I am a virtual serial port\r\n");
        wait(1);
    }
}
 */

/* 
#include "mbed.h"
#include "rtos.h"
#include "TextLCD.h"

DigitalOut led1(LED1);
DigitalOut led2(LED3);

Serial pc(USBTX, USBRX); //open serial port
I2C i2c_lcd(I2C_SDA, I2C_SCL); // create i2c instance

TextLCD_I2C lcd(&i2c_lcd, 0x4E, TextLCD::LCD16x2); // create TextLCD instance

Thread thread;

void lcdDisplay() {
	lcd.cls(); // first clean LCD screen
    
	while (true) {
		lcd.locate(0, 0); 
		lcd.printf("Hello world");
		thread_sleep_for(3000);
		lcd.locate(0, 1);
		for (int i=0; i<100; i++) {
			// lcd.locate(0, 1);
			lcd.printf("%d,", i+1);
			pc.printf("%d\r\n", i);
			led2 = !led2;
			Thread::wait(20);
		}

		thread_sleep_for(3000);
		lcd.cls();
		thread_sleep_for(1000);
    }
}
	
 
int main() {
	thread.start(lcdDisplay);
	
	while (true) {
		led1 = !led1;
		thread_sleep_for(1000);
	}
} */

/* #include "mbed.h"
#include "platform/mbed_thread.h"
#include "TextLCD.h"
 
// Blinking rate in milliseconds
#define BLINKING_RATE_MS 100

DigitalOut LG(led11);

I2C i2c_lcd(I2C_SDA, I2C_SCL);
TextLCD_I2C lcd(&i2c_lcd, 0x4E, TextLCD::LCD16x2);

int main()
{
    // Initialise the digital pin led11 as an output
	lcd.cls();
    while (true) {
		// thread_sleep_for(BLINKING_RATE_MS);
		lcd.locate(0, 0);
		lcd.printf("Hello world");

		for (int i=0; i<100; i++) {
			lcd.locate(0, 1);
			lcd.printf("%d", i);
			LG = !LG;
			wait(0.1);
		}
		wait(1.0);
		lcd.cls();

    }
}
 */
/* 
#include "mbed.h"
#include "TextLCD.h"

DigitalOut LG(led14);

I2C i2c_lcd(dp5, dp27);
TextLCD_I2C lcd(&i2c_lcd, 0x4E, TextLCD::LCD16x2);

int main(){
	lcd.cls();
	while(1){
		for(int i=0; i<5; i++){
			lcd.putc('hello' + i);
			LG = !LG;
			wait(0.5);
		}
		lcd.cls();
		wait(0.5);
	}
}
 */