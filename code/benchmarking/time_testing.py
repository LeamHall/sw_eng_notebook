#!/usr/bin/env python

# name    :  time_testing.py
# version :  0.0.1
# date    :  20241115
# author  :
# desc    :

import asyncio
import concurrent.futures
from multiprocessing import Pool
import time
import urllib.request

urls = [
    "https://docs.python.org",
    "https://github.com",
    "https://google.com",
    "https://www.wunderground.com",
    "https://pytutorial.com",
    "https://indeed.com",
    "https://dice.com",
    "https://monster.com",
    "https://linkedin.com",
]


def get_status(page):
    try:
        with urllib.request.urlopen(page) as response:
            return response.status
    except urllib.error.HTTPError as e:
        return e.code


start_time = time.perf_counter()
for url in urls:
    print("Status: {}  URL: {}".format(get_status(url), url))
stop_time = time.perf_counter()
print("Straight through:  {:3f} time units".format(stop_time - start_time))


start_time = time.perf_counter()
with Pool(5) as p:
    print(p.map(get_status, urls))
stop_time = time.perf_counter()
print("Multiprocessing:   {:3f} time units".format(stop_time - start_time))


start_time = time.perf_counter()
with concurrent.futures.ThreadPoolExecutor(
    max_workers=len(urls)
) as executor:
    future_to_url = {
        executor.submit(get_status, url): url for url in urls
    }
    for future in concurrent.futures.as_completed(future_to_url):
        url = future_to_url[future]
        try:
            code = future.result()
        except Exception as e:
            print(e)
        else:
            print(code)
stop_time = time.perf_counter()
print("Concurrent Futures:   {:3f} time units".format(stop_time - start_time))


start_time = time.perf_counter()
async def async_call(method, urls):
    status_codes = []
    for url in urls:
        status_codes.append(await asyncio.to_thread(method, url))

    return status_codes

asyncio.run(async_call(get_status, urls))
stop_time = time.perf_counter()
print("Asyncio:   {:3f} time units".format(stop_time - start_time))
