SiriProxy-TV-Control
====================

Allows the remote controlling of an LG TV and Sony Amplifier using an Arduino UNO compatible development board. It's not limited to this hardware, you'll just have to decode the IR signals yourself.

# Setup

1. Copy the contents of `config-info.yml` into your `~/.siriproxy/config.yml`.
2. rvmsudo siriproxy update.
3. Restart SiriProxy.

# Min. Requirements/Components

1. SiriProxy
2. Arduino UNO compatible development board.
3. Arduino WiFly or Ethernet Shield
4. 950nm IR Transmitting LED

# Recommended Requirements/Components

1. All of the above
2. 37Khz IR Receiver LED (Code not provided to Decode remote signals, you'll have to roll your own or Google it yourself)
3. 47ohm Resistor
4. Breadboard Cables
5. Breadboard
