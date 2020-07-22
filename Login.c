Login()
{
	/*Correlation comment - Do not change!  Original value='128993.233130822zzDfAiQptcQVzzzHDQiVApfDzfHf' Name ='userSession' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
	
	//Search parameter
	web_reg_save_param("userSessionSP","lb=name=\"userSession\" value=\"","rb=\"/>",LAST);

	web_reg_find("Fail=NotFound",
		"Text=Web Tours Navigation Bar",
		LAST);
	
	lr_start_transaction("Home");
	web_url("Home", 
		"URL=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t7.inf", 
		"Mode=HTTP", 
		LAST);
	lr_end_transaction("Home", LR_AUTO);
	lr_think_time(13);
	
		web_reg_find("Fail=NotFound",
		"Text=Web Tours",
		LAST);

	//lr_rendezvous("RendezvousPointForLoginPage");

	lr_start_transaction("Login");
	web_submit_data("Login", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userSession", "Value={userSessionSP}", ENDITEM, 
		"Name=username", "Value={UserNameFP}", ENDITEM, 
		"Name=password", "Value={UserPassFP}", ENDITEM, 
		"Name=JSFormSubmit", "Value=on", ENDITEM, 
		"Name=login.x", "Value=57", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		LAST);
	lr_end_transaction("Login", LR_AUTO);
	lr_think_time(13);
	return 0;
}
