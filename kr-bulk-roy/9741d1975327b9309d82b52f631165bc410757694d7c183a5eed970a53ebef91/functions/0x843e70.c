
undefined4 FUN_00843e70(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x174);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar6 = puVar3;
          if (puVar6 == puVar2) {
            return *(undefined4 *)(in_ECX + 0x24);
          }
          iVar4 = (**(code **)(*(int *)puVar6[4] + 8))();
          if (iVar4 == 0) {
            return 0;
          }
          puVar3 = puVar6;
        } while (*(char *)((int)puVar6 + 0x15) != '\0');
        puVar3 = (undefined4 *)puVar6[2];
        if (*(char *)((int)puVar3 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar6 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      puVar3 = (undefined4 *)puVar6[1];
    } while (*(char *)((int)puVar3 + 0x15) != '\0');
    do {
      puVar5 = puVar3;
      puVar3 = puVar5;
      if (puVar6 != (undefined4 *)puVar5[2]) break;
      puVar3 = (undefined4 *)puVar5[1];
      puVar6 = puVar5;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  } while( true );
}

