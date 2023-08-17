#pragma once
#include "configFile.hpp"
#include "locationClass.hpp"
#include "cstring"
#include "exceptions.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define WHITE "\033[0;37m"


using namespace std;

class server {
	private:
		string				_port;
		string				_host;
		string				_server_name;
		string				_client_max_body_size;
		map<string, string>	_error_pages;
		vector<location>	_locations;
		struct addrinfo 	hint;
        struct addrinfo 	*res;
		int             	server_socket;
	public:
		server();
		~server(){};
		//?
		// ? seter's
		//?
		void			setPort(string port){_port = port;};
		void			setHost(string host){_host = host;};
		void			setServerName(string serverName){_server_name = serverName;};
		void			setclient_max_body_size(string client_max){_client_max_body_size = client_max;};
		void			setErrorPage(string key, string value){
							pair<map<string, string>::iterator, bool> ret;
							ret = _error_pages.insert(std::pair<string, string>(key, value));
							if (!ret.second)
								ret.first->second = value;
						};
		//void			setLocations();
		//?
		// ? geter's
		//?
		string					getPort(){return (_port);};
		string&					getHost(){return (_host);};
		string&					getclient_max_body_size(){return (_client_max_body_size);};
		string					getServerName(){return (_server_name);};
		map<string, string>&	getErrorPage(){return (_error_pages);};
		vector<location>		getLocation(){return (_locations);};
		void					getLocationContext(ifstream &in, string line);
		int						getServerSocket() { return server_socket;};
		void					print();
        void    				CreateSocket(server servers);

		void					checkHostPort();
};


int	count_argument(string value, int count);