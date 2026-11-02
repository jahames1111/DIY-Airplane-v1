# DIY-Airplane-v1

<img width="1237" height="773" alt="image" src="https://github.com/user-attachments/assets/91c8eec5-10ee-41dd-9e1d-dc36875565b7" />

I have made many attempts to create some type of flying thing before, and they always failed because of a low budget. This is my first try that actually holds some promise. I will be creating both a remote and a receiver from scratch — the remote will use joysticks and XIAO boards I already have, and the FC board will be JLCPCB+LCSC. 

## Overview
This project contains 2 parts:
1. A flight controller board running brushless motors. It is built off of a XIAO ESP32C3 and has 2 breakouts that are optional for a NEO 6M GPS module and an MPU9250. Runs on one 450mah 1S battery and has 2 100k resistors for a voltage divider for reading remaining battery levels.
   
3. A remote using 2 analog joysticks with push buttons, another XIAO C3, and a 240x240 circular screen for showing battery levels for both. The remote runs on a 5v battery pack.

### Project Materials

| Component Name | Description | Source Link |
| :--- | :--- | :--- |
| **XIAO ESP32-C3** | Microcontroller wireless link | [Datasheet](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) |
| **Analog Joystick** | Manual thumbstick control | [Reference](https://components101.com/modules/joystick-module) |
| **GC9A01 Display** | Circular screen telemetry | [Driver](https://www.waveshare.com/wiki/1.28inch_LCD_Module) |
| **NEO-6M GPS** | Satellite navigation tracking | [Reference](https://components101.com/modules/neo-6mv2-gps-module) |
| **MPU9250 IMU** | Motion tracking gyro | [Specification](https://product.tdk.com/en/search/sensor/mortion-inertial/imu/info?part_no=MPU-9250) |
| **Brushed Motors** | Coreless propulsion drive | [Reference](https://www.adafruit.com/product/711) |
| **Foam Board** | Lightweight airframe structure | [Guide](https://www.flitetest.com/articles/ft-scratchbuild-build-videos) |
| **IRLB8721PBF-JSM** | Motor switching gate | [LCSC](https://www.lcsc.com/product-detail/MOSFETs_JSMSEMI-IRLB8721PBF-JSM_C52948633.html) |
| **1N4001 Diode** | Circuit flyback protection | [LCSC](https://www.lcsc.com/search?q=1N4001) |
| **10kΩ Resistor** | Gate pull down | [LCSC](https://www.lcsc.com/product-detail/Through-Hole-Resistors_UNI-ROYAL-MFR0W4F1002A50_C57436.html) |
| **100kΩ Resistor** | Telemetry voltage divider | [LCSC](https://www.lcsc.com/product-detail/Through-Hole-Resistors_YAGEO-MFR-25FRF52-100K_C1740093.html) |


## Assembly

The main body of the plane will be constructed of foam that I will buy at Dollar Tree, and I will assemble it according to [this guide](https://canva.link/13dvw4ls8qo39oa) I downloaded.
Since it has 2 motors, I can have one side speed up to bank the other way, or have both speed up/slow down to adjust pitch.

I also designed a 3d printed case for the transmitter, so here is the Onshape link:
https://cad.onshape.com/documents/e551e0e861c010d2a69231d2/w/2bc16dd78661a5521259ed7d/e/f502e56e68dee0d14d4a1407?renderMode=0&uiState=6ae8e8fff03f46e928020b88
<img width="979" height="713" alt="image" src="https://github.com/user-attachments/assets/807c1d4a-1d8b-4ef2-8764-c335987232eb" />

## Specs
- Flight controller board: ~3 inches by ~2/3 inches
- Remote: ~180mm by ~80mm
- 1S battery system
