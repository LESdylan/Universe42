A daemon is like a security guard in a building:
- The guard works 24/7 in the background
- we don't see them constantly, but they're always there
- they repspond to specific events (alarms, visitors...)
- they have their own schedule and duties
- if something happens to them, the building management replace them

# What do we need to tackle when building our first daemon
When we create a daemon, we're essentially telling our operating system:
"Hey OS, I have this worker(program) that I want you to :"
1. keep running even if I log out
2. restart if it crashes - llike a persistent employee who always come back to work
3. start it automatically - When the computer booots, wake up this worker
4. give it ressources, CPU time, memory, file access
5. let it talk to other parts - network, desktop, notifications, sound system

## Core Concepts of System Daemon Integration:

### 1. **Process Management** (The Supervisor)

Like a factory supervisor who:

- Assigns work shifts (when to start/stop)
- Monitors worker health (is the process alive?)
- Handles worker replacement (restart on failure)

### 2. **Service Registration** (The Employee Database)

Like HR registering a new employee:

- Name and job description (service file)
- When they work (startup conditions)
- What department they belong to (user vs system service)

### 3. **Resource Permissions** (Security Badges)

Like giving an employee access cards:

- Which files they can read/write
- Which system calls they can make
- What network ports they can use

### 4. **Communication Channels** (Office Phone System)

Your daemon needs to:

- Listen for shutdown signals (like a fire alarm)
- Send notifications to users (like announcements)
- Log what it's doing (like a work diary)

## The Configuration We're Really Setting Up:

Think of it like **hiring a permanent night shift worker**:

1. **Job Description** (systemd service file): "Watch for 25-minute intervals, then ring the break bell"
2. **Work Schedule** (startup dependencies): "Start after the desktop is ready"
3. **Emergency Contacts** (signal handling): "If someone says 'STOP', finish your current task and go home"
4. **Work Tools** (environment variables): "You can use the speakers and notification system"
5. **Workplace Rules** (user permissions): "You work for this specific user, not the whole system"