require 'optparse'
require 'etc'

@result = []
@options = {}

def check_for_conditions(file_name)
	failed = false

	if @options[:name_pattern]
		re = Regexp.new(@options[:name_pattern])
		if !(re.match(file_name))
			failed = true
		end
	end

	if !failed && @options[:type]
		case options[:type]
		when "d"
			if !File.directory?(file_name)
				failed = true
			end
		when "f"
			if !File.file?(file_name)
				failed = true;
			end
		when "l"
			if !File.symlink?(file_name)
				failed = true;
			end
		end
	end

	if !failed && @options[:newer_than_file]
		if File.mtime(file_name) <= File.mtime(@options[:newer_than_file])
			failed = true;
		end
	end

	if !failed && @options[:user_name]
		uid = File.stat(file_name).uid
		if Etc.getpwuid(uid).name != @options[:user_name]
			failed = true;
		end
	end

	if !failed
		@result << file_name
	end
end

def dir_search(cur_dir, cur_depth, max_depth)
	Dir.chdir(cur_dir) do
		Dir.entries(Dir.pwd).each do |child|
			if (child != ".") && (child != "..")
				full_path = File.join(Dir.pwd, child)
				if File.exists? full_path
					check_for_conditions(full_path)
				end
				if (!max_depth ||  cur_depth < max_depth) && File.directory?(full_path)
					dir_search(full_path, cur_depth + 1, max_depth)
				end
			end
		end
	end
end

OptionParser.new do |opts|
	opts.banner = "Usage: find.rb DIRECTORY [OPTIONS]"
	
	@options[:name_pattern] = nil
	opts.on("-n", "--name PATTERN", "Search for files with names that maches the given pattern") do |pattern|
			@options[:name_pattern] = pattern
		end

	@options[:type] = nil
	opts.on("-t", "--type TYPE", [:f, :d, :l], "Search for specified type of files. Avaliable type specificators:\nf - file\nd - directory\nl - symbolic link") do |type|
			@options[:type] = type
		end

	@options[:user_name] = nil
	opts.on("-u", "--user NAME", "Search for files owned by the given user") do |name|
			@options[:user_name] = name
		end

	@options[:max_depth] = nil
	opts.on("-d", "--max_depth N", "Do not go deeper than N subdirectories while crawling") do |n|
			@options[:max_depth] = n.to_i
		end

	@options[:newer_than_file] = nil
	opts.on("-c", "--cnewer PATH", "Search for files that are newer than the given file") do |path|
			@options[:newer_than_file] = path
		end
end.parse!

if ARGV.size < 1
	puts "Directory for search was not specified"
	exit 1
end

dir_search(ARGV[0], 0, @options[:max_depth])

puts @result
