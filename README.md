# meishi-trackball-module-aki27kbd
This is an updated set of files from aki27kbd's trackball module which was also purchased from Yushakobo in Japan. Included are .hex firmwares that you can use to flash your own device in the default style or in my modified style. A deeper look into the modules include notes about personalization of certain aspects like cursor speed &amp; scroll speed.

# To flash Ready-To-Use firmware
1. [Download](https://github.com/RomGav/meishi-trackball-module-aki27kbd/tree/main/Ready%20To%20Download%20Hex%20Firmwares) Either aki27's .hex firmware file or ImHavingARogasm .hex firmware file

2. Install [QMK Toolbox](https://qmk.fm/toolbox), select your .hex file, press the reset button on your trackball twice, and hit flash

3. You will now be able to use [REMAP](https://remap-keys.app/configure) to configure your trackball

      3a. Please note that when you remap your keys and flash the trackball, the remapping itself is successful but the preview display is not accurate

      3b. Alternatively, you can use the ImHavingARogasm Shared Keymaps on REMAP to quickly set up your trackball with this [layout](https://github.com/RomGav/meishi-trackball-module-aki27kbd/blob/main/ImHavingARogasm%20REMAP%20Keymap.png?raw=true) (Image at the bottom):

**Differences:**
Aki27's firmware has **DPI options** set in rotation at {250, 500, 750, 1000, 1250}

Aki27's firmware has **scrolling TRACKBALL speed** set in rotation at { 1, 2, 3, 4, 5, 6 } with 6 being the slowest

ImHavingARogasm's firmware has **DPI options** set in rotation at {400, 800}

ImHavingARogasm's firmware has **scrolling TRACKBALL speed** set in rotation at { 4, 5, 6 } with 6 being the slowest

# To modify your own firmware and settings
1. Install [QMK MSYS](https://github.com/qmk/qmk_distro_msys/releases/tag/1.12.0)

            In the QMK Console type "qmk setup" and enter

2. [Download](https://download-directory.github.io/) the firmware setup folder you'd like to use (Mine or aki27's Default)

3. Unzip the folder and drag it into your keyboards folder (Typically found under C:\Users\[your_username]\qmk_firmware\keyboards)

            Create a host folder in the keyboards folder and named it **aki27** and dragged the **trackball_module** folder inside it

4. Listed below are the files names and what can be modified inside (note I also left descriptions inside the files themselves):

      **trackball_module.c**
   
            Trackball Speed/DPI/CPI (you can set multiple options)

            Trackball SCROLLING Speed (you can set multiple options, the higher the value the slower the scrolling speed)

      **config.h**

            Trackball Module Direction (0 is trackball on the left; 90 is trackball at the bottom; 180 is trackball on the right; 270 is trackball at the top)

      **keymaps\default\keymap.c**

            You can adjust your keymap manually here

            Trackball Scrolling Assigned Layer (**cocot_set_scroll_mode(true)** is the command used to select which layers use trackball scrolling upon layer switch)
   
5. Once you're finished customizing your firmware, you can compile to create a .hex file and flash using QMK Toolbox OR flash directly using QMK MSYS

      5a. **Compile your .hex file:**

            5ai. In QMK MSYS type and enter: qmk compile -kb aki27/trackball_module -km default

            5aii. Your .hex file will appear in your **qmk_firmware** folder

            5aiii. Download [QMK Toolbox](https://qmk.fm/toolbox), select your .hex file, press the reset button on your trackball twice, and hit flash
   
      5b. **Flash directly from QMK MSYS**

            5ai. In QMK MSYS type and enter: qmk flash -kb aki27/trackball_module -km default

            5aii. Once prompted to reset your controller, press the reset button on your trackball twice

6. You will now be able to use [REMAP](https://remap-keys.app/configure) to configure your trackball

      6a. Please note that when you remap your keys and flash the trackball, the remapping itself is successful but the preview display is not accurate

      6b. Alternatively, you can use the ImHavingARogasm Shared Keymaps on REMAP to quickly set up your trackball with this layout:
![ImHavingARogasm Shared Keymap](https://github.com/RomGav/meishi-trackball-module-aki27kbd/blob/main/ImHavingARogasm%20REMAP%20Keymap.png?raw=true)
