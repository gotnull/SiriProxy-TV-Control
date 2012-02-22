#include <avr/pgmspace.h>
#include "Codes.h"

#define SOP '{'
#define EOP '}'

bool started = false;
bool ended = false;

char inData[80];
byte index;

int IRledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(IRledPin, OUTPUT);
}

void loop() {
  // Read all serial data available, as fast as possible
  while (Serial.available() > 0) {
    char inChar = Serial.read();

    if (inChar == SOP) {
      index = 0;
      inData[index] = '\0';
      started = true;
      ended = false;
    } 
    else if (inChar == EOP) {
      ended = true;
      break;
    } 
    else {
      if (index < 79) {
        inData[index] = inChar;
        index++;
        inData[index] = '\0';
      }
    }
  }

  // We are here either because all pending serial
  // data has been read OR because an end of
  // packet marker arrived. Which is it?
  if (started && ended) {
    // The end of packet marker arrived. Process the packet
    char *cmd = strtok(inData, ",");

    if (cmd) {
      char *val = strtok(NULL, ",");
      if (val) {
        sendCommand(cmd, val);
      }
    }

    // Reset for the next packet
    started = false;
    ended = false;
    index = 0;
    inData[index] = '\0';
  }
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli(); // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(IRledPin, HIGH); // this takes about 3 microseconds to happen
    delayMicroseconds(10); // hang out for 10 microseconds
    digitalWrite(IRledPin, LOW); // this also takes about 3 microseconds
    delayMicroseconds(10); // hang out for 10 microseconds

    // so 26 microseconds altogether
    microsecs -= 26;
  }

  sei(); // this turns them back on
}

void channel(char* numbers) {
  int i = 0;

  for (i = 0; i < 2; i++) {
    if (numbers[i] == '0') {
      sendCode(tv_channel_0);
      delay(100);
    } 
    else if (numbers[i] == '1') {
      sendCode(tv_channel_1);
      delay(100);
    } 
    else if (numbers[i] == '2') {
      sendCode(tv_channel_2);
      delay(100);
    } 
    else if (numbers[i] == '3') {
      sendCode(tv_channel_3);
      delay(100);
    } 
    else if (numbers[i] == '4') {
      sendCode(tv_channel_4);
      delay(100);
    } 
    else if (numbers[i] == '5') {
      sendCode(tv_channel_5);
      delay(100);
    } 
    else if (numbers[i] == '6') {
      sendCode(tv_channel_6);
      delay(100);
    } 
    else if (numbers[i] == '7') {
      sendCode(tv_channel_7);
      delay(100);
    } 
    else if (numbers[i] == '8') {
      sendCode(tv_channel_8);
      delay(100);
    } 
    else if (numbers[i] == '9') {
      sendCode(tv_channel_9);
      delay(100);
    }
  }
}

void volume(char *command, char* value) {
  for (int i = 0; i < atoi(value); i++) {
    if (strcmp(command, "volumeup") == 0) {
      sendCode(amp_volume_up);
      sendCode(tv_volume_up);
    } 
    else if (strcmp(command, "volumedown") == 0) {
      sendCode(amp_volume_down);
      sendCode(tv_volume_down);
    }
    delay(300);
  }
}

void power(char* device) {
  if (strcmp(device, "tv") == 0) {
    sendCode(trigger_emberplug);
    delay(3000);
    sendCode(tv_power_onoff);
  } 
  else if (strcmp(device, "amp") == 0 || strcmp(device, "amplifier") == 0) {
    sendCode(amp_power_onoff);
  } 
  else if (strcmp(device, "air-conditioner") == 0 || strcmp(device, "air-con") == 0 || strcmp(device, "aircon") == 0) {
    sendCode(aircon_power_onoff);
  }
}

void source(char* source) {
  if (strcmp(source, "ps3") == 0) {
    sendCode(ps3_source);
  } 
  else if (strcmp(source, "nintendo") == 0) {
    sendCode(nintendo_source);
  } 
  else if (strcmp(source, "xbox") == 0) {
    sendCode(xbox_source);
  } 
  else if (strcmp(source, "mute") == 0) {
    sendCode(tv_mute);
  }
}

void sendCommand(char *command, char *value) {
  if (strcmp(command, "power") == 0) {
    power(value);
  } 
  else if (strcmp(command, "source") == 0) {
    source(value);
  } 
  else if (strcmp(command, "channel") == 0) {
    channel(value);
  } 
  else if (strcmp(command, "volumeup") == 0 || strcmp(command, "volumedown") == 0) {
    volume(command, value);
  } 
  else if (strcmp(command, "info") == 0) {
    sendCode(show_hide_info);
  } 
  else if (strcmp(command, "input") == 0) {
    sendCode(tv_input);
  }
}

void sendCode(const prog_uint16_t *pInArray) {
  for (int i=0; i < calculateSize(pInArray); i=i+2) {
    pulseIR(pgm_read_word(pInArray++));
    delayMicroseconds(pgm_read_word(pInArray++));
  }
}

int calculateSize(const prog_uint16_t *pInArray) {
  return sizeof(pInArray) / sizeof(prog_uint16_t);
}
