SiriProxy-TV-Control
====================

Allows the remote controlling of an LG TV and Sony Amplifier using an Arduino UNO compatible development board. It's not limited to this hardware, you'll just have to decode the IR signals yourself.

Video
=====

http://www.youtube.com/watch?v=wrGd0kQxRDM

Setup
=====

Prerequisite Ruby Gems
----------------------

1. Nokogiri (`rvmsudo gem install nokogiri`)
2. HTTParty (`rvmsudo gem install httparty`)
3. JSON (`rvmsudo gem install json`)
4. serialport (`rvmsudo gem install serialport`)
5. scrapi (`rvmsudo gem install scrapi`)

Configure SiriProxy
-------------------

Copy the contents of `config-info.yml` into your `~/.siriproxy/config.yml`.

Your `~/.siriproxy/config.yml` should look something like this:

    - name: 'Example'
      path: './plugins/siriproxy-example'

    - name: 'SiriProxy TV Control'
      git: 'https://github.com/rakusu/SiriProxy-TV-Control.git'

Then run `rvmsudo siriproxy update` from the console. Then just start SiriProxy by running `rvmsudo siriproxy server`

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

Re-use of my code is fine under a Creative Commons 3.0 [Non-commercial, Attribution, Share-Alike](http://creativecommons.org/licenses/by-nc-sa/3.0/) license. In short, this means that you can use my code, modify it, do anything you want. Just don't sell it and make sure to give me a shout-out. Also, you must license your derivatives under a compatible license (sorry, no closed-source derivatives). If you would like to purchase a more permissive license (for a closed-source and/or commercial license), please contact me directly. See the Creative Commons site for more information.

Disclaimer
==========

I'm not affiliated with Apple in any way. They don't endorse this application. They own all the rights to Siri (and all associated trademarks).

This software is provided as-is with no warranty whatsoever. Apple could do things to block this kind of behavior if they want. Also, if you cause problems (by sending lots of trash to the Guzzoni servers or anything), I fully support Apple's right to ban your UDID (making your phone unable to use Siri). They can, and I wouldn't blame them if they do.

I'm a huge fan of Apple and the work that they do. Siri is a very cool feature and I'm pretty excited to explore it and add functionality. Please refrain from using this software for anything malicious.