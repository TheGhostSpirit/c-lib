static void *reduce(ArrayList *list, void *(*reducer)(void *accumulator, void *currentValue, void *data), void *initialValue, void *data);

void *reduce(ArrayList *list, void *(*reducer)(void *accumulator, void *currentValue, void *data), void *initialValue, void *data)
{
    for (size_t i = 0; i < list->size; i++)
    {
        initialValue = reducer(initialValue, list->proto->get(list, i), data);
    }

    return initialValue;
}
