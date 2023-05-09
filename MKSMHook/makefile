EE_BIN = ../scripts/MKSMHook.elf
EE_OBJS = main.o \
mips.o \
ps2mem.o \
mouse.o \
hook.o \
menu.o \
mksm\vector.o \
mksm\core.o \
mksm\pad.o \
mksm\draw.o \
mksm\camera.o \
mksm\minterface.o \
freecamera.o \
mksm\pxMath.o \
mksm\string_dict.o \
select.o


PS2_BUILD = 0

NEWLIB_NANO = 1
KERNEL_NOPATCH = 1

ifeq ($(PS2_BUILD), 1)
# PS2
BASE_ADDRESS = 0x800000
else
# PC
BASE_ADDRESS = 0x02020000
endif

ifeq ($(PS2_BUILD), 1)
EE_LINKFILE = linkfile_ps2
else
EE_LINKFILE = linkfile
endif

ifeq ($(PS2_BUILD), 1)
EE_CFLAGS =  -fno-zero-initialized-in-bss
endif

EE_LDFLAGS = -Wl,--entry=init -Wl,-Map,../scripts/MKSMHook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'

all: $(EE_BIN)

PS2SDK = ../external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
ifeq ($(PS2_BUILD), 1)
include eemakefile.eeglobal
else
include $(PS2SDK)/samples/Makefile.eeglobal
endif




