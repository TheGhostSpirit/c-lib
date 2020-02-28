static ArrayList *slice(ArrayList *list, size_t start, size_t end);

ArrayList *slice(ArrayList *list, size_t start, size_t end)
{
    if (!isAllocated(list) || start > end || end > list->size)
    {
        return list;
    }

    ArrayList *new = newArrayList();

    for (size_t i = start; i < end; i++)
    {
        new->proto->push(new, list->proto->get(list, i));
    }

    return new;
}