
void FUN_00613130(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined2 *in_ECX;
  undefined4 *puVar6;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  short *local_128;
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
  
  puStack_c = &LAB_0091c022;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_13c = param_1;
  local_134 = 0;
  local_12c = 0;
  local_148 = 0;
  local_138 = 0;
  local_140 = 0;
  local_144 = 0;
  local_130 = 0;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  local_8 = 0;
  local_18 = 0;
  local_120 = (short *)&DAT_00c2abb8;
  psVar4 = &local_118;
  local_124 = 0;
  local_128 = (short *)0x0;
  sVar1 = 0x3c;
  do {
    if (sVar1 == 0x7b) {
      if (local_120[1] == 0x7b) {
        psVar5 = &local_118;
        if ((int)psVar4 - (int)psVar5 == 0x100) {
          do {
            sVar1 = *psVar5;
            psVar5 = psVar5 + 1;
          } while (sVar1 != 0);
          FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
          psVar4 = &local_118;
        }
        *psVar4 = 0x7b;
        psVar4 = psVar4 + 1;
        local_120 = local_120 + 2;
        goto LAB_00613689;
      }
      local_124 = 1;
      local_128 = local_120;
LAB_006135f4:
      psVar5 = &local_118;
      if ((int)psVar4 - (int)psVar5 == 0x100) {
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
LAB_0061361b:
        FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
        psVar4 = &local_118;
      }
LAB_00613632:
      local_120 = local_120 + 1;
      goto LAB_00613689;
    }
    if (sVar1 != 0x7d) {
      if (local_124 == 0) {
        *psVar4 = sVar1;
        psVar4 = psVar4 + 1;
      }
      goto LAB_006135f4;
    }
    if (local_124 == 0) {
      *psVar4 = 0x7d;
      psVar4 = psVar4 + 1;
      psVar5 = &local_118;
      if ((int)psVar4 - (int)psVar5 == 0x100) {
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        goto LAB_0061361b;
      }
      goto LAB_00613632;
    }
    local_124 = 0xffffffff;
    local_11c = 0;
    iVar3 = FUN_00403e00(&local_124,&local_11c,local_120,uVar2);
    if ((1 < local_124) || (8 < (int)local_124)) goto switchD_00613299_default;
    *psVar4 = 0;
    psVar4 = &local_118;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
    psVar4 = &local_118;
    if (iVar3 != 0) {
      switch(local_124) {
      case 0:
        FUN_00479d80(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 1:
        FUN_00433740(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 2:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 3:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 4:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 5:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 6:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 7:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      case 8:
        FUN_00403fd0(in_ECX);
        local_120 = local_120 + 1;
        local_124 = 0;
        break;
      default:
        goto switchD_00613299_default;
      }
      goto LAB_00613689;
    }
    switch(local_124) {
    case 0:
      FUN_00479e90();
      goto switchD_00613299_default;
    case 1:
      FUN_004336e0(&stack0x00000008);
      goto switchD_00613299_default;
    case 2:
      puVar6 = &local_130;
      break;
    case 3:
      puVar6 = &local_144;
      break;
    case 4:
      puVar6 = &local_140;
      break;
    case 5:
      puVar6 = &local_138;
      break;
    case 6:
      puVar6 = &local_148;
      break;
    case 7:
      puVar6 = &local_12c;
      break;
    case 8:
      puVar6 = &local_134;
      break;
    default:
      goto switchD_00613299_default;
    }
    FUN_00404190(puVar6);
switchD_00613299_default:
    local_120 = local_120 + 1;
    local_124 = 0;
LAB_00613689:
    sVar1 = *local_120;
    if (sVar1 == 0) {
      psVar5 = &local_118;
      if (psVar4 != psVar5) {
        *psVar4 = 0;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_118,(int)psVar5 - (int)local_116 >> 1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

