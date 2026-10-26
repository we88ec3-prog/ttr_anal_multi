
undefined4 FUN_007116f0(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 local_1c [2];
  undefined4 local_14;
  undefined4 local_8;
  
  uVar1 = FUN_0070d950();
  local_8 = *(undefined4 *)(in_EAX + 0x30);
  iVar2 = FUN_0070dc60(local_8,uVar1);
  if (iVar2 == 8) {
    local_14 = 4;
    local_1c[0] = uVar1;
    uVar1 = FUN_00712090(local_8,local_1c);
    *(undefined4 *)(unaff_EDI + 8) = uVar1;
  }
  iVar2 = *(int *)(in_EAX + 0x10);
  while (iVar2 == 0x2e) {
    FUN_0070e540();
    iVar2 = *(int *)(in_EAX + 0x10);
  }
  if (*(int *)(in_EAX + 0x10) != 0x3a) {
    return 0;
  }
  FUN_0070e540();
  return 1;
}

