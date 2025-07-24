#include <iostream>
#include "include/Parser.h"


using namespace std;


int main (int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Wrong Arguments : ./server <conf_file>\n";
        return (1);
    }


    Parser parser (argv[1]);

    Server *s = parser.Parse();


    if (s == NULL)
    {
        std::cerr << "error parsing Config File\n";
        exit(1);
    }
    else
    {
        cout << "file found"  << endl;
    }


    cout << "host: " << s->listening.ip_addr << "#" << endl;
    cout << "Port: " << s->listening.Port << "#" <<  endl;



    for (size_t i = 0; i < s->error.v_error.size(); i++)
    {
        cout << s->error.v_error[i].err_number << "," << s->error.v_error[i].html_path << "#" << endl;
    }

    cout << "body max size: " << s->max_body_size<< "#" << endl; cout << "cgi pass  : " <<   s->cgi_bin.cgi_pass  << endl;

    /*cout << "upload store : " <<   s->location_upload.upload_store  << endl;

    
   
     cout << "cgi root  : " <<   s->cgi_bin.root  << endl;

     cout << "cgi methdods\n\n";


     for (int i = 0; i < (int)s->cgi_bin.methods.size(); i++)
     {
        cout << s->cgi_bin.methods[i] << endl;
     }
     */
    

    if (s)
    {
        delete s;
        return (1);
    }
    
    (void)argc;
    (void)argv;
    return (0);
}