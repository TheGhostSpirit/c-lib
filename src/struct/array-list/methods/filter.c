static ArrayList *filter(ArrayList *list, bool (*predicate)(void *element, size_t index, void *data), void *data);

ArrayList *filter(ArrayList *list, bool (*predicate)(void *element, size_t index, void *data), void *data)
{
    ArrayList *new = newArrayList();
    for (size_t i = 0; i < list->size; i++)
    {
        if (predicate(list->proto->get(list, i), i, data))
        {
            new->proto->push(new, list->proto->get(list, i));
        }
    }
    return new;
}