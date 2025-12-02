sum = 0
input = File.readlines('input/1.txt', chomp: true).each do |line|
	first = line.length - 1
	first_char = ''
	second = 0
	second_char = ''
	numbers = { 'one' => '1', 'two' => '2', 'three' => '3', 'four' => '4', 'five' => '5', 'six' => '6', 'seven' => '7', 'eight' => '8', 'nine' => '9' }

	for number in ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'] do
		if line.index(number) and first > line.index(number) then
			first = line.index(number)
			first_char = numbers[number]
		end
		if line.rindex(number) and second < line.rindex(number) then
			second = line.rindex(number)
			second_char = numbers[number]
		end
	end

	for char in line.split('') do
		if char.match?(/[[:digit:]]/) then
			if first > line.index(char) then
				first = line.index(char)
				first_char = char
			end
			break
		end
	end

	for char in line.split('').reverse do
		if char.match?(/[[:digit:]]/) then
			if second < line.rindex(char) then
				second = line.rindex(char)
				second_char = char
			end
			break
		end
	end

	if first_char == '' then
		first_char = second_char
	end
	if second_char == '' then
		second_char = first_char
	end
	sum += (first_char + second_char).to_i
end

puts sum