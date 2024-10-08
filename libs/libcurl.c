#include <stdio.h>
#include <curl/curl.h>

/* Simple demonstration using libcurl for network requests */

/* write_callback: handle incoming data from the server 
 * void *ptr: a pointer to the data received from the server
 * size: the size of each data element. (1 byte)
 * nmemb: the number of data elements.
 * *userdata: user-defined pointer, which can be used to pass additional
 * data to the callback (a file pointer if writing to a file...)
 */
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main() {
    /* handle for libcurl session, storing opt and state*/
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();

    if(curl) {
        /* set options and configure the libcurl session */
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        /* curl_easy_perform: performs the HTTP GET request */
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perfrom() failed: %s\n", curl_easy_strerror(res));
        }
        else {
            printf("data fetched successfully!\n");
        }

        /* freeing resources used by libcurl */
        curl_easy_cleanup(curl);
    }
    else {
        fprintf(stderr, "failed to init libcurl\n");
    }
    
    return 0;
}
