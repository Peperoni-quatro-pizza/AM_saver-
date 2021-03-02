begin P_EnterAssembly arriving procedure
	move into Conv1.sta1
	/* how to write comment on code */ 
	/* Get on the conv at sta1 */ 
	send to P_CompleteAssembly
	/* send to another process */ 
end 

begin P_CompleteAssembly arriving procedure
	travel to Conv1.sta2 
	/* Travel from current location to sta2 */ 
	send to die /* leave simulation */ 
end 

