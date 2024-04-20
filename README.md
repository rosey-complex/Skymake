<div style="text-align:center">
  <img src="Logo/skymake.svg" alt="Logo">
</div>

# **Skymake - A simple Skylanders figure generator**
<sup>** I am not affiliated in any way, shape or form with Activision, Blizzard, Toys For Bob, Vicarious Visions or Microsoft</sup>
<div style="text-align:center">
  <img src="Screenshots/Screenshot_1.1.png" alt="Screenshot showing how the app looks like">
</div>

## Features:
- Support for Imaginators<sup>[with slight limitations]</sup> figures.
- The ability to create a random skylander.

## Limitations:
- Inability to create Imaginators figures with custom UIDs, IDs or variant IDs (Skylanders Imaginators checks for additional data that have yet to be figured out).

## Installation:

### Windows:
-   Follow the compilation steps near the bottom of the page.

###### * If you want to start it like any ordinary desktop app... you're out of luck, unfortunately. (you will have to start skymake from MSYS2). If you know how to compile Qt applications on windows and to make them installable, feel free to contribute.

### Linux (Fedora/RHEL):
- From the releases section, download "skymake-[version]-1.fc40.x86_64.rpm"
- Install the RPM package via your package manager
    + Command line:
        + `sudo dnf in ./skymake-[version]-1.fc40.x86_64.rpm`
    + GUI:
        + Double click on the file in a file manager. It ***should*** automatically open the default store interface (e.g. Discover, Gnome Software Center etc.)

### Linux (Generic):
- Check if you have the right dependencies installed,
- From the releases section, download "skymake-linux-glibc-[version].zip",
- Extract the binary into any folder,
- Copy the extracted binary file to **/usr/bin** or **/usr/local/bin** or **~/.local/bin** (for a local installation; if you have it in your $PATH).
- Copy **skymake.desktop** to **/usr/share/applications**.
    + if you are going with a local installation, you can copy it to **~/.local/share/applications**.
- Copy **skymake.svg** to **/usr/share/icons/hicolor/scalable/apps/**.
    + if you are going with a local installation, you can copy it to **~/.local/share/icons/hicolor/scalable/apps**.

## Compiling:

### On Linux:
-   Clone the repository using `git clone https://github.com/rosey-complex/Skymake`
-   Install development files for Qt6Core and Qt6Widgets.
-   In the root directory of the reposotory, run `cmake .` .
-   After cmake finishes, run `make`.
-   If the compilation finishes, you should now have a compiled `skymake` binary.

### On Windows (MSYS2):
-   Install MSYS2.
-   Start MSYS2 MINGW64 from the start menu.
-   In the MSYS2 command line, install the required tools and libaries.
    + Run `pacman -S mingw-w64-x86_64-binutils pactoys git`.
    + Afterwards, run `pacboy -S toolchain:p cmake:p qt6-base:p extra-cmake-modules:p ninja:p`.
    + If prompted to select an option, just press "enter".
-   Clone the repository using `git clone https://github.com/rosey-complex/Skymake`
-   Enter the repository's directory.
-   Run `cmake .` and then, after cmake completes succesfully, run `cmake --build .`.
-   If there are no compilation errors, you should have a compiled `skymake.exe` executable.

## Packaging

### RPM (Fedora/RHEL):

#### Initial setup:
- Make sure that RPM development tools (`rpmdevtools`) and Qt6 (`qt6-qtbase-devel`) are installed.
- Run `rpmdev-setuptree`.
- Go to the `~/rpmbuild` directory.

#### Creating the package:
- In `~/rpmbuild`, go to the `SOURCES` directory.
- Clone the repository using `git clone https://github.com/rosey-complex/Skymake`.
- Copy `Skymake.spec` to the `SPECS` directory: `cp Skymake/Skymake.spec ../SPECS`.
- Compress the reporitory directory using `tar -czvf Skymake.tar.gz Skymake/`.
- Go back to the upper directory (`~/rpmbuild`).
- Go to the `SPECS` directory.
- Run `rpmbuild -bb Skymake.spec`.
- Choose a god and pray that it compiles without issues.
- Once compiled, you will have a fresh RPM package in `~/rpmbuild/RPMS`.