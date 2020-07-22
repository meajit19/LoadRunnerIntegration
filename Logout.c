Logout()
{
	web_reg_find("Fail=NotFound",
		"Text=Web Tours",
		LAST);
	
	lr_start_transaction("Logout");
	web_url("Logout", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t30.inf", 
		"Mode=HTTP", 
		LAST);
    lr_end_transaction("Logout", LR_AUTO);
    lr_think_time(13);
	return 0;
}
