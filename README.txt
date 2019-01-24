README.txt
CS 3013, Team Members Myo Min Thant and Dan Chao
Project 1 Checkpoint

We have completed stage 1 and are partway done with stage 2
The commands we have finished are listed below with their corresponding output

The whoami, last, and ls function from phase 1 work as specified with ls accepting additional arguments as well as a route
The chdir changes directory, which is shown by running p before and after the chdir.
The directories before and after are different
the e function correctly exits the function with the exit message

We are around halfway done with phase 2, we are currently working on the "add" functionality using data structs to store our new commands

Our logs showing our working program is at the bottom of this file.







====HOW TO RUN====
1) Enter v1
2) run "make" or "make clean" then "make" if the project has been previously built
2) type "./mc1" to launch the mid day commander















===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: 0


-- Who Am I? --
myo


== Statistics ===
Elapsed time: 0.635425 milliseconds
 0 page faults
82 page reclaims

===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: 1


-- Last Logins --
myo      tty7         :0               Thu Jan 17 13:58    gone - no logout
reboot   system boot  4.4.162mmthant   Thu Jan 17 13:58   still running
myo      tty7         :0               Wed Jan 16 11:26 - down   (02:15)
reboot   system boot  4.4.162mmthant   Wed Jan 16 11:24 - 13:41  (02:16)
myo      tty7         :0               Mon Jan 14 19:38 - down   (01:23)
reboot   system boot  4.4.162mmthant   Mon Jan 14 19:24 - 21:02  (01:37)
myo      tty7         :0               Mon Jan 14 15:58 - down   (03:39)
reboot   system boot  4.4.0-141-generi Mon Jan 14 15:55 - 19:38  (03:42)
myo      tty7         :0               Mon Jan 14 14:55 - crash  (00:59)
reboot   system boot  4.4.0-141-generi Mon Jan 14 14:55 - 19:38  (04:42)
myo      tty7         :0               Sun Jan 13 23:17 - crash  (15:38)
reboot   system boot  4.4.0-31-generic Sun Jan 13 23:16 - 19:38  (20:21)

wtmp begins Sun Jan 13 23:16:52 2019


== Statistics ===
Elapsed time: 0.755331 milliseconds
 0 page faults
87 page reclaims

===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: 2


-- Directory Listing --
Arguments?: -al
Path?: /home
total 12
drwxr-xr-x  3 root root 4096 Jan 13 23:11 .
drwxr-xr-x 23 root root 4096 Jan 13 23:44 ..
drwxr-xr-x 19 myo  myo  4096 Jan 17 13:58 myo


== Statistics ===
Elapsed time: 0.846213 milliseconds
 0 page faults
92 page reclaims

===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: p


-- Current Directory --
Directory : /home/myo/Documents/CS3013_Projects/cs3013_project1/v1


===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: c


-- Change Directory --
New Directory?: /home


===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: p


-- Current Directory --
Directory : /home


===== Mid-Day Commander, v0 =====
G'day, Commander! What command would you like to run?
   0. whoami  : Prints out the result of the whoami command
   1. last    : Prints out the result of the last command
   2. ls      : Prints out the result of a listing on a user-specified path
   c. change directory : Changes process working directory
   e. exit : Leave Mid-Day Commandar
   p. pwd : Prints working directory
Option?: e
Logging you out, Commander.

