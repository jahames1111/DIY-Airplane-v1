# DIY-Airplane-v1
I have made many attempts to create some type of flying thing before, and they always failed because of a low budget. This is my first try that actually holds some promise. I will be creating both a remote and a receiver from scratch — the remote will use joysticks and XIAO boards I already have, and the FC board will be JLCPCB+LCSC. 

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
