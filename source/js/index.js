function setValidationLinks() {
  const loc = document.location.href;
  const HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
  const CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
                           loc + '?profile=css3';
  document.getElementById("baseHref").setAttribute("href", loc);
  document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
  document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);
}

function toggleContent() {
  const article = document.getElementById("main_article")
  const nav = document.getElementById("main_nav")
  article.className = article.className === "desktop" ?
    "mobile" : "desktop";
  nav.className = article.className === "desktop" ?
    "mobile" : "desktop";
}
