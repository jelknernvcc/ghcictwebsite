async function loadCalendarHTML(semester='') {
  try {
      var calFileName ="calendar.html"; 
      if(semester!=''){
        calFileName = "calendar_"+semester+".html"; 
      }
      const response = await fetch("../../../resources/calendars2/"+calFileName);
      const html = await response.text();
      document.getElementById('cal').innerHTML = html;
  } catch (error) {
      console.error('Error loading HTML file:', error);
  }
}

async function loadDayDescriptions(semester='') {
  try {
        var datesFileName ="school_dates.json"; 
        if(semester!=''){
            datesFileName = "school_dates_"+semester+".json"; 
        }
      const response = await fetch("../../../resources/calendars2/"+datesFileName);
      const data = await response.json();
      data.forEach(dateEntry => {
          const dateElement = document.getElementById(dateEntry.date);
          if (dateElement) {
              if (!(dateEntry.day == "A" || dateEntry.day == "B")) {
                  dateElement.appendChild(document.createElement('br'));
              }
              dateElement.append(dateEntry.day);
          }
      });
  } catch (error) {
      console.error('Error loading day descriptions:', error);
  }
}

async function loadSessionTopics(sessionJsonUrl, dateJsonUrl) {
  console.log('starting load session topics');
  try {
      const [sessionData, dateData] = await Promise.all([
          fetch(sessionJsonUrl).then(response => response.json()),
          fetch(dateJsonUrl).then(response => response.json())
      ]);

      dateData.forEach(dateEntry => {
          const dateElement = document.getElementById(dateEntry.date);
          if (dateElement) {
              const sessionInfo = sessionData.find(session => session.session === dateEntry.session);
              if (sessionInfo) {
                  dateElement.classList.add(`unit${sessionInfo.unit}`);

                  // Create HTML elements
                  const day = document.createElement('p');
                  const br1 = document.createElement('br');
                  const a = document.createElement('a');
                  a.href = `../goals/session.html?num=${sessionInfo.session.replace(/ /g, "_").toLowerCase()}`;
                  a.textContent = `Session ${sessionInfo.session}`;

                  const br2 = document.createElement('br');
                  const p = document.createElement('p');
                  day.textContent = `${dateEntry.day}`;
                  p.className = 'topic';
                  p.textContent = sessionInfo.topic;

                  // Append the elements to dateElement
                  dateElement.appendChild(br1);
                  if (!Number.isNaN(Number(sessionInfo.session)) || sessionInfo.session == "HTML Pretest") {
                      dateElement.appendChild(a);
                  } else {
                      dateElement.append(sessionInfo.session);
                  }
                  dateElement.appendChild(br2);
                  dateElement.appendChild(p);
              }
          }
      });
  } catch (error) {
      console.error('Error fetching session or date data:', error);
  }
  console.log('done load session topics');
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
  }
}

async function setUp(semester="") {
  console.log("setUp called");

  await loadCalendarHTML(semester);
  await loadDayDescriptions(semester);
  await loadSessionTopics("../goals/session_topics.json", "../goals/session_dates.json");

  var loc = window.location.href;
  var HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
  var CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
      loc + '?profile=css3';
  document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
  document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);

  // Call the HTML validator API and add the result to the footer
  try {
      const response = await fetch("https://html5.validator.nu/?out=json&doc=" + encodeURIComponent(loc));
      const data = await response.json();
      if (data.messages.length === 0) {
          console.log("No Errors");
          document.getElementById("HTMLCSS").innerHTML = "<strong> HTML/CSS </strong> Valid!";
      } else {
          console.log("Errors");
          console.log(data.messages);
          document.getElementById("HTMLCSS").innerHTML = "<strong> HTML/CSS </strong> NOT Valid!";
      }
  } catch (error) {
      console.warn(error);
  }

  // Small delay for sequential DOM updates
  await new Promise(resolve => setTimeout(resolve, 100));

  for (let i = 0; i < 12; i++) {
      addChapterDays(i);
  }

  await new Promise(resolve => setTimeout(resolve, 100));

  const examDays = document.getElementsByClassName("unitother_school");
  for (let i = 0; i < examDays.length; i++) {
      addElement(examDays[i], "span", "Other");
  }

  await new Promise(resolve => setTimeout(resolve, 100));

  const noSchoolDays = document.getElementsByClassName("unitother_noschool");
  for (let i = 0; i < noSchoolDays.length; i++) {
      addElement(noSchoolDays[i], "span", "No School");
  }
}
