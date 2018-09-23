import os
# Markdown TODO list summary:
# 	only support single level * [x] / * [ ]  

buffer = open('todo-list.md', 'w', encoding = 'UTF-8')

def travel(callback):
	path = os.path.join(os.getcwd(), 'plan')
	for root, dirs, files in os.walk(path, topdown = True):
	    for file in files:
	        callback(root, file)

def check(root, file):
	filepath = os.path.join(root, file)
	file_object = open(filepath, 'r', encoding='UTF-8')
	isUnchecked = False
	try:
		list_of_all_the_lines = file_object.readlines()
		i = 1;
		for line in list_of_all_the_lines:
			if line.find('* [ ]') >= 0:
				if isUnchecked == False:
					buffer.write('> ' + file[:-3] + '\n')
					isUnchecked = True
				buffer.write(str(i) + '. ' + line)
				i = i + 1
	finally:
	    file_object.close()
	    if isUnchecked == True:
	    	buffer.write('\n')

if __name__ == '__main__':
	travel(check)
	buffer.close()