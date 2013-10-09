<?php
//this will just pick out a random language for me to complete the challenge in
//some of these I have little to 0 experience with, so more learning for me

$languages = array
(
	'PHP',
	'Ruby',
	'Python',
	'Bash',
	'Javascript',
	'Java',
	'Perl',
	'C',
	'C++',
	'Haskell',
	'Lua',
);

echo $languages[rand(0, count($languages) - 1)] . "\n";
