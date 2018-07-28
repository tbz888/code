#!/usr/bin/expect
#prerequisite: yum install expect
spawn su
expect "："
send "1\r"
interact
