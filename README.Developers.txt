This document, README.Developers.txt, provides documentation useful for the
prospective BITS developer.  See README.txt for user documentation, or
INSTALL.txt for instructions on creating a bootable USB disk.

Please send any bug reports, patches, or other mail about BITS to
<burton.w.triplett@intel.com>.

You can find the BITS homepage at http://biosbits.org/


BITS scripting
==============

BITS adds various useful commands to GRUB, and then defines all of its
higher-level functions and menus using plain text script files.  These script
files use GRUB2's menu language, which works roughly like simple shell
scripting.  You can experiment with all of the low-level BITS commands using
the GRUB2 command line; for example, you can read and write MSRs or look at
CPUID.  If you want to add options to the BITS menus, you can edit the files in
/boot/cfg on a BITS USB disk.

Note that if you rebuild your USB disk by running ./mkdisk, your configuration
files may get overwritten.  Save a separate copy of them first.  Even better,
they might prove more generally useful, so send them along to get incorporated
into BITS.


Building BITS from source
=========================

BITS builds as a set of additional modules and commands for GNU GRUB2.
Accompanying the BITS source distribution, you will find an archive of the
version of GNU GRUB2 used to build BITS.  You will need to unpack both that
source code and BITS in separate directories.  Note that BITS requires a
specific snapshot of GRUB2 (see README.txt for the bzr revision number), and
will not necessarily build with the latest version of GRUB2.

GRUB2's build system for external modules requires BITS to know the path to
GRUB2's source directory and the BITS source directory; the BITS build script
assumes you unpacked the source code for GRUB2 at ~/src/grub2/grub, and the
BITS source code at ~/src/grub2/bits.  If you unpack them to some other path,
you will need to edit the build and mkdisk scripts and change the paths at the
top.

GRUB2 itself has a few build dependencies; review the file "INSTALL" in the
GRUB2 source code for a full list.  Note that because BITS provides additional
GRUB modules and thus extends the GRUB build system, you will need the
additional tools described as required for development snapshots or hacking on
GRUB.

BITS requires GNU binutils 2.20 or newer, due to a bug in the GNU assembler in
older versions which causes it to incorrectly assemble parts of BITS.

If you build BITS repeatedly, you'll want to install and configure ccache to
speed up these repeated builds.

Once you have the source code unpacked and the build dependencies installed,
you can build BITS by running ./build in the top of the BITS source tree.  This
will produce a binary distribution of BITS as a zip file, which includes
installation instructions (INSTALL.txt) and full corresponding source code.
Read INSTALL.txt for more information on building a bootable USB disk,
including the additional software you will need to do so.

Once you have a bootable USB disk, you can quickly update that disk to include
a new version of BITS by running ./mkdisk after building.  NOTE: ./mkdisk
assumes you have a USB disk /dev/sdb with a partition /dev/sdb1 that you want
to use for BITS.  If you want to use some device other than /dev/sdb, EDIT
MKDISK FIRST!  mkdisk will refuse to write to a non-removable disk as a safety
check; if for some reason you want to write to a non-removable disk, you'll
have to comment out that check as well.  Sorry for making it inconvenient to
overwrite your hard disk.


Coding style
============

BITS follows the K&R coding style, with four space indents, and no tabs.

Don't try to wrap lines to fit an arbitrary line width, but do wrap lines when
it improves readability by lining up similar code.

The script "bits-indent" roughly approximates the right style, except that it
will un-wrap all lines, even those which look better wrapped.  Use good taste.
