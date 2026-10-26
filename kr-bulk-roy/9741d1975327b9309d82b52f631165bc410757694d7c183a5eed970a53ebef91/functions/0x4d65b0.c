
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d65b0(int param_1,int param_2,char param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 in_ECX;
  uint uVar8;
  undefined4 uVar9;
  undefined4 ***local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b973;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  piVar3 = (int *)FUN_00891268(0x24,uVar2);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3[7] = 7;
    piVar3[6] = 0;
    *(undefined2 *)(piVar3 + 2) = 0;
  }
  *piVar3 = param_2;
  *(char *)(piVar3 + 1) = param_3;
  FUN_004026e0(in_ECX,0,0xffffffff);
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  uVar4 = DAT_00fdf3a0 - DAT_00fdf39c >> 2;
  uVar8 = 0;
  if (uVar4 != 0) {
    do {
      piVar1 = *(int **)(DAT_00fdf39c + uVar8 * 4);
      if (piVar1[1] == *piVar3) {
        if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) goto LAB_004d6820;
        break;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar4);
  }
  FUN_004d7b00(param_1);
  if (param_3 == -1) {
    puVar5 = (undefined4 *)FUN_00891268(0x14,uVar2);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = FoxUI::FXUIEvent::vftable;
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf425f;
      FUN_004072a0();
      goto LAB_004d6810;
    }
  }
  else if (param_3 == '\x02') {
    puVar5 = (undefined4 *)FUN_00891268(0x18,uVar2);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4260;
      *puVar5 = FoxUI::FXUIEventI1::vftable;
      puVar5[5] = param_2;
      FUN_004072a0();
      goto LAB_004d6810;
    }
  }
  else {
    if (param_3 != '\x03') {
      if (param_3 == '\0') {
        FUN_00402110(in_ECX);
        local_8 = 0;
        iVar6 = FUN_00466df0(local_30,&DAT_00c059b8,2);
        while (iVar6 != -1) {
          FUN_00498090(iVar6,2,&DAT_00bfb894,1);
          iVar6 = FUN_00466df0(local_30,&DAT_00c059b8,2);
        }
        iVar6 = FUN_00891268(0x7c);
        local_8._0_1_ = 1;
        if (iVar6 != 0) {
          if (local_1c < 8) {
            local_30[0] = local_30;
          }
          FUN_004d47f0(local_30[0],0xffffcc00);
        }
        uVar9 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        uVar7 = FUN_00422ed0(1);
        FUN_005536e0(uVar7,uVar9);
        local_8 = 0xffffffff;
        FUN_004fa440();
      }
      goto LAB_004d6810;
    }
    puVar5 = (undefined4 *)FUN_00891268(0x18,uVar2);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4377;
      *puVar5 = FoxUI::FXUIEventI1::vftable;
      puVar5[5] = param_2;
      FUN_004072a0();
      goto LAB_004d6810;
    }
  }
  FUN_004072a0();
LAB_004d6810:
  if (*(int *)(param_1 + 0x120) == 0) {
    FUN_004d6c90();
  }
LAB_004d6820:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

