# IOS-Screentime-Brute-Forcer

Make sure to check before you run this if your iOS version is vulnerable (see below for testing).

## Testing for iOS Vulnerability

Go to **Settings > General > Transfer or Reset iPhone**.

Enter your iPhone passcode.

If the vulnerability is present, you should have infinite attempts at the Screen Time passcode.

Apple has apparently patched this in iOS 18, but it still seems to work on iOS 26.4.

## Getting Started

If your phone is vulnerable to the attack, you will need the following:

- [ ] [Raspberry Pi Pico 2 W/WH](https://thepihut.com/search?q=pico&narrow_by=Brand%2CRaspberry+Pi%2CCategories%2C289434271939&sort_by=relevency&page=1)
(You may not necessarily need this board, but I used it and it worked fine. So any other board should work ** as long as it has built-in Bluetooth**

- [ ] Micro-USB data cable

Once you have all of that, download the Arduino IDE and set it up for your board:

1. Download and install Arduino IDE from the official Arduino website (arduino.cc).
2. Open it, go to **File > Preferences** and paste this URL into "Additional Boards Manager URLs":  
   `https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json`
3. Go to **Tools > Board > Boards Manager...**, search `rp2040`, and install the **Raspberry Pi Pico/RP2040** core by Earle F. Philhower.
4. Go to **Tools > Manage Libraries...** (`Ctrl+Shift+I`), search for `KeyboardBLE` and hit install.

## Uploading the Code

1. Plug your Pico into your PC using your micro-usb data cable.
2. In Arduino IDE, go to **Tools > Board > Raspberry Pi Pico RP2040** and select **Raspberry Pi Pico W**.
3. Pick your COM port under **Tools > Port**.
4. Open the `.ino` sketch from this repo and click the Upload arrow button in the top left.
5. Wait until it says "Done uploading" at the bottom terminal.

## How to Run It

1. Plug the Pico into any USB power source (a power bank, laptop, wall plug, whatever).
2. The onboard LED will start blinking for 30 seconds. **While it's blinking:**
   - Go to **Settings > Bluetooth** on your iPhone and connect to **PicoKey**.
   - Navigate to **Settings > General > Transfer or Reset iPhone** so the passcode prompt is open on screen.
3. When the LED stops blinking and stays solid ON, the Pico is active and will start typing every combo from `0000` to `9999` with an Enter key after each one.
4. Once it hits the right code or finishes, just unplug the Pico.

## Notes & Troubleshooting

* **No way to enter in phone password/ No keypad showing** Pair the controller first, disconnect it by unplugging the board, go to the erase menu and enter password then replug the board again and the number pad should disappear when it connects properly.
* **Arduino IDE not detecting the board** Try a different cable. A lot of cheap micro usb cables lying around only supply power and don't transfer data.
