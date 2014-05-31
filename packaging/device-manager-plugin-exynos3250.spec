#sbs-git:slp/pkgs/d/device-manager-plugin-e3250 device-manager-plugin-e3250 0.0.1 5bf2e95e0bb15c43ff928f7375e1978b0accb0f8
Name:       device-manager-plugin-e3250
Summary:    Device manager plugin e3250
Version: 0.0.03
Release:    0
Group:      TO_BE/FILLED_IN
License:    TO_BE/FILLED_IN
Source0:    %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig

BuildRequires:  cmake
BuildRequires:  pkgconfig(devman_plugin)
BuildRequires:  pkgconfig(dlog)
ExclusiveArch: %arm

#!BuildIgnore:  kernel-headers
BuildRequires:  kernel-headers-3.4-exynos3250

%description
Device manager plugin e3250

%prep
%setup -q

%build
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix}

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
mkdir -p %{buildroot}/usr/share/license
cp -a apache-2.0.txt %{buildroot}/usr/share/license/%{name}
mkdir -p %{buildroot}/usr/lib/udev/rules.d
cp -a 61-tizen-video-device.rules %{buildroot}/usr/lib/udev/rules.d

%make_install

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%files
%manifest device-manager-plugin-exynos3250.manifest
/usr/share/license/device-manager-plugin-e3250
/usr/lib/libslp_devman_plugin.so
/usr/lib/udev/rules.d/61-tizen-video-device.rules
/opt/etc/dump.d/module.d/*
