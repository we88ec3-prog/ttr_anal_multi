
void FUN_0062d320(int param_1)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *in_ECX;
  int local_bc;
  int iStack_b8;
  int local_b4;
  int iStack_b0;
  int local_ac;
  uint uStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_8c [44];
  int iStack_60;
  undefined4 auStack_54 [5];
  uint uStack_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = -1;
  puStack_10 = &LAB_009384c8;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_bc;
  ExceptionList = &local_14;
  local_bc = param_1;
  if (in_ECX == (int *)0x0) {
LAB_0062d393:
    in_ECX = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff38);
    if (iVar4 != 0x105cc) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0062d393;
    }
  }
  iVar4 = in_ECX[6];
  local_b4 = in_ECX[7];
  iVar6 = in_ECX[8];
  iVar1 = in_ECX[5];
  local_ac = iVar6;
  if (iVar4 == 0) {
    FUN_0062d760(local_bc,iVar1);
  }
  else {
    cVar3 = FUN_0062b240(*(undefined4 *)(*(int *)(local_bc + 0x110) + 0x118),&iStack_b8,iVar4);
    if (cVar3 != '\0') {
      uStack_94 = 7;
      uStack_98 = 0;
      uStack_a8 = uStack_a8 & 0xffff0000;
      iStack_c._1_3_ = 0;
      if ((DAT_00fe657c & 1) == 0) {
        DAT_00fe657c = DAT_00fe657c | 1;
        iStack_c._0_1_ = 1;
        iStack_c._1_3_ = 0;
        FUN_00590370();
        _atexit((_func_4879 *)&LAB_00bcfb30);
      }
      iStack_c._0_1_ = 0;
      uVar5 = FUN_00590720(&DAT_00fe4ca0,iStack_b8);
      iStack_c._0_1_ = 2;
      FUN_00402800(uVar5);
      iStack_c._0_1_ = 0;
      if (7 < uStack_40) {
        FUN_0089120c(auStack_54[0]);
      }
      iStack_b8 = 0x1a2;
      iVar6 = FUN_005854b0();
      FUN_005740f0(&iStack_b8);
      if (iStack_b0 == *(int *)(iVar6 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar7 = (undefined4 *)(iStack_b0 + 0x10);
      if (7 < *(uint *)(iStack_b0 + 0x24)) {
        puVar7 = (undefined4 *)*puVar7;
      }
      FUN_007572f0(puVar7);
      iStack_c = CONCAT31(iStack_c._1_3_,3);
      FUN_00759ac0(0);
      iStack_b0 = 0;
      FUN_00848020(&iStack_b0);
      if (iStack_b8 != iStack_60) {
        *(undefined4 *)(iStack_b8 + 0x18) = 0xffff0000;
        *(undefined1 *)(iStack_b8 + 0x1c) = 1;
        FUN_007591a0(*(int *)(iStack_b8 + 0x10),
                     *(int *)(iStack_b8 + 0x14) - *(int *)(iStack_b8 + 0x10),0xffff0000);
      }
      puVar7 = (undefined4 *)FUN_00891268(0x24);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7[1] = 0xffffffff;
        puVar7[2] = 0xffffffff;
        puVar7[6] = iVar4;
        puVar7[3] = 0;
        puVar7[4] = 0xf43ce;
        *puVar7 = FoxUI::FXUIEventD4::vftable;
        puVar7[5] = iVar1;
        puVar7[7] = local_b4;
        puVar7[8] = local_ac;
      }
      local_ac = 0x196;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_ac);
      if (local_b4 == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar8 = (undefined4 *)(local_b4 + 0x10);
      if (7 < *(uint *)(local_b4 + 0x24)) {
        puVar8 = (undefined4 *)*puVar8;
      }
      FUN_007572f0(puVar8);
      iStack_c._0_1_ = 4;
      FUN_00407330(0xcf,auStack_8c,auStack_54,puVar7,local_bc);
      iStack_c._0_1_ = 3;
      FUN_00757640(auStack_54);
      iStack_c = (uint)iStack_c._1_3_ << 8;
      FUN_00757640(auStack_8c);
      if (7 < uStack_94) {
        FUN_0089120c(uStack_a8);
      }
      goto LAB_0062d61d;
    }
    FUN_0062d6f0(iVar1,iVar4,iVar6);
  }
  FUN_0062ccd0();
LAB_0062d61d:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_bc);
  return;
}

