/*! Timer api testing */

#include <stdio.h>
#include <time.h>
#include <api/prog_info.h>

static timespec_t t0;

static void alarm_nt(sigval_t param)
{
	int num;
	timespec_t t_monotonic, t_realtime;
	clock_gettime(CLOCK_MONOTONIC, &t_monotonic);
	clock_gettime(CLOCK_REALTIME, &t_realtime);

	num = param.sival_int;
	time_sub(&t_realtime, &t0);
	printf("[%d:%d]Alarm %d, every %d seconds - CLOCK_MONOTONIC: %d, CLOCK_REALTIME: %d\n", t_realtime.tv_sec, t_realtime.tv_nsec / 100000000, num, num, t_monotonic.tv_sec, t_realtime.tv_sec);
}

static void alarm_mon(sigval_t param)
{
	int num;
	timespec_t t_monotonic, t_realtime;
	clock_gettime(CLOCK_MONOTONIC, &t_monotonic);
	clock_gettime(CLOCK_REALTIME, &t_realtime);

	num = param.sival_int;
	time_sub(&t_realtime, &t0);
	t_realtime.tv_sec += 1;
	clock_settime(CLOCK_REALTIME, &t_realtime);
	printf("[%d:%d]Alarm %d, every %d seconds - CLOCK_MONOTONIC: %d, CLOCK_REALTIME: %d\n", t_monotonic.tv_sec, t_monotonic.tv_nsec / 100000000, num, num, t_monotonic.tv_sec, t_realtime.tv_sec);
}

int timer()
{
	timespec_t t;
	itimerspec_t t1, t2;
	timer_t timer1, timer2;
	sigevent_t evp, evp2;

	printf("Example program: [%s:%s]\n%s\n\n", __FILE__, __FUNCTION__,
		   timer_PROG_HELP);

	clock_gettime(CLOCK_REALTIME, &t);
	t0 = t;
	printf("System time: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000);

	evp.sigev_notify = SIGEV_THREAD;
	evp.sigev_notify_function = alarm_nt;
	evp.sigev_notify_attributes = NULL;

	evp2.sigev_notify = SIGEV_THREAD;
	evp2.sigev_notify_function = alarm_mon;
	evp2.sigev_notify_attributes = NULL;

	/* timer1 */
	t1.it_interval.tv_sec = 1;
	t1.it_interval.tv_nsec = 0;
	t1.it_value.tv_sec = 1;
	t1.it_value.tv_nsec = 0;
	evp.sigev_value.sival_int = t1.it_interval.tv_sec;
	timer_create(CLOCK_REALTIME, &evp, &timer1);
	timer_settime(&timer1, 0, &t1, NULL);

	/* timer2 */
	t2.it_interval.tv_sec = 3;
	t2.it_interval.tv_nsec = 0;
	t2.it_value.tv_sec = 3;
	t2.it_value.tv_nsec = 0;
	evp2.sigev_value.sival_int = t2.it_interval.tv_sec;
	timer_create(CLOCK_MONOTONIC, &evp2, &timer2);
	timer_settime(&timer2, 0, &t2, NULL);

	t.tv_sec = 11;
	t.tv_nsec = 0;

	while (TIME_IS_SET(&t))
		if (clock_nanosleep(CLOCK_REALTIME, 0, &t, &t))
			printf("Interrupted sleep?\n");

	// clock_gettime ( CLOCK_REALTIME, &t );
	// printf ( "System time: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000 );

	// t.tv_sec = 3;
	// t.tv_nsec = 0;
	// clock_settime ( CLOCK_REALTIME, &t );
	// clock_gettime ( CLOCK_REALTIME, &t );
	// printf ( "System time: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000 );

	t.tv_sec = 10;
	t.tv_nsec = 0;

	while (TIME_IS_SET(&t))
		if (clock_nanosleep(CLOCK_REALTIME, 0, &t, &t))
			printf("Interrupted sleep?\n");

	clock_gettime(CLOCK_REALTIME, &t);
	printf("System time: %d:%d\n", t.tv_sec, t.tv_nsec / 100000000);

	timer_delete(&timer1);
	timer_delete(&timer2);

	return 0;
}
