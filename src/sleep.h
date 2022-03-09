/**
 * Author: Valkryst
 *
 * Purpose
 *      A convenience function which allows the calling thread to suspend its
 *      execution for some amount of time.
 */
#ifndef SLEEP_H
#define SLEEP_H

#define MILLISECONDS_PER_SECOND 1000
#define MILLISECONDS_PER_NANOSECOND 1000000;

int sleep(int milliseconds);

#endif
