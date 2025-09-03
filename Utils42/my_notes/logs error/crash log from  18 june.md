dlesieur@dlesieur42:~$ journalctl -b -1 | grep -iE "snd|pulse|alsa|crash|segfault"
Jun 18 08:23:54 dlesieur42 kernel: x86/split lock detection: #AC: crashing the kernel on kernel split_locks and warning on user-space split_locks
Jun 18 08:23:55 dlesieur42 kernel: pstore: Using crash dump compression: deflate
Jun 18 08:23:57 dlesieur42 systemd[1]: Started whoopsie.path - Start whoopsie on modification of the /var/crash directory.
Jun 18 08:23:57 dlesieur42 systemd[1]: apport-forward.socket - Unix socket for apport crash forwarding was skipped because of an unmet condition check (ConditionVirtualization=container).
Jun 18 08:24:04 dlesieur42 systemd[1]: Starting kerneloops.service - Tool to automatically collect and submit kernel crash signatures...
Jun 18 08:24:04 dlesieur42 systemd[1]: Started kerneloops.service - Tool to automatically collect and submit kernel crash signatures.
Jun 18 08:24:05 dlesieur42 systemd[5120]: drkonqi-coredump-cleanup.timer - Cleanup lingering KCrash metadata was skipped because of an unmet condition check (ConditionPathExistsGlob=/var/lib/lightdm/.cache/kcrash-metadata/*.ini).
Jun 18 08:24:05 dlesieur42 systemd[5120]: Listening on drkonqi-coredump-launcher.socket - Socket to launch DrKonqi for a systemd-coredump crash.
Jun 18 08:24:05 dlesieur42 systemd[5120]: Listening on pipewire-pulse.socket - PipeWire PulseAudio.
Jun 18 08:24:05 dlesieur42 systemd[5120]: drkonqi-coredump-cleanup.service - Cleanup lingering KCrash metadata was skipped because of an unmet condition check (ConditionPathExistsGlob=/var/lib/lightdm/.cache/kcrash-metadata/*.ini).
Jun 18 08:24:05 dlesieur42 systemd[5120]: Started pipewire-pulse.service - PipeWire PulseAudio.
Jun 18 08:24:12 dlesieur42 systemd[5245]: drkonqi-coredump-cleanup.timer - Cleanup lingering KCrash metadata was skipped because of an unmet condition check (ConditionPathExistsGlob=/home/dlesieur/.cache/kcrash-metadata/*.ini).
Jun 18 08:24:12 dlesieur42 systemd[5245]: Listening on drkonqi-coredump-launcher.socket - Socket to launch DrKonqi for a systemd-coredump crash.
Jun 18 08:24:12 dlesieur42 systemd[5245]: Listening on pipewire-pulse.socket - PipeWire PulseAudio.
Jun 18 08:24:12 dlesieur42 systemd[5245]: drkonqi-coredump-cleanup.service - Cleanup lingering KCrash metadata was skipped because of an unmet condition check (ConditionPathExistsGlob=/home/dlesieur/.cache/kcrash-metadata/*.ini).
Jun 18 08:24:12 dlesieur42 systemd[5245]: Started pipewire-pulse.service - PipeWire PulseAudio.
Jun 18 08:24:22 dlesieur42 systemd[5120]: Closed drkonqi-coredump-launcher.socket - Socket to launch DrKonqi for a systemd-coredump crash.
Jun 18 08:24:22 dlesieur42 systemd[5120]: Stopping pipewire-pulse.service - PipeWire PulseAudio...
Jun 18 08:24:22 dlesieur42 systemd[5120]: Stopped pipewire-pulse.service - PipeWire PulseAudio.
Jun 18 08:24:22 dlesieur42 systemd[5120]: Closed pipewire-pulse.socket - PipeWire PulseAudio.
Jun 18 08:24:25 dlesieur42 kernel: gnome-character[6317]: segfault at 0 ip 0000783a68a946f4 sp 00007ffe145e0f28 error 4 in libpango-1.0.so.0.5200.1[783a68a82000+39000] likely on CPU 4 (core 8, socket 0)
Jun 18 08:30:28 dlesieur42 kernel: gnome-character[33883]: segfault at 0 ip 00007de4c05a86f4 sp 00007ffc87848da8 error 4 in libpango-1.0.so.0.5200.1[7de4c0596000+39000] likely on CPU 3 (core 4, socket 0)
Jun 18 08:30:30 dlesieur42 kernel: gnome-character[34081]: segfault at 0 ip 000078d08416d6f4 sp 00007fffb3a985e8 error 4 in libpango-1.0.so.0.5200.1[78d08415b000+39000] likely on CPU 0 (core 0, socket 0)
Jun 18 08:44:59 dlesieur42 kernel: xdg-desktop-por[6252]: segfault at 78f366490258 ip 000078f36a2d62e4 sp 00007ffc0c5867e8 error 4 in libfontconfig.so.1.12.1[78f36a2bc000+2f000] likely on CPU 7 (core 12, socket 0)
Jun 18 08:45:00 dlesieur42 systemd[1]: Started whoopsie.service - crash report submission.
Jun 18 08:45:01 dlesieur42 systemd[1]: Started whoopsie.service - crash report submission.
