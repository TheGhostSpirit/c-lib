static void forEach(ArrayList *list, void (*callback)(void *element, size_t index, void *data), void *data);

void forEach(ArrayList *list, void (*callback)(void *element, size_t index, void *data), void *data)
{
    for (size_t i = 0; i < list->size; i++)
    {
        callback(list->proto->get(list, i), i, data);
    }
}