
void FUN_006f75f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 0x10) + 0x70);
  FUN_006fd860(*(undefined4 *)(iVar1 + 0x20));
  FUN_006fa130(iVar1,1);
  *(undefined4 *)(iVar1 + 0x74) = 0;
  do {
    *(undefined4 **)(iVar1 + 0x14) = *(undefined4 **)(iVar1 + 0x28);
    uVar2 = **(undefined4 **)(iVar1 + 0x28);
    *(undefined4 *)(iVar1 + 8) = uVar2;
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    *(undefined4 *)(iVar1 + 0x34) = 0;
    iVar3 = FUN_006fdba0(iVar1,FUN_006f75e0,0);
  } while (iVar3 != 0);
  FUN_006f7300();
  return;
}

