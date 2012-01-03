require 'cora'
require 'siri_objects'
require 'json'
require 'open-uri'
require 'httparty'
require 'nokogiri'
require 'pp'

class SiriProxy::Plugin::Arduino < SiriProxy::Plugin

	def initialize(config = {})
		@custom_channels = { abctwo: 22, abcthree: 23, abcn: 24, seventwo: 72, sevenmate: 73, go: 99, gem: 90, one: 1, sbs: 3, sbstwo: 32 }
		@responses = ["One moment.", "Your wish is my command.", "Yes, my master.", "Please hold.", "Just a second.", "Just chill.", "Hang on a second.", "Hold on a second.", "Just a moment.", "Give me a second."]
		@responses_okay = ["Good choice.", "Fair enough.", "No problem.", "Okay then.", "Fine with me.", "If you say so."]
		@responses_watch = ["Would you like to watch it?", "Are you sure you want to watch this crap?", "Want me to change the station for you?", "Should I change the channel for you?"]
	end

	def change_channel(number)

		say "I'm changing the channel to: #{convert_channel(number)}"

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something broke."
			else
				t.print "{channel,#{number}}"
				say @responses[rand(@responses.size)]
				t.close
			end

			request_completed 

		}

	end

	def convert_channel(channel)
		# valid channels:
		# 2 = (2)
	  
		# 22 = (ABC2)
		if (channel == "22")
			channel = "ABC2"
		end
			
		# 23 = (ABC3)
		if (channel == "23")
			channel = "ABC3"
		end

		# 24 = (ABCN)
		if (channel == "24")
			channel = "ABCN"
		end
		  
		# 7 = (7)
	  
		# 72 = (7TWO)
		if (channel == "72")
			channel = "7TWO"
		end

		# 73 = (7MATE)
		if (channel == "73")
			channel = "7MATE"
		end
	  
		# 9 = (9)
	  
		# 99 = (GO)
		if (channel == "99")
			channel = "GO"
		end

		# 90 = (GEM)
		if (channel == "90")
		  channel = "GEM"
		end

		# 1 = (ONE)
		if (channel == "1")
			channel = "ONE"
		end
	  
		# 10 = (10)
		# 11 = (11)
	  
		# 3 = (SBS)
		if (channel == "3")
			channel = "SBS"
		end

		# 32 = (SBS2)
		if (channel == "32")
		  channel = "SBS2"
		end
		
		# 44 = (31)
		if (channel == "44")
			channel = "31_VIC"
		end

		return channel
	end

	def show_info(channel)
	
		say "Checking what's playing on: #{convert_channel(channel)}. One moment."
		
		Thread.new {
		
			number = channel

			# convert channel code to 
			# correct channel name
			channel = convert_channel(channel)

			current_time_str = ""
			program_name = ""
			program_time = ""
			program_channel = ""
			program_additional_info = "No information was found."

			# create a new time object
			t = Time.new
			
			# set time properties
			#current_time = Time.local(t.year, t.month, t.day, t.hour, t.min/5*5)
			current_time = Time.local(t.year, t.month, t.day, t.hour, t.min)
			date_str = current_time.strftime("%d%m%Y").strip
			current_time_str = current_time.strftime("%l.%M+%p").downcase

			# are we searching?
			searching = true
			attempts = 0

			# loop through programs based on 
			# properties set above
			while searching do
				# die if we've tried too many times
				if attempts == 61
					say "Sorry, but I couldn't find anything."
					
					request_completed

					return
				end

				begin
					# let's get scraping
					uri = "http://www.ourguide.com.au/tv_guide_info.php?region=melbourne&state=VIC&date=#{date_str}&channel=#{channel}&time=#{current_time_str.strip}"
					puts uri
					doc = Nokogiri::HTML(open(uri))
					
					# set scraped information
					@programs = doc.css("div.tvShow").map do |programnode|
						program_name = programnode.at_css("h3").text.strip
						program_time = programnode.at_css("div[2]").text.strip
						program_channel = programnode.at_css("div[3]").text.strip
						program_additional_info = programnode.at_css("div[4]").text.strip
					end
					
					# stop searching
					searching = false
				rescue
					#puts $!
					
					# didn't find info playing about the current show
					# so go back until we find valid info from the beginning of the show
					current_time = current_time - (1 * 60)
					current_time_str = current_time.strftime("%l.%M+%p").downcase
					attempts += 1
				end
			end

			say "Here is what's playing on #{number} - #{program_name}"

			object = SiriAddViews.new

			object.make_root(last_ref_id)

			answer = SiriAnswer.new(program_name, [
				SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/#{channel}.png"),
				SiriAnswerLine.new(program_time),
				SiriAnswerLine.new(program_additional_info)
			])

			#answer << SiriAnswerLine.new(program_additional_info) unless program_additional_info?

			object.views << SiriAnswerSnippet.new([answer])

			send_object object
			
			#response = ask "Would you like to watch it?" #{program_name}

			#if (response =~ /yes/i)
				#change_channel number
			#else
				#say "Good Choice."
			#end
      
			request_completed

		}
    
	end

	# Example: "Siri, turn the TV/amp/aircon on/off?"
	listen_for /(tv|amp|amplifier|aircon|air-conditioner) (off|on)/i do |device|

		# Say a random response:
		say @responses[rand(@responses.size)]

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Ouch. Something just broke."
			else
				t.print "{power,#{device.downcase}}"
				say "Sent power to the #{device}."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, mute/unmute the TV/Amp."
	listen_for /(mute|meet) the (tv|amp|amplifier)/i do |source|

		# Say a random response:
		say @responses[rand(@responses.size)]

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{source,mute}"
				say "I muted the TV for you."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, give me a list of channels."
	listen_for /list of (channels|shows|programs)/i do |name|
		
		# Say a random response:
		say @responses[rand(@responses.size)] 
		
		object = SiriAddViews.new

		object.make_root(last_ref_id)

		answer = SiriAnswer.new("Channels:", [
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/2.png"),
			SiriAnswerLine.new("2"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/ABC2.png"),
			SiriAnswerLine.new("22"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/ABC3.png"),
			SiriAnswerLine.new("23"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/ABCN.png"),
			SiriAnswerLine.new("24"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/7TWO.png"),
			SiriAnswerLine.new("7"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/7.png"),
			SiriAnswerLine.new("72"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/7MATE.png"),
			SiriAnswerLine.new("73"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/9.png"),
			SiriAnswerLine.new("9"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/GO.png"),
			SiriAnswerLine.new("99"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/GEM.png"),
			SiriAnswerLine.new("90"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/ONE.png"),
			SiriAnswerLine.new("1"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/10.png"),
			SiriAnswerLine.new("10"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/11.png"),
			SiriAnswerLine.new("11"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/SBS.png"),
			SiriAnswerLine.new("3"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/SBS2.png"),
			SiriAnswerLine.new("32"),
			SiriAnswerLine.new("logo", "http://www.ourguide.com.au/images/station_images/31_VIC.png"),
			SiriAnswerLine.new("44")
		])

		object.views << SiriAnswerSnippet.new([answer])

		send_object object
		
		request_completed
		
	end
	
	# Example: "Siri, show/hide channel info/information."
	listen_for /(show|hide) channel (info|information|into)/i do |info|

		# Say a random response:
		say @responses[rand(@responses.size)] 

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{info,#{info.downcase}}"
				say "Showing you channel information."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, change/modify tv input/source."
	listen_for /(change|modify) tv (input|source)/i do |info|

		# Say a random response:
		say @responses[rand(@responses.size)] 

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{input,#{info.downcase}}"
				say "Changed TV input."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, can you change the source to Nintendo?"
	listen_for /source to (ps3|nintendo|xbox)/i do |source|

		# Say a random response:
		say @responses[rand(@responses.size)]

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{source,#{source.downcase}}"
				say "Source changed to #{source.upcase}."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, turn the volume up by 10."
	listen_for /volume up by ([0-9,]*[0-9])/i do |number|

		# Say a random response:
		say @responses[rand(@responses.size)] 

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{volumeup,#{number}}"
				say "Volume turned up by #{number}."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, turn the volume down by 10."
	listen_for /volume down by ([0-9,]*[0-9])/i do |number|

		# Say a random response:
		say @responses[rand(@responses.size)]

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{volumedown,#{number}}"
				say "Volume turned down by #{number}."
				t.close
			end

			request_completed 

		}

	end

	# Example: "Siri, turn the volume up/down."
	listen_for /volume (up|down)/i do |volume|

		# Say a random response:
		say @responses[rand(@responses.size)]

		Thread.new {

			begin
				t = TCPSocket.new("10.1.1.45", 8000)
			rescue
				say "Something went wrong."
			else
				t.print "{volume#{volume},8}"
				say "Volume turned #{volume}."
				t.close
			end

		  request_completed

		}

	end

	# Example: "Siri, what's on channel 72?"
	listen_for /on channel ([0-9,]*[0-9])/i do |number|

		show_info number

	end

	# Example: "Siri, what's on GO?"
	listen_for /on (#{Regexp.union({ abctwo: 22, abcthree: 23, abcn: 24, seventwo: 72, sevenmate: 73, go: 99, gem: 90, one: 1, sbs: 3, sbstwo: 32 }.keys.map(&:to_s))})/i do |name|

		show_info @custom_channels[name.to_sym]

	end

	# Example: "Siri, change to channel GO."
	listen_for /channel (#{Regexp.union({ abctwo: 22, abcthree: 23, abcn: 24, seventwo: 72, sevenmate: 73, go: 99, gem: 90, one: 1, sbs: 3, sbstwo: 32 }.keys.map(&:to_s))})/i do |name|

		change_channel @custom_channels[name.to_sym]
		
	end

	#Example: "Siri, change to channel 72."
	listen_for /channel ([0-9,]*[0-9])/i do |number|

		change_channel number

	end
  
end
