
void FUN_0062ad40(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined1 auStack_bc [4];
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  uint uStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_8c [56];
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int iStack_c;
  
  iStack_c = -1;
  puStack_10 = &LAB_00935e92;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_bc;
  ExceptionList = &local_14;
  local_ac = in_ECX;
  if (param_1 == (int *)0x0) {
LAB_0062adb5:
    param_1 = (int *)0x0;
  }
  else {
    iVar3 = (**(code **)(*param_1 + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff38);
    if (iVar3 != 0x105cc) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0062adb5;
    }
  }
  iVar3 = param_1[5];
  iVar1 = param_1[6];
  local_b0 = param_1[7];
  local_b8 = param_1[8];
  local_b4 = iVar3;
  if (iVar1 == 0) {
    FUN_0062b440(in_ECX,iVar3);
  }
  else {
    cVar2 = FUN_00627610(*(undefined4 *)(in_ECX + 0x110),auStack_bc,iVar1);
    if (cVar2 != '\0') {
      if (*(int *)(in_ECX + 0x118) == 0) {
        uStack_94 = 7;
        uStack_98 = 0;
        uStack_a8 = uStack_a8 & 0xffff0000;
        iStack_c = 0;
        FUN_0049c410();
        uVar4 = FUN_004f7ba0();
        FUN_004026e0(uVar4,0,0xffffffff);
        uVar4 = 0x1a2;
        FUN_005854b0(0x1a2);
        uVar4 = FUN_00585330(uVar4);
        FUN_007572f0(uVar4);
        iStack_c = CONCAT31(iStack_c._1_3_,1);
        FUN_00759ac0(0);
        FUN_00758d30();
        iVar3 = FUN_00891268(0x24);
        if (iVar3 == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_00753fb0(0xf43ce,iVar1,local_b0,local_b8);
        }
        uVar5 = 0x196;
        FUN_005854b0(0x196);
        uVar5 = FUN_00585330(uVar5);
        FUN_007572f0(uVar5);
        iStack_c._0_1_ = 2;
        uVar4 = FUN_00407330(0xcf,auStack_8c,auStack_54,uVar4,local_ac);
        *(undefined4 *)(local_ac + 0x118) = uVar4;
        iStack_c._0_1_ = 1;
        FUN_00757640(auStack_54);
        iStack_c = (uint)iStack_c._1_3_ << 8;
        FUN_00757640(auStack_8c);
        if (7 < uStack_94) {
          FUN_0089120c(uStack_a8);
        }
      }
      goto LAB_0062af59;
    }
    FUN_0062b4e0(iVar3,iVar1,local_b8);
  }
  FUN_0062b1d0();
LAB_0062af59:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_bc);
  return;
}

