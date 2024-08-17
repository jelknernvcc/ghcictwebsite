function addElement(parentElem, childTag, childText) { 
   const childElem = document.createElement(childTag);
   const textNode = document.createTextNode(childText);
   childElem.appendChild(textNode);
   parentElem.appendChild(childElem);
}

function init() {
  var loc = window.location.href;
  var HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
  var CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
                        loc + '?profile=css3';
  document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
  document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);

  const altairDays = document.getElementsByClassName("altair8800");
  for (let i = 0; i < altairDays.length; i++) {
    addElement(altairDays[i], "span", "Altair 8800");
  }

  const assemblyDays = document.getElementsByClassName("assembly");
  for (let i = 0; i < assemblyDays.length; i++) {
    addElement(assemblyDays[i], "span", "Assembly");
  }

  const cpmDays = document.getElementsByClassName("cpm");
  for (let i = 0; i < cpmDays.length; i++) {
    addElement(cpmDays[i], "span", "CP/M");
  }

  const cDays = document.getElementsByClassName("c");
  for (let i = 0; i < cDays.length; i++) {
    addElement(cDays[i], "span", "C");
  }
}
