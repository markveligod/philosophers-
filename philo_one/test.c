#include "one.h"

void testing_pars(t_ptr *ptr)
{
    printf("Is alive? => %d\n", ptr->alive);
    printf("\nStruct time:\nNum philo: %d\nTime die: %d\nTime eat: %d\nTime sleep: %d\nNum eat: %d\n\n", ptr->times->num_philo, ptr->times->time_to_die, ptr->times->time_to_eat, ptr->times->time_to_sleep, ptr->times->num_eat);
}