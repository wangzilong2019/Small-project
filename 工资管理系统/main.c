#include <stdio.h>
#include "db_operation.h"

int main(void) {
    db_operation_t dbo = {0};
    init_db_operation(&dbo, "db.txt");
    start(&dbo);
    return 0;
}
