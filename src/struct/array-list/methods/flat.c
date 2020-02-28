static ArrayList *flat(ArrayList *list);

ArrayList *flat(ArrayList *list)
{
    ArrayList *res = newArrayList();
    for (size_t i = 0; i < list->size; i++)
    {
        ArrayList *current = list->proto->get(list, i);
        for (size_t j = 0; j < current->size; j++)
        {
            res->proto->push(res, current->proto->get(current, j));
        }
    }
    return res;
}