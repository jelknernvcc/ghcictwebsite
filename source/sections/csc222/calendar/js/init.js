function addElement(parentElem, childTag, childText) { 
   const childElem = document.createElement(childTag);
   const textNode = document.createTextNode(childText);
   childElem.appendChild(textNode);
   parentElem.appendChild(childElem);
}

function addChapterDays(dayNum) {
    const className = "chap" + dayNum.toString();
    const label = "Chapter " + dayNum.toString(); 
    const chapterDays = document.getElementsByClassName(className);
    console.log(chapterDays);
    for (let i = 0; i < chapterDays.length; i++) {
      addElement(chapterDays[i], "span", label);
    }
}

function setUp() {
  console.log("setUp called");
  var loc = window.location.href;
  var HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
  var CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
                        loc + '?profile=css3';
  document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
  document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);

  for (let i = 1; i < 18; i++) {
    addChapterDays(i);
    console.log("addChapterDays(" + i + " called");
  }

  const reviewDays = document.getElementsByClassName("review");
  for (let i = 0; i < reviewDays.length; i++) {
    addElement(reviewDays[i], "span", "Review");
  }

  const examDays = document.getElementsByClassName("exam");
  for (let i = 0; i < examDays.length; i++) {
    addElement(examDays[i], "span", "EXAM");
  }

  const projectDays = document.getElementsByClassName("project");
  for (let i = 0; i < projectDays.length; i++) {
    addElement(projectDays[i], "span", "Project");
  }
}
