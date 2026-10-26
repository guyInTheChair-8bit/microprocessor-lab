# EE2016 Experiments

Experiment handouts and matching source files for the AVR and FPGA/ARM lab work. Files that were previously spread across `avr experiments`, `verilog experiments`, `asm files`, `verilog files`, and `HLS_files` are now grouped here by experiment number and topic.

Each experiment folder has a short README describing its aim and included files. Extracted program examples are separated by task where useful. PDFs, reports, assignment handouts, the AVR Tools folder, and the ARM DAC square-wave source are kept locally and excluded from Git by this folder's `.gitignore`.

## AVR

| Folder | Contents |
| --- | --- |
| [Experiment 1 - Assembly Emulation](AVR/Experiment%201%20-%20Assembly%20Emulation/) | AVR assembly emulation handout and an 8-bit addition program. |
| [Experiment 2 - Peripherals](AVR/Experiment%202%20-%20Peripherals/) | Peripheral wiring and programming handout with a GPIO setup example. |
| [Experiment 3 - Interrupts](AVR/Experiment%203%20-%20Interrupts/) | Interrupt handout and an external interrupt ISR example. |
| Tools | The local AVRLASS assembler/disassembler collection is excluded from this repository. |

## Verilog and ARM

| Folder | Contents |
| --- | --- |
| [Experiment 1 - Adders](Verilog%20and%20ARM/Experiment%201%20-%20Adders/) | FPGA half-adder, full-adder, and ripple-carry adder handout. |
| [Experiment 2 - Flip-Flops and Johnson Counter](Verilog%20and%20ARM/Experiment%202%20-%20Flip-Flops%20and%20Johnson%20Counter/) | FPGA handout and associated Verilog modules for flip-flops, clock division, decoding, and the Johnson counter. |
| [Experiment 3 - Multiplier and LCD](Verilog%20and%20ARM/Experiment%203%20-%20Multiplier%20and%20LCD/) | FPGA multiplier and LCD handout. |
| [Experiment 4 - High-Level Synthesis](Verilog%20and%20ARM/Experiment%204%20-%20High-Level%20Synthesis/) | HLS handout and NAND/OR gate example sources and testbenches. |
| [Experiment 5 - ARM Assembly](Verilog%20and%20ARM/Experiment%205%20-%20ARM%20Assembly/) | ARM assembly programming handout. |
| [Experiment 6 - DAC](Verilog%20and%20ARM/Experiment%206%20-%20DAC/) | ARM microcontroller digital-to-analog conversion handout. |

Lecture slides, tutorials, and general EE2016 references remain in their existing folders because they are course materials rather than experiment handouts or experiment source files.
