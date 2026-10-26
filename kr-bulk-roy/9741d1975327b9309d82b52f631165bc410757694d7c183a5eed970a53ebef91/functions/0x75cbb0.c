
undefined4 FUN_0075cbb0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0x24c) != 0) {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x24c) + 0xcc);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = FUN_0075d370(*(undefined4 *)(iVar1 + 0xe4));
    }
    FUN_00408810();
    FUN_00757710();
    return uVar2;
  }
  return 0xffffffff;
}

