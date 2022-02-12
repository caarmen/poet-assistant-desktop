# Poet Assistant (Desktop version)

## Installing
* Download the application binary from the [releases](https://github.com/caarmen/poet-assistant-desktop/releases) page
* Linux: For text-to-speech features to be available, install `speech-dispatcher`

## Building
* Install [Qt](https://qt.io)
* Install additional dependencies:
  - Linux: `speech-dispatcher`, `libspeechd-dev`
* Run the appropriate build script for your platform:
  - `bash deploy/linux.bash`
  - `bash deploy/mac.bash`
  - `deploy\windows.bat`
* The application is created in `app/build/out`

