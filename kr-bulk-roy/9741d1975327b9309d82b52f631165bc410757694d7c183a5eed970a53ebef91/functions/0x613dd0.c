
void FUN_00613dd0(ushort *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  undefined2 *in_ECX;
  int iVar4;
  ushort *puVar5;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  undefined4 in_stack_00000024;
  uint in_stack_00000038;
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
  
  puStack_c = &LAB_0091d492;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_8 = 2;
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
      if (7 < in_stack_0000001c) {
        FUN_0089120c(param_2);
      }
      in_stack_0000001c = 7;
      in_stack_00000018 = 0;
      param_2 = param_2 & 0xffff0000;
      if (7 < in_stack_00000038) {
        FUN_0089120c(in_stack_00000024);
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
        goto LAB_00614366;
      }
      local_120 = 1;
LAB_006142d0:
      puVar3 = &local_118;
      if ((int)puVar5 - (int)puVar3 == 0x100) {
        do {
          uVar1 = *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar1 != 0);
        FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
        puVar5 = &local_118;
        local_124 = param_1 + 1;
        goto LAB_00614366;
      }
LAB_006142a5:
      local_124 = param_1 + 1;
      goto LAB_00614366;
    }
    iVar4 = uVar1 - 0x7d;
    if (iVar4 != 0) {
      if (local_120 == 0) {
        *puVar5 = uVar1;
        puVar5 = puVar5 + 1;
      }
      goto LAB_006142d0;
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
      goto LAB_006142a5;
    }
    local_120 = 0xffffffff;
    local_11c = iVar4;
    iVar4 = FUN_00403e00(&local_120,&local_11c,param_1,uVar2);
    if ((2 < local_120) || (8 < (int)local_120)) goto switchD_00613f19_default;
    puVar3 = &local_118;
    *puVar5 = 0;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
    } while (uVar1 != 0);
    FUN_00404300(&local_118,(int)puVar3 - (int)local_116 >> 1);
    puVar5 = &local_118;
    if (iVar4 != 0) {
      switch(local_120) {
      case 0:
        FUN_00418bd0();
        local_124 = param_1 + 1;
        local_120 = 0;
        break;
      case 1:
        FUN_00418bd0();
        local_124 = param_1 + 1;
        local_120 = 0;
        break;
      case 2:
        FUN_00420700(in_ECX);
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
        goto switchD_00613f19_default;
      }
      goto LAB_00614366;
    }
    switch(local_120) {
    case 0:
      FUN_004041f0(&param_2,0,0xffffffff);
      local_124 = param_1 + 1;
      local_120 = 0;
      goto LAB_00614366;
    case 1:
      FUN_004041f0(&stack0x00000024,0,0xffffffff);
      local_124 = param_1 + 1;
      local_120 = 0;
      goto LAB_00614366;
    case 2:
      FUN_004206a0(&stack0x00000040);
      goto switchD_00613f19_default;
    case 3:
      puVar6 = &stack0x00000044;
      break;
    case 4:
      puVar6 = &stack0x00000048;
      break;
    case 5:
      puVar6 = &stack0x0000004c;
      break;
    case 6:
      puVar6 = &stack0x00000050;
      break;
    case 7:
      puVar6 = &stack0x00000054;
      break;
    case 8:
      puVar6 = &stack0x00000058;
      break;
    default:
      goto switchD_00613f19_default;
    }
    FUN_00404190(puVar6);
switchD_00613f19_default:
    local_124 = param_1 + 1;
    local_120 = 0;
LAB_00614366:
    uVar1 = *local_124;
    param_1 = local_124;
  } while( true );
}

