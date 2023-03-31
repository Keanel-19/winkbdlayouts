# Apple keyboards layouts for Windows

Can be built for x86, x64 and arm64 Windows systems. Make sure to
install all build tools (compilers and libraries) for all targets
when installing or updating Visual Studio.

## Language support

As of today, the only supported layout is the French keyboard, having
no other physical keyboard for testing.

To add support for a new keyboard layout:

- Duplicate the `kbdfrapple` directory under the name `kbdXXapple` where
  `XX` is the language code for your keyboard (not necessarily two letters,
  this is just a convention).
- Rename all files as `kbdXXapple.*` in the new directory.
- Update the files `kbdXXapple.rc` and `kbdXXapple.reg` with the appropriate
  names and descriptions.
- Update the key tables in `kbdXXapple.c`.
- The files `kbdXXapple.def` and `kbdXXapple.vcxproj` do not need any modification.

That's all. Just run `build.ps1` to build the new layouts and `install.ps1` to
install them.