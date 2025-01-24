1. Find the folder: `source/resources/calendars2/course_templates`, and copy the entire contents of that folder to your course. The rest of these instructions refer to this new copied folder.
2. Add a link to the course homepage to `calendar\index.html` 
3. Update the course name in `calendar\index.html` and `goals/session.html`
4. Update the `semester` javascript variable in `calendar\index.html`
5. Update JSON files:
    - The calendar data is spread across three separate JSON files. These three files are all JOINed together to produce the calendar. The important concept behind this design is numbered course **sessions**: the first time a class meets is called 'session 1', etc. Then the sessions are mapped to dates. This is useful for classes that have multiple sections that meet on different dates (eg. Session 1 occurs on August 27 for the A day class and August 28 for the B day class. It's the same lesson plan that should show up both days on the calendar )
    - `goals/session_topics.json` has a list of class sessions. Each session has an id (usually a number), title, and a unit.
    - `goals/session_dates.json` maps the session to a date.
    - `source/calendars2/school_dates.json` contains the APS calendar with A/B days and holidays. This exists once and is shared across all courses. It should only need updating once/year.
6. In the `goals` folder, create one Markdown file per session. The name of the file should be `sessionXX.md`, where `XX` matches the session id from `goals/session_topics.json`. Eg for session 01, the file should be called `goals/session01.md`.

----
Summary:
- Students should start at `calendar/index.html`. The init.js file on that page first loads the `school_dates.json` file to construct the calendar, and then loads both `sesson_topics.json` and `session_dates.json`, JOINs them together, and adds links to each session the appropriate date.
- Each session links to the same page, which uses a URL parameter to specify the session id. Eg `goals/session.html?num=01` is the page for session 01.
- `goals/session.html` has its own `init.js` file that reads the URL parameter, fetches the appropriate md file, converts the md to html (using Showdown.js, see the function `md_to_html`, adds a header, and displays)



----
TODO:
- `goals/js/init.js` is currently in the `course_template` folder, which means that each course has its own copy. There is no course-specific information in this script, so it can probably be shared.
- The code that calls to the HTML validator API is copy/pasted across a bunch of different `init.js` files, and is outdated. This should be refactored to its own js file that is linked everywhere.
    - The latest version of that code is here: https://github.com/CJonesExample/CJonesExample.github.io/blob/main/js/init.js 