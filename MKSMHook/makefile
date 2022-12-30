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

BASE_ADDRESS = 0x02020000
EE_LINKFILE = linkfile

EE_LDFLAGS = -Wl,--entry=init -Wl,-Map,../scripts/MKSMHook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'

all: $(EE_BIN)

PS2SDK = ../external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
