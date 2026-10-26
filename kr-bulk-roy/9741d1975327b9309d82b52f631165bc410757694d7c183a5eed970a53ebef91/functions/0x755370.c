
void FUN_00755370(int param_1,undefined4 param_2,int param_3,int ****param_4,int ****param_5,
                 int ****param_6)

{
  int iVar1;
  int ****ppppiVar2;
  int *unaff_EDI;
  int ****ppppiVar3;
  int ***pppiStack_d0;
  int ***pppiStack_cc;
  int ***pppiStack_c8;
  int ***pppiStack_c4;
  undefined4 uStack_c0;
  int ***pppiStack_bc;
  int ***pppiStack_b8;
  int ***pppiStack_b4;
  int ***pppiStack_b0;
  int ***pppiStack_ac;
  int ***pppiStack_a8;
  int ***pppiStack_a4;
  int ***pppiStack_a0;
  int ***pppiStack_9c;
  int ***pppiStack_98;
  int ***pppiStack_94;
  undefined1 *puStack_90;
  int ***pppiStack_8c;
  undefined4 uStack_88;
  int ***pppiStack_84;
  undefined4 uStack_80;
  int ***pppiStack_7c;
  int iStack_78;
  int ***pppiStack_74;
  int ***pppiStack_70;
  undefined4 uStack_6c;
  int ***pppiStack_68;
  int ***pppiStack_64;
  int ***pppiStack_60;
  int ***pppiStack_5c;
  undefined1 auStack_50 [4];
  int ***local_4c;
  int ***local_48;
  int ***local_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  int iStack_34;
  int ***pppiStack_30;
  int iStack_2c;
  undefined1 *puStack_28;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_50;
  local_38 = param_2;
  iVar1 = unaff_EDI[9];
  if ((iVar1 != 0) && (ppppiVar2 = *(int *****)(iVar1 + 0x1c), param_1 != 0)) {
    if ((((uint)unaff_EDI[10] >> 7 & 1) == 0) && (*(int *)(iVar1 + 0x14b0) != 0)) {
      pppiStack_5c = (int ***)0x0;
      pppiStack_60 = (int ***)&local_48;
      pppiStack_64 = (int ***)0x0;
      pppiStack_68 = (int ***)0x15;
      uStack_6c = 1;
      pppiStack_70 = (int ***)0x1;
      local_48 = (int ***)0x0;
      local_44 = (int ***)0x0;
      local_4c = (int ***)0x0;
      pppiStack_74 = (int ***)param_4;
      iStack_78 = param_3;
      uStack_80 = 0x7553ea;
      pppiStack_7c = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x17])();
      if ((int ****)local_48 != (int ****)0x0) {
        iStack_34 = 0;
        pppiStack_30 = (int ***)0x0;
        puStack_28 = (undefined1 *)((int)param_4 + 1);
        pppiStack_5c = (int ***)&local_44;
        iStack_2c = param_3 + 1;
        pppiStack_60 = (int ***)0x0;
        pppiStack_64 = local_48;
        pppiStack_68 = (int ***)0x75541e;
        (*(code *)(*local_48)[0x12])();
        pppiStack_68 = (int ***)&stack0xffffffa8;
        uStack_6c = 0;
        pppiStack_74 = (int ***)0x755430;
        pppiStack_70 = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x26])();
        pppiStack_74 = pppiStack_5c;
        iStack_78 = 0;
        uStack_80 = 0x755442;
        pppiStack_7c = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x25])();
        uStack_80 = 0;
        pppiStack_84 = (int ***)0x0;
        uStack_88 = 0;
        pppiStack_8c = (int ***)0x1;
        puStack_90 = &stack0xffffffa8;
        pppiStack_94 = (int ***)0x1;
        pppiStack_9c = (int ***)0x755460;
        pppiStack_98 = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x2b])();
        pppiStack_9c = (int ***)&pppiStack_7c;
        pppiStack_a0 = (int ***)0x13;
        pppiStack_a8 = (int ***)0x755472;
        pppiStack_a4 = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x3a])();
        pppiStack_a8 = (int ***)&pppiStack_8c;
        pppiStack_ac = (int ***)&DAT_00000014;
        pppiStack_b4 = (int ***)0x755484;
        pppiStack_b0 = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x3a])();
        pppiStack_b4 = (int ***)0x5;
        pppiStack_b8 = (int ***)0x13;
        uStack_c0 = 0x755493;
        pppiStack_bc = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x39])();
        uStack_c0 = 6;
        pppiStack_c4 = (int ***)&DAT_00000014;
        pppiStack_cc = (int ***)0x7554a2;
        pppiStack_c8 = (int ***)ppppiVar2;
        (*(code *)(*ppppiVar2)[0x39])();
        pppiStack_cc = (int ***)param_6;
        pppiStack_d0 = (int ***)param_5;
        (**(code **)(*unaff_EDI + 0x16c))();
        (*(code *)(*ppppiVar2)[0x39])(ppppiVar2,0x13,pppiStack_b4);
        (*(code *)(*ppppiVar2)[0x39])(ppppiVar2,0x14,pppiStack_c4);
        (*(code *)(*ppppiVar2)[0x25])(ppppiVar2,0,pppiStack_c8);
        ppppiVar3 = &pppiStack_d0;
        (*(code *)(*ppppiVar2)[0x2b])(ppppiVar2,1,ppppiVar3,1,0,0,0);
        (**(code **)(**(int **)(unaff_EDI[9] + 0x14b0) + 4))(0);
        FUN_007510f0(param_3,param_4);
        (**(code **)(**(int **)(unaff_EDI[9] + 0x14b0) + 8))();
        (*(code *)(*ppppiVar2)[0x25])(ppppiVar2,0,ppppiVar3);
        if ((int ****)local_48 != (int ****)0x0) {
          pppiStack_5c = local_48;
          pppiStack_60 = (int ***)0x75555f;
          (*(code *)(*local_48)[2])();
          local_48 = (int ***)0x0;
        }
        if ((int ****)local_44 != (int ****)0x0) {
          pppiStack_5c = local_44;
          pppiStack_60 = (int ***)0x75557b;
          (*(code *)(*local_44)[2])();
          local_44 = (int ***)0x0;
        }
      }
    }
    else {
      pppiStack_5c = (int ***)&local_4c;
      pppiStack_60 = (int ***)0x0;
      pppiStack_68 = (int ***)0x755599;
      pppiStack_64 = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x26])();
      pppiStack_68 = local_44;
      uStack_6c = 0;
      pppiStack_74 = (int ***)0x7555ab;
      pppiStack_70 = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x25])();
      iStack_2c = 0;
      pppiStack_74 = (int ***)0x0;
      puStack_28 = (undefined1 *)0x3f800000;
      local_44 = (int ***)(param_3 + 1);
      local_4c = (int ***)0x0;
      iStack_78 = 0;
      pppiStack_7c = (int ***)0x0;
      uStack_80 = 1;
      local_48 = (int ***)0x0;
      uStack_3c = 0;
      local_38 = 0;
      pppiStack_84 = (int ***)&local_4c;
      puStack_40 = (undefined1 *)((int)param_4 + 1);
      iStack_34 = param_3;
      uStack_88 = 1;
      pppiStack_30 = (int ***)param_4;
      puStack_90 = (undefined1 *)0x7555fc;
      pppiStack_8c = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x2b])();
      puStack_90 = &stack0xffffffa8;
      pppiStack_98 = (int ***)0x75560c;
      pppiStack_94 = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x2f])();
      pppiStack_98 = (int ***)&pppiStack_7c;
      pppiStack_9c = (int ***)0x13;
      pppiStack_a4 = (int ***)0x75561e;
      pppiStack_a0 = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x3a])();
      pppiStack_a4 = (int ***)&pppiStack_84;
      pppiStack_a8 = (int ***)&DAT_00000014;
      pppiStack_b0 = (int ***)0x755630;
      pppiStack_ac = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x3a])();
      pppiStack_b0 = (int ***)0x5;
      pppiStack_b4 = (int ***)0x13;
      pppiStack_bc = (int ***)0x75563f;
      pppiStack_b8 = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x39])();
      pppiStack_bc = (int ***)0x6;
      uStack_c0 = 0x14;
      pppiStack_c8 = (int ***)0x75564e;
      pppiStack_c4 = (int ***)ppppiVar2;
      (*(code *)(*ppppiVar2)[0x39])();
      pppiStack_c8 = (int ***)param_6;
      pppiStack_cc = (int ***)param_5;
      pppiStack_d0 = (int ***)0x755662;
      (**(code **)(*unaff_EDI + 0x16c))();
      pppiStack_d0 = pppiStack_b4;
      ppppiVar3 = ppppiVar2;
      (*(code *)(*ppppiVar2)[0x39])(ppppiVar2,0x13);
      (*(code *)(*ppppiVar2)[0x39])(ppppiVar2,0x14,pppiStack_bc);
      (*(code *)(*ppppiVar2)[0x25])(ppppiVar2,0,ppppiVar3);
    }
    if ((int ****)local_4c != (int ****)0x0) {
      pppiStack_5c = local_4c;
      pppiStack_60 = (int ***)0x7556a8;
      (*(code *)(*local_4c)[2])();
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_50);
  return;
}

