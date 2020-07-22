FlightDetails()
{
	web_reg_find("Fail=NotFound",
		"Text=Web Tours",
		LAST);
	lr_start_transaction("SearchFlights");
	web_url("SearchFlights", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t17.inf", 
		"Mode=HTTP", 
		LAST);
    lr_end_transaction("SearchFlights", LR_AUTO);
	lr_think_time(19);

	web_reg_find("Fail=NotFound",
		"Text=Flight Selections",
		LAST);

	lr_start_transaction("FlightDetails");
	web_submit_data("FlightDetails", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t23.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={DepartCity}", ENDITEM, 
		"Name=departDate", "Value={DepartDate}", ENDITEM, 
		"Name=arrive", "Value={ReturnCity}", ENDITEM, 
		"Name=returnDate", "Value={ReturnDate}", ENDITEM, 
		"Name=numPassengers", "Value={NumPassenger}", ENDITEM, 
		"Name=roundtrip", "Value=on", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=64", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		LAST);
    lr_end_transaction("FlightDetails", LR_AUTO);
    lr_think_time(13);
    

	web_reg_find("Fail=NotFound",
		"Text=Flight Reservation",
		LAST);
    
	lr_start_transaction("FlightSelection");
	web_submit_data("FlightSelection", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t26.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=000;0;{DepartDate}", ENDITEM, 
		"Name=returnFlight", "Value=000;0;{ReturnDate}", ENDITEM, 
		"Name=numPassengers", "Value={NumPassenger}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=29", ENDITEM, 
		"Name=reserveFlights.y", "Value=11", ENDITEM, 
		LAST);
    lr_end_transaction("FlightSelection", LR_AUTO);
	lr_think_time(9);
	
	return 0;
}