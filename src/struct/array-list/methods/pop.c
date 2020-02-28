static void *pop(ArrayList *list);


void *pop(ArrayList *list)
{
    if (!isAllocated(list))
    {
        return NULL;
    }

    void *element = list->proto->get(list, list->size - 1);
    list->size--;

    return element;
}