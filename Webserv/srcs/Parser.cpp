#include "../include/Parser.h"


Parser::Parser(string s) : _configfilepath(s)
{
    cout << "parser constructor\n";
    cout << "config file path : " << _configfilepath << endl;
}

bool Parser::_isFileOpend ()
{
    
    ifstream File (_configfilepath.c_str());

    if (!File.is_open())
    {
        std::cerr << "Failed to open file : " 
            << _configfilepath << "\n";
        return (false);
    }

    return (true);
}

string Parser::_trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}


bool Parser::_ReadData()
{

    fstream file (_configfilepath.c_str());
        
    if (!file.is_open())
    {
        std::cerr << "Failed to open file : " 
            << _configfilepath << "\n";
        return (false);
    }

    string line;

    while (getline(file, line))
    {
        _conf_line.push_back(_trim(line));
    }

    // for (size_t i = 0 ; i < _conf_line.size() ; i++)
    // {
    //     cout << "line: " << _conf_line[i] << endl;
    // }
    return (true);
}


void Parser::v_clear()
{
    while (_conf_line.size( ) > 0)
    {
        _conf_line.pop_back();
    }
}


int _find_word( char * s, string word)
{
    if (*s == '\0' || s == NULL || word.empty())
        return (0);


    // cout << ":" << s << ":\n";
    // cout << ":" << word << ":\n";

    if (strncpy(s, word.c_str(), word.length() - 1))
    {
        return (word.length() - 1);
    }
    return (0);
}

std::vector<std::string> _split(const std::string& str, char delimiter)
 {
    std::vector<std::string> result;
    std::string temp;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == delimiter){
            if (!temp.empty())
                result.push_back(temp);
            temp.clear();
        } else {
            temp += str[i];
        }
    }
    if (!temp.empty())
        result.push_back(temp);
    return result;
}

string Parser::_string_ToUpper(string s)
{
    for (size_t i = 0 ; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return (s);
}

bool Parser::IsLocationExtracted(string Line, Server *srv)
{
    string tmp;
  
    vector <string> v_location = _split(Line, ';');
    vector <string> v_tmp;


    for (size_t  i= 0; i < v_location.size(); i++)
    {
        if (v_location[i].find ("root") != string::npos)
        {
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);
            srv->location.root = v_tmp[1];
        }
        else if (v_location[i].find ("autoindex") != string::npos)
        {
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);

            v_tmp[1] = _string_ToUpper(v_tmp[1]);
            if (v_tmp[1] == "ON")
                srv->location.autoindex = true;
            else if (v_tmp[1] == "OFF")
            {
                srv->location.autoindex = false;
            }
            else 
            {
                cout << "error parsing auto index\n";
                return (false);
            }
        }
        else if (v_location[i].find ("index") != string::npos)
        {

            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);
            srv->location.index =  v_tmp[1];
        }
        else if (v_location[i].find ("methods") != string::npos)
        {

            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() <= 1)
                return (false);
            
            for (size_t i = 0; i < v_tmp.size(); i++)
            {
                srv->location.methods.push_back(v_tmp[i]);
            }
        }
        else
            return (false);
    }
    return (true);
}

bool Parser::IsLocationUploadExtracted(string Line, Server *srv)
{
    string tmp;
    vector <string> v_location = _split(Line, ';');
    vector <string> v_tmp;



    for (size_t  i= 0; i < v_location.size(); i++)
    {
        if (v_location[i].find ("root") != string::npos)
        {

            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);
            srv->location_upload.root = v_tmp[1];
        }
        else if (v_location[i].find ("autoindex") != string::npos)
        {
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);

            v_tmp[1] = _string_ToUpper(v_tmp[1]);
            if (v_tmp[1] == "ON")
                srv->location_upload.autoindex = true;
            else if (v_tmp[1] == "OFF")
            {
                srv->location_upload.autoindex = false;
            }
            else 
            {
                cout << "error parsing auto index\n";
                return (false);
            }
        }
        else if (v_location[i].find ("methods") != string::npos)
        {

            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() <= 1)
                return (false);
            
            for (size_t i = 0; i < v_tmp.size(); i++)
            {
                srv->location_upload.methods.push_back(v_tmp[i]);
            }


        }
        else if (v_location[i].find ("upload_store") != string::npos)
        {
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);
            srv->location_upload.upload_store =  v_tmp[1];
        }
        else
            return (false);
    }
    return (true);
}

