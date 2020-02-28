static bool every(ArrayList *list, bool (*predicate)(void *element, size_t index, void *data), void *data);

bool every(ArrayList *list, bool (*predicate)(void *element, size_t index, void *data), void *data)
{
    for (size_t i = 0; i < list->size; i++)
    {
        if (!predicate(list->proto->get(list, i), i, data))
        {
            return false;
        }
    }
    return true;
}