Name:       skymake
Version:    1.1.0
Release:    1%{?dist}
Summary:    A simple Skylander figure data dump generator made in C++

License:    GPLv2
URL:        https://github.com/rosey-complex/Skymake
Source0:    Skymake.tar.gz

BuildRequires:  qt6-qtbase-devel
Requires:       qt6-qtbase
BuildArch:      x86_64

%description
This application generates skylander figure data in .sky files for use in emulators, figure recovery or making custom NFC cards.

%prep
%autosetup -n Skymake

%build
cmake .
cmake --build .

%install
install -d %{buildroot}/usr/bin
install -d %{buildroot}/usr/share/icons/hicolor/scalable/apps
install -d %{buildroot}/usr/share/applications

install -m 755 ./skymake %{buildroot}/usr/bin/
install -m 644 ./Logo/skymake.svg %{buildroot}/usr/share/icons/hicolor/scalable/apps/
install -m 644 ./skymake.desktop %{buildroot}/usr/share/applications/

%files
/usr/bin/skymake
/usr/share/icons/hicolor/scalable/apps/skymake.svg
/usr/share/applications/skymake.desktop

%changelog
* Fri Apr 13 2024 Rosey Complex <rosey-complex@yahoo.com>
- Added spec file for RPM packaging
