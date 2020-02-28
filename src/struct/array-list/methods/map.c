static ArrayList *map(ArrayList *list, void *(*mapper)(void *element, size_t index, void *data), void *data);

ArrayList *map(ArrayList *list, void *(*mapper)(void *element, size_t index, void *data), void *data)
{
    ArrayList *res = newArrayList();

    for (size_t i = 0; i < list->size; i++)
    {
        res->proto->push(res, mapper(list->proto->get(list, i), i, data));
    }

    return res;
}