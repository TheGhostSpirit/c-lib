static ArrayList *fill(ArrayList *list, void *value, size_t start, size_t end);

ArrayList *fill(ArrayList *list, void *value, size_t start, size_t end)
{
    if (!isAllocated(list) || start > end || end > list->size)
    {
        return list;
    }

    ArrayList *new = list->proto->clone(list);

    for (size_t i = start; i < end; i++)
    {
        new->proto->set(new, i, value);
    }

    return new;
}