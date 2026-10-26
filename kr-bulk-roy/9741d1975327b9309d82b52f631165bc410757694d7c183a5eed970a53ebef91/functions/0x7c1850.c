
void FUN_007c1850(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int in_EAX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *unaff_ESI;
  undefined4 local_8;
  
  puVar6 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  cVar1 = *(char *)((int)puVar6 + 0x29);
  bVar3 = true;
  local_8 = 1;
  puVar4 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    if (((int)puVar6[5] < *(int *)(in_EAX + 0x14)) ||
       (((int)puVar6[5] <= *(int *)(in_EAX + 0x14) && ((uint)puVar6[4] <= *(uint *)(in_EAX + 0x10)))
       )) {
      puVar5 = (undefined4 *)puVar6[2];
      bVar3 = false;
      local_8 = 0;
    }
    else {
      puVar5 = (undefined4 *)*puVar6;
      bVar3 = true;
      local_8 = 1;
    }
    puVar4 = puVar6;
    puVar6 = puVar5;
    cVar1 = *(char *)((int)puVar5 + 0x29);
  }
  if (bVar3) {
    if (puVar4 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar6 = (undefined4 *)FUN_007c1950(&param_1,1,in_EAX);
      uVar2 = *puVar6;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      *unaff_ESI = uVar2;
      return;
    }
    FUN_00827b40();
  }
  if (((int)puVar4[5] <= *(int *)(in_EAX + 0x14)) &&
     (((int)puVar4[5] < *(int *)(in_EAX + 0x14) || ((uint)puVar4[4] < *(uint *)(in_EAX + 0x10))))) {
    puVar6 = (undefined4 *)FUN_007c1950(&param_1,local_8,in_EAX);
    *unaff_ESI = *puVar6;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  if (*(int *)(in_EAX + 0x18) != 0) {
    FUN_0089120c(*(int *)(in_EAX + 0x18));
  }
  *(undefined4 *)(in_EAX + 0x18) = 0;
  *(undefined4 *)(in_EAX + 0x1c) = 0;
  *(undefined4 *)(in_EAX + 0x20) = 0;
  FUN_0089120c();
  *(undefined1 *)(unaff_ESI + 1) = 0;
  *unaff_ESI = puVar4;
  return;
}

