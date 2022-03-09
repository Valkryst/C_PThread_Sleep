/**
 * Author: Valkryst
 *
 * Purpose
 *      A convenience function which allows the calling thread to suspend its
 *      execution for some amount of time.
 *
 * Notes
 *      * The _POSIX_C_SOURCE define is required for the nanosleep function. See
 *        sources #1 & #2 for more information.
 *
 * Sources
 *      1. https://man7.org/linux/man-pages/man2/nanosleep.2.html
 *      2. https://stackoverflow.com/a/50170469/13279616
 */
#define _POSIX_C_SOURCE 199309L

#include <errno.h>
#include <stdio.h>
#include <time.h>

#include "logger.h"
#include "sleep.h"

/**
 * Suspends execution of the calling thread until at least the specified number
 * of milliseconds has elapsed.
 *
 * @param milliseconds An amount of time, in milliseconds, to sleep for.
 * @return 0 if successful or 1 if an error occurred.
 */
int sleep(int milliseconds) {
    if (milliseconds < 1) {
        printError(
			0,
			__FILE__,
			__PRETTY_FUNCTION__,
			"Could not sleep as milliseconds < 1."
		);
        return 1;
    }

    struct timespec timespec;
    timespec.tv_sec = milliseconds / MILLISECONDS_PER_SECOND;
    timespec.tv_nsec = (milliseconds % MILLISECONDS_PER_SECOND) * MILLISECONDS_PER_NANOSECOND;

    while (0 != nanosleep(&timespec, &timespec)) {
        if (EINTR != errno) {
            printError(
			errno,
			__FILE__,
			__PRETTY_FUNCTION__,
			"Could not run nanosleep."
			);
            return 1;
        }
    }

    return 0;
}