bool Parser::IsLocationCGIExtracted(string Line, Server *srv)
{
    string tmp;
    vector <string> v_location = _split(Line, ';');
    vector <string> v_tmp;


    for (size_t  i= 0; i < v_location.size(); i++)
    {
        if (v_location[i].find ("root") != string::npos)
        {
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);
            srv->cgi_bin.root = v_tmp[1];
        }
        else if (v_location[i].find ("methods") != string::npos)
        {
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() <= 1)
                return (false);
            
            for (size_t i = 1 ; i < v_tmp.size(); i++)
            {
               
                srv->cgi_bin.methods.push_back(v_tmp[i]);
            }
        }
        else if (v_location[i].find ("cgi_pass") != string::npos)
        {
            cout << "########## cgi pass found\n";
            v_tmp = _split(v_location[i], ' ');

            if (v_tmp.size() != 2)
                return (false);
            srv->cgi_bin.cgi_pass =  v_tmp[1];
            cout << "pass***__________________\n";
        }
        else
            return (false);
    }
    return (true);
}



int _find_char_position(std::string s, char c)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
            return (i);
    }
    return (-1);
}


bool isvalidnumber(string s)
{
    for (size_t i = 0; i < s.length() ; i++)
    {
        if (!isdigit(s[i]))
        {
        cout << s[i] << "hhhhhhh" <<  endl;
            return (false);
        }
            
    }
    return ( true);
}

bool _isLinesSeparated(string line)
{
    short countword = 0;
    short countcoma = 0;

    bool iswordfound=false;
    bool iscomafound=false;
    
    for (size_t i = 0; i < line.length(); i++)
    {
        if (isalnum(line[i]) || isspace(line[i]) ) 
        {
            if (!iswordfound)
            {
                countword++;
              iswordfound = true;
              iscomafound = false;
            }
        }
          

        else if (line[i] == ';' && !iscomafound)
        {
            countcoma++;
            iswordfound = false;
            iscomafound = true;
        }
    }
    if (countword != countcoma)
        return (false);
    return (true);
}

bool _check_max_body_size(string line)
{   
    short count_M = 0;

    for (size_t i = 0; i < line.length(); i++)
    {
        if (!isdigit(line[i]) && line[i] != 'M' && !line[i] == '\0')
            return (false);
        
        if (line[i] == 'M')
            count_M++;
        if (count_M > 1)
            return (false);
    }
    return (true);
}

