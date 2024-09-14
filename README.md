
<div class="container">
    <h1>Airline Management System</h1>
    <p>This is a simple Airline Management System implemented in C++. The system allows for managing flights, passengers, bookings, and cancellations.</p>

  <h2>Table of Contents</h2>
  <ul>
        <li><a href="#features">Features</a></li>
        <li><a href="#installation">Installation</a></li>
        <li><a href="#usage">Usage</a></li>
        <li><a href="#technologies">Technologies Used</a></li>
        <li><a href="#example">Example Code Execution</a></li>
    </ul>

  <h2 id="features">Features</h2>
  <ul>
        <li>Manage flight details (Add, view flights)</li>
        <li>Passenger registration and management</li>
        <li>Book flights for passengers</li>
        <li>Cancel bookings for passengers</li>
        <li>Display available flights</li>
    </ul>

  <h2 id="installation">Installation</h2>
    <p>To run the Airline Management System locally, follow the steps below:</p>
    <pre><code>1. Download or clone the repository.
2. Open a terminal and navigate to the project folder.
3. Compile the code using g++ (or another C++ compiler):
   g++ -o airline_management_system airline_management_system.cpp
4. Run the compiled program:
   ./airline_management_system
</code></pre>

  <h2 id="usage">Usage</h2>
    <p>Once the program is running, you will see a menu with options for managing flights and bookings. The available options are:</p>
    <ul>
        <li>1. Add Flight</li>
        <li>2. Add Passenger</li>
        <li>3. Display All Flights</li>
        <li>4. Book Flight for a Passenger</li>
        <li>5. Cancel Booking</li>
        <li>6. Exit</li>
    </ul>

  <h2 id="technologies">Technologies Used</h2>
    <ul>
        <li><strong>Programming Language:</strong> C++</li>
        <li><strong>Standard Libraries:</strong> iostream, string, etc.</li>
    </ul>

   <h2 id="example">Example Code Execution</h2>
    <p>Here is an example of how the system works:</p>
    <pre><code>Airline Management System Menu:
1. Add Flight
2. Add Passenger
3. Display All Flights
4. Book Flight
5. Cancel Booking
6. Exit
Enter your choice: 1

Enter Flight ID: 1001
Enter Flight Number: BA123
Enter Departure City: London
Enter Destination City: New York
Enter Available Seats: 150

Airline Management System Menu:
1. Add Flight
2. Add Passenger
3. Display All Flights
4. Book Flight
5. Cancel Booking
6. Exit
Enter your choice: 3

All Flights:
Flight ID: 1001, Flight Number: BA123, Departure City: London, Destination City: New York, Available Seats: 150
</code></pre>

  <p>More flights, passengers, bookings, and cancellations can be managed using the provided menu options.</p>
</div>
