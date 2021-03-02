begin P_EnterAssembly arriving procedure
	move into Q_Assemble
	set A_Time to ac 
	get R_Operator1
	wait for uniform 100,15 sec
	wait for 10 sec
	move into Conv1.sta1
	free R_Operator1
	send to P_CompleteAssembly 
end 

begin P_CompleteAssembly arriving procedure
	travel to Conv1.sta2 
	use R_Operator2 for uniform 60,10 sec
	
	send to oneof(50:P_Out(1), 50:P_Out(2))
end 

begin P_Out arriving procedure
	travel to Conv1.staout(procindex)
	set A_Time to ac - A_Time 
	print this load, "Time in system = " A_Time to message 
	inc V_Numdone by 1 
	send to die 
end 

