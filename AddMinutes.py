def parseTimeString(timeString: str):
    """Parses the time string into hour, minute, and the period of the day
    
    Args:
        timeString: a string representing the time in the 12-hour format "[H]H:MM {AM|PM}"

    Returns:
        a tuple of three integers (hour, minute, noon) 
          where hour is from 0 to 11, minute is from 0 to 59 
          and noon is either 0 or 1 for AM or PM respectively
    """
    hour = int(timeString.split(":")[0])
    if hour == 12:
        hour = 0

    minuteAndNoon = timeString.split(":")[1]
    minute = int(minuteAndNoon.split(" ")[0])
    if minuteAndNoon.split(" ")[1] == "AM":
        noon = 0
    else:
        noon = 1
    return (hour, minute, noon)


def formatTimeToString(hour: int, minute: int, noon: int):
    """Generates a formatted time string

    Args:
        hour: the hour in integer using the 12-hour format
        minute: the minute in integer
        noon: an integer represent which portion of the day is it. 
          0 for AM and 1 for PM 

    Returns:
        A string to represent the time in the 12-hour format "[H]H:MM {AM|PM}"
    """
    if hour == 0:
        hour = 12

    if minute < 10:
        minuteString = "0" + str(minute)
    else:
        minuteString = str(minute)

    if noon == 0:
        noonString = "AM"
    else:
        noonString = "PM"

    return str(hour) + ":" + minuteString + " " + noonString


def AddMinutes(timeString: str, minutesToAdd: int):
    """Adds to the time an integer of minutes. If the integer is negative, 
         then the clock will be rolled backward

    Args:
        timeString: a string representing the time in the 12-hour format "[H]H:MM {AM|PM}"
        minutesToAdd: an integer of the number of minutes to add to the time

    Returns:
        A string to represent the new time in the 12-hour format "[H]H:MM {AM|PM}"
    """
    hour, minute, noon = parseTimeString(timeString)

    minute += minutesToAdd % 60
    if minute >= 60:
        minute = minute % 60
        hour += 1

    hoursToAdd = minutesToAdd // 60
    hour += (hoursToAdd % 12)

    if hour >= 12:
        hour = hour % 12
        noon += 1
    
    noon += hoursToAdd // 12
    noon = noon % 2
    return formatTimeToString(hour, minute, noon)

print(AddMinutes("9:13 AM", 1000))  # 1000 mins = 16 hours + 40 minutes 
print(AddMinutes("1:15 AM", -125))  # 125 mins = 2 hours + 5 minutes
print(AddMinutes("4:20 PM", 1440))  # 1440 mins = 24 hours
print(AddMinutes("5:48 AM", -1440))  # 1440 mins = 24 hours
print(AddMinutes("4:20 AM", 2269))  # 2269 mins = 1 day 13 hours 49 minutes
