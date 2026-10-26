
void FUN_0079b4a0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x2d0);
  if ((in_EAX < puVar3) && (puVar1 = *(undefined4 **)(param_1 + 0x2cc), puVar1 <= in_EAX)) {
    if (puVar3 == *(undefined4 **)(param_1 + 0x2d4)) {
      FUN_0079bf70();
    }
    in_EAX = (undefined4 *)(((int)in_EAX - (int)puVar1 & 0xffffff80U) + *(int *)(param_1 + 0x2cc));
  }
  else if (puVar3 == *(undefined4 **)(param_1 + 0x2d4)) {
    FUN_0079bf70();
  }
  if (*(undefined4 **)(param_1 + 0x2d0) != (undefined4 *)0x0) {
    puVar3 = *(undefined4 **)(param_1 + 0x2d0);
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar3 = puVar3 + 1;
    }
  }
  *(int *)(param_1 + 0x2d0) = *(int *)(param_1 + 0x2d0) + 0x80;
  return;
}

