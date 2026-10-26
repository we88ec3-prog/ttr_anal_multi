
void FUN_004185b0(ushort *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  undefined2 *in_ECX;
  int iVar4;
  ushort *puVar5;
  uint in_stack_00000020;
  undefined1 *puVar6;
  ushort *local_124;
  uint local_120;
  int local_11c;
  ushort local_118;
  undefined1 local_116 [254];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091beda;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_8 = 1;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  uVar1 = *param_1;
  local_18 = 0;
  puVar5 = &local_118;
  local_120 = 0;
  do {
    if (uVar1 == 0) {
      puVar3 = &local_118;
      if (puVar5 != puVar3) {
        *puVar5 = 0;
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
      }
      if (7 < in_stack_00000020) {
        FUN_0089120c(param_3);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (uVar1 == 0x7b) {
      if (param_1[1] == 0x7b) {
        puVar3 = &local_118;
        if ((int)puVar5 - (int)puVar3 == 0x100) {
          do {
            uVar1 = *puVar3;
            puVar3 = puVar3 + 1;
          } while (uVar1 != 0);
          FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
          puVar5 = &local_118;
        }
        *puVar5 = 0x7b;
        puVar5 = puVar5 + 1;
        local_124 = param_1 + 2;
        goto LAB_00418b0d;
      }
      local_120 = 1;
LAB_00418a7e:
      puVar3 = &local_118;
      if ((int)puVar5 - (int)puVar3 == 0x100) {
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
        puVar5 = &local_118;
        local_124 = param_1 + 1;
      }
      else {
LAB_00418a53:
        local_124 = param_1 + 1;
      }
    }
    else {
      iVar4 = uVar1 - 0x7d;
      if (iVar4 != 0) {
        if (local_120 == 0) {
          *puVar5 = uVar1;
          puVar5 = puVar5 + 1;
        }
        goto LAB_00418a7e;
      }
      if (local_120 == 0) {
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
        puVar3 = &local_118;
        if ((int)puVar5 - (int)puVar3 == 0x100) {
          do {
            uVar1 = *puVar3;
            puVar3 = puVar3 + 1;
          } while (uVar1 != 0);
          FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
          puVar5 = &local_118;
        }
        goto LAB_00418a53;
      }
      local_120 = 0xffffffff;
      local_11c = iVar4;
      iVar4 = FUN_00403e00(&local_120,&local_11c,param_1,uVar2);
      if ((local_120 < 2) && ((int)local_120 < 9)) {
        puVar3 = &local_118;
        *puVar5 = 0;
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
        puVar5 = &local_118;
        if (iVar4 == 0) {
          switch(local_120) {
          case 0:
            puVar6 = (undefined1 *)&param_2;
            break;
          case 1:
            FUN_004041f0(&param_3,0,0xffffffff);
            local_124 = param_1 + 1;
            local_120 = 0;
            goto LAB_00418b0d;
          case 2:
            puVar6 = &stack0x00000028;
            break;
          case 3:
            puVar6 = &stack0x0000002c;
            break;
          case 4:
            puVar6 = &stack0x00000030;
            break;
          case 5:
            puVar6 = &stack0x00000034;
            break;
          case 6:
            puVar6 = &stack0x00000038;
            break;
          case 7:
            puVar6 = &stack0x0000003c;
            break;
          case 8:
            puVar6 = &stack0x00000040;
            break;
          default:
            goto switchD_004186f9_default;
          }
          FUN_00404190(puVar6);
          goto switchD_004186f9_default;
        }
        switch(local_120) {
        case 0:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 1:
          FUN_00418bd0();
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 2:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 3:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 4:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 5:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 6:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 7:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        case 8:
          FUN_00403fd0(in_ECX);
          local_124 = param_1 + 1;
          local_120 = 0;
          break;
        default:
          goto switchD_004186f9_default;
        }
      }
      else {
switchD_004186f9_default:
        local_124 = param_1 + 1;
        local_120 = 0;
      }
    }
LAB_00418b0d:
    uVar1 = *local_124;
    param_1 = local_124;
  } while( true );
}

