SiriProxy-TV-Control
====================

Allows the remote controlling of an LG TV and Sony Amplifier using an Arduino UNO compatible development board. It's not limited to this hardware, you'll just have to decode the IR signals yourself.

Setup
-----

1. Copy the contents of `config-info.yml` into your `~/.siriproxy/config.yml`.
2. rvmsudo siriproxy update.
3. Restart SiriProxy.

Requirements/Components
=======================

Electronic Components
---------------------

1. Arduino UNO compatible development board.
2. Arduino WiFly or Ethernet Shield
3. 950nm IR Transmitting LED

Electronic Components to Decode IR Signals
------------------------------------------

1. 37Khz IR Receiver LED (Code not provided to Decode remote signals, you'll have to roll your own or Google it yourself)
2. 47ohm Resistor
3. Breadboard Cables/Wires
4. Breadboard
