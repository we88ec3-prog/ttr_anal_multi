
void FUN_004cf680(short *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined2 *in_EDX;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 local_144;
  undefined4 local_140;
  short *local_13c;
  undefined4 local_138;
  undefined4 local_134 [2];
  undefined4 local_12c;
  undefined4 local_128;
  uint local_124;
  short *local_120;
  undefined4 local_11c;
  short local_118;
  undefined1 local_116 [254];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bfd2;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_134[0] = 0;
  local_12c = 0;
  local_138 = 0;
  local_140 = 0;
  local_128 = 0;
  local_144 = 0;
  *(undefined4 *)(in_EDX + 10) = 7;
  *(undefined4 *)(in_EDX + 8) = 0;
  *in_EDX = 0;
  local_8 = 0;
  sVar1 = *param_1;
  local_18 = 0;
  psVar5 = &local_118;
  local_124 = 0;
  local_13c = (short *)0x0;
  local_120 = param_1;
  do {
    if (sVar1 == 0) {
      psVar4 = &local_118;
      if (psVar5 != psVar4) {
        *psVar5 = 0;
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 0x7b) {
      if (local_120[1] == 0x7b) {
        psVar4 = &local_118;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
          psVar5 = &local_118;
        }
        *psVar5 = 0x7b;
        psVar5 = psVar5 + 1;
        local_120 = local_120 + 2;
        goto LAB_004cfbd7;
      }
      local_124 = 1;
      local_13c = local_120;
LAB_004cfb44:
      psVar4 = &local_118;
      if ((int)psVar5 - (int)psVar4 == 0x100) {
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
LAB_004cfb6b:
        FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
        psVar5 = &local_118;
      }
LAB_004cfb82:
      local_120 = local_120 + 1;
      goto LAB_004cfbd7;
    }
    if (sVar1 != 0x7d) {
      if (local_124 == 0) {
        *psVar5 = sVar1;
        psVar5 = psVar5 + 1;
      }
      goto LAB_004cfb44;
    }
    if (local_124 == 0) {
      *psVar5 = 0x7d;
      psVar5 = psVar5 + 1;
      psVar4 = &local_118;
      if ((int)psVar5 - (int)psVar4 == 0x100) {
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        goto LAB_004cfb6b;
      }
      goto LAB_004cfb82;
    }
    local_124 = 0xffffffff;
    local_11c = 0;
    iVar3 = FUN_00403e00(&local_124,&local_11c,local_120,uVar2);
    if ((2 < local_124) || (8 < (int)local_124)) goto switchD_004cf7e9_default;
    psVar4 = &local_118;
    *psVar5 = 0;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
    psVar5 = &local_118;
    if (iVar3 != 0) {
      switch(local_124) {
      case 0:
        FUN_00479d80(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 1:
        FUN_00427610(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 2:
        FUN_00427610(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 3:
        FUN_00403fd0(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 4:
        FUN_00403fd0(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 5:
        FUN_00403fd0(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 6:
        FUN_00403fd0(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 7:
        FUN_00403fd0(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 8:
        FUN_00403fd0(in_EDX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      default:
        goto switchD_004cf7e9_default;
      }
      goto LAB_004cfbd7;
    }
    switch(local_124) {
    case 0:
      FUN_00479e90();
      goto switchD_004cf7e9_default;
    case 1:
      FUN_004275b0(&stack0x00000008);
      goto switchD_004cf7e9_default;
    case 2:
      FUN_004275b0(&stack0x0000000c);
      goto switchD_004cf7e9_default;
    case 3:
      puVar6 = &local_144;
      break;
    case 4:
      puVar6 = &local_128;
      break;
    case 5:
      puVar6 = &local_140;
      break;
    case 6:
      puVar6 = &local_138;
      break;
    case 7:
      puVar6 = &local_12c;
      break;
    case 8:
      puVar6 = local_134;
      break;
    default:
      goto switchD_004cf7e9_default;
    }
    FUN_00404190(puVar6);
switchD_004cf7e9_default:
    local_120 = local_120 + 1;
    local_124 = 0;
LAB_004cfbd7:
    sVar1 = *local_120;
  } while( true );
}

