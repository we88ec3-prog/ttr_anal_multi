
void FUN_0067d0a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_EDI;
  undefined4 uVar3;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  undefined1 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cbce;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((param_1 == -1) && (param_2 == -1)) {
    *unaff_EDI = 0xffffffff;
    unaff_EDI[1] = 0xffffffff;
    unaff_EDI[2] = 0xffffffff;
    unaff_EDI[3] = 0xffffffff;
    unaff_EDI[4] = 0;
    unaff_EDI[5] = 0;
    unaff_EDI[6] = 0xffffffff;
    unaff_EDI[7] = 0xffffffff;
    *(undefined1 *)(unaff_EDI + 8) = 0;
    unaff_EDI[10] = 0;
    unaff_EDI[0xb] = 0;
    unaff_EDI[0xc] = 0;
    unaff_EDI[0xd] = 0;
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff98);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((param_1 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
      if (param_2 - 1U < 100) {
        iVar1 = param_2 * 0x20 + iVar2;
        if (((*(int *)(param_2 * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
           (iVar1 != 0)) {
          local_5c = *(undefined4 *)(iVar1 + 4);
          local_54 = FUN_004034e0();
          FUN_008438c0(&local_5c);
          iVar2 = local_54;
          if (((local_58 != *(int *)(local_54 + 4)) &&
              (local_54 = *(int *)(local_58 + 0x10), local_54 != 0)) &&
             (*(int *)(local_54 + 8) == 0xb)) {
            uVar3 = *(undefined4 *)(iVar1 + 4);
            FUN_0045af80(iVar2,uVar3);
            iVar2 = FUN_0052cc90(uVar3);
            if (iVar2 != 0) {
              FUN_0067b780();
              local_44 = *(undefined4 *)(iVar1 + 0xc);
              local_30 = *(int *)(iVar2 + 0x18) != 0;
              local_50 = param_1;
              local_40 = *(undefined4 *)(iVar1 + 0x10);
              local_4c = param_2;
              local_3c = *(undefined4 *)(iVar1 + 0x14);
              local_38 = (uint)*(ushort *)(iVar2 + 4);
              local_48 = *(undefined4 *)(iVar1 + 4);
              local_34 = *(undefined4 *)(local_54 + 0x6c);
              local_28 = *(undefined4 *)(iVar2 + 8);
              local_20 = *(undefined4 *)(iVar2 + 0x10);
              local_1c = *(undefined4 *)(iVar2 + 0x14);
              local_24 = *(undefined4 *)(iVar2 + 0xc);
              FUN_0067d2b0();
              ExceptionList = local_14;
              return;
            }
          }
          FUN_0067b780();
          ExceptionList = local_14;
          return;
        }
      }
      else {
        FUN_006edb60(&DAT_00c0ddc0);
      }
    }
    *unaff_EDI = 0xffffffff;
    unaff_EDI[1] = 0xffffffff;
    unaff_EDI[2] = 0xffffffff;
    unaff_EDI[3] = 0xffffffff;
    unaff_EDI[4] = 0;
    unaff_EDI[5] = 0;
    unaff_EDI[6] = 0xffffffff;
    unaff_EDI[7] = 0xffffffff;
    *(undefined1 *)(unaff_EDI + 8) = 0;
    unaff_EDI[10] = 0;
    unaff_EDI[0xb] = 0;
    unaff_EDI[0xc] = 0;
    unaff_EDI[0xd] = 0;
  }
  ExceptionList = local_14;
  return;
}

