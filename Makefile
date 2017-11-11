CC = gcc
current_dir = $(shell pwd)
program: json_facility.c restful_facility.c main.c

	cd $(current_dir)/lib/jsmn && $(MAKE)

	$(CC) json_facility.c restful_facility.c main.c -I$(current_dir)/include -I$(current_dir)/lib/jsmn -L$(current_dir)/lib/jsmn -lcurl $(current_dir)/lib/jsmn/libjsmn.a -o second_client_assignment

clean:
	$(RM) program
