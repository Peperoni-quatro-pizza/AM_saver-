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
	move into Q_Wait(procindex)
	move into Agv.cpin(procindex)
	send to P_Inspect
end 


begin P_Inspect arriving procedure 
	travel to Agv.cpinspect 
	use R_Inspect for 30 sec 
	send to oneof(10:P_Reject, 15:P_Repair, 75:P_Label)
end 

begin P_Reject arriving procedure
	move into Q_Reject
	wait for 30sec 
	set A_Time to ac - A_Time 
	print this load, "was rejected. Total time in system was" 
	A_Time to message 
	send to die 
end 

begin P_Repair arriving procedure 
	travel to Agv.cprepairin 
	move into Q_Repair 
	use R_Repair for normal 6,1 min 
	move into Agv.cprepairout
	send to P_Label 
end 

begin P_Label arriving procedure 
	travel to Agv.cplabelin 
	move into Q_Label 
	use R_Label for 2 min 
	move into Agv.cplabelout
	send to P_Store 
end 


begin P_Store arriving procedure 
	travel to Agv.cpstore
	move into Q_Store
	wait for 20 sec 

	set A_Time to ac - A_Time 
	print this load, "Time in system = " A_Time to message 
	inc V_Numdone by 1 
	send to die 
end 

