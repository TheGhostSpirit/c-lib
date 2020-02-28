static bool isAllocated(ArrayList *list);
static void expand(ArrayList *list);
static void swap(ArrayList *list, size_t src, size_t dest);

void swap(ArrayList *list, size_t src, size_t dest)
{
    if (!isAllocated(list) || src >= list->size || dest >= list->size)
    {
        return;
    }

    void *temp = list->proto->get(list, dest);
    list->proto->set(list, dest, list->proto->get(list, src));
    list->proto->set(list, src, temp);
}

bool isAllocated(ArrayList *list)
{
    return list->_list != NULL;
}

void expand(ArrayList *list)
{
    list->_blocks += ARRAY_LIST_SIZE_INCREMENT;
    list->_list = xrealloc(list->_list, list->_blocks + ARRAY_LIST_SIZE_INCREMENT, sizeof(void *));
}