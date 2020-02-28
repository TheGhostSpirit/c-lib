#include "array-list.h"

#include "methods/utils.c"

#include "methods/clone.c"
#include "methods/concat.c"
#include "methods/every.c"
#include "methods/fill.c"
#include "methods/filter.c"
#include "methods/find-index.c"
#include "methods/find.c"
#include "methods/flat-map.c"
#include "methods/flat.c"
#include "methods/for-each.c"
#include "methods/get.c"
#include "methods/includes.c"
#include "methods/index-of.c"
#include "methods/map.c"
#include "methods/pop.c"
#include "methods/push.c"
#include "methods/reduce.c"
#include "methods/set.c"
#include "methods/slice.c"
#include "methods/some.c"
#include "methods/sort.c"

static ArrayListPrototype *getProto();
static void destroy(ArrayList *list, void (*hook)(void *element));

ArrayList *newArrayList()
{
    ArrayList *list = xmalloc(1, sizeof(ArrayList));
    list->_list = NULL;
    list->_blocks = 0;
    list->size = 0;
    list->proto = getProto();
    return list;
}

ArrayListPrototype *getProto()
{
    static ArrayListPrototype proto;
    proto.fill = &fill;
    proto.push = &push;
    proto.pop = &pop;
    proto.clone = &clone;
    proto.get = &get;
    proto.set = &set;
    proto.concat = &concat;
    proto.every = &every;
    proto.filter = &filter;
    proto.destroy = &destroy;
    proto.forEach = &forEach;
    proto.find = &find;
    proto.findIndex = &findIndex;
    proto.includes = &includes;
    proto.indexOf = &indexOf;
    proto.map = &map;
    proto.reduce = &reduce;
    proto.slice = &slice;
    proto.some = &some;
    proto.sort = &sort;
    proto.flat = &flat;
    proto.flatMap = &flatMap;
    return &proto;
}

void destroy(ArrayList *list, void (*hook)(void *element))
{
    if (hook)
    {
        for (size_t i = 0; i < list->size; i++)
        {
            hook(list->proto->get(list, i));
        }
    }

    if (isAllocated(list))
    {
        free(list->_list);
    }

    free(list);
}
