angle = 3600000000000000000000000000000000000000000000000000L

saved = angle
for i in range(50):
    saved = saved / 2   #处理奇数情况
    print saved,
    integer = str(saved)
    summation = 0
    for x in integer:
        summation = summation + ord(x) - 48
    print "outcome: " + str(summation) + " remainder:"+ str(summation%9)
