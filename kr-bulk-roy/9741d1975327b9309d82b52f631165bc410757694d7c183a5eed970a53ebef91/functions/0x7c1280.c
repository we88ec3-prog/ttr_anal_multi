
void FUN_007c1280(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 *puVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *unaff_ESI;
  undefined4 local_8;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x39);
  bVar2 = true;
  local_8 = 1;
  puVar3 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    if (((int)puVar5[5] < *(int *)(in_EAX + 0x14)) ||
       (((int)puVar5[5] <= *(int *)(in_EAX + 0x14) && ((uint)puVar5[4] <= *(uint *)(in_EAX + 0x10)))
       )) {
      puVar4 = (undefined4 *)puVar5[2];
      bVar2 = false;
      local_8 = 0;
    }
    else {
      puVar4 = (undefined4 *)*puVar5;
      bVar2 = true;
      local_8 = 1;
    }
    puVar3 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x39);
  }
  if (bVar2) {
    if (puVar3 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar5 = (undefined4 *)FUN_007c1390(&param_1,1,in_EAX);
      *unaff_ESI = *puVar5;
      *(undefined1 *)(unaff_ESI + 1) = 1;
      return;
    }
    FUN_00742a50();
  }
  if (((int)puVar3[5] <= *(int *)(in_EAX + 0x14)) &&
     (((int)puVar3[5] < *(int *)(in_EAX + 0x14) || ((uint)puVar3[4] < *(uint *)(in_EAX + 0x10))))) {
    puVar5 = (undefined4 *)FUN_007c1390(&param_1,local_8,in_EAX);
    *unaff_ESI = *puVar5;
    *(undefined1 *)(unaff_ESI + 1) = 1;
    return;
  }
  if (0xf < *(uint *)(in_EAX + 0x2c)) {
    FUN_0089120c(*(undefined4 *)(in_EAX + 0x18));
  }
  *(undefined4 *)(in_EAX + 0x2c) = 0xf;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  *(undefined1 *)(in_EAX + 0x18) = 0;
  FUN_0089120c();
  *unaff_ESI = puVar3;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}

