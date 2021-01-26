# BetterIGT
A New Super Mario Bros. Wii mod that changes various things relating to the in-game timer.
The timer has three decimal places with the mod, and splits when entering a pipe or door.

## Installation
You can download the built Riivolution mod from the [releases](https://github.com/LetsPlentendo-CH/BetterIGT/releases) and extract the files to your Wii SD card. Alternatively, follow these steps to build the mod from source.

### Prerequisites
Install newsouper with npm: `npm install newsouper -g`

### Building
1. Clone this project: `git clone https://github.com/LetsPlentendo-CH/BetterIGT.git`.
2. Open a command shell and navigate into it.
3. Run `nsoup <project>.json [ISO file]`
(Note: you have to specify an ISO file or the mod will not build.)

This will generate a folder `PrecisionTime` and `riivolution` in the export directory. Copy these two folders to your Wii SD card.