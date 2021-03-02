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
	NEXTSEC name sec2 type DefaultSection
	NEXTSTA name sta3 type DefaultStation
	NEXTTRAN name tran1 type DefaultTransfer
	NEXTMOTOR name motor1 type DefaultMotor
	NEXTPHOTOEYE name photoeye1 type DefaultPhotoeye
	ALTERNATE NONE EXTRASECTIONWIDTH 0 Feet
CONVTOL minang 450 maxang 1350
CONVMOTORTYPE name DefaultMotor
CONVMOTOR name M_sec1 type DefaultMotor
CONVSECTIONTYPE name DefaultSection width 4 Feet motor M_sec1 vel 1 Feet Seconds acc 1 Feet Seconds Seconds dec 1 Feet Seconds Seconds accum load stopsize 1 0 Feet movesize 1 0 Feet inductsize 1 0 Feet nofixed align centered_in_interval attach rigid nav 1
CONVSECTION name sec1 type DefaultSection motor M_sec1 piece begx -0.219183609128937 begy 0.0 endx 79.345032808399 endy 0.0 upz 1
CONVSTATIONTYPE name DefaultStation raise 0 Seconds lower 0 Seconds dist 0 Feet release norestriction align leading cap Infinite scale 1 color -1 nrot 0 nscale 1
CONVSTATION name sta1 type DefaultStation at sec1 0
CONVSTATION name sta2 type DefaultStation at sec1 79.5642164175279
CONVPHOTOEYETYPE name DefaultPhotoeye blocktimeout 5 Seconds cleartimeout 5 Seconds
CONVTRANSFERTYPE name DefaultTransfer inductsize 1 0 Feet aheadinductsize 1 0 Feet speedadjust Origin starttime 0 Seconds finishtime 0 Seconds style double movemethod movesection
