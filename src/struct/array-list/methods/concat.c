static ArrayList *concat(ArrayList *list, ArrayList *list2);

ArrayList *concat(ArrayList *list, ArrayList *list2)
{
    ArrayList *new = list->proto->clone(list);

    for (size_t i = 0; i < list2->size; i++)
    {
        new->proto->push(new, list2->proto->get(list2, i));
    }

    return new;
}
