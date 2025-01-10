When talking about Google Search Engine, what words come to your mind? Page Ranking? Inverted Indexing? Web Crawler?

When developing a search engine, the first question we want to ask is, where to start? When you type "Selena Gomez" or "Tom Brady" in the search box in Google, where does Google start? Does Google start searching from one specific website? The answer is Google does not start from one specific website, rather they maintain a list of URLs which are called Seed URLs. These Seed URLs are manually chosen which represent a diverse range of high-quality, reputable websites. Search engines usually have a component called web crawler, which crawls these URLs and then follow links from these web pages to other web pages. As the web crawler crawls these other web pages, it collects links from these other web pages to more web pages, and then follow these links to crawl more web pages. This process continues, ultimately, the goal is to discover as many web pages as possible. Once all pages are visited, the search engine will build a map, which is known as the inverted index, which maps terms (i.e., individual words) to web pages (also known as documents). Below is an example:

| Key (Term) | Value (List of Document References)      |
|-----------|---------------------------------------|
| apple     | Document1, Document3, Document5       |
| banana    | Document2, Document4                   |
| orange    | Document1, Document2                   |



//Implimentation 

There are three steps when implimenting a search engine:
    1. Web crawling
    2. Query searching
    3. Page ranking

---- WEB CRAWLING ----

The web crawlers goal is to build the inverted map index

---- QUERY SEARCHING ----

The Query Searching component's goal is to identify the matching documents.

---- PAGE RANKING ----

    - When the documents are identified, I need to rank them and present to a user, we are to rank by:
        * Keywords Density
        * Backlinks

    - Calculate a page score and present these in decending order to the users. 
        * Claculate the score for each of two factors, name them :
            - keywords density score
            - backlinks score
    - Using the two scores we get the page score using the folllowing formula:
        * page score = (0.5 * keywords density score + 0.5 * backlinks score); [formula 1]

        ***** All the scores should be defined as double 

    HOW TO CALCUALTE THE KEYWORDS DENSITY SCORE:

            1. Calculate a density score for each keyword within the document
                - for each keyword, the density score is mesured on the frequency in a document compares to its occurrence in all documents. Use the following formula to calcualte the density score of one keywoord. 
                (all documents means all documents not just the document which contain the query)

                Keyword Density Score = (Number of Times Keyword Appears) / (Total Content Length of this One Document * Keyword Density Across All Documents)

                            /*
                            Also, here "Total Content Length" means the total length of the whole document, not just the length of the <body> section; and the "Number of Times Keyword Appears" means the number of times the keyword appears in the whole document, not just in the <body> section. Similarly, when calculating the "Keyword Density Across All Documents", you should also consider the whole document, not just the <body> section.


                            */

            2. Accumlate these individual density scores into a combined score.


MAIN ASSIGNMENT SCOPE:

1. search HTML files only
2. Local searching only

