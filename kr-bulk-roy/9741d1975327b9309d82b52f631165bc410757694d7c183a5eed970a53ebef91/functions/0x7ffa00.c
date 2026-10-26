
undefined4 FUN_007ffa00(void)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = FUN_007ffa70(in_ECX);
  if (iVar2 != 0) {
    FUN_007ffa00();
    FUN_007ffa00();
    FUN_007ffa00();
    FUN_007ffa00();
    iVar2 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc);
    iVar2 = iVar2 * iVar2;
    lVar1 = (ulonglong)(uint)(iVar2 * 6) * 2;
    uVar3 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(int *)(in_ECX + 0x74) = iVar2 * 2;
    *(undefined4 *)(in_ECX + 0x70) = uVar3;
    FUN_007ffbc0(0,uVar3);
  }
  return 1;
}

