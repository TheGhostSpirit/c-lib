static ArrayList *clone(ArrayList *list);

ArrayList *clone(ArrayList *list)
{
    ArrayList *new = newArrayList();

    for (size_t i = 0; i < list->size; i++)
    {
        new->proto->push(new, list->proto->get(list, i));
    }

    return new;
}