SYSTYPE Conveyor
UNITS Feet Seconds
SYSDEF timeout 60 Seconds confname Config1
FLAGS
	System Inherit
	Text Inherit
	Sections Inherit
	Section Names Inherit
	Direction Inherit
	Fixed Interval Inherit
	Loads Inherit
	Stations Inherit
	Station Names Inherit
	Transfers Inherit
	Photoeyes Inherit
	Photoeye Names Inherit
	Center Line Invisible Inherit
CONVDEF UserId 6
	NEXTSEC name sec5 type DefaultSection
	NEXTSTA name staout3 type DefaultStation
	NEXTTRAN name tran6 type DefaultTransfer
	NEXTMOTOR name motor1 type DefaultMotor
	NEXTPHOTOEYE name photoeye1 type DefaultPhotoeye
	ALTERNATE NONE EXTRASECTIONWIDTH 0 Feet
CONVTOL minang 450 maxang 1350
CONVMOTORTYPE name DefaultMotor
CONVMOTOR name M_sec1 type DefaultMotor
CONVSECTIONTYPE name DefaultSection width 4 Feet motor M_sec1 vel 1 Feet Seconds acc 1 Feet Seconds Seconds dec 1 Feet Seconds Seconds accum load stopsize 1 0 Feet movesize 1 0 Feet inductsize 1 0 Feet nofixed align centered_in_interval attach rigid nav 1
CONVSECTION name sec1 type DefaultSection motor M_sec1 piece begx -0.219183609128937 begy 0.0 endx 79.345032808399 endy 0.0 upz 1
CONVSECTION name sec2 type DefaultSection piece begx 77.3669619422572 begy -1.87309895833333 endx 77.3669619422572 endy -30.0103313648294 upz 1
CONVSECTION name sec3 type DefaultSection piece begx 75.3633858267717 begy -27.6583005249344 endx 7.7643405511811 endy -27.6583005249344 upz 1
CONVSECTION name sec4 type DefaultSection piece begx 9.64381069553806 begy -29.6913976377953 endx 9.64381069553806 endy -57.8037598425197 upz 1
CONVSECTION name sec5 type DefaultSection piece begx 25.6438106955381 begy -29.6913976377953 endx 25.6438106955381 endy -57.8037598425197 upz 1
CONVSTATIONTYPE name DefaultStation raise 0 Seconds lower 0 Seconds dist 0 Feet release norestriction align leading cap Infinite scale 1 color -1 nrot 0 nscale 1
CONVSTATION name sta1 type DefaultStation at sec1 0
CONVSTATION name sta2 type DefaultStation at sec1 78
CONVSTATION name staout1 type DefaultStation at sec4 26.3274475065617
CONVSTATION name staout2 type DefaultStation at sec5 26.4166929133858
CONVPHOTOEYETYPE name DefaultPhotoeye blocktimeout 5 Seconds cleartimeout 5 Seconds
CONVTRANSFERTYPE name DefaultTransfer inductsize 1 0 Feet aheadinductsize 1 0 Feet speedadjust Origin starttime 0 Seconds finishtime 0 Seconds style double movemethod movesection
CONVTRANSFER name tran1 type DefaultTransfer from sec1 77.5861455513862 to sec2 0
CONVTRANSFER name tran2 type DefaultTransfer from sec2 25.785201566601 to sec3 0
CONVTRANSFER name tran5 type DefaultTransfer from sec3 65.7195751312336 to sec4 0
CONVTRANSFER name tran5_1 type DefaultTransfer from sec3 49.7195751312336 to sec5 0
