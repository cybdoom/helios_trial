require 'optparse'

def check_for_conditions(file_name)

end

def dir_search(cur_dir, cur_depth, max_depth, &closure)
	Dir.chdir(cur_dir) do
		Dir.entries(Dir.pwd).each do |child|
			if (child != ".") && (child != "..")
				full_path = File.join(Dir.pwd, child)
				if File.exists? full_path
					check_for_conditions(full_path)
				end
				if (!max_depth ||  cur_depth < max_depth) && File.directory?(full_path)
					dir_search(full_path, cur_depth + 1, max_depth, &closure)
				end
			end
		end
	end
end

#dir_search(target_dir, 0, nil) {|cur_node| puts cur_node}

options = {}
OptionParser.new do |opts|
	opts.banner = "Usage: find.rb DIRECTORY [OPTIONS]"
	
	options[:name_pattern] = ""
	opts.on("-n", "--name PATTERN", "Search for files with names that maches the given pattern") do |pattern|
			options[:name_pattern] = pattern
		end

	options[:type] = "f"
	opts.on("-t", "--type TYPE", [:f, :d, :l], "Search for specified type of files. Avaliable type specificators:\nf - file\nd - directory\nl - symbolic link") do |type|
			options[:type] = type
		end
end.parse!

p options
p ARGV