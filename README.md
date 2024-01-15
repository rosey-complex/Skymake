![Logo](Logo/logo2.svg)

# **Skymake - A simple Skylanders® figure generator**

![Screenshot](Screenshots/Screenshot1.png)

## Installation:

### Windows:
- Use WSL2 and follow the linux installation steps. 

###### (Windows is far too janky when it comes to developing software compared to Linux distributions)

### Linux:
- Check if you have the right dependencies installed,
- From the releases section, download "skymake-linux-glibc-[version].zip",
- Extract the binary into any folder,
- Copy the extracted binary file to **/usr/bin** or **/usr/local/bin** or **~/.local/bin** (if you have it in your $PATH).

## ✅ What it can:
- Create Skylanders all the way up to Imaginators,
- Create Creation Crystals,
- Create Magic Items,
- Create Vehicles,
- Create Traps,
- Create Debug Skylanders,
- Create Instant/Virtual Skylander variants,
- Create ***some*** scrapped Skylanders.

## ⛔ What it can't:
- Create figures for Imaginators with unique NUIDs.
- Create files for Imaginators with custom IDs and VarIDs.

## Compiling:
### On Linux:
-   Clone the repository
-   Install development files for Qt5Core and Qt5Widgets.
-   In the root directory of the reposotory, run `cmake .` .
-   After cmake finishes, run `make`.
-   If the compilation finishes, you should now have a compiled `skymake` binary.