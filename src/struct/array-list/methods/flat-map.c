ArrayList *flatMap(ArrayList *list, void *(*mapper)(void *element, size_t index, void *data), void *data);

ArrayList *flatMap(ArrayList *list, void *(*mapper)(void *element, size_t index, void *data), void *data)
{
    ArrayList *res = newArrayList();

    for (size_t i = 0; i < list->size; i++)
    {
        ArrayList *current = mapper(list->proto->get(list, i), i, data);
        for (size_t j = 0; j < current->size; j++)
        {
            res->proto->push(res, current->proto->get(current, j));
        }
        current->proto->destroy(current, NULL);
    }

    return res;
}
