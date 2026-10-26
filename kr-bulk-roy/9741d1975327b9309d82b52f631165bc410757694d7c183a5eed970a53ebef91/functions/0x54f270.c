
bool FUN_0054f270(undefined4 param_1)

{
  ushort in_AX;
  short sVar1;
  int iVar2;
  ushort uVar3;
  int in_ECX;
  uint uVar4;
  
  if (((in_AX & 0xc0) == 0) &&
     (((((uVar3 = in_AX & 1, uVar3 != 0 && ((in_AX & 2) != 0)) ||
        ((uVar3 != 0 && ((in_AX & 4) != 0)))) ||
       ((((((in_AX & 2) != 0 && ((in_AX & 4) != 0)) || (uVar3 != 0)) ||
         (((in_AX & 2) != 0 || ((in_AX & 4) != 0)))) || ((in_AX & 8) != 0)))) ||
      ((in_AX & 0x10) != 0)))) {
    uVar4 = (uint)*(ushort *)(in_ECX + 2);
    FUN_0040f7f0(uVar4,param_1);
    iVar2 = FUN_00819220(uVar4,param_1);
    if ((iVar2 != 0) && (sVar1 = FUN_0081a8e0(iVar2), sVar1 != 0)) {
      iVar2 = FUN_0054f4e0(in_ECX + 4);
      return *(int *)(iVar2 + 4) == 0;
    }
    return false;
  }
  return true;
}

