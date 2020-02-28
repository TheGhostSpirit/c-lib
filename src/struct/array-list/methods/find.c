static void *find(ArrayList *list, bool (*predicate)(void *element, size_t index, void *data), void *data);

void *find(ArrayList *list, bool (*predicate)(void *element, size_t index, void *data), void *data)
{
    for (size_t i = 0; i < list->size; i++)
    {
        if (predicate(list->proto->get(list, i), i, data))
        {
            return list->proto->get(list, i);
        }
    }
    return NULL;
}