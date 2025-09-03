```c
//singleton accessor
t_type *get_instance(t_type *set)
{
	static t_type *instance = NULL;

	if (!set)
		instance = set;
	return (instance);
}

```

The singleton pattern allow us to access from anywhere a normally forbidden access to an inner function. Like the signal_handler that forbid all custom parameters. It fits projects rules that restrict global variables access