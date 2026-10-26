
void FUN_0077f8f0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910642;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)unaff_EDI[1];
  if ((in_ECX < piVar1) && (piVar2 = (int *)*unaff_EDI, piVar2 <= in_ECX)) {
    if (piVar1 == (int *)unaff_EDI[2]) {
      FUN_00872fb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    piVar1 = (int *)unaff_EDI[1];
    local_8 = 0;
    if (piVar1 != (int *)0x0) {
      piVar2 = *(int **)(*unaff_EDI + ((int)in_ECX - (int)piVar2 >> 2) * 4);
      *piVar1 = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 8))();
        if (iVar3 == 0) {
          iVar3 = (**(code **)(*(int *)*piVar1 + 0xc))();
          *piVar1 = iVar3;
        }
        *(int *)(*piVar1 + 4) = *(int *)(*piVar1 + 4) + 1;
      }
    }
  }
  else {
    if (piVar1 == (int *)unaff_EDI[2]) {
      FUN_00872fb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    piVar1 = (int *)unaff_EDI[1];
    local_8 = 1;
    if (piVar1 != (int *)0x0) {
      piVar2 = (int *)*in_ECX;
      *piVar1 = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 8))();
        if (iVar3 == 0) {
          iVar3 = (**(code **)(*(int *)*piVar1 + 0xc))();
          *piVar1 = iVar3;
        }
        *(int *)(*piVar1 + 4) = *(int *)(*piVar1 + 4) + 1;
      }
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 4;
  ExceptionList = local_10;
  return;
}

