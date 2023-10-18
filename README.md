![Logo](Logo/logo.svg)

# **Skymake - A just-works command line Skylander figurine generator**

## About:
To put it simply, this is a tool that I made by ✨*borrowing*✨ code from the Skylander portal emulators of both RPCS3 and Dolphin (CRC_CCITT_TABLE and list_skylanders are from RPCS3; EntropySeededPRNG and the skylander generator code are from Dolphin).

## Q&A:
#### Why make this?
- I made this ✨*abomination*✨ with the intention of having a stand-alone, easy to use, command line tool that creates empty Skylanders figurine data files. 
#### Why would anyone need this?
- There are a few possible use cases I could think of:
	+ Avoiding pre-made dumps which may sometimes be unreliable
	+ Using it to create files directly on a Raspberry Pi portal emulator through SSH
	+ Quick Skylander file creation (because, of course, there is *no file select screen*)
	+ Wasting 1.7 MiB of storage space

## Usage:
```
skymake <Options>
```
#### Options:
- `-h` - Print usage instructions.
- `-a <Skylander Name>` - Auto Mode, creates a skylander automatically based on the name that you give it.
- `-m <ID> <Variant ID>` - Manual Mode, creates a skylander using the Skylander ID and Variant ID that you give it.
- `-s` - Safe Mode, avoids overwriting a file that already exists by adding a number before the file extension
- `-f <File(*.sky) or Directory>` - If not present, it will create a file with a pre-determined name in the current working direcory. If present, skymake will do either of two things:
	+ If the argument after `-f` has a *.sky file extension, it will create a file with the specified path.
		+ Example: `-f "~/Documents/Whirly.sky"` will create the file `Whirly.sky` in `~/Documents`
	+ If the argument after `-f` doesn't have a *.sky file extension, it will create a file with a pre-determined name in the directory with the specified path.
		+ Example for Auto Mode: `-a "Whirlwind" -f ~/Documents/Whirly` will try to create a file named `Whirlwind.sky` in `~/Documents/Whirly/`.
		+ Example for Manual Mode: `-m 32 0x3805 -f ~/Documents/S4Cynder` will try to create a file named `32-14341.sky` (`ID-VarID(Dec).sky`) in `~/Documents/S4Cynder/`.

## ✅ What works:
- Creating Skylanders up to Imaginators
- Creating Magic Items
- Creating Vehicles
- Creating Traps
- Creating Debug Skylanders
- Creating Instant/Virtual Skylander variants
- Creating ***some*** scrapped Skylanders

## ⚠️ What doesn't work:
- Creating functional* Senseis 

<span style="color:#888888;">*(It can create the files correctly, but they are non-functional in-game)</span>

## ❌ What it can't do:
- Create Imaginator crystals
- ~Take over Activision~
- ~Make you immortal~

## Building and installing (Linux):
### Prerequisites:
- make
- mbedtls
- gcc

### Building and installing:
``` 
make build
sudo make install
```

## Uninstalling (Linux):
``` 
sudo make remove 
```
