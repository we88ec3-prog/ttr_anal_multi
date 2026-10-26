
undefined4 FUN_004655f0(uint param_1)

{
  int **ppiVar1;
  int **ppiVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int unaff_EDI;
  int local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b9f0;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar4 = *(int *)(unaff_EDI + 0x164) - *(int *)(unaff_EDI + 0x160) >> 2;
  if (uVar4 <= param_1) {
    if ((int)param_1 < (int)uVar4) {
      return *(undefined4 *)(*(int *)(unaff_EDI + 0x160) + param_1 * 4);
    }
    local_14 = uVar4 + 1000;
    local_1c = (param_1 - uVar4) + 1;
    ExceptionList = &local_10;
    do {
      piVar5 = _malloc(0x248);
      local_8 = 0;
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        local_18 = piVar5;
        FUN_00754880(uVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        *piVar5 = (int)FoxUI::FXUIContentButton::vftable;
        FUN_0077b520(piVar5 + 0x57);
        *(undefined1 *)(piVar5 + 0x56) = 1;
      }
      local_8 = 0xffffffff;
      local_18 = piVar5;
      (**(code **)(*piVar5 + 0x38))(local_14,0x40c3,0,0,0,0);
      piVar5[8] = local_14;
      piVar5[0x4a] = *(int *)(unaff_EDI + 0xcc);
      FUN_004026e0(unaff_EDI + 0xd0,0,0xffffffff);
      piVar5[0x52] = *(int *)(unaff_EDI + 0xec);
      piVar5[0x53] = *(int *)(unaff_EDI + 0xf0);
      piVar5[0x54] = *(int *)(unaff_EDI + 0xf4);
      piVar5[0x55] = *(int *)(unaff_EDI + 0xf8);
      piVar5[0x49] = *(int *)(unaff_EDI + 0x100);
      ppiVar1 = *(int ***)(unaff_EDI + 0x164);
      if (&local_18 < ppiVar1) {
        ppiVar2 = *(int ***)(unaff_EDI + 0x160);
        if (&local_18 < ppiVar2) goto LAB_00465769;
        if (ppiVar1 == *(int ***)(unaff_EDI + 0x168)) {
          FUN_004deab0();
        }
        if (*(undefined4 **)(unaff_EDI + 0x164) != (undefined4 *)0x0) {
          **(undefined4 **)(unaff_EDI + 0x164) =
               *(undefined4 *)
                (*(int *)(unaff_EDI + 0x160) + ((int)&local_18 - (int)ppiVar2 >> 2) * 4);
        }
      }
      else {
LAB_00465769:
        if (ppiVar1 == *(int ***)(unaff_EDI + 0x168)) {
          FUN_004deab0();
        }
        if (*(undefined4 **)(unaff_EDI + 0x164) != (undefined4 *)0x0) {
          **(undefined4 **)(unaff_EDI + 0x164) = piVar5;
        }
      }
      *(int *)(unaff_EDI + 0x164) = *(int *)(unaff_EDI + 0x164) + 4;
      local_14 = local_14 + 1;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  ExceptionList = local_10;
  return *(undefined4 *)(*(int *)(unaff_EDI + 0x160) + param_1 * 4);
}

