
Each time I want to play a sound from youtube from any browser, the push the button start option from my keyboard, to see all the windows, a crash start immediately and disconnect myself from the server. need to relog to be able to work again but without sound. Besides I had another problem with the sound that disconnect each time I reboot the computer, so I have to use this command 
```bash
sudo modprobe snd-hda-intel # and resolve the problem i have
```

to ensure the module load on bot we have to add it properly into the configuration file :
`/etc/modules/`
```bash
echo snd-hda-intel | sudo tee -a /etc/modules
```


journalctl -b -i | grep -iE
above into the hyperlink we can see the crash log from this command

```bash
journalctl -b -i | grep -iE "snd|pulse|alpha|crash|segfault"
```

[[crash log from  18 june]]

and from this one 
```bash
dmesg | grep -iE "snd|hda|audio|error|fail"
```

[[error segfault]]

those log errors show that the error is from the keyboard
## segmentation  faults in libpango-1.0.so
- Repeated segmentation fault at 0... error 4 in labpango-1.0.so.0.5200.1 in various processes (gnome-character, mutter-x11-fram)
- These affect GNOMe's graphical components and can crash the session or affect compositor stability
## `snd_hda-inte` and too many BDL entries
- message like :
	- `snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152`
- this is known issue with some intel/Realtek/Creative HDA chips and certain kerne/driver combinations

> The session that craches are triggered by the segmentation fault in the graphics stack, not directly related to the sound system. However the crash disrupts audioi services, so we lose sound as a side effect

as previously said we can reload automatically the sound driver issue
1. load the module automatically at boot
   `echo snd-hda-intel | sudo tee -a /etc/modules`
2. BDL error workaround
   `snd-hda-intel.bdl_pos_adj=0` then `sudo update-grub`
3. dealing wih the graphics session crash (libpango)
	- update all system packages
	- if we have a non-standarsd Pango or GNOME package from a PPA or source, rever to the distribution stable packages
	- better to use x11 if we're onwayland
	- try using a differnt compositor/window manage (install and try KDE plasma or XFCE to see it the crash persists)
4. Apply the auto-load and kernel parameter suggestions for `snd_hda_intel`.
5. Fully update your system.
6. If you have custom GNOME/Pango packages, revert to Ubuntu defaults.
7. Try switching your session type (Wayland/X11) or desktop environment to see if the crash persists.