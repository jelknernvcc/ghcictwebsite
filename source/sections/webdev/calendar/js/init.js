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

function loadSessionTopics(jsonUrl) {
  console.log('starting load session topics');
  fetch(jsonUrl)
      .then(response => response.json())
      .then(data => {
          data.forEach(session => {
              // Find the list item corresponding to the session number
              const listItemA = document.getElementById(`session-${session.session}A`);
              if (listItemA) {
                  //the goal is to build something that looks like this: 
                  //<td class="end unit1" id="session-1A">27 A</br>
                    //<a href="../goals/session.html?num=01">Session 1</a></br>
                    //<p class="topic">Orientation and Syllabus Review</p>
                  //</td>
                  //so I'll populate the id and date, and then this function should insert the entire hyperlink and <p> tag
                  //const htmlToAdd = `</br><a href="../goals/session.html?num=${session.session}">Session ${session.session}</a></br><p class="topic">${session.topic}</p>`;
                  //console.log(htmlToAdd);
                  //listItemA.innerHTML+=htmlToAdd;
                  listItemA.classList.add(`unit${session.unit}`)
                  const br1 = document.createElement('br');
                  const a = document.createElement('a');
                  a.href = `../goals/session.html?num=${session.session}`;
                  a.textContent = `Session ${session.session}`;
                  const br2 = document.createElement('br');
                  const p = document.createElement('p');
                  p.className = 'topic';
                  p.textContent = session.topic;

                  // Append the elements to listItemA
                  listItemA.appendChild(br1);
                  listItemA.appendChild(a);
                  listItemA.appendChild(br2);
                  listItemA.appendChild(p);
              };
              const listItemB = document.getElementById(`session-${session.session}B`);
              if (listItemB) {
                listItemB.classList.add(`unit${session.unit}`)  
                const br1 = document.createElement('br');
                  const a = document.createElement('a');
                  a.href = `../goals/session.html?num=${session.session}`;
                  a.textContent = `Session ${session.session}`;
                  const br2 = document.createElement('br');
                  const p = document.createElement('p');
                  p.className = 'topic';
                  p.textContent = session.topic;

                  // Append the elements to listItemA
                  listItemB.appendChild(br1);
                  listItemB.appendChild(a);
                  listItemB.appendChild(br2);
                  listItemB.appendChild(p);
              }
          });
      })
      .catch(error => console.error('Error fetching session topics:', error));
      console.log('done load session topics');
}

async function setUp() {
  console.log("setUp called");
  
  await loadSessionTopics("../goals/session_topics.json");
  
  
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
  const examDays = document.getElementsByClassName("unitexam");
  for (let i = 0; i < examDays.length; i++) {
    addElement(examDays[i], "span", "EXAM");
  }},100);



}
