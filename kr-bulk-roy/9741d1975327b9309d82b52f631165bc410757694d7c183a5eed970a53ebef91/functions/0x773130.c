
void FUN_00773130(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 0x60);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar3;
          if (puVar5 == puVar2) {
            puVar2 = *(undefined4 **)(param_1 + 0x70);
            puVar3 = (undefined4 *)*puVar2;
            while (puVar3 != puVar2) {
              (**(code **)(*(int *)puVar3[4] + 0x24))();
              if (*(char *)((int)puVar3 + 0x15) == '\0') {
                puVar5 = (undefined4 *)puVar3[2];
                if (*(char *)((int)puVar5 + 0x15) == '\0') {
                  cVar1 = *(char *)((int)*puVar5 + 0x15);
                  puVar3 = puVar5;
                  puVar5 = (undefined4 *)*puVar5;
                  while (cVar1 == '\0') {
                    cVar1 = *(char *)((int)*puVar5 + 0x15);
                    puVar3 = puVar5;
                    puVar5 = (undefined4 *)*puVar5;
                  }
                }
                else {
                  cVar1 = *(char *)((int)puVar3[1] + 0x15);
                  puVar4 = (undefined4 *)puVar3[1];
                  puVar5 = puVar3;
                  while ((puVar3 = puVar4, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
                    cVar1 = *(char *)((int)puVar3[1] + 0x15);
                    puVar4 = (undefined4 *)puVar3[1];
                    puVar5 = puVar3;
                  }
                }
              }
            }
            return;
          }
          (**(code **)(*(int *)puVar5[4] + 0x24))();
          puVar3 = puVar5;
        } while (*(char *)((int)puVar5 + 0x15) != '\0');
        puVar3 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar3 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar5 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar3 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar3 + 0x15) != '\0');
    do {
      puVar4 = puVar3;
      puVar3 = puVar4;
      if (puVar5 != (undefined4 *)puVar4[2]) break;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar4;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  } while( true );
}

