/*
============================================================================
Name : 2.c
Author : Saurabh Dubey
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>

int main(){
    while(1) ;
    return 0; 
}

//output
// /proc/4794$ cat status 
// Name:	a.out
// Umask:	0002
// State:	R (running)
// Tgid:	4794
// Ngid:	0
// Pid:	4794
// PPid:	2221
// TracerPid:	0
// Uid:	1000	1000	1000	1000
// Gid:	1000	1000	1000	1000
// FDSize:	256
// Groups:	4 24 27 30 46 115 136 1000 
// NStgid:	4794
// NSpid:	4794
// NSpgid:	4794
// NSsid:	2221
// VmPeak:	    6060 kB
// VmSize:	    6060 kB
// VmLck:	       0 kB
// VmPin:	       0 kB
// VmHWM:	    1872 kB
// VmRSS:	    1872 kB
// RssAnon:	     172 kB
// RssFile:	    1700 kB
// RssShmem:	       0 kB
// VmData:	     264 kB
// VmStk:	     132 kB
// VmExe:	       4 kB
// VmLib:	    3476 kB
// VmPTE:	      52 kB
// VmSwap:	       0 kB
// HugetlbPages:	       0 kB
// CoreDumping:	0
// THP_enabled:	1
// Threads:	1
// SigQ:	0/29807
// SigPnd:	0000000000000000
// ShdPnd:	0000000000000000
// SigBlk:	0000000000000000
// SigIgn:	0000000000000000
// SigCgt:	0000000000000000
// CapInh:	0000000000000000
// CapPrm:	0000000000000000
// CapEff:	0000000000000000
// CapBnd:	000001ffffffffff
// CapAmb:	0000000000000000
// NoNewPrivs:	0
// Seccomp:	0
// Seccomp_filters:	0
// Speculation_Store_Bypass:	thread vulnerable
// SpeculationIndirectBranch:	conditional enabled
// Cpus_allowed:	ff
// Cpus_allowed_list:	0-7
// Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
// Mems_allowed_list:	0
// voluntary_ctxt_switches:	0
// nonvoluntary_ctxt_switches:	10645
