The purpose of this project is to create our very first daemon that will send notification to the user to tell him when he can take either a break or work time. 
The configuration are based into a `.cfg` file that will be parsed to retrieve the value that the user has changed.

# how to run the program 
```bash
make && make install-service

#producing this output

Pomodoro Timer service installed successfully!

Usage commands:
  Start service:  systemctl --user start pomodoro-timer
  Stop service:   systemctl --user stop pomodoro-timer
  Check status:   systemctl --user status pomodoro-timer
  View logs:      journalctl --user -u pomodoro-timer -f
  Restart:        systemctl --user restart pomodoro-timer
```
then you follow the usage command to set the status of the service.
Then depending on you configuration, your first notification will get on top of your desktop display withing `N` minutes. Meanwhile you're in working mode until contrary is explicitly asked

# current features
- long break support: timer now tracks session count and triggers long breaks based on the cycle setting
- 1. **Enhanced notifications**: Colorful notifications with emojis for different states (work 🍅, break ☕, long break 🌴)
- strict mode: When enabled, breaks block the screen with a countdown timer and can only be skipped with esc
	- the esc mode is more restrictive with confirmations and warnings
- session tracking keeps count of completed sessions
- visual countdown during strict mode breaks, show a live countdown with proper formatting
# new features in development
- send a notification to the phone,
- different texture of notificaiton
- blocking the computer during the break time (only when strict mode is enabled)
- during the  blocking time,you will see a chrono that decrease as long as the time advance until 0 to let you get back where you were
- [...]
# improvement concepts
[[RAII (ressource acquisition is initialization)]]
[[Smart pointers]]
[[factory pattern]]