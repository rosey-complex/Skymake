![](Logo/logo-128x128.svg)

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
	+ Wasting 319.7 KiB of storage space

## Usage:
#### Default:
```
skymake <Skylander Name> <Directory>
```
Example:
```
skymake "Whirlwind" ~/Documents/
```

#### Alternatively, you can use manual mode:
```
skymake -m <ID> <Variant ID (Hexadecimal)> <Directory>
```
Example (for Ultimate Kaos Trap):
```
skymake -m 220 0x351F ~/Documents/
```

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
