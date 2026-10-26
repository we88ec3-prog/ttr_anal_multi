
void FUN_006423b0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar2 = *(int *)(in_EAX + 0x134);
  if (*(int *)(iVar2 + 0x24c) != 0) {
    iVar4 = *(int *)(*(int *)(iVar2 + 0x24c) + 0xcc);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xdc);
    }
    if (iVar4 != 0) {
      iVar4 = *(int *)(iVar4 + 0x20);
      goto LAB_006423e4;
    }
  }
  iVar4 = -1;
LAB_006423e4:
  if ((*(int *)(iVar2 + 0x24c) == 0) ||
     (iVar1 = *(int *)(*(int *)(iVar2 + 0x24c) + 0xcc), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2;
  }
  if (iVar4 + 1 < iVar1) {
    FUN_0075cd30(iVar2);
    (**(code **)(**(int **)(in_EAX + 0x134) + 200))();
    iVar2 = *(int *)(*(int *)(in_EAX + 0x134) + 0x24c);
    if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 0xcc), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0xdc);
    }
    puVar3 = (undefined4 *)(iVar2 + 0xe8);
    if (7 < *(uint *)(iVar2 + 0xfc)) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_00642e60(1,puVar3,0);
  }
  return;
}

