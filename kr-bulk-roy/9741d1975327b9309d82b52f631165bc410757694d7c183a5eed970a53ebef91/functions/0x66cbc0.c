
void FUN_0066cbc0(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  undefined2 *in_EDX;
  uint in_stack_0000001c;
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
  
  puStack_c = &LAB_00919e9a;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_8 = 1;
  *(undefined4 *)(in_EDX + 10) = 7;
  *(undefined4 *)(in_EDX + 8) = 0;
  *in_EDX = 0;
  local_18 = 0;
  local_124 = (ushort *)&DAT_00c34bc0;
  puVar3 = &local_118;
  local_120 = 0;
  uVar1 = 0x7b;
  do {
    if (uVar1 == 0x7b) {
      if (local_124[1] == 0x7b) {
        puVar4 = &local_118;
        if ((int)puVar3 - (int)puVar4 == 0x100) {
          do {
            uVar1 = *puVar4;
            puVar4 = puVar4 + 1;
          } while (uVar1 != 0);
          FUN_00404300(&local_118,(int)puVar4 - (int)local_116 >> 1);
          puVar3 = &local_118;
        }
        *puVar3 = 0x7b;
        puVar3 = puVar3 + 1;
        local_124 = local_124 + 2;
        goto LAB_0066d13c;
      }
      local_120 = 1;
LAB_0066d0ad:
      puVar4 = &local_118;
      if ((int)puVar3 - (int)puVar4 == 0x100) {
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar4 - (int)local_116 >> 1);
        puVar3 = &local_118;
        local_124 = local_124 + 1;
      }
      else {
LAB_0066d082:
        local_124 = local_124 + 1;
      }
      goto LAB_0066d13c;
    }
    iVar5 = uVar1 - 0x7d;
    if (iVar5 != 0) {
      if (local_120 == 0) {
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
      }
      goto LAB_0066d0ad;
    }
    if (local_120 == 0) {
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      puVar4 = &local_118;
      if ((int)puVar3 - (int)puVar4 == 0x100) {
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar4 - (int)local_116 >> 1);
        puVar3 = &local_118;
      }
      goto LAB_0066d082;
    }
    local_120 = 0xffffffff;
    local_11c = iVar5;
    iVar5 = FUN_00403e00(&local_120,&local_11c,local_124,uVar2);
    if ((2 < local_120) || (8 < (int)local_120)) goto switchD_0066cd09_default;
    *puVar3 = 0;
    puVar3 = &local_118;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
    } while (uVar1 != 0);
    FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
    puVar3 = &local_118;
    if (iVar5 != 0) {
      switch(local_120) {
      case 0:
        FUN_00479d80(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 1:
        FUN_00418bd0();
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 2:
        FUN_00479d80(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 3:
        FUN_00403fd0(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 4:
        FUN_00403fd0(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 5:
        FUN_00403fd0(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 6:
        FUN_00403fd0(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 7:
        FUN_00403fd0(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      case 8:
        FUN_00403fd0(in_EDX);
        local_124 = local_124 + 1;
        local_120 = 0;
        break;
      default:
        goto switchD_0066cd09_default;
      }
      goto LAB_0066d13c;
    }
    switch(local_120) {
    case 0:
      FUN_00479e90();
      goto switchD_0066cd09_default;
    case 1:
      FUN_004041f0(&param_2,0,0xffffffff);
      local_124 = local_124 + 1;
      local_120 = 0;
      goto LAB_0066d13c;
    case 2:
      FUN_00479e90();
      goto switchD_0066cd09_default;
    case 3:
      puVar6 = &stack0x00000024;
      break;
    case 4:
      puVar6 = &stack0x00000028;
      break;
    case 5:
      puVar6 = &stack0x0000002c;
      break;
    case 6:
      puVar6 = &stack0x00000030;
      break;
    case 7:
      puVar6 = &stack0x00000034;
      break;
    case 8:
      puVar6 = &stack0x00000038;
      break;
    default:
      goto switchD_0066cd09_default;
    }
    FUN_00404190(puVar6);
switchD_0066cd09_default:
    local_124 = local_124 + 1;
    local_120 = 0;
LAB_0066d13c:
    uVar1 = *local_124;
    if (uVar1 == 0) {
      puVar4 = &local_118;
      if (puVar3 != puVar4) {
        *puVar3 = 0;
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar4 - (int)local_116 >> 1);
      }
      if (7 < in_stack_0000001c) {
        FUN_0089120c(param_2);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

