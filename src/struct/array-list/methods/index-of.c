static long indexOf(ArrayList *list, void *element);

long indexOf(ArrayList *list, void *element)
{
    for (size_t i = 0; i < list->size; i++)
    {
        if (list->proto->get(list, i) == element)
        {
            return i;
        }
    }
    return -1;
}