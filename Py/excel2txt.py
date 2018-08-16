import xlrd

def trim(s):
    if s[:1] != ' ' and s[-1:] != ' ':
        return s
    elif s[:1] == ' ':
        return trim(s[1:])
    else:
        return trim(s[:-1])


n = 0
ans = 0
excel_file = xlrd.open_workbook(r'e:\exception_trade.xls')
sheet = excel_file.sheet_by_index(0)
for i in range(1,314):
    n = n + 1
    ans = ans + float(trim(sheet.cell(i,2).value))
    print(str(n).zfill(6) + '|' + trim(sheet.cell(i,0).value) + '|' + trim(sheet.cell(i,1).value) + '|' + trim(sheet.cell(i,2).value) + '|0.00|财付通退款|')
print(str(n) + '|' + str(ans) + '|')