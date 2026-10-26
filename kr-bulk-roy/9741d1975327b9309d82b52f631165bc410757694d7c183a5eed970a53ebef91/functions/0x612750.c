
void FUN_00612750(int param_1,byte param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *unaff_EDI;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d574;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_EDI[4] = 0;
  if (7 < (uint)unaff_EDI[5]) {
    unaff_EDI = (undefined4 *)*unaff_EDI;
  }
  uVar5 = DAT_00fb11a8 & 1;
  *(undefined2 *)unaff_EDI = 0;
  if (uVar5 == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(local_14);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  local_38 = param_1;
  FUN_0082ef00(&local_38);
  if ((local_34 != DAT_00fb11b0) &&
     (iVar4 = *(int *)(local_34 + 0x10), local_38 = iVar4, iVar4 != 0)) {
    local_3c = (uint)param_2;
    if (local_3c < (uint)(*(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x14) >> 2)) {
      iVar2 = *(int *)(*(int *)(iVar4 + 0x14) + local_3c * 4);
      local_34 = *(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2;
    }
    else {
      local_34 = 0;
    }
    uVar6 = 0;
    uVar5 = local_34;
    if (local_34 != 0) {
      do {
        iVar2 = *(int *)(*(int *)(iVar4 + 0x14) + local_3c * 4);
        if (uVar6 < (uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2)) {
          iVar2 = *(int *)(*(int *)(iVar2 + 4) + uVar6 * 4);
        }
        else {
          iVar2 = 0;
        }
        if ((*(int *)(iVar2 + 4) == 4) && (*(int *)(iVar2 + 8) != 0)) {
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_8 = 1;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_8 = 0xffffffff;
          }
          local_44 = 0x2d4;
          FUN_005740f0(&local_44);
          if (local_40 == DAT_00fe5ac8) {
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          uVar3 = FUN_00420070();
          local_8 = 2;
          FUN_004041f0(uVar3,0,0xffffffff);
          local_8 = 0xffffffff;
          iVar4 = local_38;
          uVar5 = local_34;
          if (7 < local_1c) {
            FUN_0089120c(local_30);
            iVar4 = local_38;
            uVar5 = local_34;
          }
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar5);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

