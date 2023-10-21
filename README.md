![Skymake Logo](Logo/logo2.svg)

# **Skymake - A just-works command line Skylander figurine generator**



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
- Creating functional* Senseis and Creation Crystals

<span style="color:#888888;">*(It can create the files correctly, but they are non-functional in-game)</span>

## Compiling (Linux):

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
