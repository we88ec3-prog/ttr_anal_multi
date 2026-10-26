
void FUN_00642320(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x134) + 0x24c);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xcc);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
    }
    if ((iVar1 != 0) && (0 < *(int *)(iVar1 + 0x20))) {
      FUN_0075cd30(*(int *)(in_EAX + 0x134));
      (**(code **)(**(int **)(in_EAX + 0x134) + 200))();
      iVar1 = *(int *)(*(int *)(in_EAX + 0x134) + 0x24c);
      if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0xdc);
      }
      puVar2 = (undefined4 *)(iVar1 + 0xe8);
      if (7 < *(uint *)(iVar1 + 0xfc)) {
        puVar2 = (undefined4 *)*puVar2;
      }
      FUN_00642e60(1,puVar2,0);
    }
  }
  return;
}

