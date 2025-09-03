```bash
dlesieur@dlesieur42:~$ sudo dmesg | grep -iE "snd|hda|audio|error|fail"
[sudo] password for dlesieur:               
[    0.509896] RAS: Correctable Errors collector initialized.
[   95.048007] thermal thermal_zone1: failed to read out thermal zone (-61)
[   95.319740] thermal thermal_zone1: failed to read out thermal zone (-61)
[  976.137959] gnome-character[66170]: segfault at 0 ip 0000778d399ba6f4 sp 00007ffc7571c248 error 4 in libpango-1.0.so.0.5200.1[778d399a8000+39000] likely on CPU 8 (core 16, socket 0)
[ 1034.890541] gnome-character[72090]: segfault at 0 ip 00007ff79c0386f4 sp 00007ffc0fce6458 error 4 in libpango-1.0.so.0.5200.1[7ff79c026000+39000] likely on CPU 12 (core 24, socket 0)
[ 5824.539006] snd_hda_intel 0000:00:1f.3: enabling device (0000 -> 0002)
[ 5824.539336] snd_hda_intel 0000:03:00.1: enabling device (0000 -> 0002)
[ 5824.539481] snd_hda_intel 0000:03:00.1: Force to non-snoop mode
[ 5824.539516] snd_hda_intel 0000:06:00.0: enabling device (0000 -> 0002)
[ 5824.539547] snd_hda_intel 0000:06:00.0: Disabling MSI
[ 5824.539547] snd_hda_intel 0000:06:00.0: Force to non-snoop mode
[ 5824.546859] snd_hda_intel 0000:03:00.1: bound 0000:03:00.0 (ops amdgpu_dm_audio_component_bind_ops [amdgpu])
[ 5824.548434] input: HDA ATI HDMI HDMI/DP,pcm=3 as /devices/pci0000:00/0000:00:01.0/0000:01:00.0/0000:02:00.0/0000:03:00.1/sound/card1/input18
[ 5824.548474] input: HDA ATI HDMI HDMI/DP,pcm=7 as /devices/pci0000:00/0000:00:01.0/0000:01:00.0/0000:02:00.0/0000:03:00.1/sound/card1/input19
[ 5824.548536] input: HDA ATI HDMI HDMI/DP,pcm=8 as /devices/pci0000:00/0000:00:01.0/0000:01:00.0/0000:02:00.0/0000:03:00.1/sound/card1/input20
[ 5824.548564] input: HDA ATI HDMI HDMI/DP,pcm=9 as /devices/pci0000:00/0000:00:01.0/0000:01:00.0/0000:02:00.0/0000:03:00.1/sound/card1/input21
[ 5824.548598] input: HDA ATI HDMI HDMI/DP,pcm=10 as /devices/pci0000:00/0000:00:01.0/0000:01:00.0/0000:02:00.0/0000:03:00.1/sound/card1/input22
[ 5824.559927] snd_hda_codec_realtek hdaudioC0D0: autoconfig for ALC897: line_outs=4 (0x14/0x15/0x16/0x17/0x0) type:line
[ 5824.559933] snd_hda_codec_realtek hdaudioC0D0:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
[ 5824.559934] snd_hda_codec_realtek hdaudioC0D0:    hp_outs=1 (0x1b/0x0/0x0/0x0/0x0)
[ 5824.559935] snd_hda_codec_realtek hdaudioC0D0:    mono: mono_out=0x0
[ 5824.559935] snd_hda_codec_realtek hdaudioC0D0:    inputs:
[ 5824.559936] snd_hda_codec_realtek hdaudioC0D0:      Front Mic=0x19
[ 5824.559937] snd_hda_codec_realtek hdaudioC0D0:      Rear Mic=0x18
[ 5824.559937] snd_hda_codec_realtek hdaudioC0D0:      Line=0x1a
[ 5824.582246] snd_hda_codec_realtek hdaudioC2D1: autoconfig for ALC898: line_outs=3 (0x14/0x15/0x16/0x0/0x0) type:line
[ 5824.582250] snd_hda_codec_realtek hdaudioC2D1:    speaker_outs=0 (0x0/0x0/0x0/0x0/0x0)
[ 5824.582251] snd_hda_codec_realtek hdaudioC2D1:    hp_outs=1 (0x1b/0x0/0x0/0x0/0x0)
[ 5824.582252] snd_hda_codec_realtek hdaudioC2D1:    mono: mono_out=0x0
[ 5824.582252] snd_hda_codec_realtek hdaudioC2D1:    inputs:
[ 5824.582253] snd_hda_codec_realtek hdaudioC2D1:      Front Mic=0x19
[ 5824.582254] snd_hda_codec_realtek hdaudioC2D1:      Rear Mic=0x18
[ 5824.582254] snd_hda_codec_realtek hdaudioC2D1:      Line=0x1a
[ 5824.603031] input: HDA Creative Front Mic as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input31
[ 5824.603169] input: HDA Creative Rear Mic as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input32
[ 5824.603248] input: HDA Creative Line as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input33
[ 5824.603277] input: HDA Intel PCH Front Mic as /devices/pci0000:00/0000:00:1f.3/sound/card0/input23
[ 5824.603294] input: HDA Creative Line Out Front as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input34
[ 5824.604024] input: HDA Intel PCH Rear Mic as /devices/pci0000:00/0000:00:1f.3/sound/card0/input24
[ 5824.604298] input: HDA Creative Line Out Surround as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input35
[ 5824.605437] input: HDA Intel PCH Line as /devices/pci0000:00/0000:00:1f.3/sound/card0/input25
[ 5824.605478] input: HDA Creative Line Out CLFE as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input36
[ 5824.605531] input: HDA Intel PCH Line Out Front as /devices/pci0000:00/0000:00:1f.3/sound/card0/input26
[ 5824.605532] input: HDA Creative Front Headphone as /devices/pci0000:00/0000:00:1c.1/0000:06:00.0/sound/card2/input37
[ 5824.605632] input: HDA Intel PCH Line Out Surround as /devices/pci0000:00/0000:00:1f.3/sound/card0/input27
[ 5824.605792] input: HDA Intel PCH Line Out CLFE as /devices/pci0000:00/0000:00:1f.3/sound/card0/input28
[ 5824.605968] input: HDA Intel PCH Line Out Side as /devices/pci0000:00/0000:00:1f.3/sound/card0/input29
[ 5824.606112] input: HDA Intel PCH Front Headphone as /devices/pci0000:00/0000:00:1f.3/sound/card0/input30
[ 5824.788871] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6312.357987] traps: ThreadPoolSingl[72389] trap int3 ip:594ac20a437e sp:7e27bdf4e900 error:0 in obsidian[594abe020000+897a000]
[ 6314.002879] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6320.931855] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6325.746608] gnome-character[431948]: segfault at 0 ip 00007839709ba6f4 sp 00007ffe267ac8a8 error 4 in libpango-1.0.so.0.5200.1[7839709a8000+39000] likely on CPU 2 (core 4, socket 0)
[ 6329.008296] gnome-character[433534]: segfault at 0 ip 00007078d092c6f4 sp 00007ffc8e7906d8 error 4 in libpango-1.0.so.0.5200.1[7078d091a000+39000] likely on CPU 15 (core 27, socket 0)
[ 6343.469845] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6349.905418] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6353.288686] gnome-character[438577]: segfault at 0 ip 00007d16f30806f4 sp 00007ffe6e273638 error 4 in libpango-1.0.so.0.5200.1[7d16f306e000+39000] likely on CPU 7 (core 12, socket 0)
[ 6370.510312] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6376.972633] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6455.678480] mutter-x11-fram[442439]: segfault at 0 ip 00007ce032f016f4 sp 00007ffcdc649858 error 4 in libpango-1.0.so.0.5200.1[7ce032eef000+39000] likely on CPU 18 (core 30, socket 0)
[ 6456.053460] mutter-x11-fram[449597]: segfault at 0 ip 00007e67e8b646f4 sp 00007fff960d1fc8 error 4 in libpango-1.0.so.0.5200.1[7e67e8b52000+39000] likely on CPU 2 (core 4, socket 0)
[ 6456.387331] mutter-x11-fram[449645]: segfault at 0 ip 00007feb84d646f4 sp 00007ffef4aba148 error 4 in libpango-1.0.so.0.5200.1[7feb84d52000+39000] likely on CPU 4 (core 8, socket 0)
[ 6456.749786] mutter-x11-fram[449717]: segfault at 0 ip 00007c0c34b406f4 sp 00007ffc308c35f8 error 4 in libpango-1.0.so.0.5200.1[7c0c34b2e000+39000] likely on CPU 13 (core 25, socket 0)
[ 6457.128148] mutter-x11-fram[449777]: segfault at 0 ip 00007651dd07a6f4 sp 00007ffd2e72ce18 error 4 in libpango-1.0.so.0.5200.1[7651dd068000+39000] likely on CPU 19 (core 31, socket 0)
[ 6457.481937] mutter-x11-fram[449844]: segfault at 0 ip 00007faedddee6f4 sp 00007ffd119b7b18 error 4 in libpango-1.0.so.0.5200.1[7faeddddc000+39000] likely on CPU 9 (core 16, socket 0)
[ 6458.684952] mutter-x11-fram[449994]: segfault at 0 ip 000078fa34b646f4 sp 00007fff66da5e88 error 4 in libpango-1.0.so.0.5200.1[78fa34b52000+39000] likely on CPU 0 (core 0, socket 0)
[ 6459.062709] mutter-x11-fram[450096]: segfault at 0 ip 000079d4dd7d06f4 sp 00007ffde727b6f8 error 4 in libpango-1.0.so.0.5200.1[79d4dd7be000+39000] likely on CPU 15 (core 27, socket 0)
[ 6460.114629] mutter-x11-fram[450218]: segfault at 0 ip 000075335416c6f4 sp 00007ffddfb8ada8 error 4 in libpango-1.0.so.0.5200.1[75335415a000+39000] likely on CPU 13 (core 25, socket 0)
[ 6460.478681] mutter-x11-fram[450319]: segfault at 0 ip 000077c8dedd26f4 sp 00007ffe16965f78 error 4 in libpango-1.0.so.0.5200.1[77c8dedc0000+39000] likely on CPU 19 (core 31, socket 0)
[ 6461.615399] mutter-x11-fram[450518]: segfault at 0 ip 000075a5c85cc6f4 sp 00007ffd069f3d48 error 4 in libpango-1.0.so.0.5200.1[75a5c85ba000+39000] likely on CPU 9 (core 16, socket 0)
[ 6461.970083] mutter-x11-fram[450665]: segfault at 0 ip 0000750646eb96f4 sp 00007ffdd6f37598 error 4 in libpango-1.0.so.0.5200.1[750646ea7000+39000] likely on CPU 8 (core 16, socket 0)
[ 6463.959749] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6478.784877] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 6484.866756] gnome-character[454271]: segfault at 0 ip 0000756cfd2866f4 sp 00007ffd264a92b8 error 4 in libpango-1.0.so.0.5200.1[756cfd274000+39000] likely on CPU 0 (core 0, socket 0)
[ 6683.303708] gnome-character[467369]: segfault at 0 ip 000073656e3ba6f4 sp 00007ffc3757aed8 error 4 in libpango-1.0.so.0.5200.1[73656e3a8000+39000] likely on CPU 4 (core 8, socket 0)
[ 7178.430210] traps: ThreadPoolSingl[455282] trap int3 ip:60c74d4f837e sp:76a7b074e900 error:0 in obsidian[60c749474000+897a000]
[ 7180.111206] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 7187.943611] snd_hda_intel 0000:06:00.0: Too many BDL entries: buffer=1572864, period=49152
[ 7194.704563] gnome-character[505525]: segfault at 0 ip 00007610bb5ae6f4 sp 00007ffe6e639eb8 error 4 in libpango-1.0.so.0.5200.1[7610bb59c000+39000] likely on CPU 11 (core 20, socket 0)
[ 7202.687946] gnome-character[505810]: segfault at 0 ip 0000768302c366f4 sp 00007ffdb7bd1888 error 4 in libpango-1.0.so.0.5200.1[768302c24000+39000] likely on CPU 0 (core 0, socket 0)
dlesieur@dlesieur42:~$ d

```