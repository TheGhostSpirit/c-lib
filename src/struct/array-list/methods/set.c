static void set(ArrayList *list, size_t index, void *value);

void set(ArrayList *list, size_t index, void *value)
{
    if (!isAllocated(list) || index >= list->size)
    {
        return;
    }

    list->_list[index] = value;
}