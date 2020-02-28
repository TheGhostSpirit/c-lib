static bool includes(ArrayList *list, void *element);

bool includes(ArrayList *list, void *element)
{
    for (size_t i = 0; i < list->size; i++)
    {
        if (list->proto->get(list, i) == element)
        {
            return true;
        }
    }
    return false;
}
