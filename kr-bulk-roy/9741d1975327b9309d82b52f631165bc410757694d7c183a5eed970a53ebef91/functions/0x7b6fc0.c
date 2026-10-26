
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007b6fc0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(DAT_00fd9424 + 4) + 0x15);
  piVar3 = *(int **)(DAT_00fd9424 + 4);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar3[2]);
    piVar2 = (int *)*piVar3;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  *(int *)(DAT_00fd9424 + 4) = DAT_00fd9424;
  *(int *)DAT_00fd9424 = DAT_00fd9424;
  *(int *)(DAT_00fd9424 + 8) = DAT_00fd9424;
  _DAT_00fd9428 = 0;
  return;
}

