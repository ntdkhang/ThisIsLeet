from datetime import date


def numOfDays(date1, date2):
  #check which date is greater to avoid days output in -ve number
    if date2 > date1:
        return (date2-date1).days
    else:
        return (date1-date2).days


# Driver program
date2 = date(2018, 12, 13)
date1 = date(2015, 2, 25)
print((date1-date2).days)
# print(numOfDays(date1, date2), "days")
