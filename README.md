# DIY-Airplane-v1
I have made many attempts to create some type of flying thing before, and they always failed because of a low budget. This is my first try that actually holds some promise. I will be creating both a remote and a receiver from scratch — the remote will use joysticks and XIAO boards I already have, and the FC board will be JLCPCB+LCSC. 

### Project Materials

| Component Name | Description | Source Link |
| :--- | :--- | :--- |
| **XIAO ESP32-C3** | Microcontroller wireless link | https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/ 【1-90ec42】 |
| **Analog Joystick** | Manual thumbstick control | https://docs.arduino.cc/learn/electronics/joystick-module/ |
| **GC9A01 Display** | Circular screen telemetry | https://www.waveshare.com/wiki/1.28inch_LCD_Module 【2-110d74】 |
| **NEO-6M GPS** | Satellite navigation tracking | https://components101.com/modules/neo-6mv2-gps-module 【3-15e73e】 |
| **MPU9250 IMU** | Motion tracking gyro/accelerometer/magnetometer | https://product.tdk.com/en/search/sensor/mortion-inertial/imu/info?part_no=MPU-9250 【4-d0b68a】 |
| **Brushed Motors** | Coreless propulsion drive | https://www.adafruit.com/product/711 |
| **Foam Board** | Lightweight airframe structure | https://www.flitetest.com/articles/ft-scratchbuild-build-videos |
| **IRLB8721PBF-JSM** | Motor switching MOSFET | https://www.lcsc.com/search?q=IRLB8721PBF |
| **1N4001 Diode** | Circuit flyback protection | https://www.lcsc.com/product-detail/C47018536.html 【5-cf9828】 |
| **10kΩ Resistor** | Gate pull-down resistor | https://www.lcsc.com/search?q=10K%20resistor |
| **100kΩ Resistor** | Telemetry voltage divider | https://www.lcsc.com/search?q=100K%20resistor |
