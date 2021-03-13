#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *device_name;

void turn_on()
{
	int len;
	char *command;
	len = snprintf(NULL, 0, "brightnessctl --device=%s set 100%% > /dev/null", device_name);
	command = malloc(len + 1);
	snprintf(command, len + 1, "brightnessctl --device=%s set 100%% > /dev/null", device_name);
	system(command);
	free(command);
}
void turn_off()
{
	int len;
	char *command;
	len = snprintf(NULL, 0, "brightnessctl --device=%s set 0%% > /dev/null", device_name);
	command = malloc(len + 1);
	snprintf(command, len + 1, "brightnessctl --device=%s set 0%% > /dev/null", device_name);
	system(command);
	free(command);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "You need to specify a device.\nYou can find your device in 'brightnessctl -l'\n");
		return 1;
	}
	device_name = argv[1];
	int last_status = 2;
	while(1)
	{
		FILE *file;
		char output[8];
		file = popen("audtool playback-status", "r");
		fgets(output, 8, file);
		if(strncmp(output, "playing", 8) == 0 && last_status != 0)
		{
			turn_on();
			last_status = 0;
		} else if(strncmp(output, "playing", 8) != 0 && last_status != 1)
		{
			turn_off();
			last_status = 1;
		}
		pclose(file);
		sleep(0.5);
	}
}
