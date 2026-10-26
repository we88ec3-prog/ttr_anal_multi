
int FUN_008bdfd0(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  uint uVar4;
  int local_8;
  
  uVar1 = unaff_ESI[1];
  local_8 = 0;
  iVar3 = 0;
  if (uVar1 < param_1) {
    uVar4 = (uVar1 >> 1) + 5 + uVar1;
    if (uVar1 == 0x1fffffff) {
      return 0x40;
    }
    if ((uVar4 < uVar1) || (0x1fffffff < uVar4)) {
      uVar4 = 0x1fffffff;
    }
    uVar2 = FUN_008bc7d0(unaff_ESI[3],4,uVar1,uVar4,*unaff_ESI,&local_8);
    *unaff_ESI = uVar2;
    iVar3 = local_8;
    if (local_8 == 0) {
      unaff_ESI[1] = uVar4;
    }
  }
  return iVar3;
}

