#define SYS_FREQ 				(80000000L)
void DelayMs(unsigned int msec);
void DelayUs(unsigned int usec);

void DelayMs(unsigned int msec)
{
    unsigned int tWait, tStart;
    tWait=(SYS_FREQ/2000)*msec;
    tStart=ReadCoreTimer();
    while((ReadCoreTimer()-tStart)<tWait);		// wait for the time to pass
}
void DelayUs(unsigned int usec)
{
    unsigned int tWait, tStart;
    tWait=(SYS_FREQ/2000000)*usec;
    tStart=ReadCoreTimer();
    while((ReadCoreTimer()-tStart)<tWait);		// wait for the time to pass
}