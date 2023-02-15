# web_crawler.py
# Ori P
# 15.2.23
#
# this script recives a path to a file containing a wordlist
# of common file names in websites and a URL of a website.
# Then ut checks if files with the same name exists in the given
# website.

# Imports
import requests
from urllib.parse import urljoin

def get_req(url):
    """Preforms a GET request to specific URL"""
    try:
        response = requests.get(url)
        print(response.url)

    except:
        pass

def main():
    wordlist_path = input('Enter wordlist for file names --> ').strip('"')
    website = input("Enter a website's URL --> ")
    with open(wordlist_path, 'r') as wordlist_file:
        wordlist = wordlist_file.read().splitlines()
    files_found = ()

    # Go over the wordlist and send GET requsets
    for name in wordlist:
        url = urljoin(website, f'/{name}')
        get_req(url)

if __name__ == "__main__":
    main()
