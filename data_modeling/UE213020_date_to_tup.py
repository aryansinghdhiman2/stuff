year = 2000
month_dict:dict[str,int] = {
    'JAN' : 1,
    'FEB' : 2,
    'MAR' : 3,
    'APR' : 4,
    'MAY' : 5,
    'JUN' : 6,
    'JUL' : 7,
    'AUG' : 8,
    'SEP' : 9,
    'OCT' : 10,
    'NOV' : 11,
    'DEC' : 12
}

inp = input("Enter DATE: ")

inp = inp.split('-')

inp[0] = int(inp[0])
inp[1] = month_dict[inp[1]]
inp[2] = 2000 + int(inp[2])

print(tuple(inp))