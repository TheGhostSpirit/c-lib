static ArrayList *sort(ArrayList *list, size_t (*sortFunc)(void *element, void *data), void *data);

ArrayList *sort(ArrayList *list, size_t (*sortFunc)(void *element, void *data), void *data)
{
    for (size_t i = 0; i < list->size; i++)
    {
        for (size_t j = 0; j < list->size; j++)
        {
            if (j > i && sortFunc(list->proto->get(list, i), data) > sortFunc(list->proto->get(list, j), data))
            {
                swap(list, i, j);
            }
        }
    }
    return list;
}