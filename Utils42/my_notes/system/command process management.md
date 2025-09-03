# **⚙️ Essential Linux Commands for Process Management & System Control**

Managing processes in Linux is **crucial** whether you’re handling **system performance, monitoring running tasks, or scheduling jobs**. Here’s a **power-packed** list of commands that will help you become a **Linux process management ninja!** 🥷💻

---

## **🚀 Monitoring & Managing Processes**

| Command  | What It Does                                                      |
| -------- | ----------------------------------------------------------------- |
| `ps`     | List running processes (`ps aux` for detailed view).              |
| `top`    | Show real-time system usage (press `q` to exit).                  |
| `htop`   | An **interactive** `top` alternative (`htop` must be installed).  |
| `vmstat` | Display system performance (`vmstat 5` updates every 5 sec).      |
| `pidof`  | Get the process ID of a running program (`pidof firefox`).        |
| `pmap`   | Show memory usage of a process (`pmap <PID>`).                    |
| `lsof`   | List open files by processes (`lsof -i` for network connections). |

---

## **🔧 Controlling Processes**

|Command|What It Does|
|---|---|
|`kill <PID>`|Stop a process by ID (`kill 1234`).|
|`killall <process>`|Stop **all instances** of a process (`killall firefox`).|
|`pkill <name>`|Kill a process by **name pattern** (`pkill -9 chrome`).|
|`nohup`|Run a process **even after logout** (`nohup command &`).|
|`timeout <seconds> <command>`|Run a command for a limited time (`timeout 10s sleep 100`).|
|`sleep <seconds>`|Pause execution (`sleep 5`).|
|`fg`|Bring a background process to the foreground (`fg %1`).|
|`bg`|Resume a paused process in the background (`bg %1`).|

---

## **🎛 Prioritizing Processes**

|Command|What It Does|
|---|---|
|`nice -n <priority> <command>`|Start a process with a priority (`nice -n 10 myscript.sh`).|
|`renice <priority> <PID>`|Change priority of a running process (`renice -5 1234`).|

💡 _Lower values = higher priority (-20 highest, 19 lowest)._

---

## **🖥️ Terminal Multiplexing (Run Multiple Sessions)**

|Command|What It Does|
|---|---|
|`screen`|Create a **detached** terminal session (`screen -S mysession`).|
|`tmux`|A modern alternative to `screen` (`tmux new -s mysession`).|
|`exit`|Quit a terminal session.|

🔹 **To reconnect to a detached session:**

```bash
screen -r mysession
tmux attach -t mysession

```

---

## **📜 Logging & Debugging**

|Command|What It Does|
|---|---|
|`strace <command>`|Trace **system calls** (`strace ls`).|
|`dmesg`|Show **kernel messages** (use `dmesg|
|`journalctl -xe`|View **system logs** (`journalctl -u nginx.service`).|
|`history`|Show past commands (`history|

---

## **🛠️ User & Group Management**

|Command|What It Does|
|---|---|
|`whoami`|Show current user.|
|`groups`|Show groups you belong to.|
|`groupadd <group>`|Create a new group.|
|`usermod -aG <group> <user>`|Add user to a group.|
|`chfn`|Change user info (name, office, etc.).|
|`chsh`|Change **default shell** (`chsh -s /bin/zsh`).|
|`passwd`|Change **user password**.|

---

## **🕒 Scheduling Jobs**

|Command|What It Does|
|---|---|
|`crontab -e`|Edit cron jobs (run tasks automatically).|
|`at <time>`|Schedule a **one-time** job (`echo "ls"|
|`batch`|Run jobs **when system load is low**.|

🔹 **Example: Run backup every night at 2 AM**

```bash
crontab -e
0 2 * * * /home/user/backup.sh

```

---

## **💾 System Information**

|Command|What It Does|
|---|---|
|`free -h`|Show **RAM** usage.|
|`lscpu`|Display **CPU** details.|
|`lshw`|Show **detailed hardware** info.|
|`which <command>`|Find **binary location** (`which python`).|

---

## **⚡ System Shutdown & Restart**

|Command|What It Does|
|---|---|
|`shutdown -h now`|**Shutdown immediately**.|
|`shutdown -r now`|**Restart immediately**.|
|`reboot`|**Reboot the system**.|
|`halt`|Stop all system processes.|
|`poweroff`|**Turn off** the machine.|

---

## **💡 Pro Tips: Automate & Simplify!**

Tired of long commands? Use **aliases** to make life easier:

```bash
alias cls='clear'
alias ll='ls -lah'
alias mem='free -h'
alias psm='ps aux | grep'
alias htop='htop'

```

🔹 **Make it permanent** by adding it to `~/.bashrc`:

```bash
echo "alias cls='clear'" >> ~/.bashrc
source ~/.bashrc

```

---

## **👀 Final Thoughts**

With these commands, you have **full control** over system processes, logs, and performance. Master them, and you’ll **handle Linux like a boss!** 🚀

💻 **Happy managing, and may your `kill -9` always be intentional!** 😈