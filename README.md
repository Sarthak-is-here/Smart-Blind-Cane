# Smart Walking Stick with GPS Location (Way Finder)

## What Is This?

It is a smart walking stick that assists persons who are blind or have poor eyesight. It assists in three easy ways:

- It senses obstacles ahead of the user.  
- It beeps to alert the user if an object is too near.  
- It provides the location of the user as a text message when a button is clicked.

---

## How Is It Powered?

Rechargeable batteries are used by the project:

- Two batteries power the main controller (Arduino).  
- A battery powers the portion that sends the text message (GSM module).  
- The GPS is powered directly off the main board.

---

## What Parts Are Used?

| Part              | Purpose                                 |
|-------------------|------------------------------------------|
| Arduino Uno       | The main controller that executes the program |
| Ultrasonic Sensor | Detects an object's proximity            |
| Buzzer            | Beeps when an object is too close        |
| GPS Module        | Finds the user's location                |
| GSM Module        | Sends the location as a text message (SMS) |
| Push Button       | Sends the SMS when pressed               |

---

## Other Small Components

| Part       | Why It's Needed                               |
|------------|-----------------------------------------------|
| Transistor | Ensures the buzzer is turned on and off safely |
| Resistors  | Regulate electricity flow                      |
| Diodes     | Prevent damage to the circuit                  |
| Capacitors | Ensure stable power to the GSM portion         |
| Wires      | Bridges everything together                    |

---

## How It Works

- The stick "looks ahead" with distance-measuring sensors.  
- If there's something near, it emits a beep to let the user know.  
- If the user requires assistance, they push a button on the stick.  
- The GPS determines their location.  
- The GSM module transmits that location as a text message to a caregiver or family member.

---

## Why It's Helpful

- Prevents individuals from walking into objects.  
- Transmits location in the event of an emergency.  
- Functions without internet or Wi-Fi—only requires cellular signal.  
- Is small, battery-operated, and portable.

---

## Summary

This intelligent stick provides greater safety and autonomy to visually impaired individuals. It is easy to use and can assist in actual conditions where an individual might require assistance or navigation support.

---

## Contributors

This project was designed and developed by:

- **Sarthak Tiwari** – Responsible for design, coding, and testing.  
- **Naman Singh** – Assisted with hardware setup.

**Class - 10th D , New Beersheba Public School , Pithoragarh**
**25 July , 2025**
