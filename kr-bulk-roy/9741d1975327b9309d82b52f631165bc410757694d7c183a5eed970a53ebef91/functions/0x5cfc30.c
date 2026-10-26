
int FUN_005cfc30(void)

{
  undefined4 in_EAX;
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  FUN_00542210();
  piVar1 = (int *)FUN_0050b4b0(in_EAX);
  if ((int *)*piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)*piVar1;
  }
  uVar2 = (uint)piVar1[2] >> 2;
  if (*(uint *)(iVar3 + 8) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(iVar3 + 8);
  }
  return *(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + (piVar1[2] & 3U) * 4;
}

