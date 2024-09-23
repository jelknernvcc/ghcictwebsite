function getNextTargetTime() {
    const now = new Date();
    const currentDate = now.toDateString(); // Get current date as a string
  
    // Define the target times for today
    const targetTimes = [
      new Date(`${currentDate} 09:24:00`),
      new Date(`${currentDate} 09:59:00`),
      new Date(`${currentDate} 11:32:00`),
      new Date(`${currentDate} 12:55:00`)
    ];
  
    // Find the first target time that is in the future
    let nextTarget = targetTimes.find(time => time > now);
  
    // If all target times have passed, set the countdown for the first target time tomorrow
    if (!nextTarget) {
      nextTarget = new Date(targetTimes[0].getTime() + 24 * 60 * 60 * 1000);
    }
  
    return nextTarget;
  }
  
  function updateCountdown() {
    const now = new Date();
    const targetTime = getNextTargetTime();
  
    // Calculate the time difference in milliseconds
    const timeDifference = targetTime - now;
  
    // If the target time has passed, stop the countdown
    if (timeDifference < 0) {
      document.getElementById('countdown').innerHTML = "Time's up!";
      return;
    }
  
    // Calculate total minutes and seconds
    const minutes = Math.floor(timeDifference / (1000 * 60));
    const seconds = Math.floor((timeDifference % (1000 * 60)) / 1000);
  
    // Display the countdown in the div
    document.getElementById('countdown').innerHTML =
      `Time until bell: ${minutes}m ${seconds}s`;
  
    // Update the countdown every second
    setTimeout(updateCountdown, 1000);
  }
  
  // Start the countdown when the page loads
  updateCountdown();
  