
undefined4 * FUN_00782cb0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint *in_EDX;
  undefined4 *puVar4;
  int unaff_EDI;
  uint local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a390;
  local_10 = ExceptionList;
  puVar4 = *(undefined4 **)(unaff_EDI + 4);
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar1[3] < *in_EDX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar4 != *(undefined4 **)(unaff_EDI + 4)) && ((uint)puVar4[3] <= *in_EDX)) {
    return puVar4 + 4;
  }
  local_20[2] = 0;
  local_20[0] = *in_EDX;
  local_20[1] = 0;
  local_8 = 1;
  ExceptionList = &local_10;
  uVar3 = FUN_00845250(local_20);
  FUN_00784410(puVar4,uVar3);
  ExceptionList = local_10;
  return (undefined4 *)(local_20[3] + 0x10);
}

