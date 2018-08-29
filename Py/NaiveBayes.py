import csv

reader = csv.reader(open("train.csv",'rb'))
buffer = reader.next()

total = 800000                                                          #count of training records
category = {}
condition = {}

def inc(data, container):
    if data not in container:
        container[data] = 1
    else:
        container[data] = container[data] + 1

def timeField(hour):
    if 6 <= hour < 12:     
        return '1'          
    elif 12 <= hour < 18: 
        return '2'
    elif 18 <= hour < 24: 
        return '3'
    elif 0 <= hour < 6: 
        return '4'

def getPosition(pos, XorY):
    if XorY == 'X':
        return str(round(-(float(pos)+122),2))
    else:
        return str(round((float(pos)-37),2))

#################training##############
for x in range(total):                                                  # count the attribute
    buffer = reader.next()
    token1 = buffer[1]                                                  # category
    token2 = buffer[3] + '|' + buffer[1]                                # dayOfweek
    token3 = buffer[4] + '|' + buffer[1]                                # PdDistrict
    token4 = buffer[6] + '|' + buffer[1]                                # address
    token5 = timeField(int(buffer[0][11:13])) + '|' + buffer[1]    # hour

    inc(token1, category)
    inc(token2, condition)
    inc(token3, condition)
    inc(token4, condition)
    inc(token5, condition)

categoryP = {}                                                          # compute the probability P(y)
for key, value in category.items():
    categoryP[key] = 1.0 * value / total

#################testing#################
testReader = csv.reader(open('test.csv', 'rb'))
currentTest = testReader.next()

result = []
for x in range(884262):                 #884262
    currentTest = testReader.next() 
    maxJudge = 0
    maxCategory = ''
    for key in category.keys():
        testDayweek = currentTest[2] + '|' + key
        testPD = currentTest[3] + '|' + key
        testAddress = currentTest[4] + '|' + key
        testHour = timeField(int(currentTest[1][11:13])) + '|' + key
        
        P1 = 1.0*condition[testDayweek]/category[key] if testDayweek in condition else 0.00001
        P2 = 1.0*condition[testPD]/category[key] if testPD in condition else 0.00001
        P3 = 1.0*condition[testAddress]/category[key] if testAddress in condition else 0.00001
        P4 = 1.0*condition[testHour]/category[key] if testHour in condition else 0.00001

        judge = categoryP[key] * P1 * P2 * P3 * P4 / (P1+P2+P3+P4)

        if judge > maxJudge:
            maxJudge = judge
            maxCategory = key
    result.append(maxCategory)

#################printing#################
csvfile = file('out.csv', 'wb')
writer = csv.writer(csvfile)
header = ['Id','ARSON','ASSAULT','BAD CHECKS','BRIBERY','BURGLARY','DISORDERLY CONDUCT','DRIVING UNDER THE INFLUENCE','DRUG/NARCOTIC','DRUNKENNESS','EMBEZZLEMENT','EXTORTION','FAMILY OFFENSES','FORGERY/COUNTERFEITING','FRAUD','GAMBLING','KIDNAPPING','LARCENY/THEFT','LIQUOR LAWS','LOITERING','MISSING PERSON','NON-CRIMINAL','OTHER OFFENSES','PORNOGRAPHY/OBSCENE MAT','PROSTITUTION','RECOVERED VEHICLE','ROBBERY','RUNAWAY','SECONDARY CODES','SEX OFFENSES FORCIBLE','SEX OFFENSES NON FORCIBLE','STOLEN PROPERTY','SUICIDE','SUSPICIOUS OCC','TREA','TRESPASS','VANDALISM','VEHICLE THEFT','WARRANTS','WEAPON LAWS']
writer.writerow(header)

i = 0
for x in result:
    categoryLine = []
    categoryLine.append(i)
    for y in header[1:]:
        if y == x:
            categoryLine.append(1)
        else:
            categoryLine.append(0)
    i = i + 1
    writer.writerow(categoryLine);
csvfile.close()