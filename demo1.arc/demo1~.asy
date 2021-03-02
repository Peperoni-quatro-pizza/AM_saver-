SYSTYPE Process
UNITS Feet Seconds
SYSDEF UtilByAvail off RefCheck on debugger off warningMessages on report standard
FLAGS
	System Inherit
	Text Inherit
	Resources Inherit
	Resource Names Inherit
	Queues Inherit
	Queue Names Inherit
	Queue Amounts Inherit
	Blocks Inherit
	Block Names Inherit
	Labels Inherit
PROCDEF
PROC name P_EnterAssembly 0 traf Infinite nextproc die
PROC name P_CompleteAssembly 0 traf Infinite nextproc die
LDTYPE name L_Carton 0 dis
picpos begx 3.04551837270341 begy -0.192443533669619 endx 4.04551837270341 endy -0.192443533669619 scx 2 scy 2 scz 2
 template Feet
700 17
2 2 0 1 1 none
1
310 0
1 1 1 1 1 0 0
end
		create con 5 Seconds stream stream_L_Carton_1 First P_EnterAssembly 0
RNSTREAM stream0 0 type CMRG flags 1
	cmrgseed 1 12345 12345 12345 12345 12345 12345
RNSTREAM stream_L_Carton_1 0 type CMRG flags 1
	title "Generated automatically for L_Carton"
	cmrgseed 1 3692455944 1366884236 2968912127 335948734 4161675175 475798818
RNSTATE 1015873554 1310354410 2249465273 994084013 2912484720 3876682925
SFileBegin	name mycode.m
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

#@!
