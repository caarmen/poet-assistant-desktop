# Poet Assistant (Desktop version)

## Installing
Download the application binary from the [releases](https://github.com/caarmen/poet-assistant-desktop/releases) page
* Linux:
  - For text-to-speech features to be available, install `speech-dispatcher` with your favorite package manager
* Windows:
  - For non power users, the `installer` version is recommended. If you download the `portable` version instead, extract the contents first, before running the `PoetAssistant.exe` file
  - Starting with Windows 11, you'll see a warning about an unknown publisher. To be able to run the app, you'll have to click "More info" and then allow the app. My understanding is that I'd have to pay several hundred dollars every year to get rid of this warning (by purchasing a certificate to sign the app). I'm not investing in this at this point.

## Compatibility
Poet Assistant has been tested on the following systems:
* Mac: 12
* Linux: Ubuntu 20.04, Fedora 35
* Windows: 10, 11

## Building
* Install [Qt](https://qt.io)
* Install additional dependencies:
  - Linux: `speech-dispatcher`, `libspeechd-dev`
* Run the appropriate build script for your platform:
  - `bash deploy/linux.bash`
  - `bash deploy/mac.bash`
  - `deploy\windows.bat`
* The application is created in `app/build/out`

