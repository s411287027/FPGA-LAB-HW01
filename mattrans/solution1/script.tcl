############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project mattrans
set_top mattrans
add_files mattrans.cpp
add_files mattrans.h
add_files -tb mattrans_test.cpp -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas -Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg484-1}
create_clock -period 10 -name default
source "./mattrans/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
