<div style="text-align:center">
  <img src="Logo/skymake.svg" alt="Logo">
</div>

# **Skymake - A simple Skylanders® figure generator**

<div style="text-align:center">
  <img src="Screenshots/Screenshot1.png" alt="Screenshot showing how the app looks like">
</div>

## Installation:

### Windows:
- Use WSL2 and follow the linux installation steps. 

###### (Windows is far too janky when it comes to developing software compared to Linux distributions)

### Linux:
- Check if you have the right dependencies installed,
- From the releases section, download "skymake-linux-glibc-[version].zip",
- Extract the binary into any folder,
- Copy the extracted binary file to **/usr/bin** or **/usr/local/bin** or **~/.local/bin** (for a local installation; if you have it in your $PATH).

*--OPTIONAL--*

- Copy **skymake.desktop** to **/usr/share/applications**.
    + if you are going with a local installation, you can copy it to **~/.local/share/applications**.
- Copy **skymake.svg** to **/usr/share/icons/hicolor/scalable/apps/**.
    + if you are going with a local installation, you can copy it to **~/.local/share/icons/hicolor/scalable/apps**.

## ✅ What it can:
- Create Skylanders all the way up to Imaginators,
- Create Creation Crystals,
- Create Magic Items,
- Create Vehicles,
- Create Traps,
- Create Debug Skylanders,
- Create Instant/Virtual Skylander variants,
- Create ***some**** scrapped Skylanders.
###### (*It cannot yet create scrapped imaginators figures... the reason can be figured out from the two things skymake can't do. (TL;DR: no Heartbreaker Buckshot :( ))

## ⛔ What it can't:
- Create figures for Imaginators with unique NUIDs.
- Create figures for Imaginators with custom IDs and VarIDs.

## Compiling:
### On Linux:
-   Clone the repository
-   Install development files for Qt5Core and Qt5Widgets.
-   In the root directory of the reposotory, run `cmake .` .
-   After cmake finishes, run `make`.
-   If the compilation finishes, you should now have a compiled `skymake` binary.