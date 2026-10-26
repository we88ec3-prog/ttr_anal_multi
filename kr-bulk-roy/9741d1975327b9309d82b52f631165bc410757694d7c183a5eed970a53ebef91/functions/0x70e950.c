
void FUN_0070e950(int *param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *in_ECX;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  undefined1 auStack_44 [4];
  int local_40;
  int local_3c;
  int local_38 [2];
  uint local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_44;
  local_3c = param_1[1];
  piVar7 = (int *)param_1[0xc];
  local_40 = FUN_00713370(10,*(undefined4 *)(piVar7[3] + 8));
  in_ECX[2] = local_40;
  local_14 = 0;
  local_1c = 0;
  local_18 = 0;
  in_ECX[4] = 0xffffffff;
  in_ECX[5] = 0xffffffff;
  *in_ECX = 0xb;
  local_38[0] = 0;
  local_30 = 0;
  local_28 = 0xffffffff;
  local_24 = 0xffffffff;
  local_20 = in_ECX;
  FUN_00712630();
  if (param_1[4] != 0x7b) {
    FUN_0070d750();
    piVar7 = param_1;
  }
  param_1[2] = param_1[1];
  if (param_1[8] == 0x11f) goto LAB_0070ea0b;
  param_1[4] = param_1[8];
  param_1[5] = param_1[9];
  param_1[6] = param_1[10];
  param_1[7] = param_1[0xb];
  param_1[8] = 0x11f;
  do {
    if (param_1[4] == 0x7d) {
LAB_0070eb6e:
      param_1[2] = param_1[1];
      if (param_1[8] == 0x11f) {
LAB_0070ebf1:
        iVar2 = FUN_006ffec0(param_1 + 6);
        param_1[4] = iVar2;
      }
      else {
        param_1[4] = param_1[8];
        param_1[5] = param_1[9];
        param_1[6] = param_1[10];
        param_1[7] = param_1[0xb];
        param_1[8] = 0x11f;
      }
      FUN_0070e870();
      iVar2 = 0;
      for (uVar6 = local_18; 0xf < uVar6; uVar6 = uVar6 + 1 >> 1) {
        iVar2 = iVar2 + 1;
      }
      if (7 < uVar6) {
        uVar6 = iVar2 * 8 + 8U | uVar6 - 8;
      }
      *(uint *)(*(int *)(*piVar7 + 0xc) + local_40 * 4) =
           *(uint *)(*(int *)(*piVar7 + 0xc) + local_40 * 4) & 0x7fffff | uVar6 << 0x17;
      iVar2 = 0;
      for (uVar6 = local_1c; 0xf < uVar6; uVar6 = uVar6 + 1 >> 1) {
        iVar2 = iVar2 + 1;
      }
      if (7 < uVar6) {
        uVar6 = iVar2 * 8 + 8U | uVar6 - 8;
      }
      puVar1 = (uint *)(*(int *)(*piVar7 + 0xc) + local_40 * 4);
      *puVar1 = *puVar1 ^ (uVar6 << 0xe ^ *(uint *)(*(int *)(*piVar7 + 0xc) + local_40 * 4)) &
                          0x7fc000;
      __security_check_cookie(local_c ^ (uint)auStack_44);
      return;
    }
    if (local_38[0] != 0) {
      FUN_007122a0();
      if (((local_38[0] == 0xc) && ((local_30 & 0x100) == 0)) &&
         ((int)(uint)*(byte *)((int)piVar7 + 0x32) <= (int)local_30)) {
        piVar7[9] = piVar7[9] + -1;
      }
      iVar2 = piVar7[9] + 1;
      if ((int)(uint)*(byte *)(*piVar7 + 0x4b) < iVar2) {
        if (0xf9 < iVar2) {
                    /* WARNING: Subroutine does not return */
          FUN_006ff130(piVar7[3],"function or expression too complex",
                       *(undefined4 *)(piVar7[3] + 0x10));
        }
        *(char *)(*piVar7 + 0x4b) = (char)iVar2;
      }
      piVar7[9] = piVar7[9] + 1;
      FUN_00712510(local_38,piVar7[9] + -1);
      local_38[0] = 0;
      if (local_14 == 0x32) {
        FUN_00713410(piVar7,local_20[2]);
        local_14 = 0;
      }
    }
    if (param_1[4] == 0x5b) {
LAB_0070eb1b:
      FUN_0070e710(param_1);
    }
    else {
      if (param_1[4] == 0x11d) {
        iVar2 = FUN_006ffec0(param_1 + 10);
        param_1[8] = iVar2;
        if (iVar2 == 0x3d) goto LAB_0070eb1b;
      }
      FUN_0070fc00(param_1,local_38,0);
      if (0x7ffffffd < (int)local_18) {
        piVar7 = (int *)param_1[0xc];
        FUN_0070d7c0();
        goto LAB_0070ebf1;
      }
      local_18 = local_18 + 1;
      local_14 = local_14 + 1;
    }
    if ((param_1[4] != 0x2c) && (param_1[4] != 0x3b)) {
      if (param_1[4] != 0x7d) {
        iVar2 = local_3c;
        if (local_3c == param_1[1]) {
          iVar2 = 0x7d;
          FUN_0070d750();
        }
        iVar3 = _iscntrl(0x7b);
        if (iVar3 == 0) {
          iVar3 = param_1[0xd];
          pcVar8 = "%c";
        }
        else {
          iVar3 = param_1[0xd];
          pcVar8 = "char(%d)";
        }
        uVar4 = FUN_006f7c30(iVar3,pcVar8,0x7b);
        iVar3 = _iscntrl(0x7d);
        if (iVar3 == 0) {
          iVar3 = param_1[0xd];
          pcVar8 = "%c";
        }
        else {
          iVar3 = param_1[0xd];
          pcVar8 = "char(%d)";
        }
        uVar5 = FUN_006f7c30(iVar3,pcVar8,0x7d);
        uVar4 = FUN_006f7c30(param_1[0xd],"\'%s\' expected (to close \'%s\' at line %d)",uVar5,uVar4
                             ,iVar2);
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(param_1,uVar4,param_1[4]);
      }
      goto LAB_0070eb6e;
    }
    param_1[2] = param_1[1];
    if (param_1[8] == 0x11f) {
LAB_0070ea0b:
      iVar2 = FUN_006ffec0(param_1 + 6);
      param_1[4] = iVar2;
    }
    else {
      param_1[4] = param_1[8];
      param_1[5] = param_1[9];
      param_1[6] = param_1[10];
      param_1[7] = param_1[0xb];
      param_1[8] = 0x11f;
    }
  } while( true );
}

