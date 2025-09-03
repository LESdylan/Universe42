This project emulates some aspects of handling found in higher-level langages like C++ or Jave, but tailored to C's constraints. 

# How the Error Module acts like an exception Framework

in languages iwht built-in expection handling `(try/catch)` , exceptions are thrown, caught and processed with detailed information. C lacks native exceptions, so our `t_error` struct, vtable patterm, centralized `t_error_code` and `t_error_data` union create a structured way to mimic this behavior. Here's  how it functions as a framework for "capturing exceptions in C":
1. Error detections and Propagation:
	- Like expection: in C++, an exception is thrown when an error occurs, carrying type and context information, functions like `parse_file` or `init_renderer` create a `t_error` object when an error occurs (file open failure, invalid data), which is returned to the called, similar to throwing an exception.
	- **in my code** :: Instead of returning a simple `bool` or `int`, functions return a `t_error* ` that encapsulate the error code (t_error_code) and module_specific details (t_error_data), propagating the error up to `main` 

## Key features of the framework
- centralized error codes
- module-specific handling
- automatic error processing
- resource safety

