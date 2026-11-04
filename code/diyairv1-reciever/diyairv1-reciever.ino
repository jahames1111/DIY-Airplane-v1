#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <ESP32PWM.h>

struct __attribute__((packed)) IncomingControlDataStructure {
  uint8_t throttle_axis_value;
  int8_t yaw_axis_value;
  int8_t pitch_axis_value;
  int8_t roll_axis_value;
  uint8_t button_flags_value;
};

struct IncomingControlDataStructure transmitter_packet_instance;
Servo mechanical_tail_servo_object;
unsigned long microsecond_timestamp_of_last_received_packet = 0;

void handle_espnow_receive_data(const esp_now_recv_info_t *receive_info_pointer, const uint8_t *incoming_data_buffer, int incoming_data_length) {
  if (incoming_data_length == sizeof(transmitter_packet_instance)) {
    memcpy(&transmitter_packet_instance, incoming_data_buffer, sizeof(transmitter_packet_instance));
    microsecond_timestamp_of_last_received_packet = millis();
    int servo_pulse_duration_microseconds = map(transmitter_packet_instance.yaw_axis_value, -127, 127, 1000, 2000);
    mechanical_tail_servo_object.writeMicroseconds(servo_pulse_duration_microseconds);
    int calculated_left_motor_speed_output = transmitter_packet_instance.throttle_axis_value + (transmitter_packet_instance.yaw_axis_value * 0.5);
    int calculated_right_motor_speed_output = transmitter_packet_instance.throttle_axis_value - (transmitter_packet_instance.yaw_axis_value * 0.5);
    if (calculated_left_motor_speed_output > 255) {
      calculated_left_motor_speed_output = 255;
    }
    if (calculated_left_motor_speed_output < 0) {
      calculated_left_motor_speed_output = 0;
    }
    if (calculated_right_motor_speed_output > 255) {
      calculated_right_motor_speed_output = 255;
    }
    if (calculated_right_motor_speed_output < 0) {
      calculated_right_motor_speed_output = 0;
    }
    analogWrite(2, calculated_left_motor_speed_output);
    analogWrite(3, calculated_right_motor_speed_output);
  }
}

void setup() {
  Serial.begin(115200);
  ESP32PWM::allocateTimer(0);
  mechanical_tail_servo_object.setPeriodHertz(50);
  mechanical_tail_servo_object.attach(1, 1000, 2000);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    return;
  }
  esp_now_register_recv_cb(handle_espnow_receive_data);
  microsecond_timestamp_of_last_received_packet = millis();
}

void loop() {
  unsigned long current_system_millis_timestamp = millis();
  unsigned long absolute_elapsed_time_difference = current_system_millis_timestamp - microsecond_timestamp_of_last_received_packet;
  if (absolute_elapsed_time_difference > 200) {
    analogWrite(2, 0);
    analogWrite(3, 0);
    mechanical_tail_servo_object.writeMicroseconds(1500);
  }
  delay(100);
}
