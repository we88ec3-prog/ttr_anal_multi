
void FUN_005972e0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  piVar6 = (int *)(param_1 + 0xc4);
  param_1 = 3;
  do {
    puVar2 = (undefined4 *)*piVar6;
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      if ((*(char *)((int)puVar3 + 0x16) == '\0') && (((uint)((int *)puVar3[3])[10] >> 8 & 1) != 0))
      {
        (**(code **)(*(int *)puVar3[3] + 0xd4))();
      }
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        puVar4 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar4 + 0x21) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x21);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x21);
            puVar3 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
          while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x21);
            puVar5 = (undefined4 *)puVar3[1];
            puVar4 = puVar3;
          }
        }
      }
    }
    piVar6 = piVar6 + 4;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}

