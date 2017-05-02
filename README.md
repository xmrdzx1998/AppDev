# Github link: https://github.com/xmrdzx1998/AppDev
# AppDev
Raspberry Pi acoustic sensor project 

This project will turn a raspberry Pi 3 into an acoustic sensor

1. Configuration

	1.1 Hardware configuration

		A raspberry Pi 3 is recommended. If an older version of Pi is used, corresponding configuration might be changed.

		the Pi is mounted with a USB sound card, and plugged in a microphone.

		It is recommended to have Ethernet connection for your Pi.

	1.2 Software configuration

		The USB sound card has to be set as default audio device. To do so, you need to modify two files with the following contents:
		
		a) Use “lsusb” command to check if your USB sound card is mounted
		b) Use “sudo nano /etc/asound.conf”command and put following content to the file:
		pcm.!default {
  		type plug
		  slave {
		    pcm "hw:1,0"
		  }
		}
		ctl.!default {
		    type hw
		    card 1
		}

		c) Go to your home directory. Use “nano .asoundrc” command and put the same content to the file.
		d) Run “alsamixer” you should be able to see that USB sound card is the default audio device.

		If you are using Raspberry Jessie, you have to roll back alsa-utils to an early version.
		a) Use “sudo nano /etc/apt/sources.list” command and add the last line:

	 		deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
		 	# Uncomment line below then 'apt-get update' to enable 'apt-get source'
		 	#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
		 	deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi
			
	 	b) Run “sudo apt-get update”
	 	c) Run “sudo aptitude versions alsa-utils” to check if version 1.0.25 of alsa-util is available:
	 	d) Run “sudo apt-get install alsa-utils=1.0.25-4” to downgrade
	 	e) Reboot

