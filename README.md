# ATMEGA Volt-Meter

Welcome to the ATMEGA Volt-Meter repository! This C program implements a simple volt-meter on a microcontroller, which is equipped with a 16-key keypad input device and an LCD screen output device. The volt-meter continuously samples the analog input every 500ms and updates the display to show four parameters: instantaneous voltage, maximum voltage, minimum voltage, and average voltage. The minimum, maximum, and average voltage can be reset to "---" or 0 using the '#' and 'D' buttons. The program continuously displays the instantaneous voltage, starting from when the device is powered on.


## Table of Contents
- [Overview](#Overview)
- [Setup](#setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

This program enables the user to:

- Continuously monitor and display the instantaneous voltage.
- Display the maximum, minimum, and average voltage values.
- Reset the maximum, minimum, and average voltage to default values.

## Setup

![Setup Image]([https://cdn.discordapp.com/attachments/442574704126066690/1162140239897317386/IMG_1766.jpg?ex=653ada70&is=65286570&hm=00aa40ce8b2f66bd287c6b56b434b2e83944fe427babb33700d7972c491a0bd1&](https://cdn.discordapp.com/attachments/442574704126066690/1162212948169736202/IMG_2057.jpg?ex=653b1e27&is=6528a927&hm=5fb0ed1b28c97777d48e1fbd3d78f5927c5a74bbbc5afa233cf0a4a6a4d19acf&))

- ATMEGA microcontroller.
- 16-key keypad input device.
- LCD screen output device.
- Analog input for voltage measurement.

## How to Use



1. Clone this repository to your local machine.

```bash
git clone https://github.com/your-username/your-repo.git
