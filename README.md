SiriProxy-TV-Control
====================

Allows the remote controlling of an LG TV and Sony Amplifier using an Arduino UNO compatible development board. It's not limited to this hardware, you'll just have to decode the IR signals yourself.

Setup
=====

Prerequisite Ruby Gems
----------------------

1. Nokogiri (`gem install nokogiri`)
2. HTTParty (`gem install httparty`)
3. JSON (`gem install json`)

Configure SiriProxy
-------------------

1. Copy the contents of `config-info.yml` into your `~/.siriproxy/config.yml`.
2. rvmsudo siriproxy update.
3. Restart SiriProxy.

Requirements/Components
=======================

Software
--------

1. Arduino IDE v0023

Electronic Components
---------------------

1. Arduino UNO compatible development board
2. WiFly Shield, Ethernet Shield or Xbee Shield
3. 2 x Xbee Modules (for Xbee functionality)
3. 38Khz Infrared LED (950nm)

Decoding Remote Codes
---------------------

1. Infrared Receiver Diode
2. 47ohm Resistor
3. Breadboard and Cables/Wires

Licensing
=========

Re-use of my code is fine under a Creative Commons 3.0 Non-commercial, Attribution, Share-Alike license. In short, this means that you can use my code, modify it, do anything you want. Just don't sell it and make sure to give me a shout-out. Also, you must license your derivatives under a compatible license (sorry, no closed-source derivatives). If you would like to purchase a more permissive license (for a closed-source and/or commercial license), please contact me directly. See the Creative Commons site for more information.

Disclaimer
----------

This software is provided as-is with no warranty whatsoever.
