# MSE_OS
Este es el repo de la materia de Implementación de sistemas operativos de la MSE2021.



### Estructura de archivos

```bash
    $ tree MSE_OS -L 1
MSE_OS
├── firmware_v2
├── LICENSE
├── MSE_OS
├── myOS
└── README.md

3 directories, 2 files
```

La carpeta **myOS** tiene la implementación personal del sistema operativo propuesto como trabajo práctico. La carpeta **MSE_OS** tiene el repo de la materia incluído como sub-módulo.

### Compilación en EDU-CIAA

Para compilar un projecto desde cero hace falta hacer clean, make y download con la placa conectada. 

Para esto, nos posicionamos en el directorio del firmware_v2 y ejecutamos:

```bash
~MSE_OS/firmware_v2$ make erase 
~MSE_OS/firmware_v2$ make clean
~MSE_OS/firmware_v2$ make
~MSE_OS/firmware_v2$ make download 
```

A continuación se muestran resultados parciales de la salida exitosa de cada comando. 

```bash
~MSE_OS/firmware_v2$ make erase 

Erasing flash memory...
Open On-Chip Debugger 0.10.0
Licensed under GNU GPL v2
For bug reports, read
	http://openocd.org/doc/doxygen/bugs.html
adapter speed: 2000 kHz
Info : auto-selecting first available session transport "jtag". To override use 'transport select <transport>'.
none separate
cortex_m reset_config vectreset
Info : clock speed 2000 kHz
Info : JTAG tap: lpc4337.m4 tap/device found: 0x4ba00477 (mfg: 0x23b (ARM Ltd.), part: 0xba00, ver: 0x4)
Info : JTAG tap: lpc4337.m0 tap/device found: 0x0ba01477 (mfg: 0x23b (ARM Ltd.), part: 0xba01, ver: 0x0)
Info : lpc4337.m4: hardware has 6 breakpoints, 4 watchpoints
Info : lpc4337.m0: hardware has 2 breakpoints, 1 watchpoints
target halted due to debug-request, current mode: Thread 
xPSR: 0x81000000 pc: 0x1a0003dc msp: 0x10000500
erased sectors 0 through 14 on flash bank 0 in 0.168609s
Erase done.

~MSE_OS/firmware_v2$ make clean

Clean project...

rm -f out/lpc4337_m4/obj/*.*
rm -f out/lpc4337_m4/*.*
rm -f *.launch
Clean complete.

~MSE_OS/firmware_v2$ make
Build project...
make[1]: Entering directory '/home/charlieromano/Documents/Academico/MSE/OS/MSE_OS/firmware_v2'
*** compiling C file modules/lpc4337_m4/base/src/cr_startup_lpc43xx.c ***
*** compiling C file modules/lpc4337_m4/base/src/sysinit.c ***
*** compiling C file modules/lpc4337_m4/base/src/cr_start_m0.c ***
...
*** post-build ***
~MSE_OS/firmware_v2$ make download 
*** linking project MSE_OS ***
   text	   data	    bss	    dec	    hex	filename
   5884	      4	   2068	   7956	   1f14	out/lpc4337_m4/MSE_OS.axf
copy from `out/lpc4337_m4/MSE_OS.axf' [elf32-littlearm] to `out/lpc4337_m4/MSE_OS.bin' [binary]
*** post-build ***
Downloading MSE_OS.bin to lpc4337_m4...
Open On-Chip Debugger 0.10.0
...
shutdown command invoked
Download done.
```

El archivo **Makefile** de esta ejecución se encuentra en **firmware_v2/Makefile**. Sin embargo, en la línea 33 se incluye el archivo **project.mk**:

```bash
33 -include project.mk

34 PROJECT ?= master
35 TARGET ?= lpc4337_m4
36 BOARD ?= edu_ciaa_nxp

```

El archivo project.mk contiene el siguiente extracto de código. Observar que dada la estructura del proyecto, para instanciar el repo de la materia MSE_OS indicamos con dos puntos que se encuentra un nivel más arriba del árbol de archivos:

```bash
#-------------------------------------------------------------------------------
# current project
#-------------------------------------------------------------------------------

PROJECT =  ../MSE_OS
#PROJECT = sapi_examples/edu-ciaa-nxp/bare_metal/gpio/gpio_03_blinky_switch
#PROJECT = sapi_examples/edu-ciaa-nxp/bare_metal/gpio/gpio_04_led_sequences

#-------------------------------------------------------------------------------
# current target
#-------------------------------------------------------------------------------

TARGET = lpc4337_m4
#TARGET = lpc4337_m0
#TARGET = lpc1769
#TARGET = lpc54102_m4
#TARGET = lpc54102_m0
#TARGET = lpc11u68

#-------------------------------------------------------------------------------
# current board (optional)
#-------------------------------------------------------------------------------

BOARD = edu_ciaa_nxp
#BOARD = ciaa_nxp
#BOARD = lpcxpresso1769

#-------------------------------------------------------------------------------

# Object file for multicore applications (only needed by lpc54102_m4 target if
# you need to add an lpc54102_m0 program). For example:
#SLAVE_OBJ_FILE = out/lpc54102_m0/blinky_m0.axf.o

#-------------------------------------------------------------------------------

```

