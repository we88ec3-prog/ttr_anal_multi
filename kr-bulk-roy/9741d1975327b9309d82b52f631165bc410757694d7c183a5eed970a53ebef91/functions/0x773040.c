
void FUN_00773040(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar2 = *(undefined4 **)(param_1 + 0x60);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (*(uint *)(param_1 + 0x38) < 8) {
      iVar4 = param_1 + 0x24;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x24);
    }
    (**(code **)(*(int *)puVar3[4] + 0x20))(iVar4,param_2);
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar6 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar6 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar6 + 0x15);
        puVar3 = puVar6;
        puVar6 = (undefined4 *)*puVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x15);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar6 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
        }
      }
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x70);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar6 = puVar3;
          if (puVar6 == puVar2) {
            return;
          }
          if (*(uint *)(param_1 + 0x38) < 8) {
            iVar4 = param_1 + 0x24;
          }
          else {
            iVar4 = *(int *)(param_1 + 0x24);
          }
          (**(code **)(*(int *)puVar6[4] + 0x20))(iVar4,param_2);
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

