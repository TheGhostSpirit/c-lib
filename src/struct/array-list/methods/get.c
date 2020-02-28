static void *get(ArrayList *list, size_t index);

void *get(ArrayList *list, size_t index)
{
    if (!isAllocated(list) || index >= list->size)
    {
        return NULL;
    }

    return list->_list[index];
}
