
void FUN_00463d20(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined2 *in_ECX;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 local_148;
  undefined4 local_144;
  short *local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  uint local_128;
  short *local_124;
  undefined4 local_120;
  short local_11c;
  undefined1 local_11a [254];
  undefined2 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c022;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_138 = 0;
  local_130 = 0;
  local_13c = 0;
  local_144 = 0;
  local_12c = 0;
  local_148 = 0;
  local_134 = 0;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  local_8 = 0;
  local_124 = (short *)&DAT_00bffa2c;
  local_1c = 0;
  psVar5 = &local_11c;
  local_128 = 0;
  local_140 = (short *)0x0;
  sVar1 = 0x20;
  do {
    if (sVar1 == 0x7b) {
      if (local_124[1] == 0x7b) {
        psVar4 = &local_11c;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
          psVar5 = &local_11c;
        }
        *psVar5 = 0x7b;
        psVar5 = psVar5 + 1;
        local_124 = local_124 + 2;
        goto LAB_00464259;
      }
      local_128 = 1;
      local_140 = local_124;
LAB_004641c8:
      psVar4 = &local_11c;
      if ((int)psVar5 - (int)psVar4 == 0x100) {
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
LAB_004641ec:
        FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
        psVar5 = &local_11c;
      }
LAB_00464203:
      local_124 = local_124 + 1;
      goto LAB_00464259;
    }
    if (sVar1 != 0x7d) {
      if (local_128 == 0) {
        *psVar5 = sVar1;
        psVar5 = psVar5 + 1;
      }
      goto LAB_004641c8;
    }
    if (local_128 == 0) {
      *psVar5 = 0x7d;
      psVar5 = psVar5 + 1;
      psVar4 = &local_11c;
      if ((int)psVar5 - (int)psVar4 == 0x100) {
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        goto LAB_004641ec;
      }
      goto LAB_00464203;
    }
    local_128 = 0xffffffff;
    local_120 = 0;
    iVar3 = FUN_00403e00(&local_128,&local_120,local_124,uVar2);
    if ((1 < local_128) || (8 < (int)local_128)) goto switchD_00463e7b_default;
    psVar4 = &local_11c;
    *psVar5 = 0;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
    psVar5 = &local_11c;
    if (iVar3 != 0) {
      switch(local_128) {
      case 0:
        FUN_004643f0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 1:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 2:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 3:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 4:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 5:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 6:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 7:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      case 8:
        FUN_00403fd0(in_ECX);
        local_124 = local_124 + 1;
        local_128 = 0;
        break;
      default:
        goto switchD_00463e7b_default;
      }
      goto LAB_00464259;
    }
    switch(local_128) {
    case 0:
      FUN_00464310(&stack0x00000004);
      goto switchD_00463e7b_default;
    case 1:
      puVar6 = (undefined4 *)&stack0x00000008;
      break;
    case 2:
      puVar6 = &local_134;
      break;
    case 3:
      puVar6 = &local_148;
      break;
    case 4:
      puVar6 = &local_12c;
      break;
    case 5:
      puVar6 = &local_144;
      break;
    case 6:
      puVar6 = &local_13c;
      break;
    case 7:
      puVar6 = &local_130;
      break;
    case 8:
      puVar6 = &local_138;
      break;
    default:
      goto switchD_00463e7b_default;
    }
    FUN_00404190(puVar6);
switchD_00463e7b_default:
    local_124 = local_124 + 1;
    local_128 = 0;
LAB_00464259:
    sVar1 = *local_124;
    if (sVar1 == 0) {
      psVar4 = &local_11c;
      if (psVar5 != psVar4) {
        *psVar5 = 0;
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

