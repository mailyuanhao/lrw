# lrw
linux下方便�?�取io�?口的小工�?
Please see the LICENSE file for details on copying and usage.
Please refer to the INSTALL file for instructions on how to build.

What is lrw:
  lrw is a tiny tool containing some useful commands which can be used to
  access hardware. for eaxmple get or set IO ports, PCI configurations... 
  
----------------

Using lrw:
  lrw has two modes: shell mode and command line mode;
  shell mode: Type lrw or lrw shell will enter this mode.Under this mode lrw
  will type a prefix ">" and then wait for you to input the command line. 
  After each command have been exectued it will return this state untill 
  you input "quit" to exit;

  command line mode: Under this mode, lrw will exit at once when the command
  you wanted is finished. Some comfortable traits provided by shell can be
  used. for example: using up arrow or down arrow to get the historical commands.
  Directly type "lrw cmd xx xx xx" will tell lrw to enter this mode.

----------------

getting help:
  Type lrw -h to get the general help, and lrw help to get the infomation of
  all the commands that supported.

----------------

co mmands:
	CMD Name	CMD Descript
	HELLO		HELLO SOMETHING
	help		Print Help
	I		In Port Byte
	I16		In Port Word
	I32		In Port Dword
	O		Out Port Byte
	O16		Out Port Word
	O32		Out Port Dword
	R16		Read MEM Word
	R32		Read MEM Dword
	R8		Read MEM Byte
	RPCI		Read PCI Byte
	RPCI16		Read PCI Word
	RPCI32		Read PCI Dword
	W16		Write MEM Word
	W32		Write MEM Dword
	W8		Write MEM Byte
	WPCI		Write PCI Byte
	WPCI16		Write PCI Word
	WPCI32		Write PCI Dword
  use help xx for detial information.
----------------

bugs:
  Please feed any bug you meet during the using of lrw back to me.

----------------

Portability:
  This tool is designed to work under x86 and x64 linux environment.But only
  tested under x86 linux environment.
  It seems to work well under x86_64

