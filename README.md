# Real-Time Weather App

## Description

A responsive web application that provides real-time weather updates based on the user's current location. It features animated weather icons, current temperature, and date/time display.

## Features

- Real-time weather updates
- Animated weather icons
- Temperature in Celsius and Fahrenheit
- Current date and time

## Installation

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/your-username/Real-Time-Weather-App.git
    ```

2. **Navigate to the Project Directory:**

    ```bash
    cd Real-Time-Weather-App
    ```

3. **Install Dependencies:**

    ```bash
    npm install
    ```

4. **Add API Keys:**

    Create `src/apiKeys.js` with your API key:

    ```javascript
    const apiKeys = {
      base: "https://api.openweathermap.org/data/2.5/",
      key: "YOUR_API_KEY_HERE",
    };

    export default apiKeys;
    ```

5. **Run the Application:**

    ```bash
    npm start
    ```

    Visit `http://localhost:3000` in your browser.

