#!/usr/bin/env ruby
#
#http://www.reddit.com/r/dailyprogrammer/comments/pjbj8/easy_challenge_2/
#
#
# Hello, coders! An important part of programming is being able to apply your programs, so your challenge for today is to create a calculator application that has use in your life. It might be an interest calculator, or it might be something that you can use in the classroom. For example, if you were in physics class, you might want to make a F = M * A calc.
# EXTRA CREDIT: make the calculator have multiple functions! Not only should it be able to calculate F = M * A, but also A = F/M, and M = F/A!
#
#Random language generator picked Ruby!

#This is a simple calculator that will calculate the average load of impressions over a day
#I.e. If you want to run 2,000,000 advertising impressions, what would the avg imps/sec be
#Also does the opposite, if you can handle 20 imps/sec how many would that be in a day?

def main()
	while true
	    imps = getImpressions()

        daily = getMode()

        calculateImps(imps, daily)

        break
	end
end

#ask user for num impressions
def getImpressions()
    puts "How many impressions?"
    imps = gets.chomp.gsub(/[^0-9]/, "").to_i
    #strip non numeric chars
    return imps
end

#ask user whether it is per second or per day
def getMode()

    puts "Is that per second or per day?"
    mode = gets.downcase.chomp

    if mode == "day"
        return true
    end

    if mode == "second"
        return false
    end

    puts "I'm sorry, please answer second or day"
    return getMode()
end

#does the actual calculations

def calculateImps(imps, daily)

    if daily
        puts "On average there will be " + (imps / 86400).to_s + " imps per second"
    else
        puts "You can handle " + (imps * 86400).to_s + " daily imps"
    end

end

main()