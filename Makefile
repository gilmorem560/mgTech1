#
# mgTech1 - Makefile
#
BIN 		= game

CC		= gcc
CFLAGS		= -g
LDFLAGS		= -lGL -lX11 -lasound

GRAPHICS =	src/graphics/glxcontext.o \
		src/graphics/glcontext.o \
		src/graphics/graphics.o
	
INPUT =		src/input/joystick_evdev.o \
		src/input/x11input.o \
		src/input/input.o
		
SOUND =		src/sound/sound-alsa.o \
		src/sound/sound.o
		
SCENE =		src/scene/model.o \
		src/scene/node.o \
		src/scene/scene.o
		
MODES =		src/modes/logo.o \
		src/modes/map.o \
		src/modes/modes.o
		
MODE_LOGO =	src/modes/logo_scene/models/triangle.o \
		src/modes/logo_scene/nodes/camera.o \
		src/modes/logo_scene/nodes/logo.o \
		src/modes/logo_scene/nodes/triangle.o
		
MODE_MAP =	src/modes/map_scene/models/triangle.o \
		src/modes/map_scene/nodes/camera.o \
		src/modes/map_scene/nodes/logo.o \
		src/modes/map_scene/nodes/triangle.o
	
MAIN = 		src/main.o

OBJS =		$(GRAPHICS) \
		$(INPUT) \
		$(SOUND) \
		$(SCENE) \
		$(MODES) \
		$(MODE_LOGO) \
		$(MODE_MAP) \
		$(MAIN)

main: $(OBJS)
	$(CC) -o $(BIN) $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	rm -f $(OBJS) $(BIN)
