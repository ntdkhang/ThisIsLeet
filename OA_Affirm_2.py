from datetime import date


def compute_interest_rate(loan_amount, loan_start_date, loan_end_date, total_interest_amount):
    def parse_date(date_str):
        month, day, year = date_str.split("/")
        return date(int(year), int(month), int(day))

    if loan_amount <= 0 or total_interest_amount <= 0:
        return -1

    start_date = parse_date(loan_start_date)
    end_date = parse_date(loan_end_date)

    total_days = (end_date - start_date).days
    if total_days < 0:
        return -1

    interest_rate = (total_interest_amount / (loan_amount * (total_days / 365)))

    interest_rate = round(interest_rate, 2)

    return interest_rate

# Example usage:
principal_amount = 6700  # $67.00
loan_start_date = "03/05/22"
loan_end_date = "07/10/22"
total_interest_amount = 450  # $4.50

interest_rate = compute_interest_rate(principal_amount, loan_start_date, loan_end_date, total_interest_amount)
print(f"Interest Rate: {interest_rate}%")

