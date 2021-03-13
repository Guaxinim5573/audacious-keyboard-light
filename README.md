# audacious-keyboard-light
Control keyboard light based on Audacious status
# Building and Installation
This depends on [brightnessctl](https://github.com/Hummer12007/brightnessctl)
##### Installing
```
git clone https://github.com/Guaxinim5573/audacious-keyboard-light
cd audacious-keyboard-light
sudo make
```
##### To uninstall
```
sudo make uninstall
```
# Using
First you need to get your device name, just run:
```
brightnessctl -l
```
After you find your device you just need to run `audacious-keyboard-light device-name`, example:
```
audacious-keyboard-light input10::scrolllock
```
# License
This program uses [GPL v3.0](https://github.com/Guaxinim5573/audacious-keyboard-light/blob/main/LICENSE) License.