bool Parser::_ExtractData(Server *srv)
{
    short right_bracket = 0;
    short left_bracket = 0;

    bool  is_right_bracket = false;
    bool is_left_bracket = false;
    bool isserverfound = false;

    string line = "";
    string tmp =  "";
    // size_t     pos = 0;

    for (size_t i = 0; i < _conf_line.size(); i++)
    {
        line = tmp +  _conf_line[i];

        for (size_t j = 0 ; j < _conf_line[i].length(); j++)
        {
            if (isserverfound)
            {
                string temp = "";

                if (_conf_line[i][j] == '{')
                {
                    if (is_right_bracket && !is_left_bracket)
                        return (NULL);
                    temp = &_conf_line[i][j + 1];
                    is_left_bracket = true;
                }
                else if (_conf_line[i][j] == '}')
                {
                    if (!is_left_bracket)
                        return (NULL);
                    is_right_bracket = true;
                }
            }
        }
        
        
        if (!isserverfound)
        {
           if  (  _conf_line[i].find("server") != std::string::npos)
           {
             cout << line << "\nserver found\n";
                isserverfound = true;
           }
        }
        
        
        else if (line.find("listen") != string::npos)
        {
            cout << "listen found\n";
            
            while ((_find_char_position(line, ';') == -1))
            {

                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            int tmpnb = _find_char_position(line, ';');

            tmp = &line[tmpnb + 1];
            line = line .substr(0, line.find_last_of(';'));

            line  = line.substr(_find_word((char *)line.c_str(), "listen") + 1, line.length());
            vector <string> listen = _split(line, ':');

            if (listen.size() != 2)
                return (false);

            listen[0] = _trim(listen[0]);
            listen[1] = _trim(listen[1]);

            srv->listening.ip_addr = listen[0];
        
            if (!_is_Valide_ipaddress(srv))
                return (false);

            if (!_Validate_Ports(srv, listen[1]) )
                return (false);
            cout << line << endl;
        }
        
        
        else if (line.find("error_page") != string::npos)
        {
            cout << "error_page found\n";
            while ((_find_char_position(line, ';') == -1))
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            int tmpnb = _find_char_position(line, ';');
            tmp = &line[tmpnb + 1];
            line [tmpnb + 1] = '\0';

            line  = line.substr(_find_word((char *)line.c_str(), "error_page") + 1, line.length());
            vector <string> error_page = _split(line, ' ');

            Server::sterror error;

            if (error_page.size() != 2)
                return (false);

            error.err_number = atoi(error_page[0].c_str());

            if (error_page[1][error_page[1].length() - 1] == ';')
                error_page[1][error_page[1].length() - 1] = '\0';
            error.html_path = error_page[1];

            srv->error.v_error.push_back(error);
        }

        else if (line.find("client_max_body_size") != string::npos)
        {
            cout << "client_max_body_size found\n";
            while ((_find_char_position(line, ';') == -1))
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            int tmpnb = _find_char_position(line, ';');

            tmp = &line[tmpnb + 1];

            line  = line.substr(_find_word((char *)line.c_str(), "client_max_body_size") + 1, line.length());

            vector <string> body_size = _split(line, ' ');
            
            if (body_size.size() != 1)
                return (false);
            if (body_size[0][body_size[0].length() - 1] == ';')
                body_size[0][body_size[0].length() -1] = '\0';

            _trim(body_size[0]);
            if (!_check_max_body_size(body_size[0]))
                return (false);
            srv->max_body_size = atoi(body_size[0].c_str());
        }

        else if (line.find("location /upload") != string::npos)
        {
            cout << "location /upload found\n";
            line  = line.substr(_find_word((char *)line.c_str(), "location /upload") + 1, line.length());

            int pos  = 0;
            while ((pos = _find_char_position(line, '{')) == -1)
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            line  = line.substr(pos  + 1, line.length());

            while ((pos = _find_char_position(line, '}')) == -1)
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            line  = line.substr(0, pos);
            _trim(line);

            if (!_isLinesSeparated(line))
                return (false);
            if (!IsLocationUploadExtracted(line, srv))
            {
                return (false);
            }
        }

         else if (line.find("location /cgi-bin") != string::npos)
        {
            cout << "location /cgi-bin found\n";
            line  = line.substr(_find_word((char *)line.c_str(), "location /cgi-bin") + 1, line.length());

            int pos  = 0;
            while ((pos = _find_char_position(line, '{')) == -1)
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            line  = line.substr(pos  + 1, line.length());

            while ((pos = _find_char_position(line, '}')) == -1)
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            line  = line.substr(0, pos);
            _trim(line);

            if (!_isLinesSeparated(line))
                return (false);
            if (!IsLocationCGIExtracted(line, srv))
            {
                return (false);
            }
            // return (true);
        }

        else if (line.find("location /") != string::npos)
        {
            cout << "location / found\n";
            line  = line.substr(_find_word((char *)line.c_str(), "location /") + 1, line.length());

            int pos  = 0;
            while ((pos = _find_char_position(line, '{')) == -1)
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            line  = line.substr(pos  + 1, line.length());

            while ((pos = _find_char_position(line, '}')) == -1)
            {
                if ( (i + 1) < _conf_line.size())
                {
                    line += _conf_line[i + 1];
                    i++;
                }
                else
                    return (false);
            }
            line  = line.substr(0, pos);
            _trim(line);

            if (!_isLinesSeparated(line))
                return (false);

            if (!IsLocationExtracted(line, srv))
            {
                return (false);
            }

            // return (true);
        }

        else 
        {

            for (size_t j = 0; j < line.length(); j++)
            {
                if (!isspace(_conf_line[i][j]) && _conf_line[i][j] != '{' && _conf_line[i][j] != '}')
                {
                    cout << "unkown config\n";
                    return (false);
                }
                    
            }
        }
    }
    // cout << left_bracket << "; " << right_bracket << endl;
    // while (1) {}
    if (!isserverfound || (left_bracket != right_bracket))
        return (false);
    return (true);
    (void)srv;
}

bool Parser::_is_Valide_ipaddress(Server *srv)
{
    if (srv->listening.ip_addr.empty())
    {
        return (false);
    }



    vector <string > v_ipaddress = _split(srv->listening.ip_addr, '.');

    if (v_ipaddress.size() != 4)
        return (false);

    
    for (size_t i = 0 ; i < v_ipaddress.size(); i++)
    {
        for (size_t j = 0; j < v_ipaddress[i].length(); j++ )
        {
            if (!isdigit(v_ipaddress[i][j]))
                return (false);
            
            int num = atoi (v_ipaddress[i].c_str());

            if (num > 255 || num < 0)
                return (false);
        }
    }
    return (true);
}

bool   Parser::_Validate_Ports(Server *srv, string s)
{
    if (!isvalidnumber(s))
        return (false);


    srv->listening.Port  = atoi (s.c_str());

    if (srv->listening.Port > 65535 || srv->listening.Port < 0)
        return (false);
    return (true);
}


bool Parser::_ValidateData(Server *srv)
{


    

    // check listen port ;
    // check if error_page are accessible;
    // check max body;

    //  check location element if are accessible;
    // check upload if accessible;
    // check cgi bin files if is accessible;




    // ####### - starting setuping the server;

    cout << "hey validate\n";

    (void)srv;

    return (true);
}

Server *Parser::Parse()
{
    if (!_isFileOpend())
        return (NULL);

    if (!_ReadData())
        return (NULL);

    Server *srv  = new Server();
    
    if (!_ExtractData(srv))
    {
        if (srv)
            delete srv;
        return (NULL); 
    }
       
    if (!_ValidateData(srv))
    {
         if (srv)
            delete srv;
        return (NULL); 
    }
    return ( srv );
}

Parser::~Parser() {}