
void FUN_00582530(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = (int)param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093379b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*unaff_EDI == 0) {
    FUN_00402a70("Synopsis/SynopsisFrame.eif",0x1a);
    FUN_00581eb0();
  }
  FUN_007b6d70(uVar2);
  unaff_EDI[0xb] = 1;
  unaff_EDI[0xc] = 1;
  param_1 = (undefined4 *)iVar3;
  FUN_008438c0(&param_1);
  if ((local_14 != (int *)unaff_EDI[0x10]) &&
     (local_14 = *(int **)((int)local_14 + 0x10), local_14 != (int *)0x0)) {
    unaff_EDI[0xd] = iVar3;
    iVar3 = (local_14[1] - *local_14) / 0x3c;
    if (iVar3 != 0) {
      iVar4 = 0;
      param_1 = (undefined4 *)iVar3;
      do {
        local_18 = *local_14 + iVar4;
        FUN_00804260(&local_18);
        iVar4 = iVar4 + 0x3c;
        param_1 = (undefined4 *)((int)param_1 + -1);
      } while (param_1 != (undefined4 *)0x0);
    }
    iVar3 = FUN_00582400(unaff_EDI);
    if (iVar3 == 0) {
      puVar1 = (undefined4 *)*unaff_EDI;
      unaff_EDI[0xc] = 0;
      unaff_EDI[0xb] = 0;
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = Graphics::CImage::vftable;
        local_8 = 0;
        param_1 = puVar1;
        FUN_00739120(puVar1);
        if (puVar1[4] != 0) {
          FUN_0089120c(puVar1[4]);
        }
        puVar1[4] = 0;
        puVar1[5] = 0;
        puVar1[6] = 0;
        FUN_0089120c(puVar1);
        *unaff_EDI = 0;
      }
    }
    ExceptionList = local_10;
    return;
  }
  unaff_EDI[0xc] = 0;
  ExceptionList = local_10;
  return;
}

