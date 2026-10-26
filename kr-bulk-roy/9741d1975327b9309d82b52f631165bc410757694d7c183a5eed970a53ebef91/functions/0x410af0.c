
void FUN_00410af0(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int in_EAX;
  
  FUN_00411030();
  FUN_004110a0(in_EAX);
  FUN_004107f0(in_EAX);
  iVar3 = *(int *)(in_EAX + 0x110);
  uVar1 = *(undefined1 *)(in_EAX + 0x144);
  uVar2 = *(undefined1 *)(in_EAX + 0x145);
  *(undefined4 *)(iVar3 + 0x108) = *(undefined4 *)(in_EAX + 0x158);
  *(undefined1 *)(iVar3 + 0x104) = uVar2;
  *(undefined1 *)(iVar3 + 0x105) = uVar1;
  FUN_004704c0(iVar3);
  (**(code **)(**(int **)(in_EAX + 0x110) + 200))();
  return;
}

