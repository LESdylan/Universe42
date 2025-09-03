```bash
man ps
man pgrep
ls /proc/<pid>/fd
man kill ## to send datas to process



```

# why `/proc` matters ?
the `/proc` directory is the live metadata layer of linux. Every time a process is running,  linux maps is there, with the PID as a folder name. This is like a runtime metadata registry - but not tied to file inodes. So yes it's metadata, just not file metadata

## Send a confirmation of the message to the client

in server.c (sig_handler_server):
```c
// > sig_handler_server()
if (sig_data->bits_received == 8)
{
	if (sig_data->current_char == '\0')
	{
		print_and_reset_buffer();
		kill(info->si_pid, SIGUSR2); // confirms message complete
	}
	else
	{
		add_char_to_buffer(sig_data->current_char);
		kill(info->si_pid, SIGUSR1); //confirms character received
	}
}
else
	kill(info->si_pif, SIGUSR1) // confimr bits received
```

in client.c
```c
while (!get_signal_received(sig_data))
			usleep(10);    // waits for server confirmation
```

![[transmission bit message from minitalk]]


