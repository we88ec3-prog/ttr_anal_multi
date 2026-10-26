
void FUN_00690fa0(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x134) + 0x24c);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
    FUN_006438f0(iVar1);
  }
  FUN_00757710();
  uVar3 = 2;
  uVar2 = 0x3e;
  FUN_00585620(0x3e,2);
  uVar2 = FUN_00585330(uVar2);
  FUN_00690d80(in_EAX,uVar2,uVar3);
  FUN_0075cd30(*(undefined4 *)(in_EAX + 0x134));
  *(undefined4 *)(in_EAX + 0x208) = 2;
  iVar1 = *(int *)(*(int *)(in_EAX + 0x134) + 0x24c);
  if (iVar1 != 0) {
    FUN_00749920(iVar1);
  }
  (**(code **)(**(int **)(in_EAX + 0x134) + 200))();
  FUN_00690b30();
  FUN_0075cd30(*(undefined4 *)(in_EAX + 0x138));
  (**(code **)(**(int **)(in_EAX + 0x138) + 200))();
  FUN_00691780();
  *(undefined4 *)(in_EAX + 0x208) = 2;
  iVar1 = *(int *)(*(int *)(in_EAX + 0x138) + 0x24c);
  if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xdc);
  }
  *(undefined4 *)(in_EAX + 0x20c) = *(undefined4 *)(iVar1 + 0x24c);
  FUN_006904b0(0);
  return;
}

