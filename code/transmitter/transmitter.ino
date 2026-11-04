#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

uint8_t target_mac_address[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

struct __attribute__((packed)) OutgoingControlDataStructure {
  uint8_t throttle_axis_value;
  int8_t yaw_axis_value;
  int8_t pitch_axis_value;
  int8_t roll_axis_value;
  uint8_t button_flags_value; 
};

struct __attribute__((packed)) IncomingTelemetryDataStructure {
  uint16_t battery_millivolts_value;
  int16_t pitch_angle_value;
  int16_t roll_angle_value;
  uint16_t gps_ground_speed_value;
  uint8_t connected_satellites_count;
};

struct OutgoingControlDataStructure transmitter_packet_instance;
struct IncomingTelemetryDataStructure receiver_packet_instance;

void handle_espnow_send_status(const uint8_t *mac_address_pointer, esp_now_send_status_t transmission_status_result) {
}

void handle_espnow_receive_data(const esp_now_recv_info_t *receive_info_pointer, const uint8_t *incoming_data_buffer, int incoming_data_length) {
  if (incoming_data_length == sizeof(receiver_packet_instance)) {
    memcpy(&receiver_packet_instance, incoming_data_buffer, sizeof(receiver_packet_instance));
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  WiFi.mode(WIFI_STA);
  WiFi.setTxPower(WIFI_POWER_19_5dBm);
  if (esp_now_init() != ESP_OK) {
    return;
  }
  esp_now_register_send_cb(handle_espnow_send_status);
  esp_now_register_recv_cb(handle_espnow_receive_data);
  esp_now_peer_info_t custom_peer_info_structure = {};
  memcpy(custom_peer_info_structure.peer_addr, target_mac_address, 6);
  custom_peer_info_structure.channel = 0;  
  custom_peer_info_structure.encrypt = false;
  if (esp_now_add_peer(&custom_peer_info_structure) != ESP_OK){
    return;
  }
}

void loop() {
  long throttle_accumulator = 0;
  for(int throttle_counter = 0; throttle_counter < 10; throttle_counter = throttle_counter + 1) {
    throttle_accumulator = throttle_accumulator + analogRead(0);
  }
  int throttle_average_calculated = throttle_accumulator / 10;
  transmitter_packet_instance.throttle_axis_value = map(throttle_average_calculated, 0, 4095, 0, 255);
  delayMicroseconds(5);

  long yaw_accumulator = 0;
  for(int yaw_counter = 0; yaw_counter < 10; yaw_counter = yaw_counter + 1) {
    yaw_accumulator = yaw_accumulator + analogRead(1);
  }
  int yaw_average_calculated = yaw_accumulator / 10;
  int yaw_delta_from_center = yaw_average_calculated - 2048;
  if (abs(yaw_delta_from_center) < 122) {
    transmitter_packet_instance.yaw_axis_value = 0;
  } else {
    if (yaw_delta_from_center > 0) {
      transmitter_packet_instance.yaw_axis_value = map(yaw_average_calculated, 2048 + 122, 4095, 0, 127);
    } else {
      transmitter_packet_instance.yaw_axis_value = map(yaw_average_calculated, 0, 2048 - 122, -127, 0);
    }
  }
  delayMicroseconds(5);

  long pitch_accumulator = 0;
  for(int pitch_counter = 0; pitch_counter < 10; pitch_counter = pitch_counter + 1) {
    pitch_accumulator = pitch_accumulator + analogRead(2);
  }
  int pitch_average_calculated = pitch_accumulator / 10;
  int pitch_delta_from_center = pitch_average_calculated - 2048;
  if (abs(pitch_delta_from_center) < 122) {
    transmitter_packet_instance.pitch_axis_value = 0;
  } else {
    if (pitch_delta_from_center > 0) {
      transmitter_packet_instance.pitch_axis_value = map(pitch_average_calculated, 2048 + 122, 4095, 0, 127);
    } else {
      transmitter_packet_instance.pitch_axis_value = map(pitch_average_calculated, 0, 2048 - 122, -127, 0);
    }
  }
  delayMicroseconds(5);

  long roll_accumulator = 0;
  for(int roll_counter = 0; roll_counter < 10; roll_counter = roll_counter + 1) {
    roll_accumulator = roll_accumulator + analogRead(3);
  }
  int roll_average_calculated = roll_accumulator / 10;
  int roll_delta_from_center = roll_average_calculated - 2048;
  if (abs(roll_delta_from_center) < 122) {
    transmitter_packet_instance.roll_axis_value = 0;
  } else {
    if (roll_delta_from_center > 0) {
      transmitter_packet_instance.roll_axis_value = map(roll_average_calculated, 2048 + 122, 4095, 0, 127);
    } else {
      transmitter_packet_instance.roll_axis_value = map(roll_average_calculated, 0, 2048 - 122, -127, 0);
    }
  }

  int active_button_bitmask_accumulator = 0;
  if (digitalRead(8) == LOW) {
    active_button_bitmask_accumulator = active_button_bitmask_accumulator + 1;
  }
  if (digitalRead(9) == LOW) {
    active_button_bitmask_accumulator = active_button_bitmask_accumulator + 2;
  }
  transmitter_packet_instance.button_flags_value = active_button_bitmask_accumulator;

  esp_now_send(target_mac_address, (uint8_t *) &transmitter_packet_instance, sizeof(transmitter_packet_instance));
  delay(20); 
}
