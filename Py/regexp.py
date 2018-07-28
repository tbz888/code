import re

# string
text = r"tangbzh@mail.sysu.edu.cn"

# regexp
expression = r"\..+?\."
pattern = re.compile(expression)

# find the first
match = re.search(pattern, text)
print match.group(0)[1:len(match.group(0))-1]

# find all
print pattern.findall(text)
