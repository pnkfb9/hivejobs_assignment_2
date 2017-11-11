CC = gcc
current_dir = $(shell pwd)
program: json_facility.c restful_facility.c main.c

	cd $(current_dir)/lib/jsmn && $(MAKE)

	$(CC) json_facility.c restful_facility.c main.c -Iinclude -Ilib/jsmn -Llib/jsmn -lcurl lib/jsmn/libjsmn.a -o program

clean:
	$(RM) program
