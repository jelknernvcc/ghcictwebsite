function init() {
  var loc = window.location.href;
  var HTMLvalidLinkStr = 'https://validator.w3.org/check?uri=' + loc;
  var CSSvalidLinkStr = 'https://jigsaw.w3.org/css-validator/validator?uri=' +
                         loc + '?profile=css3';
  document.getElementById("vLink1").setAttribute("href", HTMLvalidLinkStr);
  document.getElementById("vLink2").setAttribute("href", CSSvalidLinkStr);

  var conv = new showdown.Converter();
  var md_txt = document.getElementById('md_content').textContent;
  console.log(md_txt);
  var md_html = conv.makeHtml(md_txt);
  console.log(md_html);
  document.getElementById('md_to_html').innerHTML = md_html;
  
}

function md_to_html(file){
  fetch(file)
  //.then(res => response.)
  .then(response => {
    if (!response.ok) {
      // If the file is not found (status 404), throw an error
      throw new Error('File not found');
    }
    return response.text();
  })
  .then(mdContent => {
  var conv = new showdown.Converter();
  var md_html = conv.makeHtml(mdContent);
  document.getElementById('md_to_html').innerHTML = md_html;
  })
  .catch(error => {
    document.getElementById('md_to_html').innerHTML = 'Hi - you\'re faster than I am! I have not published this lesson plan yet. Please check back later!';
  });
}
