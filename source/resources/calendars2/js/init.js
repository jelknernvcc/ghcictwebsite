function loadCalendarHTML() {
    fetch("../../../resources/calendars2/calendar.html")
      .then(response => response.text())
      .then(html => {
        // Insert the HTML into a specific element on the page
        document.getElementById('cal').innerHTML = html; 
      })
      .catch(error => {
        console.error('Error loading HTML file:', error);
      });
}
  function addElement(parentElem, childTag, childText) { 
     const childElem = document.createElement(childTag);
     const textNode = document.createTextNode(childText);
     childElem.appendChild(textNode);
     parentElem.appendChild(childElem);
  }
  
  function addChapterDays(dayNum) {
      const className = "unit" + dayNum.toString();
      const label = "Unit " + dayNum.toString(); 
      const chapterDays = document.getElementsByClassName(className);
      for (let i = 0; i < chapterDays.length; i++) {
        const s = document.createElement('span');
        s.textContent = label;
        chapterDays[i].appendChild(s);
        //addElement(chapterDays[i], "span", label);
      }
  }

  function loadDayDescriptions(){
    fetch("../../../resources/calendars2/school_dates.json")
    .then(response => response.json())
    .then(data =>{
      data.forEach(dateEntry =>{
        const dateElement = document.getElementById(dateEntry.date);
            if (dateElement) {
              if(!(dateEntry.day=="A" || dateEntry.day=="B")){
                dateElement.appendChild(document.createElement('br'));
              }
              dateElement.append(dateEntry.day);
            }
      })
    })
  }
  
  function loadSessionTopics(sessionJsonUrl, dateJsonUrl) {
    console.log('starting load session topics');
  
    // Fetch both the session data and the date mapping data
    Promise.all([
        fetch(sessionJsonUrl).then(response => response.json()),
        fetch(dateJsonUrl).then(response => response.json())
    ])
    .then(([sessionData, dateData]) => {
        // Process the date-to-session mapping first
        dateData.forEach(dateEntry => {
            const dateElement = document.getElementById(dateEntry.date);
            if (dateElement) {
                // Find the corresponding session details from the sessionData
                const sessionInfo = sessionData.find(session => session.session === dateEntry.session);
                if (sessionInfo) {
                    // Build the HTML content for the session
                    dateElement.classList.add(`unit${sessionInfo.unit}`);
                    
                    // Create HTML elements
                    const day = document.createElement('p');
                    const br1 = document.createElement('br');
                    const a = document.createElement('a');
                    a.href = `../goals/session.html?num=${sessionInfo.session.replace(/ /g,"_").toLowerCase()}`;
                    a.textContent = `Session ${sessionInfo.session}`;
                    
                    const br2 = document.createElement('br');
                    const p = document.createElement('p');
                    day.textContent = `${dateEntry.day}`;
                    p.className = 'topic';
                    p.textContent = sessionInfo.topic;
  
                    // Append the elements to dateElement
                    //dateElement.append(`${dateEntry.day}`);
                    dateElement.appendChild(br1);
                    if(!Number.isNaN(Number(sessionInfo.session)) || sessionInfo.session == "HTML Pretest"){
                      dateElement.appendChild(a);
                    }else{
                      dateElement.append(sessionInfo.session)
                    }
                    dateElement.appendChild(br2);
                    dateElement.appendChild(p);
                }//else{
                //  dateElement.append(sessionInfo.session);
                //}
            }
        });
    })
    .catch(error => console.error('Error fetching session or date data:', error));
  
    console.log('done load session topics');
  }
  
  
  
  async function setUp() {
    console.log("setUp called");
  
    loadCalendarHTML();

    await loadDayDescriptions();
    
    await loadSessionTopics("../goals/session_topics.json", "../goals/session_dates.json");
    
    var loc = window.location.href;
    var HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
    var CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
                          loc + '?profile=css3';
    document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
    document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);
    
    // Call the HTML validator API and add the result to the footer
    fetch("https://html5.validator.nu/?out=json&doc=" + encodeURIComponent(loc), {
        method: "GET"
    })
    .then(response => response.json())
    .then(data => {
        if (data.messages.length === 0) {
            console.log("No Errors");
            document.getElementById("HTMLCSS").innerHTML = "<strong> HTML/CSS </strong> Valid!";
        } else {
            console.log("Errors");
            console.log(data.messages); // data.messages is an array
            document.getElementById("HTMLCSS").innerHTML = "<strong> HTML/CSS </strong> NOT Valid!";
        }
    })
    .catch(error => {
        console.warn(error);
    });
  
  
    /*this is weird. loadSessionTopics and addChapterDays both use appendChild
    I confirmed that loadSessionTopics completes before addChapterDays starts,
    (I added await, and used console.log to confirm)
    but the elements were still appearing out of order. For some reason adding a little
    timeout fixed it...
    */
    setTimeout(() => {
      for (let i = 0; i < 12; i++) {
        addChapterDays(i);
      }
    }, 100);  // Small delay
  
    setTimeout(() => {
    const examDays = document.getElementsByClassName("unitother_school");
    for (let i = 0; i < examDays.length; i++) {
      addElement(examDays[i], "span", "Other");
    }},100);
  
    setTimeout(() => {
      const examDays = document.getElementsByClassName("unitother_noschool");
      for (let i = 0; i < examDays.length; i++) {
        addElement(examDays[i], "span", "No School");
      }},100);
  
  
  
  }
  