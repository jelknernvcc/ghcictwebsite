function addElement(parentElem, childTag, childText) { 
   const childElem = document.createElement(childTag);
   const textNode = document.createTextNode(childText);
   childElem.appendChild(textNode);
   parentElem.appendChild(childElem);
}

function addLessonDays(dayNum) {
    const className = "lesson" + dayNum.toString();
    const label = "Lesson " + dayNum.toString(); 
    const lessonDays = document.getElementsByClassName(className);
    for (let i = 0; i < lessonDays.length; i++) {
      addElement(lessonDays[i], "span", label);
    }
}

function init() {
  var loc = window.location.href;
  var HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
  var CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
                        loc + '?profile=css3';
  document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
  document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);

  const prelimDays = document.getElementsByClassName("preliminaries");
  for (let i = 0; i < prelimDays.length; i++) {
    addElement(prelimDays[i], "span", "Preliminaries");
  }

  for (let i = 1; i < 11; i++) {
    addLessonDays(i);
  }

  const reviewDays = document.getElementsByClassName("review");
  for (let i = 0; i < reviewDays.length; i++) {
    addElement(reviewDays[i], "span", "Review");
  }

  const examDays = document.getElementsByClassName("exam");
  for (let i = 0; i < examDays.length; i++) {
    addElement(examDays[i], "span", "EXAM");
  }
}
