
void FUN_00667c50(void)

{
  int iVar1;
  short *psVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  int *in_EDX;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  undefined2 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00933122;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_84;
  ExceptionList = &local_14;
  if (in_EDX != (int *)0x0) {
    iVar1 = (**(code **)(*in_EDX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    if (iVar1 == 0x105ca) goto LAB_00667cbc;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EDX = (int *)0x0;
LAB_00667cbc:
  iVar1 = in_EDX[7];
  iVar6 = in_EDX[6];
  FUN_004adcd0(iVar6,iVar1);
  iVar1 = FUN_004ef160(iVar6,iVar1);
  *(int *)(in_ECX + 0x114) = iVar1;
  if (iVar1 != 0) {
    psVar2 = (short *)(iVar1 + 8);
    if (7 < *(uint *)(iVar1 + 0x1c)) {
      psVar2 = *(short **)psVar2;
    }
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0x90))(*psVar2 != 0x5b);
    FUN_00759ac0(0);
    (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
    FUN_00757800(*(int *)(in_ECX + 0x114) + 0x28);
    (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
    uStack_74 = 0;
    uStack_60 = 7;
    uStack_64 = 0;
    FUN_004026e0(*(int *)(in_ECX + 0x114) + 0x44,0,0xffffffff);
    puStack_84 = (undefined4 *)0x0;
    iStack_80 = 0;
    uStack_7c = 0;
    puStack_10._0_1_ = 1;
    puStack_10._1_3_ = 0;
    uStack_44 = 7;
    uStack_48 = 0;
    uStack_58 = (uint)uStack_58._2_2_ << 0x10;
    FUN_00402160(&DAT_00c059b8,2);
    puStack_10._0_1_ = 2;
    FUN_006687d0(&puStack_84,&uStack_58);
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
    if (7 < uStack_44) {
      FUN_0089120c(uStack_58);
    }
    FUN_00765af0();
    puVar5 = puStack_84;
    puVar3 = puStack_84;
    for (iVar1 = (iStack_80 - (int)puStack_84) / 0x1c; puStack_84 = puVar3, iVar1 != 0;
        iVar1 = iVar1 + -1) {
      puVar3 = puVar5;
      if (7 < (uint)puVar5[5]) {
        puVar3 = (undefined4 *)*puVar5;
      }
      uVar4 = FUN_007572f0(puVar3);
      puStack_10._0_1_ = 3;
      FUN_007661a0(*(undefined4 *)(in_ECX + 0x108),uVar4);
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
      FUN_00757640(&uStack_58);
      puVar5 = puVar5 + 7;
      puVar3 = puStack_84;
    }
    (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
    FUN_006673e0(in_ECX);
    if (puVar3 != (undefined4 *)0x0) {
      FUN_0049bf30();
      FUN_0089120c(puVar3);
    }
    if (7 < uStack_5c) {
      FUN_0089120c(uStack_70);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&puStack_84);
  return;
}

