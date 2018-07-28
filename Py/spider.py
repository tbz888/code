import urllib
import urllib2

request = urllib2.Request("http://www.baidu.com");
response = urllib2.urlopen(request);
print response.read()

#post
# values = {"username":"test","password":"test"}
# data = urllib.urlencode(values)
# url = "http://59.151.65.97:8181/login"  # success
# request2 = urllib2.Request(url, data)
# response2 = urllib2.urlopen(request2)
# print response2.read()

#get: user password at the end of URL

#debug log
# httpHandler = urllib2.HTTPHandler(debuglevel=1)
# httpsHandler = urllib2.HTTPSHandler(debuglevel=1)
# opener = urllib2.build_opener(httpHandler, httpsHandler)
# urllib2.install_opener(opener)
# response5 = urllib2.urlopen('http://www.baidu.com')
# print response5.read()