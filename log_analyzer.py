entries = []

with open("sample.log", "r") as file:
    for line in file:
        # Remove leading/trailing whitespace and newline characters.
        line = line.strip();
        
        # Ignore empty lines.
        if not line:
            continue
            
        # Split into a maximum of four parts:
        # date, time, severity, and the remaining message.
        parts = line.split(" ", 3)
        
        # A valid log must contain all four fields
        if len(parts) != 4 :
            print ("Invalid log format. Skipping entry")
            continue
         # Unpack the parsed fields.
        date, time, severity, message = parts
        
        # Basic validation for YYYY-MM-DD date format.
        if len(date) != 10 or date[4] != '-' or date[7] != '-':
            print("Invalid date format. Skipping entry")
            continue
        
        # Represent one valid log entry as a dictionary.        
        entry = { "date" : date, "time" : time, "severity" : severity, "message" : message }
        
        # Store the valid entry in our collection.
        entries.append(entry)
        # Display all successfully parsed log entries.
print(entries)
