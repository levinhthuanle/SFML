import calendar
from datetime import datetime

def generate_calendar_text():
    # Get current year and month
    now = datetime.now()
    current_year = now.year
    current_month = now.month

    # Create a calendar for the current month and year
    cal = calendar.monthcalendar(current_year, current_month)

    # Get the name of the month
    month_name = datetime.strftime(now, "%B")

    # Prepare the calendar text
    calendar_text = []

    # Find the weekday index of the 1st day of the month (0 = Monday, 6 = Sunday)
    first_day_weekday = datetime(current_year, current_month, 1).weekday()

    # Generate each week's data
    for week in cal:
        week_str = ''
        for day in week:
            if day == 0:
                week_str += '   '  # Print empty space for days outside the month
            else:
                if len(week_str) > 0:
                    week_str += ' '  # Add space between days
                if len(week_str) < first_day_weekday * 3:
                    week_str += '00'  # Add '00' for days before the 1st day of the month
                week_str += f"{day:2}"  # Format day number with leading space
        calendar_text.append(week_str + '\n')

    return calendar_text

def save_calendar_to_file():
    # Generate calendar text
    calendar_text = generate_calendar_text()

    # Write calendar text to file
    with open("data/calendar.txt", "w") as file:
        file.writelines(calendar_text)

    print("Calendar saved to calendar.txt")

# Call the function to save the calendar to a file
save_calendar_to_file()
