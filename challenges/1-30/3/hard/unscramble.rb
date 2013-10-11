#!/usr/bin/env ruby
#
#http://www.reddit.com/r/dailyprogrammer/comments/pkwgf/2112012_challenge_3_difficult/
#
#
# Welcome to cipher day!
#  For this challenge, you need to write a program that will take the scrambled words from this post, and compare them against wordlist.txt to unscramble them. For bonus points, sort the words by length when you are finished. Post your programs and/or subroutines!
#  Here are your words to de-scramble:
#  mkeart
#  sleewa
#  edcudls
#  iragoge
#  usrlsle
#  nalraoci
#  nsdeuto
#  amrhat
#  inknsy
#  iferkna
#
# Random language generator picked Ruby!

def main()
    word_list = getWordList("wordlist.txt")
    word_lookup = getWordLookup(word_list)
    scrambled_list = [
    "mkeart",
    "sleewa",
    "edcudls",
    "iragoge",
    "usrlsle",
    "nalraoci",
    "nsdeuto",
    "amrhat",
    "inknsy",
    "iferkna",
    ]
    scrambled_list.each do |word|
        print word_lookup[scrambleWord(word)] + "\n"
    end
end


#read in the input
def getWordList(filepath)
    return File.read(filepath).split("\n")
end

#get a big hash table of scrambled words
def getWordLookup(word_list)
    word_lookup = {}
    word_list.each do |word|
        word_lookup[scrambleWord(word)] = word
    end
    return word_lookup
end


#sort all the letters in the word, so it doesn't matter if they were originally scrambled
def scrambleWord(word)
    return word.split("").sort().join("")
end

main()