import calendar
from datetime import datetime

def generate_calendar_text():
    now = datetime.now()
    current_year = now.year
    current_month = now.month

    cal = calendar.monthcalendar(current_year, current_month)
    month_name = datetime.strftime(now, "%B")
    calendar_text = []


    first_day_weekday = datetime(current_year, current_month, 1).weekday()
    for week in cal:
        week_str = ''
        for day in week:
            if day == 0:
                week_str += '   '  
            else:
                if len(week_str) > 0:
                    week_str += ' '  
                if len(week_str) < first_day_weekday * 3:
                    week_str += '00'  
                week_str += f"{day:2}"  
        calendar_text.append(week_str + '\n')

    return calendar_text

def save_calendar_to_file():
    calendar_text = generate_calendar_text()

    with open("data/calendar.txt", "w") as file:
        file.writelines(calendar_text)

    print("Calendar saved to calendar.txt")

save_calendar_to_file()
