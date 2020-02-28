static ArrayList *push(ArrayList *list, void *value);

ArrayList *push(ArrayList *list, void *value)
{
    if (list->size == list->_blocks)
    {
        expand(list);
    }

    list->size++;
    list->proto->set(list, list->size - 1, value);

    return list;
}
